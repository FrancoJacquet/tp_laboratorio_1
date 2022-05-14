#define TRUE 1
#define FALSE 0
#include "ctype.h"
#include "string.h"

typedef struct{
	int id;
	char estado[25];
}eStatus;

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int status;
	int isEmpty;
}ePassenger;

int initPassangers(ePassenger list[], int len);
int addPassenger(ePassenger list[], int len, int id, char name[], char lastName[], float price,int typePassenger, char flycode[]);
int findPassengerById(ePassenger list[], int len, int id);
int printPassenger(ePassenger lista[], int len, eStatus estado[]);
int removePassenger(ePassenger list[], int len, int id);
int sortPassengers(ePassenger list[], int len, int order);
int sortPassengersByCode(ePassenger lista[], int len, int order);
