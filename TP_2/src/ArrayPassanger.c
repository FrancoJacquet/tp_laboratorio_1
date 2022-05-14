#include "Funciones.h"
/// \brief inicializa la bandera isEmpty como TRUE en todas las posiciones del array
/// \param list
/// \param len
/// \return retorna -1 si hay un error o 0 si esta todo ok
int initPassangers(ePassenger list[], int len)
{
	int retorno;
	retorno=-1;
	for(int i=0;i<len;i++)
	{
		list[i].isEmpty=TRUE;
		retorno=0;
	}
	return retorno;
}
/// \brief agrega un pasajero con los parametros recibidos en la lista de pasajeros en la primer posicion libre
/// \param list
/// \param len
/// \param id
/// \param name
/// \param lastName
/// \param price
/// \param typePassenger
/// \param flycode
/// \return retorna -1 si hay un error o 0 si la carga se realizo correctamente
int addPassenger(ePassenger list[], int len, int id, char name[], char lastName[], float price,int typePassenger, char flycode[])
{
	int index;
	int carga;
	index=BuscarLibre(list, len);
	if(index!=-1)
	{
		list[index].id=id;
		strcpy(list[index].name,name);
		strcpy(list[index].lastName,lastName);
		list[index].price=price;
		strcpy(list[index].flycode,flycode);
		list[index].typePassenger=typePassenger;
		list[index].status=rand()%3;
		list[index].isEmpty=FALSE;
		carga=0;
	}
	else
	{
		carga=index;
	}
	return carga;
}
/// \brief busca un pasajero por id
/// \param list
/// \param len
/// \param id
/// \return retorna el index en posicion -1 o la posicion libre del array
int findPassengerById(ePassenger list[], int len, int id)
{
	int index;
	index=-1;
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty==FALSE && list[i].id==id)
		{
			index=i;
			break;
		}
	}
	return index;
}
/// \brief remueve un pasajero pasandole el ID
/// \param list
/// \param len
/// \param id
/// \return retorna -1 si hay un error o 0 si esta todo ok
int removePassenger(ePassenger list[], int len, int id)
{
	int retorno;
	retorno=-1;

	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty==FALSE && list[i].id==id)
		{
			list[i].isEmpty=TRUE;
			retorno=0;
		}
	}

	return retorno;
}
/// \brief ordena los elementos en el array de pasajeros, el argumento indica si es ascendente o descendente
/// \param lista
/// \param len
/// \param order 1 si es creciente o 0 decreciente
/// \return retorna -1 si da error o 0 si esta todo ok
int sortPassengers(ePassenger lista[], int len, int order)
{
	int retorno;
	ePassenger aux;
	retorno=-1;
	if(order==0)
	{
		retorno=0;
		for(int i=0;i<len-1;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				if(strcmp(lista[i].lastName,lista[j].lastName)>0)
				{
					aux=lista[i];
					lista[i]=lista[j];
					lista[j]=aux;
				}
				else
				{
					if(strcmp(lista[i].lastName,lista[j].lastName)==0)
					{
						if(lista[i].typePassenger > lista[j].typePassenger)
						{
							aux=lista[i];
							lista[i]=lista[j];
							lista[j]=aux;
						}
					}
				}
			}
		}
	}
	else
	{
		if(order==1)
		{
			retorno=0;
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmp(lista[i].lastName,lista[j].lastName)<0)
					{
						aux=lista[i];
						lista[i]=lista[j];
						lista[j]=aux;
					}
					else
					{
						if(strcmp(lista[i].lastName,lista[j].lastName)==0)
						{
							if(lista[i].typePassenger < lista[j].typePassenger)
							{
								aux=lista[i];
								lista[i]=lista[j];
								lista[j]=aux;
							}
						}
					}
				}
			}
		}
	}

	return retorno;
}
/// \brief imprime el array de pasajeros de forma encolumnada
/// \param lista
/// \param len
/// \param estado
/// \return retorna -1 si no puede listar o 0 si esta todo ok
int printPassenger(ePassenger lista[], int len, eStatus estado[])
{
	int retorno;
	retorno=-1;
	for(int i=0;i<len;i++)
	{
		if(lista[i].isEmpty==FALSE)
		{
			printf("%.2d | %10s | %10s | %10.2f  | \t%10s | %2d | %10s\n",lista[i].id,
											  	  	  	  	  	  	  	  lista[i].name,
																		  lista[i].lastName,
																		  lista[i].price,
																		  lista[i].flycode,
																		  lista[i].typePassenger,
																		  estado[lista[i].status].estado);
			retorno=0;
		}
	}
	return retorno;
}
/// \brief ordena los pasajeros por codigo de vuelo y estado de vuelo de manera descendente o ascendente
/// \param lista
/// \param len
/// \param order 1 si es creciente o 0 decreciente
/// \return retorna -1 si da error o 0 si esta todo ok
int sortPassengersByCode(ePassenger lista[], int len, int order)
{
	int retorno;
	ePassenger aux;
	retorno=-1;
	if(order==0)
	{
		retorno=0;
		for(int i=0;i<len-1;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				if(strcmp(lista[i].flycode,lista[j].flycode)>0)
				{
					aux=lista[i];
					lista[i]=lista[j];
					lista[j]=aux;
				}
				else
				{
					if(strcmp(lista[i].flycode,lista[j].flycode)==0)
					{
						if(lista[i].status > lista[j].status)
						{
							aux=lista[i];
							lista[i]=lista[j];
							lista[j]=aux;
						}
					}
				}
			}
		}
	}
	else
	{
		if(order==1)
		{
			retorno=0;
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmp(lista[i].flycode,lista[j].flycode)<0)
					{
						aux=lista[i];
						lista[i]=lista[j];
						lista[j]=aux;
					}
					else
					{
						if(strcmp(lista[i].flycode,lista[j].flycode)==0)
						{
							if(lista[i].status < lista[j].status)
							{
								aux=lista[i];
								lista[i]=lista[j];
								lista[j]=aux;
							}
						}
					}
				}
			}
		}
	}

	return retorno;
}

