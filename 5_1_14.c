#include <stdio.h>

int main() {

	int i, j, perfect;

	for(i = 1; i < 9000; i++) {
		perfect = 0;
		for(j = 1; j < i; j++)  i % j == 0 ? perfect += j : 0; 

		perfect == i ? printf("%2d\t", perfect) : 0;
	
	}
	printf("\n");
	return 0;
}
