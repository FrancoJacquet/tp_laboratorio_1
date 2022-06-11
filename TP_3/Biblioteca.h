#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "Validaciones.h"
#include "LinkedList.h"

void PedirTexto(char cadena[],char texto[],int limite);
int PedirEnteroRango(char texto[],int limiteInferior, int limiteSuperior);
void FormatearCadena(char cadena[]);
void PedirAlpha(char [], char []);
float FlotantePositivo(char texto[]);
int controller_getUltimaId();
int controller_setUltimaId();
int PedirEntero(char texto[]);
int getIndexId(LinkedList* pArrayListPassenger, int id);

