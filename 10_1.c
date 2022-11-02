#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dni;
  int nota1;
  int nota2;
  char nombre[20];
  char apellido[20];
  float prom;
} alumno;

alumno data_input() {
  alumno estudiante;

  printf("[+] ingrese el nombre del estudiante -> "); 
  fflush(stdin); gets(estudiante.nombre);
  printf("[+] ingrese el apellido del estudiante -> ");
  fflush(stdin); gets(estudiante.apellido);
  printf("[+] ingrese las notas del estudiante con el siguiente formato (nota1 nota2) -> ");
  scanf("%d %d", &estudiante.nota1, &estudiante.nota2);

  return estudiante;
}

void fshow(char fname[], char fmode[], alumno file) {
  alumno aux;

  FILE *pf = fopen(fname, fmode);
  if(pf == NULL) {
    perror("error reading the required file - finish process...");
    system("PAUSE"); exit(1);
  }
  fread(&aux, sizeof(alumno), 1, pf);
  while(!feof(pf))
    fread(&aux, sizeof(alumno), 1, pf);
  
  fclose(pf);
}

int main() {
  FILE *pf = fopen("Alumnos.dat", "wb");
  alumno estudiantes;
  int i;

  if(pf == NULL) {
    perror ("error creating file 'Alumnos.dat' - finish process....");
    return 1;
  }

  printf("ingrese el numero de dni del estudiante -> "); scanf("%d", &estudiantes.dni);
  while(estudiantes.dni == 0) {
    estudiantes = data_input();
    estudiantes.prom = (float) (estudiantes.nota1 + estudiantes.nota2) / 2;
    fwrite(&estudiantes, sizeof(alumno), 1, pf);
    printf("ingrese el numero de dni del estudiante -> "); scanf("%d", &estudiantes.dni);
  }

  fclose(pf);
  return 0;
}
