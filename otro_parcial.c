/*
una empresa que se dedica a la venta por mayot de productos de informatica, desea controlar los pediodos de sus clientes. La empresa comercializaq casi 5000
productos diferentes, para ello cuenta con los siguientes datos que se hallan en el archivo llamado STOCK.dat a fines del mes de junio:
	- codigo de producto (int entre 1000 y 10000)
	- descripcion del producto (30 caracteres)
	- punto de pedido (int)(si el stock del producto esta por debajo de este valor se debe solicitar reposicion del producto al proveedor)
	- stock (int)
	
junto con el archivo anterior nos entregan por cada pedido a cumplir en el mes de julio los siguientes datos:
	- codigo de producto (entero entre 1000 y 10000)
	- cantidades de unidades pedidas (int)
	- numero de cliente (entero entre 1 y 3000)
	- dia (entero entre 1 y 30)

dichos datos se ingresan por teclado y finalizan al ingresar un codigo de producto 0. Si la cantidad de unidades vendidas es superior al stock del producto 
existente NO se realizara la venta.

	a) con los datos ingresados por teclado en el mes de estudio, informar el codigo de producto mas vendido
	b) informar los productos que se necesita reponer (productos cuyo stock haya quedado por debajo del punto de pedido)
	c) confeccionar una funcion para informar un listado con los dias donde se solicitaron mas de 10000 productos con el siguiente formato:
			DIA		CANTIDAD DE PRODUCTOS
			xx		xxxx
			xx		xxxx
	d) generar un nuevo archivo con los stocks actualizados con el mismo diseño de registro STOCK.dat
	
realizar al menos 3 funciones 
	1. para la busqueda del codigo de producto ingresado por teclado en el archivo
	2. para imprimir el punto c)
	3. para cargar en memoria los datos que se encuentran en el archivo STOCK.dat  o para grabar los datos en el nuevo archivo (a eleccion)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "E:\prog\prog\C\libraries\funcs.h"

#define _LEN_ 5000

typedef struct {
	int cod; /*entre 1000 y 10000*/
	char desc[31]; /*descripcion del producto*/
	int max_pedido; 
	int stock;
}Prod_Info;

typedef struct {
	Prod_Info prev_info;
	int pedido;
	int num_cliente; /*entero entre 1 y 1 y 3000*/
	int dia; /*entero entre 1 y 30*/
}Ped_Info;

int freading(Prod_Info[], Ped_Info[], int, char[], char[]);
void fnite(Prod_Info[], Ped_Info[], int, char[]);
int arr_search(Prod_Info[], int, int);

int main() {
	Prod_Info productos[_LEN_];
	Ped_Info pedidos[_LEN_];
	char new_fname[31];
	int registros;
	
	printf("ingrese el nombre del archivo el cual desea leer\nincluya la extension si este la tiene -> "); gets(new_fname); fflush(stdin);
	system("cls");
	registros = freading(productos, pedidos, _LEN_, new_fname, "rb");
	
	fnite(productos, pedidos, registros, "wb");
	
	return 0;
}

int freading(Prod_Info arr[], Ped_Info narr[], int len, char fname[], char fmode[]) {
	FILE *pf = fopen(fname, fmode);
	Prod_Info aux;
	int registros = 0;
	
	if(pf == NULL) { printf("FATAL ERROR...\n"); system("pause"); exit(1); }
	
	printf("[+] Leyendo registros del archivo %s...", fname);
	fread(&aux, sizeof(Prod_Info), 1, pf);
	while(!feof(pf) && registros < len) {
		arr[registros] = aux;
		narr[registros].prev_info = aux;
		registros++;
		fread(&aux, sizeof(Prod_Info), 1, pf);
	}
	fclose(pf);
	
	Sleep(2000);
	system("cls");
	
	return registros;
}

void fnite(Prod_Info arr[], Ped_Info narr[], int len, char fmode[]) {
	FILE *pf;
	char gen_fname[31];
	int i;
	int requested_pos, query_pos;
	
	printf("[+] ingrese el nombre del nuevo archivo -> "); gets(gen_fname); fflush(stdin);
	system("cls");
	
	pf = fopen(gen_fname, fmode);
	
	printf("[+] ingrese el codigo que desea buscar\n"); query_pos = lee_valida_plusplus(1000, 10000, 0);
	while(query_pos != 0) {
		requested_pos = arr_search(arr, query_pos, len);
		if(requested_pos != -1) {
			printf("[+] ingrese el numero pedidos del producto [%d] -> ", query_pos); scanf("%d", &narr[requested_pos].pedido);
			printf("[+] ingrese numero de cliente que realizo el pedido\n"); narr[requestd_pos].num_cliente = lee_valida(1, 3000);
			printf("[+] ingrese el dia en el que se realizo el pedido\n"); narr[requested_pos].dia = lee_valida(1, 30);
		}
		else printf("[-] valor no encontrado entre los registros...");
		printf("[+] ingrese el codigo que desea buscar\n"); query_pos = lee_valida_plusplus(1000, 10000, 0);
	}
	
	fclose(pf);	
	
	Sleep(2000);
	system("cls");
}

int arr_searc(Prod_Info arr[], int elem, int len) {
	int i = 0; 
	int pos = -1;
	while(i < len && pos == -1) 
		if(arr[i].cod == elem) pos == i;
		else i++;
	return pos;
}
