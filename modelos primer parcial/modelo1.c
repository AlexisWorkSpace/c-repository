// este modelo corresponde al primer parcial

#include <stdio.h>
#include "../libraries/common_funcs.h"

#define VISITADORES 20
#define PRODUCTOS 300
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cantidad_minima (int bid_arr[][PRODUCTOS]) {
  int arr[VISITADORES] = {0};
  int i, j;
  int min_pos, min_cant, first_time = 1;

  for (i = 0; i < VISITADORES; i++)
    for (j = 0; j < PRODUCTOS; j++) {
      arr[i] += bid_arr[i][j];
    }
  for (i = 0; i < VISITADORES; i++) {
    if (first_time) {
      min_cant = arr[i];
      min_pos = i;
      first_time = 0;
    }
    else if (arr[i] < min_cant) {
      min_cant = arr[i];
      min_pos = i;
    }
  }

  printf("[+] la cantidad minima corresponde a -> %d\n[+] la cantidad minima es -> %d\n", min_pos + 1, min_cant);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ordenamiento (int arr1[], int arr2[]) {
  int aux, i, j;
  for (i = 0; i < PRODUCTOS; i++)
    for (j = 0; j < PRODUCTOS - 1; j++) {
      if (arr1[j] > arr1[j + 1]) {
	aux = arr1[j];
	arr1[j] = arr1[j + 1];
	arr1[j + 1] = aux;

	aux = arr2[j];
	arr2[j] = arr2[j + 1];
	arr2[j + 1] = aux;
      }
    }

  for (i = 0; i < PRODUCTOS; i++) 
    printf("[+] producto %d\tcantidad %d\n", arr1[i], arr2[i]);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main () {
  int visitador, cod_producto, cantidad, max, first_time = 1;
  int unid_visitador[VISITADORES][PRODUCTOS] = {{0}};
  int cant_producto [PRODUCTOS] = {0};
  int combinaciones[VISITADORES] = {0};
  int arr_vendedor14[PRODUCTOS] = {0};
  int arr_cant14[PRODUCTOS] = {0};
  int i, j; 

  visitador = lee_valida (0, VISITADORES);
  while (visitador != 0) {
    cod_producto = lee_valida (1, PRODUCTOS);
    cantidad = lee_valida (1, 50);

    //completado de matriz
    unid_visitador[visitador - 1][cod_producto - 1] = cantidad;

    visitador = lee_valida (0, VISITADORES);
  }
  
  // punto a)
  for (i = 0; i < VISITADORES; i++)
    for (j = 0; j < PRODUCTOS; j++) {
      //printf ("-> %d  ", unid_visitador[i][j]);
      cant_producto[j] += unid_visitador[i][j];
      combinaciones[j] += unid_visitador[i][j]; // parte del punto c)
      // parte del punto d)
      if (i == 13) {
	arr_vendedor14[j] = i + 1;
	arr_cant14[j] += unid_visitador[i][j];
      }
    }

  printf ("Producto\tcantidad\n");
  for (j = 0; j < PRODUCTOS; j++) {
    printf (">%3d\t\t>%3d\n", j + 1, cant_producto[j]);
  }

  //punto b)
  cantidad_minima (unid_visitador);

  //punto c)
  for (i = 0; i < PRODUCTOS; i++) {
    if (first_time) {
      max = combinaciones[i];
      first_time = 0;
    } else if (combinaciones[i] > max) 
      max = combinaciones[i];
  }
  for (i = 0; i < PRODUCTOS; i++) 
    if (combinaciones[i] == max) 
      printf ("[+] el vendedor %d vendio %d - cantidad maxima\n", i + 1, max);

  //punto d)
  ordenamiento (arr_vendedor14, arr_cant14);

  return 0;
}

