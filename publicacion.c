#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"
#include "cliente.h"
#include "publicacion.h"

/** \brief INCIALIZA ARRAY PUBLICACIONES
 * \param array Publicacion* ARRAY A TRABAJAR
 * \param limite int LIMITE DE ARRAY
 * \return int RETORNA [0] SI SE INICIALIZO CON EXITO
 *
 */
int publicacion_init(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
            array[i].estado=-1;
            array[i].rubro=-1;
        }
    }
    return retorno;
}

/** \brief IMPRIME PUBLICACIONES CLIENTE SI ID = IDCLIENTE IMPRIMO.
 *
 * \param array Publicacion* ARRAY DE PUBLICACIONES TRABAJAR
 * \param id int ID A COMPARAR
 * \param limite int LIMITE ARRAY PUBLICACIONES
 * \return int RETORNO [0] SI SE REALIZO IMP CON EXITO, [1] ERROR!!
 *
 */
int publicacion_mostrar(Publicacion* array,int id,int limite)
{
    int retorno = 1;
    int i;
    if(limite > 0 && array != NULL)
    {

        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty&&array[i].idCliente==id)
            {
                printf("\nDESCRIPCION: %s RUBRO: %d ID PUBLICACION: %d ESTADO: %d - EMPTY: %d\n",array[i].texto,array[i].rubro, array[i].idPublicacion, array[i].estado, array[i].isEmpty);
                retorno = 0;
            }

        }
    }
    return retorno;
}

/** \brief ALTA PUBLICACION AVISO
 *
 * \param array Publicacion* ARRAY DE PUBLICACIONES TRABAJAR
 * \param arrayCliente Cliente* ARRAY DE CLIENTES TRABAJAR
 * \param limiteA int LIMITE DE ARRAY PUBLICACIONES
 * \param limiteC int LIMITE DE ARRAY CLIENTE
 * \return int RETORNO [0] SI EL ALTA SE REALIZO CON EXITO [1] ERROR EN CARGA.
 *
 */
int publicacion_alta(Publicacion* array,Cliente* arrayCliente,int limiteA,int limiteC)
{
    int retorno = -1;
    int i,rubro,idAux,idAuxResultado;
    char texto[50];
    if(limiteA > 0 && limiteC > 0 && array != NULL && arrayCliente != NULL)
    {
        getNumero(100,0,&idAux,"Ingrese ID Usuario: ","\nID INVALIDO: ");
        idAuxResultado = cliente_buscarPorId(arrayCliente,limiteC,idAux);
        i = buscarLugarLibrePublicacion(array,limiteA);
        if(i >= 0 && idAuxResultado >=0)
        {
            if(!getCadena(texto,"Ingrese descripcion publicacion: ","ERROR!!"))
            {
                if(!getNumero(20,1,&rubro,"Ingrese rubro producto: ","ERROR!!!"))
                {
                    retorno = 0;
                    strcpy(array[i].texto,texto);
                    array[i].idCliente = idAuxResultado;
                    array[i].idPublicacion = proximoIdPublicacion();
                    array[i].isEmpty = 0;
                    array[i].estado=0;
                    printf("Publicacion grabada con exito!! El id es: %d\n", array[i].idPublicacion);
                }
            }
        }
    }
    return retorno;
}


/** \brief BAJA DE PUBLICACIONES (AVISOS)
 *
 * \param array Publicacion* ARRAY DE PUBLICACIONES TRABAJAR
 * \param limite int LIMITE DE ARRAY PUBLICACIONES
 * \param idCliente int ID A COMPARAR
 * \return int RETORNO [0] SI EL BAJA SE REALIZO CON EXITO [-1] ERROR EN BAJA.
 *
 */
