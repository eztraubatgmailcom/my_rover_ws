from setuptools import setup

package_name = 'joy_twist_bridge_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/joy.launch.py']),
    ],
    
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='rover',
    maintainer_email='rover@todo.todo',
    description='Translates PS4 controller input to /cmd_vel Twist messages using ps_ros2_common.',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'joy_to_twist = joy_twist_bridge_pkg.joy_to_twist:main',
        ],
    },
)
