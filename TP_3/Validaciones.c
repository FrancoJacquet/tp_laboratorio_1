#include "Validaciones.h"

void ValidarCadena(char cadena[], char dato[],int limite)
{
	int bandera;

	bandera=ValidarTexto(cadena);

	while(bandera==0 || strlen(cadena)>limite)
	{
		printf("Error, ingrese un %s valido: ",dato);
		fflush(stdin);
		gets(cadena);
		bandera=ValidarTexto(cadena);
	}
}

int ValidarTexto(char cadena[])
{
	int validacion;
	for(int i=0;i<strlen(cadena);i++)
	{
		if(isalpha(cadena[i]) || cadena[i]==' ')
		{
			validacion = 1;
		}
		else
		{
			validacion=0;
			break;
		}
	}
	return validacion;
}

int ValidarNumero(char cadena[])
{
	int validacion;

	for(int i=0;i<strlen(cadena);i++)
	{
		if(isdigit(cadena[i]))
		{
			validacion = 1;
		}
		else
		{
			validacion = 0;
			break;
		}
	}

	return validacion;
}

int ValidarCadenaInt(char numero[],char tipo[],int limiteInferior,int limiteSuperior)
{
	int numeroi;
	numeroi=atoi(numero);
	while(ValidarNumero(numero)==0 || numeroi<limiteInferior || numeroi>limiteSuperior)
	{
		printf("Error. Ingrese %s entre %d y %d: ",tipo,limiteInferior,limiteSuperior);
		scanf("%s",numero);
		numeroi=atoi(numero);
	}
	return numeroi;
}


