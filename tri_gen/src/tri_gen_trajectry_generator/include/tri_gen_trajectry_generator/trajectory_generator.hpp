#pragma once

#include <casadi/casadi.hpp>
#include <vector>
#include "tri_gen_trajectry_generator/utils.hpp"
#include "tri_gen_msgs/msg/control.hpp"
#include "tri_gen_msgs/msg/state.hpp"
#include "tri_gen_msgs/msg/trajectory.hpp"

/**
 * @brief Base class for NLP-based trajectory generation for a tricycle vehicle.
 *
 * Implements common setup including dynamics, integration (RK4), and parameter handling.
 */
class NLPTrajectoryGeneratorBase
{
    using State = tri_gen_msgs::msg::State;
    using Control = tri_gen_msgs::msg::Control;
    using Trajectory = tri_gen_msgs::msg::Trajectory;

public:
    /**
     * @brief Constructor.
     * @param L Wheelbase length of the tricycle model.
     */
    explicit NLPTrajectoryGeneratorBase(double L);

    /// Virtual destructor.
    virtual ~NLPTrajectoryGeneratorBase() = default;

    /**
     * @brief Struct containing the result of the NLP solve.
     */
    struct Result
    {
        std::vector<casadi::DM> states;    ///< List of optimized states.
        std::vector<casadi::DM> controls;  ///< List of optimized controls.
        std::vector<casadi::DM> durations; ///< Time durations between each step (may be fixed or variable).
    };

    /// Set the number of trajectory steps.
    void setHorizon(int N) { N_ = N; };

    /// Set the time step size (used only in fixed-dt solver).
    void setDt(double dt) { dt_ = dt; };

    /// Set motion and control constraints.
    void setConstraints(const Constraints &constraints);

    /**
     * @brief Converts a ROS2 state message to a CasADi DM vector.
     * @param state ROS2 state message.
     * @return CasADi DM vector [x, y, theta, phi].
     */
    casadi::DM stateMsgToDM(const State &state) const;

    /**
     * @brief Converts the NLP result into a ROS2 trajectory message.
     * @param result NLP optimization result.
     * @return Trajectory message containing the sequence of states and controls.
     */
    Trajectory resultToTrajectory(const Result &result) const;

    /**
     * @brief High-level entry point for generating a trajectory.
     * @param start Initial state.
     * @param goal Target state.
     * @return Trajectory from start to goal.
     */
    Trajectory generateTrajectory(const State &start, State &goal);

protected:
    int N_ = 20;      ///< Horizon length (number of steps).
    double dt_ = 0.1; ///< Fixed timestep duration.
    double L_;        ///< Vehicle wheelbase.

    // Constraint bounds
    double v_min_ = -1.0, v_max_ = 1.0;
    double omega_min_ = -1.0, omega_max_ = 1.0;
    double phi_min_ = -M_PI / 2, phi_max_ = M_PI / 2;
    double acc_min_ = -2.0, acc_max_ = 2.0;

    /**
     * @brief Defines the tricycle model dynamics.
     * @param state Current state [x, y, theta, phi].
     * @param control Control input [v, omega_phi].
     * @return Time derivative of state.
     */
    casadi::SX dynamics(const casadi::SX &state, const casadi::SX &control) const;

    /**
     * @brief Wraps the dynamics in a CasADi Function.
     * @return CasADi Function for dynamics.
     */
    casadi::Function createDynamicsFunction() const;

    /**
     * @brief Runge-Kutta 4th order integrator.
     * @param f CasADi Function representing the system dynamics.
     * @param xk Current state.
     * @param uk Control input.
     * @param dt Time step.
     * @return State after one time step.
     */
    casadi::SX rk4(const casadi::Function &f, const casadi::SX &xk, const casadi::SX &uk, const casadi::SX &dt) const;

    /**
     * @brief Abstract solver function to be implemented by subclasses.
     * @param x0 Initial state.
     * @param x_goal Target state.
     * @return Optimized trajectory.
     */
    virtual Result solve(const casadi::DM &x0, const casadi::DM &x_goal) = 0;
};

/**
 * @brief NLP-based trajectory generator with fixed time step.
 *
 * This implementation uses a fixed duration for each timestep and is currently the active trajectory generator.
 */
class NLPTrajectoryGeneratorFixedDt : public NLPTrajectoryGeneratorBase
{
public:
    /**
     * @brief Constructor.
     * @param L Wheelbase length of the tricycle model.
     */
    explicit NLPTrajectoryGeneratorFixedDt(double L);

    /**
     * @brief Solve the NLP problem with fixed dt.
     * @param x0 Initial state.
     * @param x_goal Target state.
     * @return Optimized trajectory result.
     */
    Result solve(const casadi::DM &x0, const casadi::DM &x_goal);
};

/**
 * @brief NLP-based trajectory generator with variable time step durations.
 *
 * @note This version is experimental and currently not used in the system.
 */
class NLPTrajectoryGeneratorVariableDt : public NLPTrajectoryGeneratorBase
{
public:
    /**
     * @brief Constructor.
     * @param L Wheelbase length of the tricycle model.
     */
    explicit NLPTrajectoryGeneratorVariableDt(double L);

    /**
     * @brief Solve the NLP problem with variable durations.
     * @param x0 Initial state.
     * @param x_goal Target state.
     * @return Optimized trajectory result.
     */
    Result solve(const casadi::DM &x0, const casadi::DM &x_goal);

private:
    int M_ = 5;            ///< Number of different dt options to optimize over (discretized).
    double dt_min_ = 0.05; ///< Minimum allowed time step.
    double dt_max_ = 0.5;  ///< Maximum allowed time step.
};
