#!/bin/bash - 
set -o nounset                              # Treat unset variables as an error

if [  $# -lt 1 ]; then
    echo one argument\'process name\' is required
    exit
elif [ "x$1" == "x" ]; then
    echo process name is empty
    exit
fi

psname=$1
declude=grep\|$$\|/bin/bash

if [ $# -gt 1 ]; then
    declude=$declude\|$2
fi

function get_psid() {
    echo `ps -ef | grep -v -E "$declude" | grep $psname | awk '{print $2}'`
}

processid=$(get_psid)

