#!/bin/bash

FILE='FindBST'

g++ -o $FILE -I./include/ -O2 -g -Wall -fmessage-length=0 -std=c++11 -fno-omit-frame-pointer -fsanitize=address ${FILE}.cpp

./${FILE}

rm -f ${FILE}