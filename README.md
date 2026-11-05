# Tricycle trajectory generator

A ROS 2 demo that generates trajectories for a tricycle vehicle using CasADi and
IPOPT, then displays them in RViz. The optimizer uses direct multiple shooting,
RK4 integration, and limits on steering, speed, steering rate, and acceleration.

## Run

Requires Docker Compose and a Linux desktop with X11 or XWayland.
From the repository root:

```bash
# Allow GUI access; run on the host.
xhost +si:localuser:"$(id -un)"

cd docker
docker compose up --build
```

The container user defaults to UID 1000 and must match your host UID for this
display permission to work. Adjust the Compose build arguments `USER_UID` and
`USER_GID` if needed.

Edit [trajectory_request.yaml](trajectory_request.yaml), then send a request from
another terminal:

```bash
docker exec -t tricycle_trajectory_generator /request_trajectory.sh
```

RViz arrows show the start (**yellow**), goal (**red**), vehicle heading
(**green**), and steering direction (**blue**).

After C++ source changes, rebuild and recreate the container:

```bash
cd docker
docker compose up --build --force-recreate
```

YAML request changes do not require rebuilding. When finished, stop the demo
with Ctrl+C and revoke display access:

```bash
xhost -si:localuser:"$(id -un)"
```

## How it works

The state is `[x, y, heading, steering angle, drive-wheel speed]`; controls are
steering rate and acceleration. RK4 integrates the kinematic model over a fixed
time step. The objective penalizes position and heading error plus control effort.
Constraints enforce the initial and terminal states and motion limits, with
periodic heading error to handle wraparound.

Requests run sequentially. Success requires solver convergence and checks on
endpoints, bounds, finite values, and dynamics residuals. Responses include the
trajectory, length, maximum absolute speed, sampled curvature, and generation time.
The startup parameter `wheelbase` defaults to `1.3` meters.

## Packages

- `tri_gen_msgs`: messages and trajectory-generation service.
- `tri_gen_trajectory_requester`: YAML-configured service client.
- `tri_gen_trajectry_generator`: optimizer, service node, and RViz configuration.

The generator package currently uses the spelling `trajectry` in ROS commands.

## Tests

In a ROS/CasADi environment:

```bash
cd tri_gen
colcon build --packages-up-to tri_gen_trajectry_generator
source install/setup.bash
colcon test --packages-select tri_gen_trajectry_generator --ctest-args -R test_trajectory_generator
colcon test-result --verbose
```

Six regression tests cover forward/reverse motion, heading wraparound, tight
steering, invalid inputs, corrupted output, and infeasibility. All passed locally
with ROS 2 Jazzy and CasADi 3.8.2; the Docker environment uses ROS 2 Humble.

## Limitations

No obstacle avoidance, tracking controller, or animated playback is implemented.
The horizon heuristic and local solver can fail on feasible requests. Objective
weights are hardcoded, the solver is rebuilt per request, and Docker builds
CasADi from its moving `main` branch. Solver reuse, dependency pinning, benchmarks,
and plots remain planned improvements.
