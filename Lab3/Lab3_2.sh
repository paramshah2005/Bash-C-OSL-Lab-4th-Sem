#!/bin/sh

echo "Enter folder to search:"
read folder

echo "Enter pattern to search:"
read pattern

grep -l "$pattern" "$folder"/*

