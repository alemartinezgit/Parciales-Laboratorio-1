#include "LinkedList.h"
#include "perros.h"

#ifndef CONTROLER_H_
#define CONTROLER_H_



#endif /* CONTROLER_H_ */

int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);

int controller_List(LinkedList* pArrayList);
int controller_show(ePerro* pElement);

int controller_filterPerros45Dias(LinkedList* pArrayList);
int controller_filterNoMachos(LinkedList* pArrayList);
int controller_printfCallejeros(LinkedList* pArrayList);
