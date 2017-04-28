#!/bin/bash -x
count=0
cat misc/confname.h | while read line
do
echo "#ifdef $line"
IFS='='
set -- $line
echo "DEF_SYSCONF_CONST($1)"
echo "#endif"
done
