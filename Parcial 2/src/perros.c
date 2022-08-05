#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "perros.h"
#include "controler.h"
#include "utn.h"
#include "LinkedList.h"

ePerro* lista_new() {

	ePerro* nuevaPelicula = (ePerro*) malloc(sizeof(ePerro));

    return nuevaPelicula;
}

ePerro* lista_newParametros(char* idCachorro,char* nombre,char* dias,char* raza,char* reservado,char* genero){

	ePerro* pPerro = lista_new();

	if(pPerro != NULL) {
		perro_setId(pPerro,(atoi(idCachorro)));
		perro_setNombre(pPerro,nombre);
		perro_setDias(pPerro,(atoi(dias)));
		perro_setRaza(pPerro,raza);
		perro_setReservado(pPerro,reservado);
		perro_setGenero(pPerro,(genero));
	}
	return pPerro;
}


void lista_delete(ePerro* this) {

	if(this!= NULL) {
		free(this);
	}
}

int controller_List(LinkedList* pArrayList){
	ePerro* pAuxElement = NULL;
	int todoOk = 0;
	int len;

	if(pArrayList != NULL)	{
		len =  ll_len(pArrayList);
		if(len > 0) {
			printf("              *** LISTA PERROS  ***\n");
			printf("------------------------------------------------------------------------------------\n");
			printf(" ID NOMBRE  	    DIAS       RAZAS       RESERVADO      GENERO       \n");
			printf("-------------------------------------------------------------------------------------\n");
			for(int i = 0; i < len; i++) {
				pAuxElement = ll_get(pArrayList,i);
				controller_show(pAuxElement);
			}
			todoOk =1;
		} else {
			printf("NO HAY NADA PARA MOSTRAR\n");
			system("pause");
		}

	}
	return todoOk;
}


int controller_show(ePerro* pElement) {

	int id;
	char nombre[50];
	int dias;
	char raza[50];
	char reservado[5];
	char genero;


    int todoOk = 0;

    if(pElement != NULL &&
		perro_getId(pElement,&id) &&
		perro_getNombre(pElement,nombre) &&
		perro_getDias(pElement,&dias)  &&
		perro_getRaza(pElement,raza) &&
		perro_getReservado(pElement,reservado)  &&
		perro_getGenero(pElement,&genero))    {

        printf("%d    %-20s %2d  %-20s  %-20s %c\n",id,nombre,dias,raza,reservado,genero);
        todoOk = 1;
    }
    return todoOk;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///  GETTERS & SETTERS
///
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int perro_setId(ePerro* this,int id) {

	int todoOk = 0;
	if(this != NULL && id > 0) {
		this->id = id;
		todoOk = 1;
	}
	return todoOk;
}
int perro_getId(ePerro* this,int* id) {

	int todoOk = 0;
	if(this != NULL && id != NULL) {
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int perro_setNombre(ePerro* this,char* nombre) {

	int todoOk = 0;

	if(this != NULL) {
		strcpy(this->nombre,nombre);
		todoOk = 1;
	}
	return todoOk;

}
int perro_getNombre(ePerro* this,char* nombre) {

	int todoOk = 0;

	if(this != NULL && nombre != NULL) {
		strcpy(nombre,this->nombre);
		todoOk = 1;
	}
	return todoOk;
}

int perro_setDias(ePerro* this,int dias) {

	int todoOk = 0;
	if(this != NULL && dias > 0) {
		this->dias = dias;
		todoOk = 1;
	}
	return todoOk;
}
int perro_getDias(ePerro* this,int* dias) {

	int todoOk = 0;
	if(this != NULL && dias != NULL) {
		*dias = this->dias;
		todoOk = 1;
	}
	return todoOk;
}

int perro_setRaza(ePerro* this,char* raza) {

	int todoOk = 0;

	if(this != NULL) {
		strcpy(this->raza,raza);
		todoOk = 1;
	}
	return todoOk;

}
int perro_getRaza(ePerro* this,char* raza) {

	int todoOk = 0;

	if(this != NULL && raza != NULL) {
		strcpy(raza,this->raza);
		todoOk = 1;
	}
	return todoOk;
}

int perro_setReservado(ePerro* this,char* reservado) {

	int todoOk = 0;

	if(this != NULL) {
		strcpy(this->reservado,reservado);
		todoOk = 1;
	}
	return todoOk;

}
int perro_getReservado(ePerro* this,char* reservado) {

	int todoOk = 0;

	if(this != NULL && reservado != NULL) {
		strcpy(reservado,this->reservado);
		todoOk = 1;
	}
	return todoOk;
}

int perro_setGenero(ePerro* this,char* genero) {

	int todoOk = 0;

	if(this != NULL) {
		this->genero = *genero;
		todoOk = 1;
	}
	return todoOk;

}
int perro_getGenero(ePerro* this,char* genero) {

	int todoOk = 0;

	if(this != NULL && genero != NULL) {
		*genero = this->genero;
		todoOk = 1;
	}
	return todoOk;
}



int perros_filterMenores45(void* a) {

	int ok = 0;
	int dias;

	if(a != NULL ) {
		perro_getDias(a,&dias);
		if(dias < 45) {
			ok = 1;
		}
	}
	return ok;
}

int perros_filterNoMachos(void* a) {

	int ok = 0;
	char genero;

	if(a != NULL ) {
		perro_getGenero(a,&genero);
		if(genero != 'M') {
			ok = 1;
		}
	}
	return ok;
}

int perros_filterCallejeros(void* a) {

	int ok = 0;
	char raza[50];

	if(a != NULL ) {
		perro_getRaza(a,raza);
		if(strcmp("Callejero", raza) == 0) {
			ok = 1;
		}
	}
	return ok;
}


