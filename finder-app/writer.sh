#!/bin/bash

if [ $# -ne 2 ]; then
    echo "one of two arguments was not provided"
    exit 1
fi

writefile=$1
writestr=$2

dir=$(dirname "$writefile")
if [ ! -d "$dir" ]; then
    mkdir -p "$dir" || {
        echo "Could not create file $writefile"
        exit 1
    }
fi 

echo "$writestr" > "$writefile" || {
    echo "Could not create file $writefile"
    exit 1
}

