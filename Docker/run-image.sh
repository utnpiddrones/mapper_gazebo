#The argument must be the path to the repository
cd --
findPath=$(find "$(pwd)" -name run-image.sh -printf '%h\n' | grep 'mapper_gazebo' | grep -v 'Trash')
repoPath=${1:-$findPath/..}
docker run -it --rm -e DISPLAY=$DISPLAY -v "/tmp/.X11-unix:/tmp/.X11-unix:rw"  \
-v "$repoPath:/home/user/catkin_ws/src/" \
utn/mapper-img /bin/bash

