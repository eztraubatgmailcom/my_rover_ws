from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='joy_twist_bridge_pkg',
            executable='joy_to_twist',
            name='joy_to_twist',
            output='screen'
        )
    ])