#include <gtest/gtest.h>
#include <cmath>
#include <limits>
#include "tri_gen_trajectry_generator/trajectory_generator.hpp"

namespace {
Constraints bounds() { return {-0.7, 0.7, -1.0, 1.0, 0.5, -0.5, -1.0, 1.0}; }

TEST(TrajectoryGenerator, StraightTravelAndReverse) {
    for (double direction : {-1.0, 1.0}) {
        NLPTrajectoryGeneratorFixedDt generator(1.3);
        generator.setConstraints(bounds());
        generator.setDt(0.2);
        generator.setHorizon(40);
        tri_gen_msgs::msg::State start, goal;
        goal.x = direction;
        auto trajectory = generator.generateTrajectory(start, goal);
        ASSERT_EQ(trajectory.states.size(), 41u);
        ASSERT_EQ(trajectory.controls.size(), 40u);
        EXPECT_NEAR(trajectory.states.front().x, 0.0, 1e-5);
        EXPECT_NEAR(trajectory.states.back().x, goal.x, 1e-5);
        EXPECT_NEAR(trajectory.states.back().v, 0.0, 1e-5);
        EXPECT_NEAR(trajectory.states.back().phi, 0.0, 1e-5);
        for (const auto &state : trajectory.states) {
            EXPECT_LE(std::abs(state.v), 0.5 + 1e-5);
            EXPECT_LE(std::abs(state.phi), 0.7 + 1e-5);
        }
    }
}

TEST(TrajectoryGenerator, EquivalentHeadings) {
    NLPTrajectoryGeneratorFixedDt generator(1.3);
    generator.setConstraints(bounds());
    tri_gen_msgs::msg::State start, goal;
    start.theta = M_PI;
    goal.theta = -M_PI;
    auto trajectory = generator.generateTrajectory(start, goal);
    EXPECT_NEAR(std::sin(trajectory.states.back().theta - goal.theta), 0.0, 1e-5);
}

TEST(TrajectoryGenerator, TurnAcrossHeadingBoundaryWithTightSteering) {
    NLPTrajectoryGeneratorFixedDt generator(1.3);
    auto constraints = bounds();
    constraints.phi_min = -0.31;
    constraints.phi_max = 0.31;
    generator.setConstraints(constraints);
    generator.setDt(0.2);
    generator.setHorizon(60);
    tri_gen_msgs::msg::State start, goal;
    start.theta = 3.0;
    start.phi = goal.phi = 0.3;
    start.v = goal.v = 0.4;
    const double yaw_rate = start.v / 1.3 * std::sin(start.phi);
    const double theta_final = start.theta + 12.0 * yaw_rate;
    goal.theta = std::atan2(std::sin(theta_final), std::cos(theta_final));
    goal.x = start.v / yaw_rate * (std::sin(theta_final + start.phi) -
                                    std::sin(start.theta + start.phi));
    goal.y = start.v / yaw_rate * (std::cos(start.theta + start.phi) -
                                    std::cos(theta_final + start.phi));
    const auto trajectory = generator.generateTrajectory(start, goal);
    EXPECT_NEAR(trajectory.states.back().x, goal.x, 1e-5);
    EXPECT_NEAR(trajectory.states.back().y, goal.y, 1e-5);
    EXPECT_NEAR(std::atan2(std::sin(trajectory.states.back().theta - goal.theta),
                          std::cos(trajectory.states.back().theta - goal.theta)), 0.0, 1e-5);
}

TEST(TrajectoryGenerator, InvalidInputs) {
    EXPECT_THROW(NLPTrajectoryGeneratorFixedDt(0.0), std::invalid_argument);
    NLPTrajectoryGeneratorFixedDt generator(1.3);
    generator.setConstraints(bounds());
    tri_gen_msgs::msg::State start, goal;
    for (double dt : {0.0, -0.1, std::numeric_limits<double>::quiet_NaN()}) {
        generator.setDt(dt);
        EXPECT_THROW(generator.generateTrajectory(start, goal), std::invalid_argument);
    }
    generator.setDt(0.1);
    generator.setHorizon(0);
    EXPECT_THROW(generator.generateTrajectory(start, goal), std::invalid_argument);
    generator.setHorizon(20);
    goal.v = 1.0;
    EXPECT_THROW(generator.generateTrajectory(start, goal), std::invalid_argument);
}

class InvalidResultGenerator : public NLPTrajectoryGeneratorBase {
public:
    InvalidResultGenerator() : NLPTrajectoryGeneratorBase(1.3) {}
    int corruption = 0;
protected:
    Result solve(const casadi::DM &, const casadi::DM &) override {
        Result result;
        result.states.assign(N_ + 1, casadi::DM::zeros(5));
        result.controls.assign(N_, casadi::DM::zeros(2));
        result.durations.assign(N_, casadi::DM(dt_));
        if (corruption == 0) result.states.back()(0) = 0.01;  // terminal error
        if (corruption == 1) result.states[1](0) = 0.01;  // dynamics error
        if (corruption == 2) result.controls[0](0) = 2.0;  // control bounds
        if (corruption == 3) result.states[1](0) = std::numeric_limits<double>::quiet_NaN();
        if (corruption == 4) result.controls.clear();
        return result;
    }
};

TEST(TrajectoryGenerator, RejectsInvalidSolverOutput) {
    InvalidResultGenerator generator;
    generator.setConstraints(bounds());
    tri_gen_msgs::msg::State start, goal;
    for (int corruption = 0; corruption < 5; ++corruption) {
        generator.corruption = corruption;
        EXPECT_THROW(generator.generateTrajectory(start, goal), std::runtime_error);
    }
}

TEST(TrajectoryGenerator, InfeasibleGoalFails) {
    NLPTrajectoryGeneratorFixedDt generator(1.3);
    generator.setConstraints(bounds());
    generator.setHorizon(2);
    tri_gen_msgs::msg::State start, goal;
    goal.x = 100.0;
    EXPECT_THROW(generator.generateTrajectory(start, goal), std::exception);
}
}  // namespace
