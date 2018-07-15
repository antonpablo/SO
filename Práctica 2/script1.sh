#!/bin/bash
NUM=1
NUM2=2
echo "(1) Prog1 (2) Prog2 (3) Prog1 y Prog2"
read n

if [ $n -eq "1" ]; then 
./Prog1
elif [ $n -eq "2" ]; then 
./Prog2
elif [ $n -eq "3" ]; then 
./Prog1
./Prog2
fi



