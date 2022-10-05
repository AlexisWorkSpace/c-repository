#define _LEN_ROWS_ 12
#define _LEN_COLS_ 31

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

void bubble_sort (int arr[], int num, int conf) {
  int i, j, aux;

  // conf definira si el ordenamiento es de menor a mayor
  // de ser 1 el valor de conf, se ordenara de manera creciente
  // mientras que si conf es igual a 0, se ordenara de forma decreciente
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

void max_min_comb (int bid_arr[][_LEN_COLS_], int row, int col, int conf) {
  int i, j, max_comb = 0, min_comb = 0, first_time = 1;

  for (i = 0; i < row; i++)
    for (j = 0; j < col; j++) {
      if (conf == 1) {
	if (first_time) {
	  max_comb = bid_arr[i][j];
	  first_time = 0;
	} else if (bid_arr[i][j] > max_comb)
	  max_comb = bid_arr[i][j];
      } else if (conf != 1) {
	if (first_time && bid_arr[i][j] != 0) {
	  min_comb = bid_arr[i][j];
	  first_time = 0;
	} else if (bid_arr[i][j] < min_comb && bid_arr[i][j] != 0)
	  min_comb = bid_arr[i][j];
      }
    }

  for (i = 0; i < row; i++)
    for (j = 0; j < col; j++) { 
      if (conf == 1) { 
	if (bid_arr[i][j] == max_comb)
	  printf ("[+] para la combinacion [%d;%d] el mayor es (%d)\n", i + 1, j + 1, max_comb);
      } else if (conf != 1) {
	if (bid_arr[i][j] == min_comb)
	  printf ("[+] para la combinacion [%d;%d] el menor es (%d)\n", i + 1, j + 1, min_comb);
      }
    }
}

void min (int bid_arr[][_LEN_COLS_], int row, int col) {
  int i, j, first_time = 1;
  int arr[_LEN_ROWS_] = {0};
  int min, min_arr;

  for (i = 0; i < row; i++)
    for (j = 0; j < col; j++)
      arr[i] += bid_arr[i][j];

  for (i = 0; i < row; i++)
    if (first_time) {
      min = arr[i];
      min_arr = i;
      first_time = 0;
    } else if (arr[i] < min) { 
      min = arr[i];
      min_arr = i;
    }

  printf ("[+] al minimo (%d) se da en (%d)\n", min, min_arr);
}


