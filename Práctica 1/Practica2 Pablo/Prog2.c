#include <stdio.h>
#include <stdlib.h>
	

main()
	{

		FILE *archivo1,*final; //archivo 1 de lectura que será el copiado, final que será donde estén las copias

		char c; //caracter
		int num;
		scanf("%d",&num); //pedir por teclado el nombre del archivo de copia
		int cont=0;
		int i=0;
		char *res;
		final=fopen("copia.txt","w"); //abrir el fichero copia en modo escritura
		while(i<num)
		{
			cont=0;	
			i=i+1;	
			scanf("%ms",&res); 
			
			archivo1=fopen(res,"r");  //abrir el archivo copiado en modo lectura

			if ((archivo1==NULL)) //si unos de los archivos es igual a null salta error

				printf("Error al abrir ficheros");

			else

			{
			
				while((c=getc(archivo1))!=EOF) //mientras el archivo tenga caracteres 
					putc(c,final);

			if (fclose(archivo1)!=0) //error al cerra el fichero copiado
				printf("Error al cerrar fichero copia");	
			}
			
		
		}
		

		if (fclose(final)!=0) ////error al cerrar el fichero copia
				printf("Error al cerrar fichero copia");

		exit(0);

}
