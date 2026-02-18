#!/bin/sh

echo "Enter file or directory name:"
read name

if [ -d "$name" ]; then
    echo "$name is a directory"
elif [ -f "$name" ]; then
    echo "$name is a regular file"
else
    echo "$name does not exist"
fi
