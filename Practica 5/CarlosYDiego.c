#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>

// Autores: Carlos Jiménez Álvarez y Diego Laguna Martín

int generarAleatorio();
void iluminacion(int leds, int velocidad);

int main (){
	int leds, velocidad=3000000;
	srand(time(NULL));
	printf("Autores: Carlos Jiménez Álvarez y Diego Laguna Martín\n");
	leds = open("/dev/leds", O_WRONLY | O_CREAT | O_TRUNC);
	iluminacion(leds, velocidad);
	close(leds);
	return 0;
}

int generarAleatorio(){
	int num;
	num = rand() % 1001;
	return num;
}

void iluminacion (int leds, int velocidad){
	int divisor, num;
	char buffer[4];
	printf("Escriba el numero que quiere que sea divisor\n");
	scanf("%d", &divisor);
	int i = 0;
	for(i; i < 8; i++){
		num = generarAleatorio();
		printf("El numero es %d. Primer led = Par. Segundo led = Impar. Tercer led = Múltiplo de %d\n", num, divisor);
		buffer[0] = ' ';
		buffer[1] = ' ';
		buffer[2] = ' ';
		if (num % 2 == 0){
			buffer[0] = '1';
		}
		else{
			buffer[1] = '2';
		}
		if (num % divisor == 0){
			buffer[2] = '3';
		}
		write(leds, buffer, 4);
		usleep(velocidad);
	}
}
	
