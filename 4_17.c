#include <stdio.h>
#include <ctype.h>

int main() {
  int numero_historia, importe;
  char codigo;

  //variable para definir verdader o falso
  int boolean = 1;

  printf("ingrese el codigo de de la prestacion-> "); scanf("%c", &codigo);
  codigo = toupper(codigo);

  //limpio el buffer de entrada
  fflush(stdin);
  printf("ingrese el numero de historia del paciente-> "); scanf("%d", &numero_historia);
  
  /*
  dentro del switch pude reemplazarse de la siguiente manera sin usar toupper:
  
  case 'a': case 'A':
    importe = 20;
    break;
   case 'd': case 'D':
    importe = 40;
    break;
  
  */
  
  switch(codigo) {
    case 'A':
      importe = 20;
      break;
    case 'D':
      importe = 40;
      break;
    case 'F':
      importe = 60;
      break;
    case 'M': case 'T':
      importe = 150;
      break;
    default:
      printf("\n-el ingreso de datos es invalido, no se puede proceder con el pedido\n");
      boolean = 0;
      break;
  }
  boolean ? printf("+el codigo del paciente es->\t%c\n+la historia del paciente es->\t%d\n+el importe es de->\t%d\n", codigo, numero_historia, importe) : 0;
  return 0;
}
