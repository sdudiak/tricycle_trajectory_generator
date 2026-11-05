from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import ExecuteProcess
import os

from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_name = 'tri_gen_trajectry_generator'
    pkg_share = get_package_share_directory(pkg_name)

    rviz_config_path = os.path.join(pkg_share, 'config', 'trajectory_visualizer_config.rviz')

    return LaunchDescription([
        Node(
            package=pkg_name,
            executable='trajectory_generator_node',
            name='trajectory_generator',
            output='screen'
        ),
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config_path],
            output='screen'
        )
    ])
