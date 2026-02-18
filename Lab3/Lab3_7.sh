#!/bin/bash

echo "Enter File Name"
read file

sed '2~2d' -i "$file".txt

