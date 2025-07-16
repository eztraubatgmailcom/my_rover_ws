from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='joy',
            executable='joy_node',
            name='joy_node',
            output='screen'
        ),
        Node(
            package='joy_twist_bridge',
            executable='joy_to_twist',
            name='joy_to_twist_node',
            output='screen'
        ),
        # Optional: start Miti driver
        # Node(
        #     package='roverrobotics_driver',
        #     executable='miti.launch.py',
        #     output='screen'
        # )
    ])
