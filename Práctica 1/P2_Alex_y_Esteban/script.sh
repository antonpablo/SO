#!/bin/bash
#Autores: 
#	Alejandro López Alburquerque
#	Esteban Lozano Milla
#Equipo: 
#	Habrá que Aprobarla(TM)

if [ $2 = "0" ]; then
	./Prog $1
elif [ $2 = "1" ]; then
	./Prog $1
	rm info.txt
elif [ $2 = "2" ]; then
	./Prog $1
	if [ -d SALIDA ]; then
		rm -r SALIDA
	fi
	mkdir SALIDA
	cp info.txt SALIDA
	cp copia.txt SALIDA
else
    echo "Ese modo no existe."
fi
