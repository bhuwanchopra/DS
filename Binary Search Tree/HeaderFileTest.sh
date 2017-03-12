#!/bin/bash

g++ -o HeaderFileTest -I./include/ -O2 -g -Wall -fmessage-length=0 -std=c++11 -fno-omit-frame-pointer -fsanitize=address HeaderFileTest.cpp

./HeaderFileTest

rm -f HeaderFileTest