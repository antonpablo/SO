#!/bin/bash
#Autores: 
#	Alejandro López Alburquerquer
#	Esteban Lozano Milla
#Equipo: 
#	Habrá que Aprobarla(TM)
echo "(1) Ejecutar Prog1"
echo "(2) Ejecutar Prog2"
echo "(3) Ejecutar ambos"
read valor

if [ $valor = "1" ]; then
    ./Prog1
elif [ $valor = "2" ]; then
    ./Prog2
elif [ $valor = "3" ]; then
    ./Prog1
    ./Prog2
fi
