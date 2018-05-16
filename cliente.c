#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "funciones.h"

/** \brief INICIALIZO ARRAY CLIENTE (.ISEMPTY =1)
 * \param array Cliente* ARRAY CLIENTE A TRABAJAR
 * \param limite int LIMITE DE ARRAY CLIENTE
 * \return int RETORNO [0] SI SE INICIALIZA CON EXITO [1] ERROR!!!
 *
 */
int cliente_init(Cliente* array,int limite)
{
    int retorno = 1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief ALTA FORAZADA (TESTEAR)
 *
 * \param array Cliente*
 * \param nombre char*
 * \param apellido char*
 * \param cuit char*
 * \param limite int
 * \return int
 *
 */
int cliente_altaForzada(Cliente* array,char* nombre, char* apellido, char* cuit,int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibreCliente(array,limite);
        if(i >= 0)
        {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        strcpy(array[i].apellido,apellido);
                        strcpy(array[i].cuit,cuit);
                        array[i].idCliente = proximoIdCliente();
                        array[i].isEmpty = 0;

        }
    }
    return retorno;
}

/** \brief ALTA CLIENTE (CARGA NUEVO CLIENTE)
 *
 * \param array Cliente* ARRAY CLIENTE A TRABAJAR
 * \param limite int LIMITE ARRAY CLIENTE
 * \return int RETORNA [0] SI SE PRODUCE EL ALTA // [1] ERROR!!
 *
 */
int cliente_alta(Cliente* array,int limite)
{
    int retorno = 1;
    int i;
    char nombre[50],apellido[50],cuit[50];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibreCliente(array,limite);
        if(i >= 0)
        {
            if(!getArrayChar(nombre,"\nIngrese Nombre: ","ERROR, NOMBRE NO CONTIENE NUMEROS: ",50))
            {
                if(!getArrayChar(apellido,"\nIngrese Apellido: ","ERROR, APELLIDO NO CONTIENE NUMEROS: ",50))
                {
                    if(!getCharNumeros(cuit, "Ingrese cuit: ","ERROR, EL CUIT NO CONTIENE LETRAS: ",50))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        strcpy(array[i].apellido,apellido);
                        strcpy(array[i].cuit,cuit);
                        array[i].idCliente = proximoIdCliente();
                        array[i].isEmpty = 0;
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief BAJA CLIENTE (ID = ID CLIENTE -> BAJA)
 *
 * \param array Cliente* ARRAY CLIENTE (A TRABAJAR)
 * \param limiteC int LIMITE ARRAY DE CLIENTE
 * \param id int ID CLIENTE A COMPARAR
 * \return int RETORNA [0] SI SE REALIZA LA BAJA // [1] ERROR!!
 *
 */
int cliente_baja(Cliente* array, int limiteC, int id)
{
    int retorno = 1;
    int i;
    if(limiteC > 0 && array != NULL)
    {
        for(i=0;i<limiteC;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                        array[i].isEmpty = 1;
                        retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief MODIFICA DATOS DE CLIENTE (NOMBRE, APELLIDO, CUIT)
 *
 * \param array Cliente* ARRAY CLIENTE
 * \param limite int LIMITE DE ARRAY CLIENTE
 * \param id int ID USUARIO A COMPARAR
 * \return int RETORNA [0] SI SE REALIZA MODIFICACION CON EXITO [1] ERROR!!
 *
 */
int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = 1;
    int i;
    char nombre[50],apellido[50],cuit[50];
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                if(!getArrayChar(nombre,"\nIngrese Nombre: ","ERROR, NOMBRE NO CONTIENE NUMEROS: ",50))
                {
                    if(!getArrayChar(apellido,"\nIngrese Apellido: ","ERROR, APELLIDO NO CONTIENE NUMEROS: ",50))
                    {
                        if(!getCharNumeros(cuit, "Ingrese cuit: ","ERROR, EL CUIT NO CONTIENE LETRAS: ",50))
                        {
                            retorno = 0;
                            strcpy(array[i].nombre,nombre);
                            strcpy(array[i].apellido,apellido);
                            strcpy(array[i].cuit,cuit);
                        }
                    }
                }

            }
        }
    }
    return retorno;
}

/** \brief BUSCA LUGAR LIBRE DENTRO DEL ARRAY
 *
 * \param array Cliente* ARRAY CLIENTE (A TRABAJAR)
 * \param limite int LIMITE DE ARRAY CLIENTE
 * \return int RETORNA [I] SI ENCUENTRA LUGAR LIBRE
 *
 */
int buscarLugarLibreCliente(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief PROXIMO ID CLIENTE (ID UNICO)
 *
 * \return int RETORNA ID++
 *
 */
int proximoIdCliente()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

/** \brief FUNCION UTILIZADA PARA COMPARAR ID
 *
 * \param array Cliente* ARRAY DE CLIENTE
 * \param limite int LIMITE ARRAY CLIENTE
 * \param id int ID A COMPARAR
 * \return int RETORNA [I] (POSICION EN EL ARRAY) // [1] ERROR!!
 *
 */
int cliente_buscarPorId(Cliente* array,int limite, int id)
{
    int retorno = 1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
