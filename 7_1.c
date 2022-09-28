#include <stdio.h>

#define ARRAY_LENGHT 10

void invertir (float *);

int main() {

    float base_array[ARRAY_LENGHT], inverse_array[ARRAY_LENGHT];
    int i;

    for(i = 0; i < ARRAY_LENGHT; i++) {
        printf("ingrese el valor deseado-> "); scanf("%f", &base_array[i]);
    }

    invertir(base_array);

    return 0;
}

void invertir(float *base) {

    int j, indice = 9;
    float inverted[ARRAY_LENGHT];

    printf("el array invertido es-> \n");

    for(j = 0 ; j <= ARRAY_LENGHT - 1; j++) {
            inverted[j] = base[indice];
            printf("<%.2f> ", inverted[j]);
            indice--;
    }
}














































https://github.com/FabianNorbertoEscobar/Elementos-de-Programacion
