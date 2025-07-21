from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gps_navigator_pkg',
            executable='read_nav_external',
            name='serial_bridge',
            output='screen'
        ),
        Node(
            package='gps_navigator_pkg',
            executable='gps_to_utm_node',
            name='gps_to_utm_node',
            output='screen'
        )
    ])
