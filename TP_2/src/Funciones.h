#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define PASAJEROS 2000

int BuscarLibre(ePassenger lista[], int size);
int GetInt();
int AltaPasajero(ePassenger lista[],int len);
void ValidarCadena(char cadena[], char dato[]);
int validarTexto(char cadena[]);
float FlotantePositivo(char texto[]);
int AutoId();
void PedirTexto(char [], char []);
void PedirAlpha(char [], char []);
int PedirEnteroRango(char texto[],int limiteInferior, int limiteSuperior);
void FormatearCadena(char cadena[]);
void MostrarPasajeros(ePassenger lista[],int len);
int PasajeroPorId(ePassenger lista[], int len,char texto[], eStatus estado[]);
void ModificarPasajero(ePassenger lista[], int len, eStatus estado[]);
void CambiarNombre(ePassenger lista[], int index);
void CambiarApellido(ePassenger lista[], int index);
void CambiarPrecio(ePassenger lista[],int index);
void CambiarTipoPasajero(ePassenger lista[],int index);
void CambiarCodigoVuelo(ePassenger lista[],int index);
int validarNumero(char cadena[]);
void RemoverPasajero(ePassenger lista[], int len,eStatus estado[]);
int HardcodearPasajeros(ePassenger lista[], int len);
void Informar(ePassenger lista[], int len, eStatus estado[]);
int ListarActivos(ePassenger lista[], int len, eStatus estado[]);
void ListarAlfabeticamente(ePassenger lista[], int len, eStatus estado[]);
void ListarPorCode(ePassenger lista[], int len, eStatus estado[]);
float TotalPasajes(ePassenger lista[], int len);
int ContarPasajeros(ePassenger lista[], int len);
int PasajerosMasPromedio(ePassenger lista[],int len);
void TotalPromedioPasajeros(ePassenger lista[], int len);
