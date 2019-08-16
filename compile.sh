#!/bin/bash - 
set -o nounset                              # Treat unset variables as an error
gcc -fno-elide-constructors -std=c++11 -Wno-unused -lstdc++ "$@"
