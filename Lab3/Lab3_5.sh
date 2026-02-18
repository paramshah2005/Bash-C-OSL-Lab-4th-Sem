#!/bin/bash

echo "Enter file extension : " 
read ext
echo "Enter destination folder name: " 
read dest


mkdir -p "$dest"

for file in *"$ext"; do
    if [ -f "$file" ]; then
        cp "$file" "$dest"
    fi
done

echo "Files copied successfully."
