from setuptools import find_packages, setup

package_name = 'gps_navigator_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='rover',
    maintainer_email='rover@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'serial_simple = gps_navigator_pkg.serial_simple:main',
            'read_nav_external = gps_navigator_pkg.read_nav_external:main',
            'odom_echo = gps_navigator_pkg.odom_echo:main',
        ],
    },
)
