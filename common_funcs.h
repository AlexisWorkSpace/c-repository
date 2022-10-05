int lee_valida (int cota_min, int cota_max) {
  int value;
  int condition = 1;
  
  do {    
    if (condition) {
      printf("[+] ingrese el valor deseado-> "); scanf("%d", &value);
    } else {
      printf("[-] valor invalido - ingrese un valor dentro de los parametros establecidos\n------------> "); scanf("%d", &value);
    }
  } while (value < cota_min || value > cota_max);
  return value;
}

void bubble_sort (int arr[], int num, int conf) {
  int i, j, aux;
  
  // conf definira si el ordenamiento se lleva a cabo de manera ascendente o descendente
  // si conf es igual a 1, el ordenamiento sera de manera creciente
  // si conf es igual a 0, el ordenamiento sera de manera decreciente
  for (i = 0; i < num; i++)
    for (j = 0; j < num - 1 - i; j++) {
      if (conf) {
        if (arr[j] > arr[j + 1]) {
          aux = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = aux;
        }
      } else {
        if (arr[j] < arr[j + 1]) {
          aux = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = aux;
        }
      }
    }
}
