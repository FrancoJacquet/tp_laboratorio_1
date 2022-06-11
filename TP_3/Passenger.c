#include "Passenger.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/// \brief crea un pasajero con espacio en memoria
/// \return retorna un pasajero creado;
Passenger* Passenger_new()
{
	Passenger* pasajero;
	pasajero = (Passenger*) malloc(sizeof(Passenger));
	return pasajero;
}
/// \brief crea un pasajero con sus datos en memoria
/// \param idStr
/// \param nombreStr
/// \param tipoPasajeroStr
/// \param apellidoStr
/// \param precioStr
/// \param codigoVueloStr
/// \param statusFlightStr
/// \return retorna un pasajero con datos cargados o Nulo si hubo un error al cargarle llos datos
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellidoStr,char* precioStr, char* codigoVueloStr, char* statusFlightStr)
{
	Passenger* this;
	int idPasajero;
	int tipoPasajero;
	int statusFlight;
	float precioAux;

	this = Passenger_new();

	if(this!=NULL)
	{

		idPasajero = atoi(idStr);
		precioAux = atof(precioStr);
		statusFlight = atoi(statusFlightStr);
		tipoPasajero = atoi(tipoPasajeroStr);
		if(Passenger_setId(this,idPasajero) == -1 ||
		   Passenger_setNombre(this,nombreStr) == -1 ||
		   Passenger_setTipoPasajero(this,tipoPasajero) == -1 ||
		   Passenger_setApellido(this,apellidoStr) == -1 ||
		   Passenger_setPrecio(this,precioAux) == -1 ||
		   Passenger_setCodigoVuelo(this, codigoVueloStr) == -1 ||
		   Passenger_setStatusFlight(this, statusFlight) == -1)
		{
			Passenger_delete(this);
			this=NULL;
		}
	}

	return this;
}
/// \brief libera el espacio en memoria de un pasajero
/// \param pasajero
void Passenger_delete(Passenger* pasajero)
{
	if(pasajero!=NULL)
	{
		free(pasajero);
	}
}
/// \brief setea el id en un pasajero
/// \param this
/// \param id
/// \return retorna 0 si se pudo setear
int Passenger_setId(Passenger* this,int id)
{
	int allOk;
	allOk = -1;
	if(this!=NULL)
	{
		this->id = id;
		allOk = 0;
	}
	return allOk;
}
/// \brief consigue el id de un pasajero
/// \param this
/// \param id
/// \return retorna 0 si pudo acceder al pasajero o -1 si no
int Passenger_getId(Passenger* this,int* id)
{
	int allOk;
	allOk = -1;
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		allOk = 0;
	}
	return allOk;
}
/// \brief setea un nombre en un pasajero
/// \param this
/// \param nombre
/// \return retorna 0 si pudo -1 si no
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int allOk;
	allOk = -1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		allOk = 0;
	}
	return allOk;
}
/// \brief consigue el nombre de un pasajero
/// \param this
/// \param nombre
/// \return retorna 0 si pudo -1 si no
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int allOk;
	allOk = -1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		allOk = 0;
	}
	return allOk;
}
/// \brief setea el apellido de un pasajero
/// \param this
/// \param apellido
/// \return retorna 0 si pudo -1 si no
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int allOk;
	allOk = -1;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido,apellido);
		allOk = 0;
	}
	return allOk;
}
/// \brief consigue el apellido de un pasajero
/// \param this
/// \param apellido
/// \return retorna 0 si pudo -1 si no
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int allOk;
	allOk = -1;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido,this->apellido);
		allOk = 0;
	}
	return allOk;
}
/// \brief setea el codigo de vuelo de un pasajero
/// \param this
/// \param codigoVuelo
/// \return retorna 0 si pudo -1 si no
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int allOk;
	allOk = -1;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		allOk = 0;
	}
	return allOk;
}
/// \brief consigue el codigo de vuelo de un pasajero
/// \param this
/// \param codigoVuelo
/// \return retorna 0 si pudo -1 si no
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int allOk;
	allOk = -1;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		allOk = 0;
	}
	return allOk;
}
/// \brief setea el tipo de un pasajero
/// \param this
/// \param tipoPasajero
/// \return retorna 0 si pudo -1 si no
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int allOk;
	allOk = -1;
	if(this!=NULL)
	{
		this->tipoPasajero = tipoPasajero;
		allOk = 0;
	}
	return allOk;
}
/// \brief consigue el tipo de un pasajero
/// \param this
/// \param tipoPasajero
/// \return retorna 0 si pudo -1 si no
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int allOk;
	allOk = -1;
	if(this!=NULL && tipoPasajero!=NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		allOk = 0;
	}
	return allOk;
}
/// \brief setea el precio dentro de un pasajero
/// \param this
/// \param precio
/// \return retorna 0 si pudo -1 si no
int Passenger_setPrecio(Passenger* this,float precio)
{
	int allOk;
	allOk = -1;
	if(this!=NULL)
	{
		this->precio = precio;
		allOk = 0;
	}
	return allOk;
}
/// \brief consigue el precio de un pasajero
/// \param this
/// \param precio
/// \return retorna 0 si pudo -1 si no
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int allOk;
	allOk = -1;
	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		allOk = 0;
	}
	return allOk;
}
/// \brief setea el estado de vuelo de un pasajero
/// \param this
/// \param status
/// \return retorna 0 si pudo -1 si no
int Passenger_setStatusFlight(Passenger* this,int status)
{
	int allOk;
	allOk = -1;
	if(this!=NULL)
	{
		this->statusFlight = status;
		allOk = 0;
	}
	return allOk;
}
/// \brief consigue el estado de vuelo de un pasajero
/// \param this
/// \param status
/// \return retorna 0 si pudo -1 si no
int Passenger_getStatusFlight(Passenger* this,int* status)
{
	int allOk;
	allOk = -1;
	if(this!=NULL && status!=NULL)
	{
		*status = this->statusFlight;
		allOk = 0;
	}
	return allOk;
}
/// \brief determina si un precio es mayor que el otro
/// \param elemento1
/// \param elemento2
/// \return retorna 0 si son iguales, 1 si el primero es mayor que el segundo o -1 si el primero es menor
/// que el segundo
int Passenger_sortPrecio(void* elemento1, void* elemento2)
{

	int retorno;
	Passenger* p1;
	Passenger* p2;
	float precio1;
	float precio2;

	retorno = 0;

	p1=(Passenger*)elemento1;
	p2=(Passenger*)elemento2;

	if(Passenger_getPrecio(p1, &precio1)==0 &&
	   Passenger_getPrecio(p2, &precio2)==0)
	{
		if(precio1>precio2)
		{
			retorno=1;
		}
		else
		{
			if(precio2>precio1)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}
/// \brief determina si un nombre es mayor que otro
/// \param elemento1
/// \param elemento2
/// \return retorna 0 si son iguales, 1 si el primero es mayor que el segundo o -1 si el primero es menor
/// que el segundo
int Passenger_sortNombre(void* elemento1, void* elemento2)
{
	int retorno;
	Passenger* p1;
	Passenger* p2;
	char nombre1[51];
	char nombre2[51];

	retorno = 0;

	p1=(Passenger*)elemento1;
	p2=(Passenger*)elemento2;

	if(Passenger_getNombre(p1, nombre1)==0 &&
	   Passenger_getNombre(p2, nombre2)==0)
	{

		if(strcmp(nombre1,nombre2)>0)
		{
			retorno=1;
		}
		else
		{
			if(strcmp(nombre2,nombre1)>0)
			{
				retorno=-1;
			}
		}

	}
	return retorno;
}
/// \brief determina si un apellido es mayor que el otro
/// \param elemento1
/// \param elemento2
/// \return retorna 0 si son iguales, 1 si el primero es mayor que el segundo o -1 si el primero es menor
/// que el segundo
int Passenger_sortApellido(void* elemento1, void* elemento2)
{
	int retorno;
	Passenger* p1;
	Passenger* p2;
	char apellido1[51];
	char apellido2[51];

	retorno = 0;

	p1=(Passenger*)elemento1;
	p2=(Passenger*)elemento2;

	if(Passenger_getApellido(p1, apellido1)==0 &&
	   Passenger_getApellido(p2, apellido2)==0)
	{

		if(strcmp(apellido1,apellido2)>0)
		{
			retorno=1;
		}
		else
		{
			if(strcmp(apellido1,apellido2)>0)
			{
				retorno=-1;
			}
		}

	}
	return retorno;
}
/// \brief determina si una id es mayor que la otra
/// \param elemento1
/// \param elemento2
/// \return retorna 0 si son iguales, 1 si el primero es mayor que el segundo o -1 si el primero es menor
/// que el segundo
int Passenger_sortId(void* elemento1, void* elemento2)
{
	int retorno;
	Passenger* p1;
	Passenger* p2;
	int id1;
	int id2;

	retorno = 0;

	p1=(Passenger*)elemento1;
	p2=(Passenger*)elemento2;

	if(Passenger_getId(p1, &id1)==0 &&
	   Passenger_getId(p2, &id2)==0)
	{
		if(id1>id2)
		{
			retorno=1;
		}
		else
		{
			if(id2>id1)
			{
				retorno=-1;
			}
		}
	}

	return retorno;
}
/// \brief determina si un tipo de pasajero es mayor que el otro
/// \param elemento1
/// \param elemento2
/// \return retorna 0 si son iguales, 1 si el primero es mayor que el segundo o -1 si el primero es menor
/// que el segundo
int Passenger_sortTipoPasajero(void* elemento1, void* elemento2)
{
	int retorno;
	Passenger* p1;
	Passenger* p2;
	int tipo1;
	int tipo2;

	retorno = 0;

	p1=(Passenger*)elemento1;
	p2=(Passenger*)elemento2;

	if(Passenger_getTipoPasajero(p1,&tipo1)==0 &&
	   Passenger_getTipoPasajero(p2,&tipo2)==0)
	{
		if(tipo1>tipo2)
		{
			retorno=1;
		}
		else
		{
			if(tipo2>tipo1)
			{
				retorno=-1;
			}
		}
	}

	return retorno;
}
/// \brief determina si un codigo de vuelo es mayor que el otro
/// \param elemento1
/// \param elemento2
/// \return retorna 0 si son iguales, 1 si el primero es mayor que el segundo o -1 si el primero es menor
/// que el segundo
int Passenger_sortCodigoVuelo(void* elemento1, void* elemento2)
{
	int retorno;
	Passenger* p1;
	Passenger* p2;
	char codigo1[6];
	char codigo2[6];

	retorno = 0;

	p1=(Passenger*)elemento1;
	p2=(Passenger*)elemento2;

	if(Passenger_getCodigoVuelo(p1, codigo1)==0 &&
	   Passenger_getCodigoVuelo(p2, codigo2)==0)
	{

		if(strcmp(codigo1,codigo2)>0)
		{
			retorno=1;
		}
		else
		{
			if(strcmp(codigo2,codigo1)>0)
			{
				retorno=-1;
			}
		}

	}
	return retorno;
}
