# tricycle_trajectory_generator

## Description

This repository contains the code for evaluating the trajectory generation for a tricycle vehicle. It contains the following packages:
- `tri_gen_msgs` - containing necessary ROS2 interfaces
- `tri_gen_trajectory_requester` - containing a simple node used for requesting a trajectory
- `tri_gen_trajectory_generator` - containing a node responsible for trajectory generation based on solving an NLP problem

## Usage
After downloading this repository, build and run the docker container:
``` bash
cd tricycle_trajectory_generator/docker
docker compose build
docker compose up
```
You should see a running rviz window. To select trajectory parameters use the `trajectory_request.yaml` file. When the parameters are selected, in a separate terminal run:

```
docker exec -t tricycle_trajectory_generator /request_trajectory.sh
```

In rviz:

- **Red** arrow is the goal state
- **Yellow** arrow is the start state
- **Green** represent the vechicle's position and orientation
- **Blue** arrow represents the wheel's orientation