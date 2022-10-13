#include <stdio.h>

int lee_valida (int cota_min, int cota_max) {
  int val;
  int ft = 1;
  do {
    if (ft == 1) {
      printf ("[+] ingrese valor dentro del intervalo [%d;%d] -> ", cota_min, cota_max); scanf ("%d", &val);
      ft = 0;
    } else {
      printf ("[-] valor fuera de los parametros - reingrese -> "); scanf ("%d", &val);
    }
  } while (val < cota_min || val > cota_max);
  return val;
}

int main () {
  int cant_prod[10] = {0};
  int productos[10] = {0};
  int producto, cant;
  int i = 0;

  producto = lee_valida (0, 10);
  while (producto != 0) {
    productos[i] = producto;
    printf ("ingrese cantidad -> "); scanf ("%d", &cant);
    cant_prod[i] += cant;
    if (i == 10) i = 0;
    else i++;
    producto = lee_valida(0, 10);
  }

  printf("cod\tcant\n");
  for (i = 0; i < 10; i++)
    printf("%d\t%d\n", productos[i], cant_prod[i]);

  return 0;  
}


