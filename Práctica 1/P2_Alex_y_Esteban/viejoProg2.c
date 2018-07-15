#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define n 80

bool impar(int a){
	return a%2 != 0;
}

void copiaFichero(char *nombreArchivo){
	FILE *archivo1,*archivo2;
	
	archivo1=fopen(nombreArchivo,"r");
	archivo2=fopen("copia.txt","a");
	char c;
	
	if ((archivo1==NULL)||(archivo2==NULL))
		printf("Error al abrir ficheros");
	else
	{
		while((c=getc(archivo1))!=EOF)
		{
			putc(c,archivo2);  
		}
	}
	
	//Cierra el archivo1.
	if (fclose(archivo1)!=0)
		printf("Error al cerrar fichero info.\n");
	if (fclose(archivo2)!=0)
		printf("Error al cerrar fichero info.\n");
}

main()
{
	//Declaración de variables.
	FILE *archivo1;
	int cont = 0;
	char nombreArchivo[n];
	
	//Habre fichero en modo lectura.
	archivo1=fopen("info.txt","r");
	
	while (fgets(nombreArchivo, n, archivo1) != NULL)
	{
		if(!impar(cont))
		{
			copiaFichero(nombreArchivo);
		}
		cont++;
	}
	
	
	//Cierra el archivo1.
	if (fclose(archivo1)!=0)
		printf("Error al cerrar fichero info.\n");

	exit(0);
}
