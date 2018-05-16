#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Verifica que el array de char contenga solo NUMEROS.
 *
 * \param auxCarga char* Array de char a validar.
 * \param mensajeError char* Mensaje de error a mostrar si se ingresa alguna LETRA.
 * \param tamanioVector int tamaño del array/vector.
 * \return int retorno [0] si no contiene LETRAS. [1] = ERROR.
 *
 */
int verificacionDigito(char *auxCarga, char *mensajeError, int tamanioVector)
{
    int i=0;
    int j=strlen(auxCarga);
    int retorno =1;
    while(i<j-1)
    {
        retorno =1;
        if(isdigit(auxCarga[i])!=0)
        {
            i++;
            retorno =0;
        }
        else
        {
            printf("%s", mensajeError);
            fflush(stdin);
            fgets(auxCarga, tamanioVector, stdin);
            j=strlen(auxCarga);
            i=0;

        }
    }
    return retorno;
}

/** \brief Verifica que el array de char contenga solo LETRAS.
 *
 * \param auxCarga char* Array de char a validar.
 * \param mensajeError char* Mensaje de error a mostrar si se ingresa algun NUMERO.
 * \param tamanioVector int tamaño del array/vector.
 * \return int retorno [0] si no contiene NUMEROS. [1] = ERROR.
 *
 */
int verificacionChar(char *auxCarga, char *mensajeError, int tamanioVector)
{
    int i=0;
    int j=strlen(auxCarga);
    int retorno =1;
    while(i<j-1)
    {
        retorno =1;
        if(!isdigit(auxCarga[i]))
        {
            i++;
            retorno =0;
        }
        else
        {
            printf("%s", mensajeError);
            fflush(stdin);
            fgets(auxCarga, tamanioVector, stdin);
            j=strlen(auxCarga);
            i=0;
        }
    }
    return retorno;
}

/** \brief Valida Array de Char(LETRAS).
 *
 * \param nombre char* Mediante puntero paso array de char.
 * \return int retorno [0] si se cargo el ArrayChar con exito. [1] = ERROR.
 *
 */
int getArrayChar(char* nombre, char *mensaje, char *mensajeError,int limite)
{
    int retorno=1;
    char auxString[limite];
    printf("%s",mensaje);
    fflush(stdin);
    fgets(auxString, limite, stdin);
    if(!verificacionChar(auxString,mensajeError,limite))
    {
            strcpy(nombre, auxString);
            retorno=0;
    }
    return retorno;
}

/** \brief Valida Array de char(NUMEROS).
 *
 * \param nombre char* Mediante puntero paso array de char.
 * \return int retorno [0] si se cargo el Array Char con exito. [1] = ERROR.
 *
 */
int getCharNumeros(char* cuit, char *mensaje, char *mensajeError, int limite)
{
    int retorno=1;
    char auxCuit[limite];
    printf("%s",mensaje);
    fflush(stdin);
    fgets(auxCuit, limite, stdin);
    if(!verificacionDigito(auxCuit,mensajeError,limite))
    {
            strcpy(cuit, auxCuit);
            retorno=0;
    }
    return retorno;
}


/** \brief Obtiene Cadena Alfanumerica
 *
 * \param array char* Mediante puntero pasa texto
 * \param mensaje char* Instruccion usuario
 * \param mensajeError char* Muestra error
 * \return int retorna [0] si se obtuvo cadena, [1] ERROR
 *
 */
int getCadena(char* array, char *mensaje, char *mensajeError)
{
    int retorno=1;
    char auxArray[64];
    printf("%s",mensaje);
    fflush(stdin);
    fgets(auxArray, 64, stdin);

    if(strlen(auxArray)>0 && auxArray!=NULL)
    {
            strcpy(array, auxArray);
            retorno=0;
    }
    else
    {
        printf("%s",mensajeError);
    }

    return retorno;
}

/** \brief Valida NUMERO.
 *
 * \param numMax int Defino NUMERO maximo.
 * \param numMin int Defino NUMERO minima.
 * \param numero int* Mediante puntero paso NUMERO.
 * \return int retorno [0] si se cargo la NUMERO con exito. [1] = ERROR.
 *
 */
int getNumero(int numMax, int numMin, int *numero,char *mensaje, char *mensajeError){
    char auxCharNum[10];
    int retorno=1;
    int auxNum;
    int verificacion=0;
    printf("%s",mensaje);
    fflush(stdin);
    fgets(auxCharNum, 10, stdin);
    if(!verificacionDigito(auxCharNum,mensajeError, 10))
    {
        auxNum = atoi(auxCharNum);

        while(auxNum > numMax || auxNum < numMin || verificacion==1)
        {
            printf("%s",mensajeError);
            fflush(stdin);
            fgets(auxCharNum, 10, stdin);
            verificacion = verificacionDigito(auxCharNum,mensajeError, 10);
            if(!verificacion)
            {
                auxNum = atoi(auxCharNum);
            }
        }
        *numero = auxNum;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida DNI.
 *
 * \param dni int* Mediante puntero devuelve DNI ingresado y validado.
 * \return int retorno [0] si se cargo el DNI con exito. [1] = ERROR.
 *
 */
int getDni(int *dni){

    char auxDni[10];
    int retorno=1;
    int longitudDni=0;
    int verificacion=0;
    printf("\nIngrese DNI: ");
    fflush(stdin);
    fgets(auxDni, 20, stdin);
    if(!verificacionDigito(auxDni,"EL DNI NO CONTIENE LETRAS, REINGRESE DNI VALIDO: ", 20))
    {
        longitudDni = strlen(auxDni);
        while(!(longitudDni == 8 || longitudDni == 9) || verificacion==1)
        {
            printf("\nEl DNI ingresado no es valido. REINGRESE DNI: ");
            fflush(stdin);
            fgets(auxDni, 20, stdin);
            verificacion = verificacionDigito(auxDni,"\nEL DNI NO CONTIENE LETRAS, REINGRESE DNI VALIDO:  ", 20);
            if(!verificacion)
            {
                longitudDni = strlen(auxDni);
            }
        }
        *dni = atoi(auxDni);
        retorno=0;
    }
    return retorno;
}
