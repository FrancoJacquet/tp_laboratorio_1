#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	char id[30];
	char name[100];
	char lastname[100];
	char price[100];
	char flycode[100];
	char typePassenger[100];
	char statusFlight[100];
	int retorno;
	retorno= -1;
	Passenger* pasajero;
	//pFile = fopen("data.csv","r"); verificar punteros !=NULL
	while(!feof(pFile))
	{
		retorno = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,name,lastname,price,flycode,typePassenger,statusFlight);
		if(retorno == 7)
		{
			pasajero = Passenger_newParametros(id, name, typePassenger, lastname, price, flycode, statusFlight);
			if(pasajero!=NULL && feof(pFile)==0)
			{
				retorno=ll_add(pArrayListPassenger,pasajero);
			}
		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	retorno=-1;
	Passenger* pasajero;
	while(!feof(pFile))
	{
		pasajero=Passenger_new();
		fread(pasajero, sizeof(Passenger),1,pFile);
		if(pasajero!=NULL && feof(pFile)==0)
		{
			retorno=ll_add(pArrayListPassenger,pasajero);
		}
	}

    return retorno;
}

