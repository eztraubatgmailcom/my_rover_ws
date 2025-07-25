from setuptools import setup

package_name = 'odometry_patcher_pkg'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
         ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='you',
    maintainer_email='you@example.com',
    description='Injects covariance into wheel odometry',
    license='MIT',
    entry_points={
        'console_scripts': [
            'odometry_covariance_patcher = odometry_patcher_pkg.odometry_covariance_patcher:main'
        ],
    },
)
