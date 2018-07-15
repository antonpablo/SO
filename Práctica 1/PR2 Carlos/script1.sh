#!/bin/bash
echo "(1) Prog1 (2) Prog2 (3) Ambos"
read n
if [ $n = "1" ]; 
then 
./Prog1
elif [ $n = "2" ] 
then
./Prog2
elif [ $n = "3" ]
then
./Prog1
./Prog2
else
echo"error en el numero"
fi

