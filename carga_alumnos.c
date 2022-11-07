#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dni;
  char nya[51];
  float promedio;
} Alumno;

int lee_valida (int cota_min, int cota_max) {
  int value;
  int condition = 1;
  
  do {    
    if (condition) {
      printf ("[+] ingrese un valor correspondiente al siguiente intervalo [%d;%d] -> ", cota_min, cota_max); scanf("%d", &value);
      condition = 0;
    } else {
      printf("[-] valor invalido - ingrese un valor dentro de los parametros establecidos\n------------> "); scanf("%d", &value);
    } 
  } while (value < cota_min || value > cota_max);
  return value;
}

Alumno student_data(void) {
  Alumno student;
  printf("\n[+] ingrese el dni del estudiante -> "); scanf("%d", &student.dni); fflush(stdin);
  if(student.dni != 0) {
    printf("[+] ingrese el nombre y el apellido del estudiante -> "); gets(student.nya); fflush(stdin);
    printf("[+] ingrese la nota promedio de %s ->", student.nya); scanf("%f", &student.promedio);  
  }
  return student;
}

void data_upload(void) {
  FILE *pf = fopen("alumnos.dat", "wb");
  Alumno student;

  if(pf == NULL) {
    perror("[-] error inesperado de archivo - finalizando tareas...");
    exit(1);
  }

  student = student_data();
  while(student.dni != 0){
    fwrite(&student, sizeof(Alumno), 1, pf);
    student = student_data();
  }
  fclose(pf);
}

void data_download(void) {
  FILE *pf = fopen("alumnos.dat", "rb");
  Alumno student;
  if(pf == NULL) {
    perror("[-] error inesperado de archivo - finalizando tares");
    exit(1);
  }
  printf("[+] Datos almacenados hasta la fecha\n    ----- ----------- ----- -- -----\n");
  fread(&student, sizeof(Alumno), 1, pf);
  while(!feof(pf)) {
    printf("%8d\t%-40s%4.2f\n", student.dni, student.nya, student.promedio);
    fread(&student, sizeof(Alumno), 1, pf);
  }
  fclose(pf);
}

int main() {
  int select;
  // 248 el circulo
  printf("que accion desea realizar?\n\t%c 1 - Guardar datos\n\t%c 2 - Leer datos\n\t%c 3 - Finalizar\n", 3, 3, 3); select = lee_valida(1, 3);
  while(select != 3) {
    if(select == 1) data_upload();
    else if(select == 2) data_download();

    printf("\n[+] que accion desea realizar?\n"); select = lee_valida(1, 3);
  }

  printf("[+] tarea finalizada con exito\n");
  return 0;
}
