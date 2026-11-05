#!/bin/bash

set -e
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
source /opt/ros/humble/setup.bash
source /ros_ws/install/setup.bash

exec ros2 launch tri_gen_trajectry_generator trajectory_generator.launch.py
