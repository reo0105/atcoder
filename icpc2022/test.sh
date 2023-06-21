#!/bin/bash

g++ $1.cpp
for i in `seq $2`
do
    ./a.out < ./judgedata/data/$1$i > $1$i.out
    diff $1$i.out ./judgedata/data/$1$i.ans 
    if [ $? -eq 0 ]; then
        echo "$1$i is ok"
    else 
        echo "$1$i is ng"
    fi
done