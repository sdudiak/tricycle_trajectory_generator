#include "tri_gen_trajectry_generator/trajectory_generator.hpp"

using namespace casadi;

// --------------------- Base Class ---------------------

NLPTrajectoryGeneratorBase::NLPTrajectoryGeneratorBase(double L) : L_(L) {}

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

NLPTrajectoryGeneratorBase::Trajectory NLPTrajectoryGeneratorBase::generateTrajectory(const State& start, State& goal)
{
    casadi::DM start_dm = stateMsgToDM(start);
    casadi::DM goal_dm = stateMsgToDM(goal);

    Result raw_trajectory = solve(start_dm,goal_dm);

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
        SX angle_err = err(2); // theta
        SX vel_err = err(4);                          // v
        // Objective function. Currently we care only about the x and y positions and orientation
        obj += 1 * (10.0 * dot(pos_err, pos_err) +
                              10.0 * angle_err * angle_err + 
                              0.0 * vel_err * vel_err) +
               0.01 * dot(Uk, Uk);
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

    // ---------- Solve ----------
    std::map<std::string, DM> args = {
        {"x0", DM::zeros(total_vars)},
        {"lbx", lbx},
        {"ubx", ubx},
        {"lbg", lbg},
        {"ubg", ubg},
        {"p", DM::vertcat({x0_dm, x_goal_dm})}};

    auto res = solver(args);
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

// // --------------------- Variable Dt Optimizer --------------------- //

// NLPTrajectoryGeneratorVariableDt::NLPTrajectoryGeneratorVariableDt(double L)
//     : NLPTrajectoryGeneratorBase(L) {}

// NLPTrajectoryGeneratorVariableDt::Result NLPTrajectoryGeneratorVariableDt::solve(const DM &x0, const DM &x_goal)
// {
//     Function f = createDynamicsFunction();

//     std::vector<SX> X, U, T_vec, g;
//     SX obj = 0;

//     SX X0 = SX::sym("X0", 4);
//     SX X_goal = SX::sym("X_goal", 4);
//     X.push_back(X0);

//     for (int k = 0; k < N_; ++k)
//     {
//         SX Uk = SX::sym("U_" + std::to_string(k), 2);
//         SX Tk = SX::sym("T_" + std::to_string(k));
//         SX Xk = SX::sym("X_" + std::to_string(k + 1), 4);

//         SX x_step = X[k];
//         SX dt_k = Tk / M_;
//         for (int i = 0; i < M_; ++i)
//         {
//             x_step = rk4(f, x_step, Uk, dt_k);
//         }

//         X.push_back(Xk);
//         U.push_back(Uk);
//         T_vec.push_back(Tk);
//         g.push_back(Xk - x_step);

//         SX pos_err = Xk(Slice(0, 3)) - X_goal(Slice(0, 3));
//         obj += dot(pos_err, pos_err) + 0.1 * dot(Uk, Uk) + 0.01 * Tk;
//     }

//     for (int k = 0; k < N_ - 1; ++k)
//     {
//         SX acc = (U[k + 1](0) - U[k](0)) / T_vec[k];
//         g.push_back(acc);
//     }

//     SX nlp_x = SX::vertcat({SX::vertcat(U), SX::vertcat(T_vec), SX::vertcat(std::vector<SX>(X.begin() + 1, X.end()))});
//     SXDict nlp = {{"x", nlp_x}, {"f", obj}, {"g", SX::vertcat(g)}, {"p", SX::vertcat({X0, X_goal})}};
//     Function solver = nlpsol("solver", "ipopt", nlp);

//     std::vector<double> lbx, ubx;
//     for (int k = 0; k < N_; ++k)
//     {
//         lbx.push_back(v_min_);
//         ubx.push_back(v_max_);
//         lbx.push_back(omega_min_);
//         ubx.push_back(omega_max_);
//     }
//     for (int k = 0; k < N_; ++k)
//     {
//         lbx.push_back(dt_min_);
//         ubx.push_back(dt_max_);
//     }
//     for (int k = 0; k < N_; ++k)
//     {
//         lbx.insert(lbx.end(), {-inf, -inf, -inf, phi_min_});
//         ubx.insert(ubx.end(), {inf, inf, inf, phi_max_});
//     }

//     DM lbg = DM::zeros(g.size());
//     DM ubg = DM::zeros(g.size());
//     for (int i = 4 * N_; i < g.size(); ++i)
//     {
//         lbg(i) = acc_min_;
//         ubg(i) = acc_max_;
//     }
//     std::map<std::string, DM> args = {
//         {"x0", DM::zeros(nlp_x.size1())},
//         {"lbx", lbx},
//         {"ubx", ubx},
//         {"lbg", lbg},
//         {"ubg", ubg},
//         {"p", DM::vertcat({x0, x_goal})}
//     };
//     auto res = solver(args);

//     DM sol = res.at("x");
//     std::vector<DM> U_opt, X_opt, T_opt;
//     int idx = 0;
//     for (int k = 0; k < N_; ++k)
//     {
//         U_opt.push_back(sol(Slice(idx, idx + 2)));
//         idx += 2;
//     }
//     for (int k = 0; k < N_; ++k)
//     {
//         T_opt.push_back(sol(Slice(idx, idx + 1)));
//         idx += 1;
//     }
//     for (int k = 0; k < N_; ++k)
//     {
//         X_opt.push_back(sol(Slice(idx, idx + 4)));
//         idx += 4;
//     }

//     X_opt.insert(X_opt.begin(), x0);
//     return Result{X_opt, U_opt, T_opt};
// }
