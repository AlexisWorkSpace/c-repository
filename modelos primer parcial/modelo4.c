//modelo primer parcial

#include <stdio.h>
#include "../libraries/common_funcs.h"

#define _SECTORES_ 8
#define   _DIAS_   5

int main () {
  float costo_sector[_SECTORES_];
  float total_rec = 0;
  int cantidad_localidad[_DIAS_][_SECTORES_] = {{0}};
  int sectores[_SECTORES_];
  int dia, sector, elem_pos;
  int max_cants, first_time = 1;
  int i, j;

  for (i = 0; i < _SECTORES_; i++) {
    sectores[i] = lee_valida (1000, 9999);
    printf ("ingreso costo del sector %d -> $", sectores[i]); scanf ("%f", &costo_sector[i]);
    while (costo_sector[i] <= 0) {
      printf ("[-] ingreso de costo invalido - reingrese un costo para el sector %d -> $", sectores[i]); scanf ("%f", &costo_sector[i]);
    }
  }
  
    dia = lee_valida (0, 5);
    while (dia != 0) {
      sector = lee_valida (1000, 9999);
      elem_pos = arr_search (sectores, _SECTORES_, sector);
      if (elem_pos != -1) {
	printf ("[+] ingrese la cantidad de entradas vendidas -> "); scanf ("%d", &cantidad_localidad[dia - 1][elem_pos]);
      }
      else
	printf ("[-] el ingreso de datos es invalido - reingrese datos con dia/sector antes mencionados -\n");

      dia = lee_valida (0, 5);
    }

    // punto a)
    printf ("[+] sector\t\tdia 1\t\tdia 2\t\tdia 3\t\tdia 4\t\tdia 5\n");
    for (i = 0; i < _SECTORES_; i++) {
      printf("-> %1d\t\t\t", sectores[i]);
      for (j = 0; j < _DIAS_; j++) {
	if (cantidad_localidad[j][i] != 0)
	  total_rec += cantidad_localidad[j][i] * costo_sector[i];
	printf ("$%.2f\t\t", cantidad_localidad[j][i] * costo_sector[i]);

      }
      printf ("\n");
    }

    // punto b)
    for (i = 0; i < _DIAS_; i++)
      for (j = 0; j < _SECTORES_; j++) 
	if (first_time == 1) {
	  max_cants = cantidad_localidad[i][j];
	  first_time = 0;
	} else if (cantidad_localidad[i][j] > max_cants) 
	  max_cants = cantidad_localidad[i][j];

    printf ("[+] dia-sector\tcantidad\n");
    for (i = 0; i < _DIAS_; i++) 
      for (j = 0; j < _SECTORES_; j++)
	if (cantidad_localidad[i][j] == max_cants)
	  printf ("%5d\t%1d\t%d\n", i + 1, j + 1, max_cants);

    // punto c) 
    for (i = 0; i < _SECTORES_; i++) 
      if (cantidad_localidad[2][i] == 0)
	printf ("[+] la localidad %d tuvo cero entradas vendidas\n", i + 1);

    // punto d) 
    printf("[+] la recaudacion total fue -> $%.2f\n", total_rec);
  return 0;
}
