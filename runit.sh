#!/bin/bash

# shortcut to compile and run the program

rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare *.cpp
./a.out input1.txt svg1.svg

# on Mac, use "open htmlfile"
# on Windows, use "start htmlfile"

