FROM ros:humble

ARG USERNAME=USERNAME
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN if id -u $USER_UID >/dev/null 2>&1; then userdel -f $(id -un $USER_UID); fi

# Create user and setup sudo
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y sudo \
    && echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# Install dependencies
RUN apt update && apt install -y \
    python3-pip \
    gfortran liblapack-dev pkg-config \
    swig coinor-libipopt-dev \
    git \
    ros-humble-desktop \
    build-essential \
    cmake \
    python3-colcon-common-extensions \
    python3-rosdep \
    python3-vcstool \
    curl

RUN pip3 install casadi

RUN cd / \
    && git clone https://github.com/casadi/casadi.git -b main casadi \
    && cd casadi \
    && mkdir build \
    && cd build \
    && cmake -DWITH_PYTHON=ON -DWITH_IPOPT=ON -DWITH_OPENMP=ON -DWITH_THREAD=ON .. \
    && make \
    && make install

# Set up ROS workspace
RUN mkdir -p /ros_ws/src

# Copy tri_gen contents
COPY tri_gen/src /ros_ws/src

# Source ROS setup and build
RUN . /opt/ros/humble/setup.sh && \
    cd /ros_ws && \
    colcon build

# Environment setup
ENV SHELL=/bin/bash
ENV ROS_DISTRO=humble
ENV ROS_LOCALHOST_ONLY=1
ENV ROS_DOMAIN_ID=42

# Source ROS and workspace by default
RUN echo "source /opt/ros/humble/setup.bash" >> /home/$USERNAME/.bashrc && \
    echo "source /ros_ws/install/setup.bash" >> /home/$USERNAME/.bashrc

COPY docker/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

COPY docker/request_trajectory.sh /request_trajectory.sh
RUN chmod +x /request_trajectory.sh

# Set user
USER $USERNAME

WORKDIR /ros_ws