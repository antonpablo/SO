/*
Autores: Carlos Jimenez Alvarez y Diego Laguna Martin
Grupo: Habra que aprobarla
*/
#include <stdio.h>
#include <stdlib.h>
	

main(int argc, char *argv[])//argc: numero de parametros
//argv: array de parametros
	{

		FILE *archivo,*info,*copia; //archivo de lectura, final donde se va a escribir los nombres de los archivos y el número de bytes

		char c; //caracter
		int num=atoi(argv[1]);//Transforma un caracter numerico en un entero
		
		int cont=0;
		int i=0;
		char *res;
		info=fopen("info.txt","w"); //abrir final en modo escritura
		copia=fopen("copia.txt","w"); //abrir final en modo escritura
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
			
				while((c=getc(archivo))!=EOF){ //mientras el archivo tenga caracteres 
					cont=cont+1;//guarda el número de bytes
					putc(c,copia); //escribe su contenido en final 
				}


			fprintf(info," %s \n %d \n",res,cont);
			
			fprintf(copia, "\n");

			if (fclose(archivo)!=0) //error al cerrar archivo
				printf("Error al cerrar el archivo\n");	
			}
			
		
		}
		

		if (fclose(info)!=0 && fclose(copia)!=0) //error al cerrar el fichero info
				printf("Error al cerrar\n");

		free (res);		
		exit(0);

}
