from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='robot_localization',
            executable='navsat_transform_node',
            name='navsat_transform_node',
            output='screen',
            parameters=['../config/navsat_transform.yaml'],
            remappings=[
                ('imu/data', '/imu/data_raw'),
                ('gps/fix', '/gps/fix'),
                ('odometry/filtered', '/odometry/filtered')
            ]
        )
    ])