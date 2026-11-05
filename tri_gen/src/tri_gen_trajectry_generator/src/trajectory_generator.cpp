#include "tri_gen_trajectry_generator/trajectory_generator.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace casadi;

// --------------------- Base Class ---------------------

NLPTrajectoryGeneratorBase::NLPTrajectoryGeneratorBase(double L) : L_(L) {
    if (!std::isfinite(L) || L <= 0.0)
        throw std::invalid_argument("Wheelbase must be finite and positive");
}

SX NLPTrajectoryGeneratorBase::dynamics(const SX &state, const SX &control) const
{
    SX x = state(0), y = state(1), theta = state(2), phi = state(3), v = state(4);
    SX omega = control(0), a = control(1);

    SX dx = SX::zeros(5);
    dx(0) = v * cos(theta + phi);
    dx(1) = v * sin(theta + phi);
    dx(2) = v / L_ * sin(phi);
    dx(3) = omega;
    dx(4) = a;
    return dx;
}

Function NLPTrajectoryGeneratorBase::createDynamicsFunction() const
{
    SX state = SX::sym("state", 5);
    SX control = SX::sym("control", 2);
    SX x_dot = dynamics(state, control);
    return Function("f", {state, control}, {x_dot});
}

SX NLPTrajectoryGeneratorBase::rk4(const Function &f, const SX &xk, const SX &uk, const SX &dt) const
{
    SX k1 = f(std::vector<SX>{xk, uk})[0];
    SX k2 = f(std::vector<SX>{xk + dt / 2 * k1, uk})[0];
    SX k3 = f(std::vector<SX>{xk + dt / 2 * k2, uk})[0];
    SX k4 = f(std::vector<SX>{xk + dt * k3, uk})[0];

    return xk + dt / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
}

void NLPTrajectoryGeneratorBase::setConstraints(const Constraints &constraints)
{
    v_min_ = constraints.v_min;
    v_max_ = constraints.v_max;
    omega_min_ = constraints.omega_min;
    omega_max_ = constraints.omega_max;
    phi_min_ = constraints.phi_min;
    phi_max_ = constraints.phi_max;
    acc_min_ = constraints.acc_min;
    acc_max_ = constraints.acc_max;
}

casadi::DM NLPTrajectoryGeneratorBase::stateMsgToDM(const State &state) const
{
    return casadi::DM::vertcat({state.x,
                                state.y,
                                state.theta,
                                state.phi,
                                state.v});
}

NLPTrajectoryGeneratorBase::Trajectory NLPTrajectoryGeneratorBase::resultToTrajectory(const Result &result) const
{
    Trajectory trajectory;
    double current_time = 0.0;

    // Convert states
    for (size_t i = 0; i < result.states.size(); ++i)
    {
        if (i > 0 && i - 1 < result.durations.size())
        {
            // Advance current_time using duration of previous control
            double duration = static_cast<double>(result.durations[i - 1]);
            current_time += duration;
        }

        const casadi::DM &s = result.states[i];
        State state;
        state.x = static_cast<double>(s(0));
        state.y = static_cast<double>(s(1));
        state.theta = static_cast<double>(s(2));
        state.phi = static_cast<double>(s(3));
        state.v = static_cast<double>(s(4));

        // Timestamp
        int64_t total_ns = static_cast<int64_t>(std::round(current_time * 1e9));
        state.stamp_from_start.sec = static_cast<int32_t>(total_ns / 1000000000);
        state.stamp_from_start.nanosec = static_cast<uint32_t>(total_ns % 1000000000);

        trajectory.states.push_back(state);
    }

    // Convert controls
    for (size_t i = 0; i < result.controls.size(); ++i)
    {
        const casadi::DM &u = result.controls[i];
        Control control;
        control.omega_phi = static_cast<double>(u(0));
        control.a = static_cast<double>(u(1));

        if (i < trajectory.states.size())
        {
            trajectory.states[i].omega_phi = control.omega_phi;
        }

        double duration_sec = static_cast<double>(result.durations[i]);
        int64_t dur_ns = static_cast<int64_t>(std::round(duration_sec * 1e9));
        control.duration.sec = static_cast<int32_t>(dur_ns / 1000000000);
        control.duration.nanosec = static_cast<uint32_t>(dur_ns % 1000000000);

        trajectory.controls.push_back(control);
    }
    return trajectory;
}

