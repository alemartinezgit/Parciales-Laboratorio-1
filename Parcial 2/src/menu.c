#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"

int menu() {
	  int opcion;

	printf(" **** MENU PERROS ****\n");
	printf("1- Cargar archivo \n");
	printf("2- Listas\n");
	printf("3- Filtrar menor de 45 dias\n");
	printf("4- Filtrar machos\n");
	printf("5- Listado de callejeros\n");
	printf("6 - SALIR\n");

	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}




