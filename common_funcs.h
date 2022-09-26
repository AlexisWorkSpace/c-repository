int lee_valida (int cota_min, int cota_max) {
  int value = cota_min;
  
  do {    
    if (value < cota_min || value > cota_max) {
      printf("[-] valor invalido - ingrese un valor dentro de los parametros establecidos\n------------> "); scanf("%d", &value);
    } else {
      printf("[+] ingrese el valor deseado-> "); scanf("%d", &value);
    }
  } while (value < cota_min || value > cota_max);
  return value;
}

void merge (int *arr1, int num1, int *arr2, int num2, int *arr3) {
  int x1 = 0, x2 = 0, x3 = 0;

  while (x1 < num1 && x2 < num2) {
    if (arr1[x1] < arr2[x2]) {
      arr3[x3] = arr1[x1];
      x1++;
    } else {
      arr3[x3] = arr2[x2];
      x2++;
    }
    x3++;
  }
  while (x1 < num1) {
    arr3[x3] = arr1[x1];
    x1++; x3++;
  }
  while (x2 < num2) {
    arr3[x3] = arr2[x2];
    x2++; x3++;
  }
}

void merge_sort (int *arr, int num) {
  int *arr1, *arr2;
  int n1, n2, x, y;

  if (num > 1) {
    if (num % 2 == 0) n1 = n2 = ( int ) num / 2;
    else {
      n1 = ( int ) num / 2;
      n2 = n1 + 1;
    }
    arr1 = ( int* ) malloc (sizeof ( int ) * n1);
    arr2 = ( int* ) malloc (sizeof ( int ) * n2);
    for (x = 0; x < n1; x++) arr1[x] = arr[x];
    for (y = 0; y < n2; x++, y++) arr2[y] = arr[x];

    merge_sort (arr1, n1);
    merge_sort (arr2, n2);
    merge (arr1, n1, arr2, n2, arr);
    free (arr1);
    free (arr2);
  }
}
