#!/bin/bash - 

set -o nounset 

if [  "$#" != "1" ]; then
    echo kill \'what\' is required, \'bitcoin\', \'bitcoin-sv\' ......
    exit
fi

killwho=$1

if [ "x$killwho" == "x" ]; then
    echo kill \'what\' is required, \'bitcoin\', \'bitcoin-sv\' ......
    exit
fi

source ./get_processid.sh $killwho sudo

if [ "$processid" == "" ]; then
    echo didn\'t found any \'$killwho\'
    exit
fi

echo "ko2005" | sudo -S kill -9 $processid
echo process $killwho:$processid is successly killed.

