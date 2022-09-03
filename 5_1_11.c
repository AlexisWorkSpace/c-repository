#include <stdio.h>

int main() {

	int i, contador_negativos = 0, contador_positivos = 0; //variables usadas por el programa
	float temperatura_uno, temperatura_dos, temperatura_tres; //variables ingresadas por teclado

	printf("ingrese el valor de las ternas con el siguiente formato-> (t1, t2, t3) con un espacio entre temperaturas en lugar de una coma\n");

	for(i = 0; i < 18; i++) {
	
		printf("ingrese la primer terna-> "); scanf("%f %f %f", &temperatura_uno, &temperatura_dos, &temperatura_tres);
		temperatura_uno >= 0 && temperatura_dos >= 0 && temperatura_tres >= 0 ? contador_positivos++ : contador_negativos++;
	
	}

	printf("[+] la cantidad de ternas positivas es->\t%d\n", contador_positivos);
	printf("[+] la cantidad de ternas negativas es->\t%d\n", contador_negativos);

	return 0;
}
