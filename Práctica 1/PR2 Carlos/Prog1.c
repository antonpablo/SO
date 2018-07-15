#include <stdio.h>
#include <stdlib.h>
	

main()
	{

		FILE *archivo,*final; //archivo de lectura, final donde se va a escribir los nombres de los archivos y el número de bytes

		char c; //caracter
		int num;
		printf("Escribe el número de archivos:\n");
		scanf("%d",&num); //pedir por teclado el nombre del archivo de lectura
		int cont=0;
		int i=0;
		char *res;
		final=fopen("info.txt","w"); //abrir final en modo escritura
		while(i<num)
		{
			cont=0;	
			i=i+1;	
			printf("Escribe el nombre del archivo: \n");
			scanf("%ms",&res); 
			
			archivo=fopen(res,"r");  //abrir archivo en modo lectura

			if ((archivo==NULL)) //si archivo es igual a null salta error

				printf("Error al abrir fichero\n");

			else

			{
			
				while((c=getc(archivo))!=EOF) //mientras el archivo tenga caracteres 
					cont=cont+1; //guarda el número de bytes

			fprintf(final," %s \n %d \n",res,cont);
			if (fclose(archivo)!=0) //error al cerrar archivo
				printf("Error al cerrar el archivo\n");	
			}
			
		
		}
		

		if (fclose(final)!=0) //error al cerrar el fichero info
				printf("Error al cerrar info.txt\n");

		exit(0);

}
