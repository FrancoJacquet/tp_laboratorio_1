/*
 ============================================================================
 Name        : TP2.c
 Author      : Franco Jacquet
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void) {
	setbuf(stdout,NULL);
	eStatus estado[3]={{0,"ACTIVO"},{1,"DEMORADO"},{2,"INACTIVO"}};
	ePassenger lista[PASAJEROS];
	int opcion;
	int bandera;
	bandera=1;
	initPassangers(lista,PASAJEROS);
	printf("------ ABM AEROLINEAS ------\n");
	while(bandera!=-1)
	{
		if(bandera!=0 && bandera!=-1)
		{
			do
			{
				printf("1.ALTA\n");
				printf("2.HARDCODE\n");
				printf("3.SALIR\n");
				opcion=GetInt();
				switch(opcion)
				{
					case 1:
						bandera=AltaPasajero(lista,PASAJEROS);
					break;
					case 2:
						bandera=HardcodearPasajeros(lista,5);
					break;
					case 3:
						printf("FIN DEL PROGRAMA.\n");
						system("PAUSE");
						bandera=-1;
					break;
				}
			}while(opcion!=3 && bandera!=0);
		}
		else
		{
			if(bandera==0)
			{
				do
				{
					printf("1.ALTA\n");
					printf("2.MODIFICAR\n");
					printf("3.BAJA\n");
					printf("4.INFORMAR\n");
					printf("5.HARDCODE\n");
					printf("6.SALIR\n");
					opcion=GetInt();
					switch(opcion)
					{
						case 1:
							bandera=AltaPasajero(lista,PASAJEROS);
						break;
						case 2:
							ModificarPasajero(lista, PASAJEROS,estado);
						break;
						case 3:
							RemoverPasajero(lista, PASAJEROS,estado);
						break;
						case 4:
							Informar(lista, PASAJEROS,estado);
						break;
						case 5:
							printPassenger(lista, PASAJEROS, estado);
						break;
						case 6:
							printf("FIN DEL PROGRAMA.\n");
							system("PAUSE");
							bandera=-1;
						break;
					}
				}while(opcion!=6);
			}
		}
	}

	return 0;
}
