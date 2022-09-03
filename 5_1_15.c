#include<stdio.h>

#define PARTICIPANTES 5
#define TIROS 3

int main() {
	int coordenadas_x, coordenadas_y; //variables destinadas al ingreso por teclado
	int i, j, tiros_centro, cuadrante_uno, cuadrante_dos, cuadrante_tres, cuadrante_cuatro; //variables que utilizara el programa

	printf("las coordenadas se deben ingresar con el siguiente formato (x;y)\n");

	for(i = 1; i <= PARTICIPANTES; j++) {
		cuadrante_uno = 0;
		cuadrante_dos = 0;
		cuadrante_tres = 0;
		cuadrante_cuatro = 0;
		tiros_centro = 0;

		for(j = 0; j < TIROS; j++) {
			printf("ingrese las coordenadas del disparo-> "); scanf("%d %d", &coordenadas_x, &coordenadas_y);

			if(coordenadas_x == 0 && coordenadas_y == 0) tiros_centro++;
			else if(coordenadas_x > 0 && coordenadas_y > 0) cuadrante_uno++;
			else if(coordenadas_x < 0 && coordenadas_y > 0) cuadrante_dos++;
			else if(coordenadas_x < 0 && coordenadas_y < 0) cuadrante_tres++;
                        else if(coordenadas_x > 0 && coordenadas_y < 0) cuadrante_cuatro++;
			else if(coordenadas_x == 0 || coordenadas_y == 0) printf("[-] tiro invalido - no suma puntos\n");

		}
		printf("[+] los datos del jugador son: \n");
		printf("primer cuadrante\t%d\nsegundo cuadrante\t%d\ntercer cuadrante\t%d\ncuarto cuadrante\t%d\n", 
				cuadrante_uno, 
				cuadrante_dos, 
				cuadrante_tres, 
				cuadrante_cuatro
				);
		printf("eje de coordenadas\t%d\n", tiros_centro);
	
	}
	return 0;
}
