#Autores: Carlos Jimenez Alvarez y Diego Laguna Martin
#Grupo: Habra que aprobarla
#!/bin/bash
if [ $2 = "1" ]
then 
./Prog1e $1
rm info.txt
elif [ $2 = "2" ] 
then
./Prog1e $1
mkdir SALIDA
cp info.txt SALIDA/copiainfo.txt
cp copia.txt SALIDA/copiacopia.txt
elif [ $2 = "0" ]
then
./Prog1e $1
else
echo"Ese modo no existe"
fi

