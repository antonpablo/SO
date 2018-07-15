#!/bin/bash

if [[ -d carpetaExterna]]; then
	rm -rf ./copiasTemporales;
fi

mkdir carpetaExterna;

echo ">>> Creando archivos p4.txt y nada.txt";
touch ./mount-point/p4.txt;
touch ./mount-point/nada.txt;
echo Comprobando funcionalidad del sistema de archivos >> p4.txt;
ls ./mount-point/;
cp ./mount-point/p4.txt ./carpetaExterna/;
diff ./carpetaExterna/p4.txt ./mount-point/p4.txt > ./mount-point/nada.txt;

