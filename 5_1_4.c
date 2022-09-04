#include <stdio.h>
#include <ctype.h>

int main() {

	char letra; // variable utilizada para la entrada de datos por teclado
	int i, vocales = 0; // variables usadas por el programa

	for(i = 0; i < 100; i++) {
		
		printf("ingrese una letra-> ");
		scanf("%c", &letra); getchar();

		letra = toupper(letra);
		letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U' 
			? vocales++ : 0;

	}
	printf("[+] la cantidad de vocales es-> %d\n", vocales);
	return 0;
}

