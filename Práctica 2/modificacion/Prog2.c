#include <stdio.h>
#include <stdlib.h>

//Autores: Pablo Antón Estrella y Javie Alonso Garralón
//Equipo: Habrá que aprobarla	

int main(int argc, char *argv[] )
	{

	FILE *archivo1,*final, *final2; //archivo 1 de lectura, archivo 2 donde se va a copiar el archivo

	char c; //caracter
	int num;

	num = 	atoi(argv[1]);	

	int cont=0;
	int i=0;
	char *res;
	final=fopen("copia.txt","w"); //abrir el archivo copia en modo escritura
	final2=fopen("info.txt","w"); //abrir el archivo info en modo escritura
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
			
			while((c=getc(archivo1))!=EOF){
				cont=cont+1;		
				putc(c,final);
			}
			fprintf(final2," %s \n %d \n",res,cont); //se escribe info.txt

			if (fclose(archivo1)!=0) //error al cerra el fichero 1
				printf("Error al cerrar fichero prueba");	
			}
		free(res);
	}
		

	if (fclose(final)!=0) ////error al cerra el fichero 1
		printf("Error al cerrar fichero copia");
	if (fclose(final2)!=0) ////error al cerra el fichero 2
		printf("Error al cerrar fichero info");

	exit(0);

}
