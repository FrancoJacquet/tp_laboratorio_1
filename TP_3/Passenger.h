/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#define VACIO 0

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[6];
	int statusFlight;
}Passenger;
//primero los constructores, despues getters y setters -> despues programar el parser -> despues los controladores
Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellidoStr,char* precioStr, char* codigoVueloStr, char* statusFlightStr);
void Passenger_delete(Passenger* pasajero);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setStatusFlight(Passenger* this,int status);
int Passenger_getStatusFlight(Passenger* this,int* status);

int Passenger_sortPrecio(void* , void*);
int Passenger_sortNombre(void* , void*);
int Passenger_sortApellido(void* , void*);
int Passenger_sortId(void* , void*);
int Passenger_sortTipoPasajero(void* , void*);
int Passenger_sortCodigoVuelo(void* , void*);

#endif /* PASSENGER_H_ */
