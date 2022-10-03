// este modelo corresponde al primer parcial

#include <stdio.h>
#include "../libraries/common_funcs.h"

#define PRODUCTOS 30
#define SUPERS 8
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void promedio_precios (float bid_arr[][SUPERS]) {
  float arr[PRODUCTOS];
  int i, j = 0;
  int count = 0;

  for (i = 0; i < PRODUCTOS; i++)
    while (j < SUPERS || bid_arr[i][j] != 0) {
      arr[i] += bid_arr[i][j];
      j++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main () {
  int cod_prod, super;
  int i, j, first_time = 1;
  int super_economico[SUPERS] = {0};
  float precio, precio_min;
  float precio_minimo[PRODUCTOS] = {0};
  float mat_precios[PRODUCTOS][SUPERS] = {{0}};

  cod_prod = lee_valida (0, PRODUCTOS);
  while (cod_prod != 0) {
    super = lee_valida (1, SUPERS);
    printf ("ingrese el precio del producto-> "); scanf("%f", &precio);
    mat_precios[cod_prod - 1][super - 1] = precio;
    cod_prod = lee_valida (0, PRODUCTOS);
  }

  // punto a)
  promedio (mat_precios);

  //punto b)
  for (i = 0; i < SUPERS; i++) {
    super_economico[i] = i + 1;
    precio_minimo[i] += mat_precios[11][i];
    if (first_time) {
      precio_min = precio_minimo[i];
      first_time = 0;
    } else if (precio_minimo[i] < precio_min) 
      precio_min = precio_minimo[i];
  }

  for (i = 0; i < SUPERS; i++)
    if (precio_minimo[i] == precio_min)
      printf ("[+] el supermercado %d vende el producto 12 a $%.2d\n", super_economico[i], precio_minimo[i]);

  return 0;
}

