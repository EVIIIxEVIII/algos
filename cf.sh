#!/bin/bash
# Usage: ./cf.sh 1056c

if [ -z "$1" ]; then
    echo "Usage: $0 <contest+letter> (e.g. 1056c)"
    exit 1
fi

name="$1"
src="cf_${name}.cpp"
out="${name}"

if [ ! -f "$src" ]; then
    echo "Source file $src not found."
    exit 1
fi

g++ -std=c++20 -O2 -Wall -Wextra -fsanitize=undefined -g "$src" -o "$out"
if [ $? -eq 0 ]; then
    echo "Compiled successfully: ./$out"
else
    echo "Compilation failed."
fi

