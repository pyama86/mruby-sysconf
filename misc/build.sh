#!/bin/bash
count=0
cat confname.h | while read line
do
echo "#ifdef $line"
echo "{\"$line\", $count},"
echo "#endif"
count=`expr $count + 1`
done