NLPTrajectoryGeneratorBase::Trajectory NLPTrajectoryGeneratorBase::generateTrajectory(const State& start, const State& goal)
{
    if (N_ < 1 || N_ > 1000 || !std::isfinite(dt_) || dt_ <= 0.0 ||
        N_ * dt_ > 2147483647.0)
        throw std::invalid_argument("Invalid horizon or timestep");
    for (const auto &bounds : {std::make_pair(phi_min_, phi_max_),
            std::make_pair(v_min_, v_max_), std::make_pair(omega_min_, omega_max_),
            std::make_pair(acc_min_, acc_max_)}) {
        if (!std::isfinite(bounds.first) || !std::isfinite(bounds.second) ||
            bounds.first >= bounds.second)
            throw std::invalid_argument("Bounds must be finite and ordered");
    }
    for (const auto *state : {&start, &goal}) {
        for (double value : {state->x, state->y, state->theta, state->phi, state->v, state->omega_phi})
            if (!std::isfinite(value)) throw std::invalid_argument("Nonfinite endpoint");
        if (state->phi < phi_min_ || state->phi > phi_max_ ||
            state->v < v_min_ || state->v > v_max_)
            throw std::invalid_argument("Endpoint outside state bounds");
    }
    casadi::DM start_dm = stateMsgToDM(start);
    casadi::DM goal_dm = stateMsgToDM(goal);
    // Select an equivalent heading near the initial heading for initialization.
    goal_dm(2) = start.theta + std::atan2(std::sin(goal.theta - start.theta),
                                        std::cos(goal.theta - start.theta));
    Result raw_trajectory = solve(start_dm, goal_dm);
    if (raw_trajectory.states.size() != static_cast<size_t>(N_ + 1) ||
        raw_trajectory.controls.size() != static_cast<size_t>(N_) ||
        raw_trajectory.durations.size() != static_cast<size_t>(N_))
        throw std::runtime_error("Invalid solution dimensions");
    const double tolerance = 1e-5;
    auto check = [tolerance](double value, double lower, double upper) {
        if (!std::isfinite(value) || value < lower - tolerance || value > upper + tolerance)
            throw std::runtime_error("Solution violates bounds or dynamics");
    };
    const auto dynamics_function = createDynamicsFunction();
    SX sx = SX::sym("validation_x", 5), su = SX::sym("validation_u", 2);
    Function step("validation_rk4", {sx, su}, {rk4(dynamics_function, sx, su, dt_)});
    for (int k = 0; k <= N_; ++k) {
        const auto &state = raw_trajectory.states[k];
        for (int i = 0; i < 5; ++i) check(static_cast<double>(state(i)), -1e20, 1e20);
        check(static_cast<double>(state(3)), phi_min_, phi_max_);
        check(static_cast<double>(state(4)), v_min_, v_max_);
        if (k == 0 || k == N_) {
            const auto &endpoint = k == 0 ? start_dm : goal_dm;
            for (int i = 0; i < 5; ++i) {
                double error = static_cast<double>(state(i) - endpoint(i));
                if (i == 2) error = std::atan2(std::sin(error), std::cos(error));
                check(error, 0.0, 0.0);
            }
        }
        if (k == N_) continue;
        const auto &control = raw_trajectory.controls[k];
        check(static_cast<double>(control(0)), omega_min_, omega_max_);
        check(static_cast<double>(control(1)), acc_min_, acc_max_);
        check(static_cast<double>(raw_trajectory.durations[k]), dt_, dt_);
        const auto predicted = step(std::vector<DM>{state, control})[0];
        for (int i = 0; i < 5; ++i)
            check(static_cast<double>(raw_trajectory.states[k + 1](i) - predicted(i)), 0.0, 0.0);
    }

    return resultToTrajectory(raw_trajectory);
}

// --------------------- Fixed Dt Optimizer ---------------------

NLPTrajectoryGeneratorFixedDt::NLPTrajectoryGeneratorFixedDt(double L)
    : NLPTrajectoryGeneratorBase(L)
{
}

