#include <stdio.h>
#include <string.h>

void rep_dig(char *str, int pos) {
    int len = strlen(cadena);
    if (pos >= 0 && pos < len) str[pos] = '0';
    else printf("fuera de rango\n");
}
