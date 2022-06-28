FROM ubuntu:20.04

ARG UID
ARG GID
ENV TZ=America/Argentina/Buenos_Aires

RUN apt-get update && apt-get upgrade -y
RUN DEBIAN_FRONTEND=noninteractive apt-get -y install software-properties-common python g++ build-essential

RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
RUN apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y ros-noetic-desktop-full

RUN apt install -y python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool python3-pip ros-noetic-rtabmap-ros
RUN rosdep init

RUN groupadd --gid $GID user
RUN adduser --disabled-password --gecos '' --uid $UID --gid $GID user
USER user

WORKDIR /home/user

RUN echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc

RUN rosdep update
RUN mkdir catkin_ws
CMD /bin/bash
