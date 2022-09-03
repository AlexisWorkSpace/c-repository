
#include <stdio.h>

int main() {

	int i, numero_natural, entrada_numero, numero_negativo = 0, numero_positivo, zeros = 0;
	float acumulacion_negativos = 0, acumulacion_positivos = 0, promedio_neg, promedio_pos;

	if(numero_natural < 12 && numero_natural > 0) {
		for(i = 0; i < numero_natural) {
			printf("ingrese un numero-> "); scanf("%d", %entrada_num);
			if(entrada < 0) {
				numero_negativo++;
				acumulacion_negativos += entrada_num;
			} else if(entrada > 0) {
				numero_positivo++;
				acumulacion_positivos += entrada_num;			
			} else if(entrada_num == 0) {
				zeros++;
			}
		}
	} else prnitf("numero invalido");

	promedio_neg = acumulacion_negativos / numero_negativo;
        promedio_pos = acumulacion_positivos / numero_positivo;
        printf("promedio pos; %f\n", promedio_pos);
	printf("promedio neg: %f\n", promedio_neg);
	printf("ceros %d\n", zeros);
	
	return 0;
