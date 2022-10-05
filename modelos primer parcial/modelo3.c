// este modelo corresponde al primer parcial

#include <stdio.h>
#include "../libraries/common_funcs.h"

#define _MONTH_ 12
#define _DAYS_  31
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void minimum_day (int bid_arr[][_DAYS_]) {
  int i, j;
  int min_comb, first_time = 1;

  for (i = 0; i < _MONTH_; i++)
    for (j = 0;j < _DAYS_; j++) {
      if (first_time && bid_arr[i][j] != 0) {
	min_comb = bid_arr[i][j];
	first_time = 0;
      } else if (bid_arr[i][j] < min_comb && bid_arr[i][j] != 0)
	min_comb = bid_arr[i][j];
    }

  printf ("[+] dia/mes\t\tminimo mensual\n");
  for (i = 0; i < _MONTH_; i++)
    for (j = 0;j < _DAYS_; j++) 
      if (bid_arr[i][j] == min_comb)
	printf ("-> %2d/%1d\t\t\t->%1d\n", j + 1, i + 1, min_comb);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main () {
  int day, month;
  int min_aux, min_month, max_comb, first_time = 1;
  int monthly_inv[_MONTH_][_DAYS_] = {{0}};
  int min_invs[_MONTH_] = {0};
  int nov_invs[_DAYS_]  = {0};
  int i, j;

  month = lee_valida (0, _MONTH_);
  while (month != 0) {
    day = lee_valida (1, _DAYS_);
    printf ("ingrese la cantidad de facturas realizadas en el dia-> "); scanf ("%d", &monthly_inv[month - 1][day - 1]);
    month = lee_valida (0, _MONTH_);
  }

  printf ("\n------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

  //punto a)
  for (i = 0; i < _MONTH_; i++)
    for (j = 0;j < _DAYS_; j++) {
      if (first_time) {
	max_comb = monthly_inv[i][j];
	first_time = 0;
      } else if (monthly_inv[i][j] > max_comb)
	max_comb = monthly_inv[i][j];
      min_invs[i] += monthly_inv[i][j]; // parte del punto b)
    }

  printf ("[+] dia/mes\t\tmaxima cantidad\n");
  for (i = 0; i < _MONTH_; i++) 
    for (j = 0;j < _DAYS_; j++)
      if (monthly_inv[i][j] == max_comb)
	printf ("-> %2d/%1d\t\t\t->%1d\n", i + 1, j + 1, max_comb);
  
  printf ("\n------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

  //punto b) 
  first_time = 1;
  for (i = 0; i < _MONTH_; i++)
    if (first_time) {
      min_aux = min_invs[i];
      min_month = i;
      first_time = 0;
    } else if (min_invs[i] < min_aux) { 
      min_aux = min_invs[i];
      min_month = i;
    }

  printf ("[+] Mes\t\tmenor numero de facturas\n-> %1d\t\t\t-> %1d\n", min_month + 1, min_aux);

  printf ("\n------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

  //punto c) 
  minimum_day (monthly_inv);

  printf ("\n------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

  //punto d) 
  for (i = 0; i < _DAYS_; i++)
    nov_invs[i] = monthly_inv[1][i];
  bubble_sort (nov_invs, _DAYS_, 1);
  printf ("[+] facturas de noviembre:\n[+] dia\t\tcantidad\n");
  for (i = 0; i < _DAYS_; i++)
    printf ("-> %1d\t\t%1d\n", i + 1, nov_invs[i]);

  return 0;
}
