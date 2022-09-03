#!/bin/sh

filename="$1"
time=""
msg=""

while [ -z "$time" ] ; do
	read -p "Time: " time_input
	time="$(date -d "$time_input" "+%s")"
done
read -p "Message: " msg

printf "$time\t$msg\n" >> $filename
