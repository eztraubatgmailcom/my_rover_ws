from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Static TF from base_link to gps_link (no offset)
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='gps_tf',
            arguments=['0', '0', '0', '0', '0', '0', 'base_link', 'gps_link'],
            output='screen'
        ),

        # EKF node
        Node(
            package='robot_localization',
            executable='ekf_node',
            name='ekf_filter_node',
            output='screen',
            parameters=[
                '/home/rover/my_rover_ws/src/my_rover_launch_pkg/config/ekf_gps.yaml'
            ],
            remappings=[
                ('/odometry/filtered', '/odometry/filtered'),
                ('/odometry0', '/odometry/wheels'),
                ('/odometry1', '/odometry/gps'),
                ('/imu0', '/imu/data_raw')
            ]
        )
    ])
