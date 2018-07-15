#include <stdio.h>
#include <stdlib.h>

/*
Autores:
	Alejandro López Alburquerque
	Esteban Lozano Milla
Equipo:
	Habrá que Aprobarla(TM)
*/

main(int argc, char *argv[]) {

	if(argc != 2) {
		printf("El numero de parametros introducidos es incorrecto\n");
		printf("%d", argc);
		exit(1);
	}

	//Declaración de variables.
	FILE *archivoEnt, *archivoInfo, *archivoCopia;
	char c;
	char nombreArchivo[40];
	int nBytes;
	int nArchivos = atoi(argv[1]); //Convierte una cadena en entero.
	int i;

	//Apertura de los ficheros de salida.	
	archivoInfo=fopen("info.txt","w");
	archivoCopia=fopen("copia.txt","w");

	//Bucle para todos los archivos de entrada.	
	for(i = 0; i < nArchivos ; i++)	{
		//Nombre del archivo de entrada
		printf("Introduce el nombre del archivo:\n");
		scanf("%s",nombreArchivo);
	
		//Apertura del archivo de entrada para lectura.
		archivoEnt=fopen(nombreArchivo,"r");
		
		//Comprueba si los archivos de entrada y salida 
		//se han abierto correctamente.
		if ((archivoEnt==NULL)||(archivoInfo==NULL)||(archivoCopia==NULL))
			printf("Error al abrir ficheros.\n");
		else {
			/*----Parte Prog2----*/			
			//Copia el contenido del archivo de entrada 
			//en el archivo de salida
			while((c=getc(archivoEnt))!=EOF) {
				putc(c,archivoCopia);  
			}
			
			/*----Parte Prog1----*/
			//Tamaño en bytes.
			nBytes = ftell(archivoEnt);

			//Guarda el nombre del archivo y su tamaño.
			fprintf(archivoInfo,"%s\n",nombreArchivo);
			fprintf(archivoInfo,"%d\n",nBytes);
		
			//Cierra el archivo de entrada.
			if (fclose(archivoEnt)!=0)
				printf("Error al cerrar fichero %s.\n",nombreArchivo);
		}
	}
	
	//Cierra los archivos de salida.
	if (fclose(archivoInfo)!=0)
				printf("Error al cerrar fichero info.\n");
	if (fclose(archivoCopia)!=0)
				printf("Error al cerrar fichero copia.\n");

	exit(0);
}
