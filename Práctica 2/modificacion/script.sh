#!/bin/bash

#Autores: Pablo Anton Estrella y Javie Alonso Garralón
#Equipo: Habrá que aprobarla

#$1 numero archivos para leer #2 modo funcionamiento




case $2 in
  "0")
	./prog2 $1
	echo "hecho modo 0"
     ;;
  "1")
	./prog2 $1
     	rm "info.txt"
	echo "hecho modo 1"
     ;;
  "2")
	./prog2 $1
     	mkdir "SALIDA"
	cp "info.txt" "SALIDA/info.txt"
	cp "copia.txt" "SALIDA/copia.txt"
	echo "hecho modo 2"
     ;;
*)
     echo "Ese modo no existe"
     ;;
esac




