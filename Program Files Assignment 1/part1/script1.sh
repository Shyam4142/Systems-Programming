#!/bin/bash

# Directory dir1 contains file10
mkdir dir1
touch dir1/file10

# Directory dir2 contins file20
mkdir dir2
touch dir2/file20

# Current directory contains file1
touch file1

# Current directory contains a symbolic link, link1, that links to file20 of dir2
ln -s dir2/file20 link1


