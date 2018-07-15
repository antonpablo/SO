#include <stdio.h>
#include <stdlib.h>
	

main()
	{

		FILE *archivo,*final; //archivo de lectura, final donde se va a escribir el contenido de todos los archivos

		char c; //caracter
		int num;
		printf("Escribe el número de archivos cuyo contenido quiere copiar:\n");
		scanf("%d",&num); //pedir por teclado el número de archivos a abrir
		int cont=0;
		int i=0;
		char *res;
		final=fopen("copia.txt","w"); //abrir final en modo escritura
		while(i<num)
		{
			cont=0;	
			i=i+1;	
			printf("Escribe el nombre del archivo:\n");
			scanf("%ms",&res);
			
			archivo=fopen(res,"r");  //abrir archivo en modo lectura

			if ((archivo==NULL)) //si archivos es igual a null salta error

				printf("Error al abrir ficheros\n");

			else

			{
			
				while((c=getc(archivo))!=EOF) //mientras el archivo tenga caracteres 
					putc(c,final); //escribe su contenido en final
					fprintf(final, "\n");

			if (fclose(archivo)!=0) //error al cerrar archivo
				printf("Error al cerrar el archivo\n");	
			}
			
		
		}
		

		if (fclose(final)!=0) //error al cerrar final
				printf("Error al cerrar fichero copia\n");

		exit(0);

}
