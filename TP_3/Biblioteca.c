#include "Biblioteca.h"
/// \brief pide texto y lo pone en la cadena que recibe
/// \param cadena
/// \param texto
/// \param limite indica el limite de la cadena
void PedirTexto(char cadena[],char texto[],int limite)
{
	printf("Ingrese %s: ",texto);
	fflush(stdin);
	gets(cadena);
	ValidarCadena(cadena, texto,limite);
	FormatearCadena(cadena);
}
/// \brief formatea la cadena para que su primer letra sea mayuscula y las demas minusculas
/// \param cadena
void FormatearCadena(char cadena[])
{
	strlwr(cadena);
	cadena[0]=toupper(cadena[0]);
}
/// \brief pide entero dentro de un rango y lo valida
/// \param texto
/// \param limiteInferior
/// \param limiteSuperior
/// \return retorna el numero entero
int PedirEnteroRango(char texto[],int limiteInferior, int limiteSuperior)
{
	char numero[15];
	int numeroi;

	printf("Ingrese %s:",texto);
	scanf("%s",numero);
	numeroi=ValidarCadenaInt(numero,texto,limiteInferior,limiteSuperior);

	return numeroi;
}
/// \brief pide un alfanumerico
/// \param cadena recibe la cadena en la que se pone el alfa
/// \param texto
void PedirAlpha(char cadena[], char texto[])
{
	printf("Ingrese %s: ",texto);
	fflush(stdin);
	gets(cadena);
}
/// \brief pide un flotante positivo y lo valida
/// \param texto
/// \return retorna el flotante validado que se ingreso
float FlotantePositivo(char texto[])
{
	char numero[10];
	float numerof;
	printf("Ingrese %s: ",texto);
	scanf("%s",numero);

	while(numero<0 || ValidarNumero(numero)==0)
	{
		printf("Error ingrese %s valido: ",texto);
		fflush(stdin);
		scanf("%s",numero);
	}

	numerof=atof(numero);
	return numerof;
}
/// \brief setea la ultima id que se asigno dentro de un archivo
/// \param ultimaIdStr
/// \return retorna -1 si recibio una id vacia o 0 si pudo hacerlo
int controller_setUltimaId(char* ultimaIdStr)
{
	int retorno;
	FILE* pFile;
	retorno=-1;
	if(ultimaIdStr!=NULL)
	{
		pFile = fopen("ultimaId.csv","w");
		fprintf(pFile,"%s",ultimaIdStr);
		printf("%s",ultimaIdStr);
		fclose(pFile);
		retorno=0;
	}
	return retorno;
}
/// \brief consigue la ultima id que se guardo en el archivo
/// \return retorna la ultima id que se guardo
int controller_getUltimaId()
{
	FILE* pFile;
	int ultimaId;
	char ultimaIdStr[51];
	pFile = fopen("ultimaId.csv","r");
	fscanf(pFile,"%[^\n] ",ultimaIdStr);
	ultimaId=atoi(ultimaIdStr);
	fclose(pFile);
	return ultimaId;
}
/// \brief pide un entero
/// \param texto
/// \return retorna un entero
int PedirEntero(char texto[])
{
	int numero;
	printf("%s: \n",texto);
	scanf("%d",&numero);
	return numero;
}
/// \brief consigue el index de un pasajero por su id
/// \param pArrayListPassenger
/// \param id
/// \return retorna el index si se encontro o -1 si no encuentra el id
int getIndexId(LinkedList* pArrayListPassenger, int id)
{
	int index;
	int idBusqueda;
	int len;
	Passenger* this;
	len=ll_len(pArrayListPassenger);
	index=-1;
	for(int i=0;i<len;i++)
	{
		this=(Passenger*) ll_get(pArrayListPassenger, i);
		Passenger_getId(this, &idBusqueda);
		if(idBusqueda==id)
		{
			index=i;
			break;
		}
	}

	return index;
}
//fprintf(pFile,"%s",ultimaIdStr);
