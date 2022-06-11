#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Biblioteca.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
	int retorno;
	int opcion;
	int bandera;
	int banderaSalir;
	int banderaAdd;
	bandera=0;
	banderaSalir=0;
	banderaAdd=0;
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	printf("			-|TRABAJO PRACTICO 3|-			\n");
    	printf("1.Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
    	printf("2.Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
    	printf("3.Alta de pasajero\n");
    	printf("4.Modificar datos de pasajero\n");
    	printf("5.Baja de pasajero\n");
    	printf("6.Listar pasajeros\n");
    	printf("7.Ordenar pasajeros\n");
    	printf("8.Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
    	printf("9.Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n");
    	printf("10.Salir\n");
    	opcion=PedirEntero("Seleccione una opcion");
    	switch(opcion)
    	{
    	    case 1:
    	    	if(bandera!=1)
    	    	{
					retorno=controller_loadFromText("data.csv", listaPasajeros);
					if(retorno==1)
					{
						printf("Carga exitosa.\n");
					}
					else
					{
						printf("Se produjo un error en la carga.\n");
					}
					bandera=1;
    	    	}
    	    	else
    	    	{
    	    		printf("Ya se realizo una carga de datos.\n");
    	    	}
    		break;
    	    case 2:
    	    	if(bandera!=1)
    	    	{
    	    		retorno=controller_loadFromBinary("data.bin", listaPasajeros);
    	    		if(retorno!=1)
    	    		{
    	    			printf("Carga exitosa.\n");
    	    		}
    	    		else
					{
						printf("Se produjo un error en la carga.\n");
					}
    	    		bandera=1;
    	    	}
    	    	else
				{
					printf("Ya se realizo una carga de datos.\n");
				}

    	    break;
    	    case 3:
    	    	retorno=controller_addPassenger(listaPasajeros);
    	    	if(retorno==0)
    	    	{
    	    		printf("Se cargo exitosamente el pasajero.");
    	    		banderaAdd=1;
    	    	}
    	    	else
    	    	{
    	    		printf("No se pudo cargar el pasajero");
    	    	}
    	    break;
    	    case 4:
    	    	retorno=controller_editPassenger(listaPasajeros);
    	    	if(retorno!=0)
    	    	{
    	    		printf("Se realizaron cambios en el pasajero.\n");
    	    	}
    	    	else
    	    	{
    	    		printf("No se realizaron cambios en el pasajero.\n");
    	    	}

    	    break;
    	    case 5:
    	    	retorno=controller_removePassenger(listaPasajeros);
    	    	if(retorno!=-1)
    	    	{
    	    		printf("Se elimino el pasajero\n");
    	    	}
    	    	else
    	    	{
    	    		if(retorno==1)
    	    		{
    	    			printf("No se elimino el pasajero\n");
    	    		}
    	    		else
    	    		{
    	    			printf("No se encontro el pasajero.\n");
    	    		}
    	    	}
    	    break;
    	    case 6:
    	    	retorno=controller_ListPassenger(listaPasajeros);
    	    	if(retorno!=0)
    	    	{
    	    		printf("Se produjo un error al listar.\n");
    	    	}
    	    break;
    	    case 7:
    	    	controller_sortPassenger(listaPasajeros);
    	    break;
    	    case 8:
    	    	if(bandera==1 || banderaAdd==1)
    	    	{
					retorno=controller_saveAsText("data.csv",listaPasajeros);
					if(retorno==1)
					{
						printf("Se realizo el guardado como texto.\n");
					}
					else
					{
						printf("No se realizo el guardado.\n");
					}
					banderaSalir=1;
    	    	}
				else
				{
					printf("No se puede guardar porque no hay datos cargados.\n");
				}
    	    break;
    	    case 9:
    	    	if(bandera==1 || banderaAdd==1)
    	    	{
        	    	retorno=controller_saveAsBinary("data.bin",listaPasajeros);
        	    	if(retorno==1)
        	    	{
        	    		printf("Se realizo el guardado en binario.\n");
        	    	}
        	    	else
        	    	{
        	    		printf("No se realizo el guardado.\n");
        	    	}
        	    	banderaSalir=1;
    	    	}
    	    	else
    	    	{
    	    		printf("No se puede guardar porque no hay datos cargados.\n");
    	    	}
    	    break;
    	    case 10:
    	    	if(banderaSalir!=1)
    	    	{
    	    		printf("No se puede salir sin antes hacer un guardado de datos.\n");
    	    	}
    	    	else
    	    	{
    	    		printf("Fin del programa...\n");
    	    	}
    	    break;
    	    default:
    	    	printf("Seleccione una opcion valida.\n");
    	    break;
    	}
    }while(opcion!=10 || banderaSalir!=1);

    return 0;
}

