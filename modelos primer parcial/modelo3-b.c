#include <stdio.h>
#include "../libraries/common_funcs.h"

#define _MONTH_ 12
#define _DAYS_  31

int main () {
  int monthly_invs[_MONTH_][_DAYS_] = {{0}};
  int nov_invs[_DAYS_] = {0};
  int month, day;
  int i;

  month = lee_valida (0, _MONTH_);
  while (month != 0) {
    day = lee_valida (1, _DAYS_);
    printf ("ingrese valor de la matriz correspondiente a la posicion [%d;%d]-> ", month, day); scanf ("%d", &monthly_invs[month - 1][day - 1]);
    month = lee_valida (0, _MONTH_);
  }
  
  //punto a)
  max_min_comb (monthly_invs, _MONTH_, _DAYS_, 1);

  //punto b)
  min (monthly_invs, _MONTH_, _DAYS_);

  //punto c)
  max_min_comb (monthly_invs, _MONTH_, _DAYS_, 0);

  //punto d)
  for (i = 0; i < _DAYS_; i++)
    nov_invs[i] = monthly_invs[10][i];
  bubble_sort (nov_invs, _DAYS_, 1);
  printf ("[+] facturas de noviembre:\n[+] dia\t\tcantidad\n");
  for (i = 0; i < _DAYS_; i++)
    printf ("-> %1d\t\t%1d\n", i + 1, nov_invs[i]);

  return 0;
}
