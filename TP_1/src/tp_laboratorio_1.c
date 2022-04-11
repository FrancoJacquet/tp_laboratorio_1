/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : Franco Jacquet
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void)
{
	setbuf(stdout,NULL);
	//declaracion de variables
	float kilometrosIngresados;
	float precioAerolineas;
	float precioLatam;
	int menuOpcion;
	int validar;
	char seguir;

	//asignacion de variables
	validar=0;
	kilometrosIngresados=0;
	seguir='s';

	do
	{
		//recibe la opcion de menu
		menuOpcion=CargarMenu(kilometrosIngresados, precioAerolineas, precioLatam);
		switch(menuOpcion)
		{
			case 1:
				//se piden los kilometros
				kilometrosIngresados=PedirDatos("Ingrese kilometros:","Ingrese kilometros validos:");
				break;
			case 2:
				//se piden los precios para Aerolineas y Latam
				precioAerolineas=PedirDatos("Ingrese precio para Aerolineas:","Ingrese un precio valido para Aerolineas:");
				precioLatam=PedirDatos("Ingrese precio para Latam:", "Ingrese un precio valido para Latam:");
				break;
			case 3:
				//se valida si se puede o no calcular los costos
				validar=ValidarDatos(precioAerolineas, precioLatam, kilometrosIngresados);
				break;
			case 4:
				//se informan los datos solo despues de que se puedan calcular
				if(validar==0)
				{
					printf("No se pueden informar los resultados sin calcular los costos antes.\n");
				}
				else
				{
					MostrarDatos(precioAerolineas,precioLatam,kilometrosIngresados);
				}
				break;
			case 5:
				//carga forzada
				kilometrosIngresados=7090;
				precioAerolineas=162965;
				precioLatam=159339;
				MostrarDatos(precioAerolineas,precioLatam,kilometrosIngresados);
				break;
			case 6:
				//salir
				printf("El programa finalizó...");
				system("PAUSE");
				seguir='n';
				break;
		}
	}while(seguir=='s');
	return 0;
}
