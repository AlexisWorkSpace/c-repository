#include <stdio.h>

int main() {
  int actual_day, actual_month, actual_year; //fecha actual
  int birth_day, birth_month, birth_year; //fecha de nacimiento

  printf("ingrese la fecha actual con el siguiente formato (dd/mm/aaaa) -recuerde usar un espacio entre cada valor ingresado-> ");
  scanf("%d %d %d", &actual_day, &actual_month, &actual_year);
  printf("ingrese la fecha de nacimiento con el mismo formato anterior -recuerde los espacios-> ");
  scanf("%d %d %d", &birth_day, &birth_month, &birth_year);

  if(actual_month > 0 && actual_month<= 12 && birth_month > 0 && birth_month <= 12) {
    if(actual_day > 0 && birth_day > 0 && actual_day <= 31 && birth_day <= 31) {
      printf("+su edad es-> %d\n", actual_year - birth_year);
    }
    else {
      printf("-formato de fecha incorrecto\n");
    }
  }
  else {
    printf("-formato de fecha incorrecto\n");
  }

  return 0;
}
~                                                                                                                                                     
~                                                                                                                                                     
~                                                                                                                                                     
~                                                                                                                                                     
~                       
