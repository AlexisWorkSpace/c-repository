/*este si es %100 legal para el parcial*/

int lee_valida(int cota_min, int cota_max) {
	int val; 
	int cond = 1;
	do {
		if (cond) printf("[+] ingrese un valor dentro del rango [%d-%d] -> ", cota_min, cota_max);
		else printf("[-] el valor se encuentra fuera de rango...\nreingrese un valor correspondiente al rango [%d-%d] -> "), cota_min, cota_max;
		scanf("%d", &val); cond = 0;
	} while(val < cota_min || val > cota_max);
	return val;
}

int lee_valida_plusplus(int cota_min, int cota_max, int corte) {
	int val; 
	int cond = 1;
	do {
		if (cond) printf("[+] ingrese un valor dentro del rango [%d-%d] -> ", cota_min, cota_max);
		else printf("[-] el valor se encuentra fuera de rango...\nreingrese un valor correspondiente al rango [%d-%d] -> "), cota_min, cota_max;
		scanf("%d", &val); cond = 0;
	} while((val < cota_min || val > cota_max) &&  val != corte);
	return val;
}
