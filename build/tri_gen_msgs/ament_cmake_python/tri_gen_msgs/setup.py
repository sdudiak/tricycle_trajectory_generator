from setuptools import find_packages
from setuptools import setup

setup(
    name='tri_gen_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('tri_gen_msgs', 'tri_gen_msgs.*')),
)
