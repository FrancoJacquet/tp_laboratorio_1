#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
/// \brief funcion que valida que el valor ingresado no sea cero ni negativo
/// \param valorIngresado
/// \param mensajeError
/// \return retorna el valor que recibe de PedirDatos validado
float ValidarValorIngresado(float valorIngresado, char mensajeError[])
{
	while(valorIngresado<=0)
	{
		printf("Error. %s \n",mensajeError);
		fflush(stdin);
		scanf("%f",&valorIngresado);
	}
	return valorIngresado;
}
/// \brief pide un valor parametrizado, puede ser precio o km dependiendo de lo que se le envie
/// \param mensaje
/// \param mensajeError
/// \return retorna el valor validado por la funcion ValidarValorIngresado
int PedirDatos(char mensaje[], char mensajeError[])
{
	float valor;
	printf("%s\n",mensaje);
	fflush(stdin);
	scanf("%f",&valor);
	//valido el valor ingresado para retornarlo, en el caso de que sea 0 sale el mensaje de error
	valor=ValidarValorIngresado(valor, mensajeError);

	return valor;
}
/// \brief valida que todos los datos esten ingresados
/// \param precioAerolineas
/// \param precioLatam
/// \param kilometros
/// \return retorna 0 si faltan datos o 1 si se pudieron calcular los costos
int ValidarDatos(float precioAerolineas, float precioLatam, float kilometros)
{
	int x;
	if(precioAerolineas==0 || precioLatam==0 || kilometros==0)
	{
		x=0;
		printf("No se pueden calcular los costos porque faltan datos.\n");
	}
	else
	{
		x=1;
		printf("Se calcularon los costos exitosamente.\n");
	}
	return x;
}
/// \brief funcion que calcula los costos mediante parametros
/// \param precio recibe precio
/// \param kilometros recibe los kilometros ingresados
/// \param empresa recibe la empresa a la que pertenece la informacion
void CalcularCostos(float precio, float kilometros, char empresa[])
{
		float debito;
		float credito;
		float bitcoin;
		float preciokm;
		debito = precio - precio * 0.1;
		credito = precio + precio * 0.25;
		bitcoin = precio / 4606955.55;
		preciokm = precio / kilometros;

		printf("Precio %s: $ %.2f\n",empresa, precio);
		printf("a)Tarjeta de debito (descuento 10%%): $ %.2f\n", debito);
		printf("b)Tarjeta de credito (interés 25%%): $ %.2f\n", credito);
		printf("c)Precio pagando con bitcoin: %.3f BTC\n", bitcoin);
		printf("d)Precio unitario por KM: $ %.2f\n\n", preciokm);
}
/// \brief informa los precios
/// \param precioAerolineas recibe el precio aerolineas
/// \param precioLatam	recibe el precio latam
/// \param kilometros recibe los kilometros
void MostrarDatos(float precioAerolineas, float precioLatam, float kilometros)
{
	float diferenciaPrecio;
	system("CLS");
	printf("KMs ingresados: %.2f kms \n \n",kilometros);
	CalcularCostos(precioAerolineas, kilometros, "Aerolineas");
	CalcularCostos(precioLatam, kilometros, "Latam");
	if(precioLatam>precioAerolineas)
	{
		diferenciaPrecio=precioLatam-precioAerolineas;
		printf("La diferencia de precio entre Latam y Aerolineas es de $ %.2f \n",diferenciaPrecio);
	}
	else
	{
		diferenciaPrecio=precioAerolineas-precioLatam;
		printf("La diferencia de precio entre Aerolineas y Latam es de $ %.2f \n",diferenciaPrecio);
	}
	system("PAUSE");
}
/// \brief carga el menu de opciones
/// \param kilometros
/// \param precioAerolineas
/// \param precioLatam
/// \return retorna la opcion seleccionada
int CargarMenu(float kilometros, float precioAerolineas, float precioLatam)
{
	int menuOpcion;
	printf("1. Ingresar Kilometros (km=%.2f) \n",kilometros);
	printf("2. Ingresar precio de Vuelos (Aerolineas:$ %.2f Latam:$ %.2f) \n",precioAerolineas,precioLatam);
	printf("3. Calcular todos los costos\n");
	printf("4. Informar resultados\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n");
	scanf("%d",&menuOpcion);
	return menuOpcion;
}
