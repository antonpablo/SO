#include <stdio.h>
#include <stdlib.h>
	

main()
	{

		FILE *archivo1,*final; //archivo 1 de lectura, archivo 2 donde se va a copiar el archivo

		char c; //caracter
		int num;
		printf("dame un numero de archivos \n");
		scanf("%d",&num); //pedir por teclado el nombre del archivo de lectura
		int cont=0;
		int i=0;
		char *res;
		final=fopen("copia.txt","w"); //abrir el archivo 2 en modo escritura
		while(i<num)
		{
			cont=0;	
			i=i+1;	
			printf("nombre del archivo \n");
			scanf("%ms",&res); 
			
			archivo1=fopen(res,"r");  //abrir el archivo 1 en modo lectura

			if ((archivo1==NULL)) //si unos de los archivos es igual a null salta error

				printf("Error al abrir ficheros");

			else

			{
			
				while((c=getc(archivo1))!=EOF) //mientras el archivo tenga caracccccccccccteres 
					putc(c,final);

			if (fclose(archivo1)!=0) //error al cerra el fichero 1
				printf("Error al cerrar fichero prueba");	
			}
			
		
		}
		

		if (fclose(final)!=0) ////error al cerra el fichero 1
				printf("Error al cerrar fichero copia");

		exit(0);

}
