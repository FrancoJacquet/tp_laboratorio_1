#include "Funciones.h"

static int idIncremental=0;
/// \brief genera un id automaticamente de manera incremental
/// \return retorna un id
int AutoId()
{
	return idIncremental++;
}
/// \brief pide un entero
/// \return retorna un entero
int GetInt()
{
	int numero;
	scanf("%d",&numero);
	return numero;
}
/// \brief pide texto, lo valida y lo carga en una cadena
/// \param cadena
/// \param texto
void PedirTexto(char cadena[],char texto[])
{
	printf("Ingrese %s: ",texto);
	fflush(stdin);
	gets(cadena);
	ValidarCadena(cadena, texto);
	FormatearCadena(cadena);
}
/// \brief pide una cadena alfanumerica y lo carga en una cadena
/// \param cadena
/// \param texto
void PedirAlpha(char cadena[], char texto[])
{
	printf("Ingrese %s: ",texto);
	fflush(stdin);
	gets(cadena);
}
/// \brief pide una cadena alfanumerica, valida el largo y lo carga en una cadena
/// \param cadena
/// \param texto
/// \param limiteInferior
/// \param limiteSuperior
void PedirAlphaRango(char cadena[], char texto[],int limiteInferior, int limiteSuperior)
{
	int len;
	PedirAlpha(cadena,texto);
	len=strlen(cadena);
	while(len<limiteInferior || len>limiteSuperior)
	{
		PedirAlpha(cadena,texto);
		len=strlen(cadena);
	}
}
/// \brief busca una posicion libre dentro de la lista
/// \param lista
/// \param size
/// \return devuelve como index la posicion del primer lugar libre en lalista
int BuscarLibre(ePassenger lista[], int size)
{
	int index;
	index=-1;

	for(int i=0;i<size;i++)
	{
		if(lista[i].isEmpty==TRUE)
		{
			index=i;
			break;
		}
	}
	return index;
}
/// \brief pide los datos de una pasajero
/// \param lista
/// \param len
/// \return retorna si se pudo realizar la carga o no
int AltaPasajero(ePassenger lista[],int len)
{
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char flycode[10];
	int tipoPasajero;
	int carga;

	id=AutoId();
	PedirTexto(nombre,"nombre");
	PedirTexto(apellido,"apellido");
	precio=FlotantePositivo("precio");
	PedirAlphaRango(flycode,"codigo de vuelo",0,10);
	tipoPasajero=PedirEnteroRango("tipo de pasajero",1,3);

	carga=addPassenger(lista,len,id,nombre,apellido,precio,tipoPasajero,flycode);

	return carga;

}
/// \brief valida que una cadena sea solo texto
/// \param cadena
/// \param dato
void ValidarCadena(char cadena[], char dato[])
{
	int bandera;

	bandera=validarTexto(cadena);

	while(bandera==0)
	{
		printf("Error, ingrese un %s valido: ",dato);
		fflush(stdin);
		gets(cadena);
		bandera=validarTexto(cadena);
	}
}
/// \brief valida que no haya numeros en una cadena
/// \param cadena
/// \return retorna 0 si no encuentra numeros y -1 si hay un numero
int validarTexto(char cadena[])
{
	int validacion;

	for(int i=0;i<strlen(cadena);i++)
	{
		if(isalpha(cadena[i]))
		{
			validacion = -1;
		}
		else
		{
			validacion=0;
			break;
		}
	}
	return validacion;
}
/// \brief pide un numero flotante positivo
/// \param texto
/// \return retorna un numero flotante validado en positivo
float FlotantePositivo(char texto[])
{
	char numero[10];
	float numerof;
	printf("Ingrese %s: ",texto);
	scanf("%s",numero);

	while(numero<0 || validarNumero(numero)==0)
	{
		printf("Error ingrese %s valido: ",texto);
		fflush(stdin);
		scanf("%s",numero);
	}

	numerof=atof(numero);
	return numerof;
}
/// \brief pide un entero dentro de un rango y lo valida
/// \param texto
/// \param limiteInferior
/// \param limiteSuperior
/// \return devuelve un numero entero validado dentro de un rango
int PedirEnteroRango(char texto[],int limiteInferior, int limiteSuperior)
{
	int numero;

	printf("Ingrese %s entre %d y %d: ",texto,limiteInferior,limiteSuperior);
	scanf("%d",&numero);

	while(numero<limiteInferior || numero>limiteSuperior)
	{
		printf("Error. Ingrese %s entre %d y %d",texto,limiteInferior,limiteSuperior);
		scanf("%d",&numero);
	}

	return numero;
}
/// \brief formatea la cadena que recibe para que su primer letra este en mayuscula y lo demas en minuscula
/// \param cadena
void FormatearCadena(char cadena[])
{
	strlwr(cadena);
	cadena[0]=toupper(cadena[0]);
}
/// \brief pide el id de un pasajero
/// \param lista
/// \param len
/// \param texto
/// \param estado
/// \return retorna la id que se ingreso
int PasajeroPorId(ePassenger lista[], int len,char texto[], eStatus estado[])
{
	int id;
	printf("Ingrese el ID del pasajero que desea %s: \n", texto);
	printPassenger(lista, len,estado);
	fflush(stdin);
	scanf("%d",&id);
	return id;
}
/// \brief contiene las modificaciones para el nombre, apellido, precio, tipo de pasajero, codigo de vuelo
/// \param lista
/// \param len
/// \param estado
void ModificarPasajero(ePassenger lista[], int len, eStatus estado[])
{
	int index;
	int opcion;
	int id;
	id=PasajeroPorId(lista, len, "modificar",estado);
	index=findPassengerById(lista, len, id);
	if(index!=-1)
	{
		do
		{
			printf("Que desea modificar del pasajero %s %s?\n",lista[index].name,lista[index].lastName);
			printf("1.Nombre\n");
			printf("2.Apellido\n");
			printf("3.Precio\n");
			printf("4.Tipo de pasajero\n");
			printf("5.Codigo de vuelo\n");
			printf("6.Salir\n");
			scanf("%d",&opcion);
			switch(opcion)
			{
				case 1:
					CambiarNombre(lista,index);
				break;
				case 2:
					CambiarApellido(lista, index);
				break;
				case 3:
					CambiarPrecio(lista,index);
				break;
				case 4:
					CambiarTipoPasajero(lista, index);
				break;
				case 5:
					CambiarCodigoVuelo(lista,index);
				break;
			}
		}while(opcion!=6);
	}
	else
	{
		printf("No se encontro el pasajero.\n");
	}
}
/// \brief cambia el nombre de un pasajero
/// \param lista
/// \param index
void CambiarNombre(ePassenger lista[], int index)
{
	int subOpcion;
	char nombre[51];
	do{
		PedirTexto(nombre,"nuevo nombre");
		printf("Esta seguro de que quiere cambiar el nombre de %s por %s?\n",lista[index].name,nombre);
		printf("1.Si\n");
		printf("2.No\n");
		fflush(stdin);
		scanf("%d",&subOpcion);
    }while(subOpcion!=1 && subOpcion!=2);
	if(subOpcion==1)
	{
		strcpy(lista[index].name,nombre);
		printf("Se modifico el nombre exitosamente.\n");
	}
	else
	{
		printf("No se modifico el nombre.\n");
	}
}
/// \brief cambia el apellido de un pasajero
/// \param lista
/// \param index
void CambiarApellido(ePassenger lista[], int index)
{
	int subOpcion;
	char apellido[51];
	do{
		PedirTexto(apellido,"nuevo apellido");
		printf("Esta seguro de que quiere cambiar el apellido de %s por %s?\n",lista[index].lastName,apellido);
		printf("1.Si\n");
		printf("2.No\n");
		fflush(stdin);
		scanf("%d",&subOpcion);
    }while(subOpcion!=1 && subOpcion!=2);
	if(subOpcion==1)
	{
		strcpy(lista[index].lastName,apellido);
		printf("Se modifico el apellido exitosamente.\n");
	}
	else
	{
		printf("No se modifico el apellido.\n");
	}
}
/// \brief cambia el precio de un pasajero
/// \param lista
/// \param index
void CambiarPrecio(ePassenger lista[],int index)
{
	int subOpcion;
	float precio;
	do{
		precio=FlotantePositivo("nuevo precio");
		printf("Esta seguro de que quiere cambiar el precio de %.2f por %.2f?\n",lista[index].price,precio);
		printf("1.Si\n");
		printf("2.No\n");
		fflush(stdin);
		scanf("%d",&subOpcion);
    }while(subOpcion!=1 && subOpcion!=2);
	if(subOpcion==1)
	{
		lista[index].price=precio;
		printf("Se modifico el precio exitosamente.\n");
	}
	else
	{
		printf("No se modifico el precio.\n");
	}
}
/// \brief cambia el tipo de pasajero
/// \param lista
/// \param index
void CambiarTipoPasajero(ePassenger lista[],int index)
{
	int subOpcion;
	int tipoPasajero;
	do{
		tipoPasajero=PedirEnteroRango("tipo de pasajero",1,3);
		printf("Esta seguro de que quiere cambiar el tipo de pasajero de %d por %d?\n",lista[index].typePassenger,tipoPasajero);
		printf("1.Si\n");
		printf("2.No\n");
		fflush(stdin);
		scanf("%d",&subOpcion);
	}while(subOpcion!=1 && subOpcion!=2);
	if(subOpcion==1)
	{
		lista[index].typePassenger=tipoPasajero;
		printf("Se modifico el tipo de pasajero exitosamente.\n");
	}
	else
	{
		printf("No se modifico el tipo de pasajero.\n");
	}
}
/// \brief cambia el codigo de vuelo de un pasajero
/// \param lista
/// \param index
void CambiarCodigoVuelo(ePassenger lista[],int index)
{
	int subOpcion;
	char codigoVuelo[10];
	do{
		PedirAlphaRango(codigoVuelo,"nuevo codigo de vuelo",0,10);
		printf("Esta seguro de que quiere cambiar el codigo de vuelo de %s por %s?\n",lista[index].flycode,codigoVuelo);
		printf("1.Si\n");
		printf("2.No\n");
		fflush(stdin);
		scanf("%d",&subOpcion);
    }while(subOpcion!=1 && subOpcion!=2);
	if(subOpcion==1)
	{
		strcpy(lista[index].flycode,codigoVuelo);
		printf("Se modifico el codigo de vuelo exitosamente.\n");
	}
	else
	{
		printf("No se modifico el codigo de vuelo.\n");
	}
}
/// \brief valida que un numero no tenga letras
/// \param cadena
/// \return retorna -1 si no se encontraron letras, retorna 0 si encuentra letras
int validarNumero(char cadena[])
{
	int validacion;
	validacion=-1;
	for(int i=0;i<strlen(cadena);i++)
	{
		if(isalpha(cadena[i]))
		{
			validacion = 0;
			break;
		}
	}
	return validacion;
}
/// \brief remueve un pasajero poniendo su estado de isEmpty en TRUE
/// \param lista
/// \param len
/// \param estado
void RemoverPasajero(ePassenger lista[], int len,eStatus estado[])
{
	int index;
	int id;
	int opcion;
	id=PasajeroPorId(lista, len, "eliminar",estado);
	index=findPassengerById(lista, len, id);

	if(index!=-1)
	{
		do{
		printf("Seguro que desea eliminar el pasajero %s %s ID %d?\n",lista[index].name,lista[index].lastName,lista[index].id);
		printf("1.Confirmar\n");
		printf("2.Cancelar\n");
		scanf("%d",&opcion);
		}while(opcion!=1 && opcion!=2);
		if(opcion==1)
		{
			removePassenger(lista, len, id);
			printf("Se elimino el pasajero %s %s ID %d.\n",lista[index].name,lista[index].lastName,lista[index].id);
		}
		else
		{
			printf("No se elimino el pasajero.");
		}
	}
	else
	{
		printf("No se encontro el pasajero.\n");
	}
}
/// \brief realiza los informes de los pasajeros
/// \param lista
/// \param len
/// \param estado
void Informar(ePassenger lista[], int len, eStatus estado[])
{
	int opcion;
	do{
		printf("1.Listado de los pasajeros ordenados alfabeticamente por Apellido y tipo de Pasajero\n");
		printf("2.Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio.\n");
		printf("3.Listado de los pasajeros por codigo de vuelo y estados de vuelo ACTIVO\n");
		printf("4.Salir\n");
		opcion=GetInt();
		switch(opcion)
		{
			case 1:
				ListarAlfabeticamente(lista, len, estado);
				system("PAUSE");
			break;
			case 2:
				TotalPromedioPasajeros(lista, len);
				system("PAUSE");
			break;
			case 3:
				ListarPorCode(lista, len, estado);
				system("PAUSE");
			break;
		}
	}while(opcion!=4);
}
/// \brief ordena y lista los pasajeros alfabeticamente y por estado
/// \param lista
/// \param len
/// \param estado
void ListarAlfabeticamente(ePassenger lista[], int len, eStatus estado[])
{
	sortPassengers(lista, len, 0);
	printPassenger(lista, len, estado);

}
/// \brief hardcodea pasajeros
/// \param lista
/// \param len
/// \return retorna 0 si se realizo la carga -1 si no
int HardcodearPasajeros(ePassenger lista[], int len)
{
	int carga;
	carga=-1;
	ePassenger impostores[10]= {
	        {AutoId(),"Juan", "Roco", 2393111, "IIAK21",1,0,FALSE},
	        {AutoId(),"Daniela", "Cardozo", 2333112, "AASD12",1,0,FALSE},
	        {AutoId(),"Pablo", "Rosales", 322132, "221AAS",1,1,FALSE},
	        {AutoId(),"Mauro", "Iglesias", 1441511, "STDAM2",3,2,FALSE},
	        {AutoId(),"Marco", "Ramon", 154512, "KUR212",2,2,FALSE},
	        {AutoId(),"Carlos", "Tucson", 325411, "FWAR21",1,1,FALSE},
	        {AutoId(),"Laura", "Rojas", 513612, "21AK12",1,2,FALSE},
	        {AutoId(),"Marta", "Perez", 1678211, "TRAL92",2,1,FALSE},
	        {AutoId(),"Carla", "Gutierrez", 41721, "MRH420",3,0,FALSE},
	        {AutoId(),"Nacho", "Marlo", 4771121, "SFDKS12",1,0,FALSE},};

	for(int i=0;i<len;i++)
	{
		if(lista[i].isEmpty==TRUE)
		{
			lista[i]=impostores[i];
			carga=0;
		}

	}
	return carga;
}
/// \brief lista los vuelos activos
/// \param lista
/// \param len
/// \param estado
/// \return retorna -1 si no se puede listar por algun problema y 0 si se realizo con exito
int ListarActivos(ePassenger lista[], int len, eStatus estado[])
{
	int retorno;
	retorno=-1;
	for(int i=0;i<len;i++)
	{
		if(lista[i].isEmpty==FALSE && lista[i].status==0)
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
/// \brief ordena y lista los vuelos activos
/// \param lista
/// \param len
/// \param estado
void ListarPorCode(ePassenger lista[], int len, eStatus estado[])
{
	sortPassengersByCode(lista, len, 0);
	ListarActivos(lista, len, estado);
}
/// \brief suma el total de todos los pasajes
/// \param lista
/// \param len
/// \return retorna el precio total de todos los pasajes
float TotalPasajes(ePassenger lista[], int len)
{
	float total;
	total=0;

	for(int i=0;i<len;i++)
	{
		if(lista[i].isEmpty==FALSE)
		{
			total+=lista[i].price;
		}
	}

	return total;
}
/// \brief cuenta la cantidad de pasajeros
/// \param lista
/// \param len
/// \return retorna la cantidad de pasajeros
int ContarPasajeros(ePassenger lista[], int len)
{
	int pasajeros;
	pasajeros=0;
	for(int i=0;i<len;i++)
	{
		if(lista[i].isEmpty==FALSE)
		{
			pasajeros++;
		}
	}
	return pasajeros;
}
/// \brief realiza el promedio de los precios
/// \param lista
/// \param len
/// \return devuelve el promedio de los precios en funcion a los pasajeros
float PromedioPrecios(ePassenger lista[],int len)
{
	float promedio;
	float totalPrecios;
	int pasajeros;
	totalPrecios=TotalPasajes(lista, len);
	pasajeros=ContarPasajeros(lista, len);
	promedio=totalPrecios/pasajeros;
	return promedio;
}
/// \brief busca los pasajeros que pasen el promedio de los precios
/// \param lista
/// \param len
/// \return retorna la cantidad de pasajeros que pasan el promedio de los precios
int PasajerosMasPromedio(ePassenger lista[],int len)
{
	float promedio;
	int contador;
	contador=0;
	promedio=PromedioPrecios(lista, len);
	for(int i=0;i<len;i++)
	{
		if(lista[i].isEmpty==FALSE && lista[i].price>promedio)
		{
			contador++;
		}
	}
	return contador;
}
/// \brief muestra el total y promedio de los precios y la cantidad de pasajeros que superan el promedio
/// \param lista
/// \param len
void TotalPromedioPasajeros(ePassenger lista[], int len)
{
	float totalPrecios;
	float promedio;
	int masPromedio;
	totalPrecios=TotalPasajes(lista, len);
	promedio=PromedioPrecios(lista, len);
	masPromedio=PasajerosMasPromedio(lista, len);
	printf("El total de los precios es %.2f, el promedio es %.2f y la cantidad de pasajeros que superan el promedio son %d\n",totalPrecios,promedio,masPromedio);
}
