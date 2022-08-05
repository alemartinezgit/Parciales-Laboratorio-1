#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "perros.h"
#include "controler.h"
#include "parser.h"

int parser_FromText(FILE* pFile , LinkedList* pArrayList) {

	ePerro* pElementAux;
	int cantLeida;
	char buffer[6][128];
	int todoOk = 0;

	if(pFile != NULL && pArrayList != NULL) {
		// FALSA LECTURA PARA SACAR LEER EL ENCABEZADO Y NO LO GUARDO, CORRO EL CURSOR A LA SEGUNDA LINEA
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
		do {
			cantLeida = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);

			if(cantLeida == 6) {
				pElementAux = lista_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);

				if(pElementAux != NULL) {
					ll_add(pArrayList,pElementAux);
					todoOk = 1;
				}
			}

		} while(!feof(pFile));
	} else {
		printf("Error abriendo el archivo\n");
		todoOk = 0;
		system("pause");
	}
	fclose(pFile);

	return todoOk;
}

