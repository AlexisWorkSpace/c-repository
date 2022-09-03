/*
	5.1.5 Confeccionar un programa para calcular la suma de los primeros N números naturales. El valor de N lo
	solicita por teclado el programa.
*/

#include <stdio.h>

int main() {

	int numeros_naturales; // declaracion de variables ingresadas por el usuario
	int i, suma = 0; // declaracion variables utilizadas por el programa

	printf("ingrese la cantidad de numeros naturales deseados-> "); scanf("%d", &numeros_naturales);

	for(i = 1; i <= numeros_naturales; i++) suma += i;

	printf("[+]la suma es-> %d\n", suma);
	return 0;

}
