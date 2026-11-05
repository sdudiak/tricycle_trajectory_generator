#include <rclcpp/rclcpp.hpp>
#include "tri_gen_trajectry_generator/trajectory_generator_node.hpp"
#include <rclcpp/rclcpp.hpp>
#include "tri_gen_trajectry_generator/trajectory_generator_node.hpp"
#include <casadi/casadi.hpp>
#include <iostream>

using namespace casadi;

using namespace casadi;
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::executors::MultiThreadedExecutor executor;
    rclcpp::Node::SharedPtr node = std::make_shared<TrajectoryGeneratorNode>();
    executor.add_node(node);
    executor.spin();
    
    rclcpp::shutdown();

        // const int N = 100;
        // const double dt = 0.1;
        // const double L = 1.3;

        // // Define state and control variables
        // SX state = SX::sym("state", 5);     // [x, y, theta, phi, v]
        // SX control = SX::sym("control", 2); // [omega_phi, a]

        // SX x = state(0), y = state(1), theta = state(2), phi = state(3), v = state(4);
        // SX omega = control(0), a = control(1);

        // SX dx = SX::zeros(5);
        // dx(0) = v * cos(theta + phi);
        // dx(1) = v * sin(theta + phi);
        // dx(2) = v / L * sin(phi);
        // dx(3) = omega;
        // dx(4) = a;

        // Function f = Function("f", {state, control}, {dx});

        // // Optimization variables
        // SX X = SX::sym("X", 5, N + 1);
        // SX U = SX::sym("U", 2, N);

        // std::vector<SX> constraints;
        // std::vector<SX> objective;

        // // Initial and goal state
        // SX x0 = SX::vertcat({0.0, 0.0, 0.0, 0.0, 0.0});
        // SX xf = SX::vertcat({2.0, 2.0, 0.0, 0.0, 0.0});

        // constraints.push_back(X(Slice(), 0) - x0);

        // for (int k = 0; k < N; ++k)
        // {
        //     SX x_curr = X(Slice(), k);
        //     SX u_curr = U(Slice(), k);

        //     SX x_next = x_curr + dt * f(std::vector<SX>{x_curr, u_curr})[0];
        //     constraints.push_back(X(Slice(), k + 1) - x_next);

        //     SX err = X(Slice(), k + 1) - xf;
        //     objective.push_back(10 * mtimes(err.T(), err));
        //     objective.push_back(0.1 * mtimes(u_curr.T(), u_curr));
        // }

        // SX cost = SX::sum1(SX::vertcat(objective));

        // SX opt_vars = SX::vertcat({SX::reshape(X, 5 * (N + 1), 1),
        //                            SX::reshape(U, 2 * N, 1)});

        // SX g = SX::vertcat(constraints);
        // SXDict nlp = {{"x", opt_vars}, {"f", cost}, {"g", g}};

        // Dict opts;
        // opts["ipopt.print_level"] = 0;
        // opts["print_time"] = false;
        // Function solver = nlpsol("solver", "ipopt", nlp, opts);

        // std::vector<double> lbx(opt_vars.size().first, -1e20);
        // std::vector<double> ubx(opt_vars.size().first, 1e20);

        // // Apply constraints to control inputs
        // for (int k = 0; k < N; ++k)
        // {
        //     int idx = 5 * (N + 1) + 2 * k;
        //     lbx[idx] = -1.0;     // omega_phi min
        //     ubx[idx] = 1.0;      // omega_phi max
        //     lbx[idx + 1] = -2.0; // a min
        //     ubx[idx + 1] = 2.0;  // a max
        // }

        // // Apply constraints to phi, v
        // for (int k = 0; k <= N; ++k)
        // {
        //     int idx_phi = k * 5 + 3;
        //     int idx_v = k * 5 + 4;
        //     lbx[idx_phi] = -0.5;
        //     ubx[idx_phi] = 0.5;
        //     lbx[idx_v] = -1.0;
        //     ubx[idx_v] = 1.0;
        // }

        // std::vector<double> lbg(g.size().first, 0.0);
        // std::vector<double> ubg(g.size().first, 0.0);
        // std::vector<double> x_init(opt_vars.size().first, 0.0);

        // std::map<std::string, DM> arg = {
        //     {"x0", x_init},
        //     {"lbx", lbx},
        //     {"ubx", ubx},
        //     {"lbg", lbg},
        //     {"ubg", ubg}};

        // auto res = solver(arg);
        // DM sol = res.at("x");

        // DM Xsol = sol(Slice(0, 5 * (N + 1)));
        // DM Usol = sol(Slice(5 * (N + 1), sol.size1()));

        // std::cout << "Trajectory and Control Data:" << std::endl;
        // for (int k = 0; k < N; ++k)
        // {
        //     double x = Xsol(5 * k).scalar();
        //     double y = Xsol(5 * k + 1).scalar();
        //     double theta = Xsol(5 * k + 2).scalar();
        //     double phi = Xsol(5 * k + 3).scalar();
        //     double v = Xsol(5 * k + 4).scalar();
        //     double omega = Usol(2 * k).scalar();
        //     double a = Usol(2 * k + 1).scalar();

        //     std::cout << "Step " << k << ": "
        //               << "x=" << x << ", y=" << y
        //               << ", theta=" << theta << ", phi=" << phi
        //               << ", v=" << v << ", omega_phi=" << omega
        //               << ", a=" << a << std::endl;
        // }

        // // Print final state
        // double xN = Xsol(5 * N).scalar();
        // double yN = Xsol(5 * N + 1).scalar();
        // std::cout << "Final Step " << N << ": x=" << xN << ", y=" << yN << std::endl;

        // return 0;
    }
