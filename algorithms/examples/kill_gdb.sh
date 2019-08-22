#===============================================================================
#          FILE: kill_gdb.sh
#         USAGE: ./kill_gdb.sh 
#===============================================================================

set -o nounset                              # Treat unset variables as an error

ps -ef | grep -v -E "grep|($$)|/bin/bash|sudo|macvim" | grep 'gdb' | awk '{print $2}'

