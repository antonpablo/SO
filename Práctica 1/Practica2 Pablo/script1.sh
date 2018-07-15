#!/bin/bash


NUM1="1"
NUM2=2
echo "(1) Prog1 (2) Prog2"
read n
if [ $n = $NUM1 ]; then 
./prog1
elif [ $n -eq $NUM2 ]; then
./prog2
else
echo "error en el numero"
fi


