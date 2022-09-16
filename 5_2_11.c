#include <stdio.h>

int main () {
  int number;
  int min, max, testigo = 1;

  do {
    printf ("ingrese cualquier digito entero\nel proceso se finaliza con un digito 0 (cero)\n------------> "); scanf("%d", &number);
    
    if (testigo) {
      max = number;
      min = 0;
      testigo = 0;
    } else if (number > max) max = number;
    else if (number > min && number < max) min = number;

  } while (number != 0);

  printf ("[+] proceso finalizado con exito.\n");
  printf ("[+] el numero mas grande ingresado es -> %d\n", max);
  printf ("[+] el segundo numero mas grande fue -> %1d\n", min);

  return 0;
}
