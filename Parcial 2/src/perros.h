#ifndef PERROS_H_
#define PERROS_H_

typedef struct {

	int id;
	char nombre[50];
	int dias;
	char raza[50];
	char reservado[10];
	char genero;

}ePerro;

#endif /* PERROS_H_ */

ePerro* lista_new();
ePerro* lista_newParametros(char* idCachorro,char* nombre,char* dias,char* raza,char* reservado,char* genero);
void lista_delete(ePerro* this);

int perros_filterMenores45(void* a);
int perros_filterNoMachos(void* a);
int perros_filterCallejeros(void* a);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int perro_setId(ePerro* this,int id);
int perro_getId(ePerro* this,int* id);

int perro_setNombre(ePerro* this,char* nombre);
int perro_getNombre(ePerro* this,char* nombre);

int perro_setDias(ePerro* this,int dias);
int perro_getDias(ePerro* this,int* dias);

int perro_setRaza(ePerro* this,char* raza);
int perro_getRaza(ePerro* this,char* raza);

int perro_setReservado(ePerro* this,char* reservado);
int perro_getReservado(ePerro* this,char* reservado);

int perro_setGenero(ePerro* this,char* genero);
int perro_getGenero(ePerro* this,char* genero);
