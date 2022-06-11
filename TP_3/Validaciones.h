#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
/// \brief valida que una cadena sea texto y no se pase del limite
/// \param cadena
/// \param dato
/// \param limite recibe el limite por parametro
void ValidarCadena(char cadena[], char dato[],int);

/// \brief valida que todas las posiciones sean texto
/// \param cadena
/// \return retorna 1 si esta todo ok, retorna 0 y se corta cuando encuentra un numero o caracter
int ValidarTexto(char cadena[]);

/// \brief valida que una cadena sea solo numerica
/// \param cadena
/// \return retorna 1 si esta todo ok, retorna 0 y se corta cuando encuentra una letra o caracter
int ValidarNumero(char cadena[]);

/// \brief valida una cadena de enteros dentro de un rango y la devuelve como entero
/// \param numero
/// \param tipo
/// \param limiteInferior recibe limte inferior
/// \param limiteSuperior recibe limite superior
/// \return retorna un numero que se pidio como cadena en entero
int ValidarCadenaInt(char numero[],char tipo[],int limiteInferior,int limiteSuperior);

