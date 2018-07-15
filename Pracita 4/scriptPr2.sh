#!/bin/bash

chmod +x ./my-fsck
./my-fsck virtual-disk

echo "Borramos el fichero1.txt y auditamos"
read p

rm mount-point/fichero1.txt 
./my-fsck virtual-disk

echo "Borramos el fichero2.txt y auditamos"
read p

rm mount-point/fichero2.txt 
./my-fsck virtual-disk


echo "Pulsa enter para continuar. Apartado a)"
read p

echo "Copiando fuseLib.c y myFS.h a nuestro SF..."
cp src/fuseLib.c mount-point/
cp src/myFS.h mount-point

echo "Creando directorio temporal(copiasTemporales)..."
rm -R -f copiasTemporales
mkdir copiasTemporales

echo "Copiando fuseLib.c y myFS.h al directorio temporal..."
cp src/fuseLib.c copiasTemporales
cp src/myFS.h copiasTemporales/

echo "Pulsa enter para continuar. Apartado b)"
read p

./my-fsck virtual-disk

diff src/fuseLib.c mount-point/fuseLib.c
if [ $? -eq 0 ] ; then
	echo "IGUALES"
else	
	echo "NO IGUALES"
fi

diff src/myFS.h mount-point/myFS.h
if [ $? -eq 0 ] ; then
	echo "IGUALES"
else	
	echo "NO IGUALES"
fi

diff src/fuseLib.c copiasTemporales/fuseLib.c
if [ $? -eq 0 ] ; then
	echo "IGUALES"
else	
	echo "NO IGUALES"
fi


diff src/myFS.h copiasTemporales/myFS.h
if [ $? -eq 0 ] ; then
	echo "IGUALES"
else	
	echo "NO IGUALES"
fi


echo "Pulsa enter para continuar. Apartado c)"
read p

truncate -s 16384 copiasTemporales/fuseLib.c
truncate -s 16384 mount-point/fuseLib.c

echo "Pulsa enter para continuar. Apartado d)"
read p

./my-fsck virtual-disk

diff src/fuseLib.c mount-point/fuseLib.c > d1.txt
if [ $? -eq 0 ] ; then
	echo "IGUALES"
else	
	echo "NO IGUALES"
fi

diff src/fuseLib.c copiasTemporales/fuseLib.c > d2.txt
if [ $? -eq 0 ] ; then
	echo "IGUALES"
else	
	echo "NO IGUALES"
fi


echo "Pulsa enter para continuar. Apartado e)"
read p

echo "CarlosSalvadorAmoresMartinez_23 ----- AndresFelipeAguilarOchoa_69" > cf.txt
echo "Copiando cf.txt nuestro SF..."
cp cf.txt mount-point/

echo "Pulsa enter para continuar. Apartado f)"
read p

./my-fsck virtual-disk

diff cf.txt mount-point/cf.txt
if [ $? -eq 0 ] ; then
	echo "IGUALES"
else	
	echo "NO IGUALES"
fi

echo "Pulsa enter para continuar. Apartado g)"
read p

truncate -s 4097 copiasTemporales/myFS.h
truncate -s 4097 mount-point/myFS.h

echo "Pulsa enter para continuar. Apartado h)"
read p

./my-fsck virtual-disk

diff src/myFS.h mount-point/myFS.h > h1.txt
if [ $? -eq 0 ] ; then
	echo "IGUALES"
else	
	echo "NO IGUALES"
fi

diff src/myFS.h copiasTemporales/myFS.h > h2.txt
if [ $? -eq 0 ] ; then
	echo "IGUALES"
else	
	echo "NO IGUALES"
fi

echo "HEMOS TERMINADO. PULSA ENTER"
read p








