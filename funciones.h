#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string.h>
#include <ctype.h>

int verificacionDigito(char *auxCarga, char *mensajeError, int tamanioVector);
int verificacionChar(char *auxCarga, char *mensajeError, int tamanioVector);
int getArrayChar(char* array, char *mensaje, char *mensajeError,int limite);
int getNumero(int numMax, int numMin, int *numero,char *mensaje, char *mensajeError);
int getDni(int *dni);
int getCharNumeros(char* array, char *mensaje, char *mensajeError,int limite);
int getCadena(char* array, char *mensaje, char *mensajeError);
#endif // FUNCIONES_H_INCLUDED
