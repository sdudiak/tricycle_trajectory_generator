FROM ros:humble
ARG USERNAME=USERNAME
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Delete user if it exists in container (e.g Ubuntu Noble: ubuntu)
RUN if id -u $USER_UID ; then userdel `id -un $USER_UID` ; fi

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME
    
# RUN apt-get update && apt-get upgrade -y

RUN apt update && apt install -y \
    python3-pip

RUN pip3 install casadi

RUN  sudo apt install -y gfortran liblapack-dev pkg-config --install-recommends \
 && sudo apt install -y swig coinor-libipopt-dev \
 && cd \ 
 && git clone https://github.com/casadi/casadi.git -b main casadi \
 && cd casadi \
 && mkdir build \
 && cd build \
 && cmake -DWITH_PYTHON=ON -DWITH_IPOPT=ON -DWITH_OPENMP=ON -DWITH_THREAD=ON .. \
 && make \
 && sudo make install
 
ENV SHELL /bin/bash


USER $USERNAME
CMD ["/bin/bash"]