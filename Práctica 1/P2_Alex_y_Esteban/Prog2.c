#include <stdio.h>
#include <stdlib.h>

/*
Autores:
	Alejandro López Alburquerque
	Esteban Lozano Milla
Equipo:
	Habrá que Aprobarla(TM)
*/

main() {
	//Declaración de variables.
	FILE *archivoEnt, *archivoSal;
	char c;
	char nombreArchivo[40];
	int nArchivos;
	int i;
	
	//Apertura del fichero de salida.
	archivoSal=fopen("copia.txt","w");
	
	//nº de archivos de entrada.
	printf("Introduce el numero de archivos:\n");
	scanf("%d",&nArchivos);
	
	//Bucle para todos los archivos de entrada.
	for(i = 0; i < nArchivos ; i++) {
		//Nombre del archivo de entrada
		printf("Introduce el nombre del archivo:\n");
		scanf("%s",nombreArchivo);
	
		//Apertura del archivo de entrada para lectura
		archivoEnt=fopen(nombreArchivo,"r");
		
		//Comprueba si los archivos de entrada y salida 
		//se han abierto correctamente.
		if ((archivoEnt==NULL)||(archivoSal==NULL))
			printf("Error al abrir el fichero.\n");
		else {
			//Copia el contenido del archivo de entrada 
			//en el archivo de salida
			while((c=getc(archivoEnt))!=EOF) {
				putc(c,archivoSal);  
			}		
				
			//Cierra el archivo de entrada.
			if (fclose(archivoEnt)!=0)
				printf("Error al cerrar fichero %s.\n",nombreArchivo);
		}
	}
	
	//Cierra el archivo de salida.
	if (fclose(archivoSal)!=0)
				printf("Error al cerrar fichero info.\n");

	exit(0);
}
