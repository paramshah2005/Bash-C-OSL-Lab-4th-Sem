#!/bin/bash
echo "Enter Basics"
read basics

echo "Enter TA"
read ta

result=$(echo "$basics * 1.1 + $ta" | bc -l)
echo $result

