#include <stdio.h>
#include <stdlib.h>
#include "perros.h"
#include "controler.h"
#include "parser.h"
#include "LinkedList.h"
#include "utn.h"
#include "menu.h"

int main(void) {

	setbuf(stdout, NULL);

	int seguir = 1;
	char nombreArchivo[50];

	LinkedList* lista = ll_newLinkedList();

	do {
		switch(menu()) {
			case 1:
				//miGetCadena("Ingrese nombre del archivo: ", nombreArchivo);
				//DATA_perros.csv
				if (!controller_loadFromText("DATA_perros.csv",lista)) {
					printf("archivo incorrecto\n");
				}
				break;
			case 2:
				controller_List(lista);
				break;
			case 3:
				controller_filterPerros45Dias(lista);
				break;
			case 4:
				controller_filterNoMachos(lista);
				break;
			case 5:
				controller_printfCallejeros(lista);
				break;
			case 6:
				seguir = 0;
				break;

			default:
				printf("OPCION INVALIDA\n");
		}
	} while(seguir);

	printf("salio con exito\n");
	system("pause");

	return EXIT_SUCCESS;
}
