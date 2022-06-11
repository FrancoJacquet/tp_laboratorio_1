#include <stdio.h>
#include <stdlib.h>

#include "Biblioteca.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;
	retorno=-1;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile = fopen(path,"r");
		if(pFile!=NULL)
		{
			retorno=parser_PassengerFromText(pFile, pArrayListPassenger);
			ll_sort(pArrayListPassenger,Passenger_sortId,1);
		}
		fclose(pFile);
	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;
	retorno=-1;
	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile = fopen(path,"rb");
		if(pFile!=NULL)
		{
			retorno=parser_PassengerFromBinary(pFile,pArrayListPassenger);
			ll_sort(pArrayListPassenger,Passenger_sortId,1);
		}
		fclose(pFile);
	}

    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	char nombre[51];
	int tipoPasajero;
	char tipoPasajeroStr[51];
	char apellido[51];
	float precio;
	char precioStr[51];
	char codigoVuelo[5];
	int id;
	char idStr[51];
	int statusFlight;
	char statusFlightStr[51];
	retorno=-1;
	if(pArrayListPassenger!=NULL)
	{
		Passenger* pasajero;
		PedirTexto(nombre, "nombre", 51);
		PedirTexto(apellido, "apellido", 51);
		tipoPasajero=PedirEnteroRango("tipo de pasajero", 1, 3);
		itoa(tipoPasajero,tipoPasajeroStr,10);
		precio=FlotantePositivo("precio");
		gcvt(precio,10,precioStr);
		PedirAlpha(codigoVuelo,"codigo de vuelo");
		statusFlight=PedirEnteroRango("estado de vuelo", 1, 3);
		itoa(statusFlight,statusFlightStr,10);
		id=controller_getUltimaId();
		id++;
		itoa(id,idStr,10);
		pasajero=Passenger_newParametros(idStr, nombre, tipoPasajeroStr, apellido, precioStr, codigoVuelo,statusFlightStr);
		if(pasajero!=NULL)
		{
			retorno=ll_add(pArrayListPassenger, pasajero);
			controller_setUltimaId(idStr);
		}
	}

    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int opcion;
	int id;
	int index;
	int subOpcion;
	int retorno;
	char nombre[51];
	char nuevoNombre[51];
	char apellido[51];
	char nuevoApellido[51];
	float precio;
	float nuevoPrecio;
	char codigoVuelo[51];
	char nuevoCodigoVuelo[51];
	int statusFlight;
	int nuevoStatusFlight;
	int tipoPasajero;
	int nuevoTipoPasajero;
	retorno=0;
	Passenger* this;
	controller_ListPassenger(pArrayListPassenger);
	id=PedirEntero("Elija ID del pasajero a editar");
	index=getIndexId(pArrayListPassenger, id);
	retorno=-1;
	if(index!=-1)
	{
		this= (Passenger*) ll_get(pArrayListPassenger, index);
		if(this!=NULL)
		{
			do
			{
				Passenger_getNombre(this, nombre);
				Passenger_getApellido(this, apellido);
				Passenger_getPrecio(this, &precio);
				Passenger_getCodigoVuelo(this, codigoVuelo);
				Passenger_getStatusFlight(this, &statusFlight);
				Passenger_getTipoPasajero(this, &tipoPasajero);
				printf("PASAJERO: %s %s\n",nombre,apellido);
				printf("      EDITAR PASAJERO      \n");
				printf("1.Nombre\n");
				printf("2.Apellido\n");
				printf("3.Precio\n");
				printf("4.Codigo de vuelo\n");
				printf("5.Tipo de pasajero\n");
				printf("6.Estado de vuelo\n");
				printf("7.Salir\n");
				opcion=PedirEntero("Elija una opcion");
				switch(opcion)
				{
					case 1:
						PedirTexto(nuevoNombre,"nuevo nombre", 51);
						printf("Desea cambiar %s por %s?\n",nombre,nuevoNombre);
						printf("1.Si\n");
						printf("2.No\n");
						subOpcion=PedirEntero("Elija un a opcion");
						switch(subOpcion)
						{
							case 1:
								Passenger_setNombre(this, nuevoNombre);
								retorno++;
							break;
							case 2:
								retorno=0;
							break;
						}
					break;
					case 2:
						PedirTexto(nuevoApellido,"nuevo apellido", 51);
						printf("Desea cambiar %s por %s?\n",apellido,nuevoApellido);
						printf("1.Si\n");
						printf("2.No\n");
						subOpcion=PedirEntero("Elija un a opcion");
						switch(subOpcion)
						{
							case 1:
								Passenger_setApellido(this, nuevoApellido);
								retorno++;
							break;
							case 2:
								retorno=0;
							break;
						}
					break;
					case 3:
						nuevoPrecio=FlotantePositivo("nuevo precio");
						printf("Desea cambiar %.2f por %.2f?\n",precio,nuevoPrecio);
						printf("1.Si\n");
						printf("2.No\n");
						subOpcion=PedirEntero("Elija un a opcion");
						switch(subOpcion)
						{
							case 1:
								Passenger_setPrecio(this, nuevoPrecio);
								retorno++;
							break;
							case 2:
								retorno=0;
							break;
						}
					break;
					case 4:
						PedirAlpha(nuevoCodigoVuelo,"nuevo codigo de vuelo");
						printf("Desea cambiar %s por %s?\n",codigoVuelo,nuevoCodigoVuelo);
						printf("1.Si\n");
						printf("2.No\n");
						subOpcion=PedirEntero("Elija un a opcion");
						switch(subOpcion)
						{
							case 1:
								Passenger_setCodigoVuelo(this, nuevoCodigoVuelo);
								retorno++;
							break;
							case 2:
								retorno=0;
							break;
						}
					break;
					case 5:
						nuevoStatusFlight=PedirEnteroRango("nuevo estado de vuelo", 1, 3);
						printf("Desea cambiar %d por %d?\n",statusFlight,nuevoStatusFlight);
						printf("1.Si\n");
						printf("2.No\n");
						subOpcion=PedirEntero("Elija un a opcion");
						switch(subOpcion)
						{
							case 1:
								Passenger_setStatusFlight(this, nuevoStatusFlight);
								retorno++;
							break;
							case 2:
								retorno=0;
							break;
						}
					break;
					case 6:
						nuevoTipoPasajero=PedirEnteroRango("nuevo estado de vuelo", 1, 3);
						printf("Desea cambiar %d por %d?\n",tipoPasajero,nuevoTipoPasajero);
						printf("1.Si\n");
						printf("2.No\n");
						subOpcion=PedirEntero("Elija un a opcion");
						switch(subOpcion)
						{
							case 1:
								Passenger_setTipoPasajero(this, nuevoTipoPasajero);
								retorno++;
							break;
							case 2:
								retorno=0;
							break;
						}
					break;
				}
			}while(opcion!=7);
		}
	}
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int id;
	int index;
	int opcion;
	int retorno;
	char nombre[51];
	char apellido[51];
	Passenger* this;
	controller_ListPassenger(pArrayListPassenger);
	id=PedirEntero("Elija ID del pasajero a eliminar");
	index=getIndexId(pArrayListPassenger, id);
	retorno=-1;
	if(index!=-1)
	{
		this= (Passenger*) ll_get(pArrayListPassenger, index);
		if(this!=NULL)
		{
			do
			{
				Passenger_getNombre(this, nombre);
				Passenger_getApellido(this, apellido);
				printf("Se encontro el pasajero %s %s\n",nombre,apellido);
				printf("Desea eliminarlo?\n");
				printf("1.Si\n");
				printf("2.No\n");
				opcion=PedirEntero("Seleccione una opcion");
				if(opcion==1)
				{
					ll_remove(pArrayListPassenger, index);
					retorno=0;
				}
				else
				{
					retorno=1;
				}
			}while(opcion!=1 && opcion!=2);

		}
	}
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int len;
	int retorno;
	int id;
	char nombre[50];
	char apellido[50];
	char codigoVuelo[6];
	int tipoPasajero;
	int statusFlight;
	float precio;
	Passenger* this;
	retorno=-1;
	len=ll_len(pArrayListPassenger);
	printf("ID   |      NOMBRE     |     APELLIDO    |     PRECIO    | CODIGO VUELO | TIPO PASAJERO	| ESTADO\n");
	printf("--------------------------------------------------------------------------------------------------\n");
	for(int i = 0;i<len;i++)
	{
		this = (Passenger*) ll_get(pArrayListPassenger, i);
		if(Passenger_getId(this, &id) == 0 &&
		   Passenger_getNombre(this, nombre) == 0 &&
		   Passenger_getApellido(this, apellido) == 0 &&
		   Passenger_getCodigoVuelo(this, codigoVuelo) == 0 &&
		   Passenger_getTipoPasajero(this, &tipoPasajero) == 0 &&
		   Passenger_getPrecio(this, &precio) == 0 &&
		   Passenger_getStatusFlight(this, &statusFlight) == 0)
		{
			printf("%4d | %15s | %15s | $%.2f\t |     %4s     |       %d       |    %d\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,statusFlight);
			retorno=0;
		}

	}
	printf("--------------------------------------------------------------------------------------------------\n");
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int bandera;
	int orden;
	int criterio;
	LinkedList* clon = ll_newLinkedList();
	bandera=0;
	do
	{
		printf("Como desea ordenar?\n");
		printf("1.ASCENDENTE\n");
		printf("2.DESCENDENTE\n");
		orden=PedirEntero("Elija una opcion");
		if(orden==1)
		{
			bandera=1;
		}
		else
		{
			if(orden==2)
			{
				orden=0;
				bandera=1;
			}
		}
	}while(bandera==0);
	do
	{
		printf("Por que criterio desea ordenar?\n");
		printf("1.ID\n");
		printf("2.Nombre\n");
		printf("3.Apellido\n");
		printf("4.Precio\n");
		printf("5.Codigo de vuelo\n");
		printf("6.Tipo pasajero\n");
		printf("7.Salir\n");
		criterio=PedirEntero("Seleccione criterio:");
		switch(criterio)
		{
			case 1:
				printf("Ordenando...\n");
				clon=ll_clone(pArrayListPassenger);
				retorno=ll_sort(clon,Passenger_sortId,orden);
				if(retorno==0)
				{
					system("CLS");
					printf("Se ordeno exitosamente.\n");
					controller_ListPassenger(clon);
					ll_deleteLinkedList(clon);
					system("PAUSE");
				}
				else
				{
					printf("No se pudo ordenar.\n");
					ll_deleteLinkedList(clon);
				}
				bandera=0;
			break;
			case 2:
				printf("Ordenando...\n");
				clon=ll_clone(pArrayListPassenger);
				retorno=ll_sort(clon,Passenger_sortNombre,orden);
				if(retorno==0)
				{
					system("CLS");
					printf("Se ordeno exitosamente.\n");
					controller_ListPassenger(clon);
					ll_deleteLinkedList(clon);
					system("PAUSE");
				}
				else
				{
					printf("No se pudo ordenar.\n");
					ll_deleteLinkedList(clon);
				}
				bandera=0;
			break;
			case 3:
				printf("Ordenando...\n");
				clon=ll_clone(pArrayListPassenger);
				retorno=ll_sort(clon,Passenger_sortApellido,orden);
				if(retorno==0)
				{
					system("CLS");
					printf("Se ordeno exitosamente.\n");
					controller_ListPassenger(clon);
					ll_deleteLinkedList(clon);
					system("PAUSE");
				}
				else
				{
					printf("No se pudo ordenar.\n");
					ll_deleteLinkedList(clon);
				}
				bandera=0;
			break;
			case 4:
				printf("Ordenando...\n");
				clon=ll_clone(pArrayListPassenger);
				retorno=ll_sort(clon,Passenger_sortPrecio,orden);
				if(retorno==0)
				{
					system("CLS");
					printf("Se ordeno exitosamente.\n");
					controller_ListPassenger(clon);
					ll_deleteLinkedList(clon);
					system("PAUSE");
				}
				else
				{
					printf("No se pudo ordenar.\n");
					ll_deleteLinkedList(clon);
				}
				bandera=0;
			break;
			case 5:
				printf("Ordenando...\n");
				clon=ll_clone(pArrayListPassenger);
				retorno=ll_sort(clon,Passenger_sortCodigoVuelo,orden);
				if(retorno==0)
				{
					system("CLS");
					printf("Se ordeno exitosamente.\n");
					controller_ListPassenger(clon);
					ll_deleteLinkedList(clon);
					system("PAUSE");
				}
				else
				{
					printf("No se pudo ordenar.\n");
					ll_deleteLinkedList(clon);
				}
				bandera=0;
			break;
			case 6:
				printf("Ordenando...\n");
				clon=ll_clone(pArrayListPassenger);
				retorno=ll_sort(clon,Passenger_sortTipoPasajero,orden);
				if(retorno==0)
				{
					system("CLS");
					printf("Se ordeno exitosamente.\n");
					controller_ListPassenger(clon);
					ll_deleteLinkedList(clon);
					system("PAUSE");
				}
				else
				{
					printf("No se pudo ordenar.\n");
					ll_deleteLinkedList(clon);
				}
				bandera=0;
			break;
			case 7:
				bandera=0;
			break;
		}
	}while(bandera==1);

    return retorno;

}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* this;
	int id;
	char nombre[51];
	char apellido[51];
	char codigoVuelo[51];
	int tipoPasajero;
	float precio;
	int statusFlight;
	int len;
	char idStr[100];
	char tipoStr[100];
	char precioStr[100];
	char statusStr[100];
	len=ll_len(pArrayListPassenger);
	pFile = fopen(path,"w");
	for(int i=0;i<len;i++)
	{
		this = (Passenger*) ll_get(pArrayListPassenger, i);
		if(Passenger_getId(this, &id) == 0 &&
		   Passenger_getNombre(this, nombre) == 0 &&
		   Passenger_getApellido(this, apellido) == 0 &&
		   Passenger_getCodigoVuelo(this, codigoVuelo) == 0 &&
		   Passenger_getTipoPasajero(this, &tipoPasajero) == 0 &&
		   Passenger_getPrecio(this, &precio) == 0 &&
		   Passenger_getStatusFlight(this, &statusFlight) == 0)
		{
			itoa(id,idStr,10);
			itoa(tipoPasajero,tipoStr,10);
			itoa(statusFlight,statusStr,10);
			gcvt(precio,10,precioStr);
			fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n",idStr,nombre,apellido,precioStr,codigoVuelo,tipoStr,statusStr);
		}
	}
	fclose(pFile);

    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	Passenger* this;
	int len;
	len=ll_len(pArrayListPassenger);
	pFile = fopen(path,"wb");
	for(int i=0;i<len;i++)
	{
		this = (Passenger*) ll_get(pArrayListPassenger, i);
		if(this!=NULL)
		{
			fwrite(this, sizeof(Passenger),1,pFile);
		}
	}
	fclose(pFile);
    return 1;
}


