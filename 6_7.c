#include <stdio.h>

int lee_valida (int cota_min, int cota_max) {
  int value, time = 1;
  
  do {
    if ((value < cota_min || value > cota_max) && time != 1) {
      printf ("\n[-] valor ingresado invalido - reingresar un valor dentro de los parametros estimados\n------------> ");
      scanf ("%d", &value);
    } else {
      printf ("[+] ingrese un valor deseado-> "); scanf("%d", &value);
    }
    time++;
  } while (value < cota_min || value > cota_max);
  return value;
}

int mayor_menor (int first_value, int second_value, int third_value, int configuracion) {
  do {
    if (configuracion == 1) {
      return first_value > second_value && first_value > third_value
        ? first_value
        : second_value > first_value && second_value > third_value
	? second_value
	: third_value > first_value && third_value > second_value
        ? third_value : 0;
    } else if (configuracion == 2) {
      return first_value < second_value && first_value < third_value
	? first_value
	: second_value < first_value && second_value < third_value
	? second_value
        : third_value < first_value && third_value < second_value
        ? third_value : 0;
    } else {
      printf ("[-] valor de configuracion invalido - ingrese un valor dentro de los parametros estimados\n------------> ");
      scanf("%d", &configuracion);
    }
  } while (configuracion < 1 || configuracion > 2);
}

int main () {
  int first_value, second_value, third_value;
  int configuracion;
  int required_value;
  
  printf ("[+] ingrese un valor entre 1 y 98\n[+] el valor 98 es para finalizar el ingreso de numeros\n\n");

  first_value = lee_valida (1, 98);
  second_value = lee_valida (1, 98);
  third_value = lee_valida (1, 98);

  while (first_value != 98 && second_value != 98 && third_value != 98) {
    printf ("\ningrese que valor desea conocer:\n1) para conocer el numero mas grande ingresado en la terna\n2) para conocer el numero mas chico de la terna\n");
    printf ("------------> "); scanf("%d", &configuracion);

    required_value = mayor_menor (first_value, second_value, third_value, configuracion);
    printf ("\n[+] el numero que usted desea conocer es-> %d\n", required_value);

    first_value = lee_valida (1, 98);
    second_value = lee_valida (1, 98);
    third_value = lee_valida (1, 98);
  } 
  
  printf("\n[+] finalizacion del proceso exitosa\n");
  return 0;
}
