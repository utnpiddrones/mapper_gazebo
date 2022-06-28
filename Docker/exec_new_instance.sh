var=`docker ps --filter ancestor=utn/mapper-img | awk '{print $NF}' | awk 'FNR == 2 {print}'` 
docker exec -it -e DISPLAY=$DISPLAY $var /bin/bash

