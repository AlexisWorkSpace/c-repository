#include <stdio.h>

// definicion de prototipos
int leer_validar(int, int);
int menu(int , int);
int suma(int, int);
int resta(int, int);
int multiplicar(int, int);
int dividir(int, int);
int ingreso_reingreso(int);
void operaciones(int, int);

int main() {
  int a, b;

  //ingreso
  a = ingreso_reingreso(0);
  b = ingreso_reingreso(0);
  //operaciones
  operaciones(a, b);
  
  return 0;
}

// aqui se valida el ingreso del codigo
int leer_validar(int cota_minima, int cota_maxima) {
  int code;

  do {
    scanf("%d", &code);
    if(code < 1 || code > 6) {
      printf("[-] codigo erroneo\n");
    }
  } while(code < cota_minima || code > cota_maxima);
  return code;
}

// aqui se corre el menu de opciones
int menu(int a, int b) {
  int code; 

  printf("los numeros ingresados son: \n[+] primer valor-> %d\t[+] segundo valor %d\n", a, b);
  printf("\nmenu de opciones\n---- -- --------\n");
  printf("\n\t1) suma\n\t2) resta\n\t3) multiplicar\n\t4) dividir\n\t5) reingreso de numero\n\t6) salir\n");
  printf("\ningrese codigo deseado-> "); code = leer_validar(1, 6);

  return code;  
}

// aqui se llevan a cabo las operaciones de la calculadora
void operaciones(int a, int b) {
  int i;
  int code;

  do {
    code = menu(a, b);
    if(code == 1) printf("\n[+] suma-> %d\n\n", suma(a, b));
    else if(code == 2) printf("\n[+] resta-> %d\n\n", resta(a, b));
    else if(code == 3) printf("\n[+] multiplicacion-> %d\n\n", multiplicar(a, b));
    else if(code == 4) printf("\n[+] division-> %d\n\n", dividir(a, b));
    else if(code == 5) 
      for(i = 0; i < 2; i++)
	i == 0 ? a = ingreso_reingreso(code) : b = ingreso_reingreso(code);
    else if (code == 6) printf("\n[+] fin del proceso\n\n");
  } while((code > 1 || code < 6) && code != 6);
}

// desde este punto se realizan las operaciones aritmeticas desde la suma hasta la division
int suma(int a, int b) {
  return a + b;
}
int resta(int a, int b) {
  return a - b;
}
int multiplicar(int a, int b) {
  return a * b;
}
int dividir(int a, int b) {
  while(b == 0) {
    printf("reingrese nuevo valor para b-> "); scanf("%d", &b); // aqui se revisa que que b sea distinto de 0
  }
  return a / b;
}

// aqui se hacer el ingreso y reingreso de los valores a y b
int ingreso_reingreso(int code) {
  int new_number;

  if(code == 5) {
    printf("reingrese numero-> "); scanf("%d", &new_number);
  } else {
    printf("ingrese valor-> "); scanf("%d", &new_number);
  }

  return new_number;
}
