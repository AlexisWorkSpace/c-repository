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
