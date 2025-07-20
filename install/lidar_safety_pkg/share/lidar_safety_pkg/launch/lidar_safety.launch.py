from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='lidar_safety_pkg',
            executable='obstacle_detector_node',
            name='obstacle_detector_node',
            output='screen',
            parameters=[{'stop_distance': 0.5}]
        )
    ])
