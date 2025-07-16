from launch import LaunchDescription
from launch.actions import ExecuteProcess

def generate_launch_description():
    return LaunchDescription([
        # Launch RPLIDAR S2 Node
        ExecuteProcess(
            cmd=[
                'ros2', 'launch', 'rplidar_ros', 'rplidar_s2_launch.py',
                'serial_port:=/dev/ttyUSB0',
                'serial_baudrate:=1000000'
            ],
            output='screen'
        ),
        # Launch RVIZ2 with your default config
        ExecuteProcess(
            cmd=[
                'rviz2'
            ],
            output='screen'
        )
    ])