NLPTrajectoryGeneratorBase::Result NLPTrajectoryGeneratorFixedDt::solve(const DM &x0_dm, const DM &x_goal_dm)
{
    Function f = createDynamicsFunction();

    // Symbolic parameter vector: [x0; x_goal]
    SX param = SX::sym("param", 10);
    SX X_goal = param(Slice(5, 10));

    // Symbolic variables
    std::vector<SX> Xs; // X_0 to X_N
    std::vector<SX> Us; // U_0 to U_{N-1}
    SX obj = 0;
    std::vector<SX> g;

    // Declare X0 as a symbolic variable, and constrain it to match param(0:5)
    SX X0_sym = SX::sym("X_0", 5);
    for (int i = 0; i < 5; ++i)
        g.push_back(X0_sym(i) - param(i));
    Xs.push_back(X0_sym);

    // Iterate over the optimizationsteps
    for (int k = 0; k < N_; ++k)
    {
        SX Uk = SX::sym("U_" + std::to_string(k), 2);
        SX Xk = SX::sym("X_" + std::to_string(k + 1), 5);

        Us.push_back(Uk);
        Xs.push_back(Xk);

        SX Xk_pred = rk4(f, Xs[k], Uk, dt_);

        // Dynamics constraint. It assures that the states follow the system dynamics
        SX diff = Xk - Xk_pred;
        for (int i = 0; i < 5; ++i)
            g.push_back(diff(i));

        SX err = Xk - X_goal;
        SX pos_err = SX::vertcat({err(0), err(1)});   // x, y
        SX angle_err = atan2(sin(err(2)), cos(err(2))); // theta
        SX vel_err = err(4);                          // v
        // Objective function. Currently we care only about the x and y positions and orientation
        obj += 1 * (10.0 * dot(pos_err, pos_err) +
                              10.0 * angle_err * angle_err +
                              0.0 * vel_err * vel_err) +
               0.01 * dot(Uk, Uk);
    }

    // Enforce the complete terminal state; heading is periodic.
    for (int i = 0; i < 5; ++i) {
        SX error = Xs.back()(i) - X_goal(i);
        g.push_back(i == 2 ? atan2(sin(error), cos(error)) : error);
    }

    // Stack variables: [X0, ..., XN, U0, ..., UN-1]

    SX opt_vars = SX::vertcat({SX::reshape(SX::horzcat(Xs), 5 * (N_ + 1), 1),
                               SX::reshape(SX::horzcat(Us), 2 * N_, 1)});

    SXDict nlp = {
        {"x", opt_vars},
        {"f", obj},
        {"g", SX::vertcat(g)},
        {"p", param}};

    Function solver = nlpsol("solver", "ipopt", nlp);

    // ---------- Bounds ----------
    int total_vars = 5 * (N_ + 1) + 2 * N_;
    std::vector<double> lbx(total_vars, -1e20);
    std::vector<double> ubx(total_vars, 1e20);

    // Bound phi and v in state variables
    for (int k = 0; k <= N_; ++k)
    {
        int phi_idx = k * 5 + 3;
        int v_idx = k * 5 + 4;

        lbx[phi_idx] = phi_min_;
        ubx[phi_idx] = phi_max_;

        lbx[v_idx] = v_min_;
        ubx[v_idx] = v_max_;
    }

    // Bound omega_phi and a in control variables
    for (int k = 0; k < N_; ++k)
    {
        int offset = 5 * (N_ + 1) + 2 * k;
        lbx[offset] = omega_min_;
        ubx[offset] = omega_max_;
        lbx[offset + 1] = acc_min_;
        ubx[offset + 1] = acc_max_;
    }

    int ng = static_cast<int>(g.size());
    DM lbg = DM::zeros(ng);
    DM ubg = DM::zeros(ng);

    // Initialize on a straight interpolation between the endpoint states.
    std::vector<double> initial(total_vars, 0.0);
    for (int k = 0; k <= N_; ++k)
        for (int i = 0; i < 5; ++i)
            initial[5 * k + i] = static_cast<double>(x0_dm(i)) +
                double(k) / N_ * static_cast<double>(x_goal_dm(i) - x0_dm(i));

    // ---------- Solve ----------
    std::map<std::string, DM> args = {
        {"x0", initial},
        {"lbx", lbx},
        {"ubx", ubx},
        {"lbg", lbg},
        {"ubg", ubg},
        {"p", DM::vertcat({x0_dm, x_goal_dm})}};

    auto res = solver(args);
    const auto stats = solver.stats();
    if (!stats.at("success").to_bool())
        throw std::runtime_error("Solver failed: " + stats.at("return_status").to_string());
    DM sol = res.at("x");

    // ---------- Extract solution ----------
    DM Xsol = sol(Slice(0, 5 * (N_ + 1)));
    DM Usol = sol(Slice(5 * (N_ + 1), sol.size1()));

    std::vector<DM> X_opt, U_opt, T_opt;
    for (int k = 0; k <= N_; ++k)
        X_opt.push_back(Xsol(Slice(5 * k, 5 * (k + 1))));

    for (int k = 0; k < N_; ++k)
    {
        U_opt.push_back(Usol(Slice(2 * k, 2 * (k + 1))));
        T_opt.push_back(DM(dt_));
    }

    return Result{X_opt, U_opt, T_opt};
}
