from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.conditions import IfCondition

def generate_launch_description():
    #--------------------- Declare launch arguments
    lidar_arg = DeclareLaunchArgument('lidar', default_value='true')
    rviz_arg = DeclareLaunchArgument('rviz', default_value='true')

    return LaunchDescription([
        lidar_arg,
        rviz_arg,

        #------------------ Launch RPLIDAR node conditionally
        Node(
            package='rplidar_ros',
            executable='rplidar_node',
            name='rplidar_node',
            output='screen',
            parameters=[{
                'serial_port': '/dev/ttyUSB0',
                'serial_baudrate': 1000000,
                'frame_id': 'laser',
                'scan_mode': 'DenseBoost'
            }],
            condition=IfCondition(LaunchConfiguration('lidar'))
        ),

        #------------------ Launch RVIZ2 conditionally
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            arguments=[],
            condition=IfCondition(LaunchConfiguration('rviz'))
        ),
    ])