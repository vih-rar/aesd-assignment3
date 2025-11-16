#!/bin/sh
# Finder script for assignment 1
# Author: Vihar Vasavada

# Accepts the following runtime arguments: the first argument is a path to a directory on the filesystem, referred to below as filesdir; the second argument is a text string which will be searched within these files, referred to below as searchstr

# Exits with return value 1 error and print statements if any of the parameters above were not specified

# Exits with return value 1 error and print statements if filesdir does not represent a directory on the filesystem

# Prints a message "The number of files are X and the number of matching lines are Y" where X is the number of files in the directory and all subdirectories and Y is the number of matching lines found in respective files, where a matching line refers to a line which contains searchstr (and may also contain additional content).

if [ $# -ne 2 ]
then
    echo "Usage: ./finder.sh <path_to_directory> <search_string>"
    exit 1
fi

PATH_TO_DIR=$1
SEARCH_STR=$2

cd $PATH_TO_DIR
if [ $? -ne 0 ]
then
    echo "Directory does not exist"
    exit 1
fi
PWD=$(pwd)
NUM_MATCHES=0
NUM_FILES=0
for file in $(find . -type f); do
    MATCHES=$(grep -c "$SEARCH_STR" "$file" 2>/dev/null || echo 0)
    if [ "$MATCHES" -gt 0 ]; then
        NUM_FILES=$((NUM_FILES + 1))
    fi
    NUM_MATCHES=$((NUM_MATCHES + MATCHES))
done

echo "The number of files are $NUM_FILES and the number of matching lines are $NUM_MATCHES"