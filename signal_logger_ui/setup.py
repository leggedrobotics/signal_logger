from setuptools import setup

try:
    from catkin_pkg.python_setup import generate_distutils_setup
except ImportError:
    setup()
else:
    setup_args = generate_distutils_setup(
        scripts=['bin/signal_logger_ui'],
        packages=['signal_logger_ui', 'signal_logger_ui.ui'],
        package_dir={'': 'src'},
    )
    setup(**setup_args)
