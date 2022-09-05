#include <stdio.h>

int main() {

	int i, j, cantidad_primos = 0, primo;

	for(i = 1; i <= 100; i++) {
		primo = 1;
		for(j = 2; j <= i / 2; j++) {

			if(i % j == 0) primo = 0;
		}
		if(primo) {
			printf("%d\n", i);
			cantidad_primos++;
		}
	}
	printf("cantidad primos-> %d\n", cantidad_primos);
	return 0;
}
