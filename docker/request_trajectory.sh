#!/bin/bash
source /ros_ws/install/setup.bash

ros2 run tri_gen_trajectory_requester trajectory_requester --ros-args --params-file /trajectory_request.yaml

