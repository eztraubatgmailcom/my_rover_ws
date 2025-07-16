from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='rplidar_ros',
            executable='rplidar_composition',
            name='vertical_rplidar',
            output='screen',
            parameters=[{
                'serial_port': '/dev/ttyUSB1',   
                'serial_baudrate': 460800,
                'frame_id': 'vertical_lidar',
            }],
            remappings=[
                ('scan', '/lidar_vertical/scan')  # Custom topic name
            ]
        )
    ])

      #          'scan_mode': 'Standard'