int publicacion_baja(Publicacion* array,int limite, int idCliente)
{
    int retorno = -1;
    int i;
    char borrar;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==idCliente)
            {
                borrar=getChar("\nConfirmar baja <S/N>");
                if(borrar=='s')
                {
                    array[i].isEmpty = 1;
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

/** \brief BUSCAR LUGAR LIBRE EN ARRAY
 *
 * \param array Publicacion* ARRAY DE PUBLICACIONES TRABAJAR
 * \param limite int LIMITE DE ARRAY PUBLICACIONES
 * \return int RETORNO [I] SI ENCUENTRA LUGAR EN EL ARRAY
 *
 */
int buscarLugarLibrePublicacion(Publicacion* array,int limite)
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

/** \brief PROXIMO ID
 *
 * \return int RETORNA ID UNICO
 *
 */
int proximoIdPublicacion()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

/** \brief PAUSA PUBLICACION (ID = ID PUBLICACION -> PAUSA)
 *
 * \param array Publicacion* ARRAY DE PUBLICACIONES TRABAJAR
 * \param limite int LIMITE DE ARRAY PUBLICACIONES
 * \param id int ID A COMPARAR
 * \return int RETORNA [0] SI SE REALIZO LA PAUSA, [1] ERROR
 *
 */
int publicacion_pausa(Publicacion* array,int limite, int id)
{
    int retorno = 1;
    char pausa;
    if(limite > 0 && array != NULL)
    {
            if(!array[id].isEmpty && array[id].idPublicacion==id && array[id].estado!=1)
            {
                pausa=getChar("\nPausar publicacion? <S/N>");
                if(pausa=='s')
                {
                    array[id].estado = 1;
                    printf("\nESTADO = 1, AVISO PAUSADO!!\n");
                    retorno = 0;
                }
            }
    }
    return retorno;
}

/** \brief REANUDAR PUBLICACION (ID = ID PUBLICACION -> REANUDA)
 *
 * \param array Publicacion* ARRAY DE PUBLICACIONES TRABAJAR
 * \param limite int LIMITE DE ARRAY PUBLICACIONES
 * \param id int ID A COMPARAR
 * \return int RETORNA [0] SI SE REALIZO LA REANUDACION, [1] ERROR
 *
 */
int publicacion_reanudar(Publicacion* array,int limite, int id)
{
    int retorno = 1;
    char pausa;
    if(limite > 0 && array != NULL)
    {
            if(!array[id].isEmpty && array[id].idPublicacion==id && array[id].estado!=0)
            {
                pausa=getChar("\nReanudar publicacion? <S/N>");
                if(pausa=='s')
                {
                    array[id].estado = 0;
                    printf("\nESTADO = 0, AVISO ACTIVO!!\n");
                    retorno = 0;
                }
            }
    }
    return retorno;
}

/** \brief ALTA FORZADA PARA TEST
 *
 * \param array Publicacion* ARRAY A TRABAJAR (PUBLICACION)
 * \param arrayCliente Cliente* ARRAY A TRABAJAR (CLIENTE)
 * \param limiteA int LIMITE DE ARRAY PUBLICACIONES
 * \param limiteC int LIMITE ARRAY CLIENTE
 * \param texto char* DESCRIPCION PUBLICACION
 * \param idCliente int ID CLIENTE
 * \param rubro int RUBRO PUBLICACION
 * \return int RETORNO [0] SI SE REALIZO SATISFACTORIAMENTE
 *
 */
int publicacion_altaForzada(Publicacion* array,Cliente* arrayCliente,int limiteA,int limiteC, char* texto, int idCliente, int rubro)
{
    int retorno = -1;
    int i;
    if(limiteA > 0 && limiteC > 0 && array != NULL && arrayCliente != NULL)
    {
        i = buscarLugarLibrePublicacion(array,limiteA);
        if(i >= 0)
        {
                retorno = 0;
                strcpy(array[i].texto,texto);
                array[i].idCliente = idCliente;
                array[i].idPublicacion = proximoIdPublicacion();
                array[i].isEmpty = 0;
                array[i].estado=0;
                array[i].rubro=rubro;
                printf("\nPublicacion publicado con exito!! El id es: %d", array[i].idPublicacion);
        }
    }
    return retorno;
}

/** \brief LISTA CLIENTES JUNTO INCLUYENDO CANTIDAD PUBLICACIONES ACTIVAS
 *
 * \param clientes Cliente* ARRAY A TRABAJAR CLIENTES
 * \param publicaciones Publicacion* ARRAY A TRABAJAR PUBLICACIONES (AVISOS)
 * \param limiteCliente int LIMITE DE ARRAY CLIENTES
 * \param limitePublicacion int LIMITE DE ARRAY PUBLICACIONES
 * \return int RETORNA [0] = IMPRIME // [1] ERROR!!!
 *
 */
int listarClientes(Cliente* clientes, Publicacion* publicaciones, int limiteCliente, int limitePublicacion)
{
    int i,j,cantidadPublicActivos,retorno=1;
    if(limiteCliente > 0 && limitePublicacion > 0 && clientes != NULL && publicaciones != NULL)
    {
        for(i=0;i<limiteCliente;i++)
        {
            cantidadPublicActivos=0;
            for(j=0;j<limitePublicacion;j++){
                if(publicaciones[j].idCliente==clientes[i].idCliente)
                {
                    cantidadPublicActivos=cantidadPublicActivos+1;
                }
            }
            if(!publicaciones[i].estado&&!publicaciones[i].isEmpty&&!clientes[i].isEmpty)
            {
                retorno=0;
                printf("\nNombre: %s Apellido: %s Cuit: %s ID: %d Cantidad publicaciones activas: %d\n",clientes[i].nombre,clientes[i].apellido,clientes[i].cuit,clientes[i].idCliente,cantidadPublicActivos);
            }
        }
    }

    return retorno;
}

/** \brief LISTA PUBLICACIONES ACTIVAS JUNTO A CUIT CLIENTE
 *
 * \param clientes Cliente* ARRAY A TRABAJAR CLIENTES
 * \param publicaciones Publicacion* ARRAY A TRABAJAR PUBLICACIONES
 * \param limiteCliente int LIMITE DE ARRAY CLIENTES
 * \param limitePublicacion int LIMITE DE ARRAY PUBLICACIONES
 * \return int RETORNA [0] = IMPRIME // [1] ERROR!!!
 *
 */
int listarPublicacionesActivas(Cliente* clientes, Publicacion* publicaciones, int limiteCliente, int limitePublicacion)
{
    int i,retorno=1;
        if(limiteCliente > 0 && limitePublicacion > 0 && clientes != NULL && publicaciones!=NULL)
        {
            for(i=0;i<limitePublicacion;i++)
            {
                if(!publicaciones[i].estado&&!publicaciones[i].isEmpty)
                {
                    printf("\nDESCRIPCION: %s RUBRO: %d ID PUBLICACION: %d CUIT: %s ESTADO: %d - EMPTY: %d\n",publicaciones[i].texto,publicaciones[i].rubro, publicaciones[i].idPublicacion, clientes[publicaciones[i].idCliente].cuit, publicaciones[i].estado, publicaciones[i].isEmpty);
                    retorno=0;
                }
            }
        }
    return retorno;
}
