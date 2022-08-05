#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "perros.h"
#include "LinkedList.h"
#include "controler.h"
#include "utn.h"
#include "parser.h"
#include "menu.h"

int controller_loadFromText(char* path , LinkedList* pArrayList) {

	int todoOk = 0;
	FILE* pFile;
	pFile = fopen(path, "r");
	if (path != NULL && pArrayList != NULL) {
		if (parser_FromText(pFile, pArrayList)) {
			printf("Carga de archivo de texto exitosa\n");
			system("pause");
			todoOk = 1;
		}
	} else {
		printf("No se pudo abrir el archivo\n");
		system("pause");
	}
	fclose(pFile);
	return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayList) {

	int todoOk = 0;
	int id;
	char nombre[100];
	int dias;
	char raza[100];
	char reservado[5];
	char genero;
	int len;

	FILE* pFile;
	pFile = fopen(path, "w");
	ePerro* auxPerro = NULL;

	if (path != NULL && pArrayList != NULL && pFile != NULL) {

		len = ll_len(pArrayList);

		// ENCABEZADO
		fprintf(pFile,"ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero\n");

		for (int i = 0; i < len; i++) {

			auxPerro = ll_get(pArrayList, i);

			perro_getId(auxPerro,&id);
			perro_getNombre(auxPerro,nombre);
			perro_getDias(auxPerro,&dias);
			perro_getRaza(auxPerro,raza);
			perro_getReservado(auxPerro,reservado);
			perro_getGenero(auxPerro,&genero);

			fprintf(pFile,"%d,%s,%d,%s,%s,%c\n", id,nombre,dias,raza,reservado,genero);

			todoOk = 1;
		}
			printf("EL archivo se guardo exitosamente\n");
	} else {
		printf("No se pudo guardar el archivo\n");
	}
	fclose(pFile);

	return todoOk;
}

/////////////////////////////////////////////////////////////////

int controller_filterPerros45Dias(LinkedList* pArrayList) {
	int retorno;
	retorno = 0; // LL NULA
	LinkedList* pArrayMenores45;

	if (pArrayList != NULL) {
		retorno = 1;

		pArrayMenores45 = ll_filter(pArrayList, perros_filterMenores45);
		retorno = controller_saveAsText("perrosMenores45.csv", pArrayMenores45);
		ll_deleteLinkedList(pArrayMenores45);

	}
	return retorno;
}

int controller_filterNoMachos(LinkedList* pArrayList) {
	int retorno;
	retorno = 0; // LL NULA
	LinkedList* pArrayNoMachos;

	if (pArrayList != NULL) {
		retorno = 1;

		pArrayNoMachos = ll_filter(pArrayList, perros_filterNoMachos);
		retorno = controller_saveAsText("nomACHOS.csv", pArrayNoMachos);
		ll_deleteLinkedList(pArrayNoMachos);
	}
	return retorno;
}

int controller_printfCallejeros(LinkedList* pArrayList) {

	int retorno;
	retorno = 0; // LL NULA
	LinkedList* pArrayCallejeros;

	if (pArrayList != NULL) {
		retorno = 1;

		pArrayCallejeros = ll_filter(pArrayList, perros_filterCallejeros);
		retorno = controller_List(pArrayCallejeros);
		ll_deleteLinkedList(pArrayCallejeros);
	}
	return retorno;
}



