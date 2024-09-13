#!/bin/bash

# Recursively lists all files/directories created using script1
ls -R 

# Code to recursively delete files/directories made in script1 is appened to a new script3
echo "rm -r link1  dir1 dir2 file1" > script3.sh

# Executes the script3 script
bash script3.sh

# Recursively lists all files/directories after script3 runs
ls -R


