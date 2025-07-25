from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='keyboard_controller_pkg',
            executable='keyboard_teleop',
            name='keyboard_controller',
            output='screen'
        )
    ])
