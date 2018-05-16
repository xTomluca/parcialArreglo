#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "aviso.h"
#include "utn.h"
#include "funciones.h"
#include "cliente.h"

/** \brief INCIALIZA ARRAY PUBLICACIONES
 * \param array Aviso* ARRAY A TRABAJAR
 * \param limite int LIMITE DE ARRAY
 * \return int RETORNA [0] SI SE INICIALIZO CON EXITO
 *
 */
int aviso_init(Aviso* array,int limite)
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
 * \param array Aviso* ARRAY DE PUBLICACIONES TRABAJAR
 * \param id int ID A COMPARAR
 * \param limite int LIMITE ARRAY PUBLICACIONES
 * \return int RETORNO [0] SI SE REALIZO IMP CON EXITO, [1] ERROR!!
 *
 */
int aviso_mostrar(Aviso* array,int id,int limite)
{
    int retorno = 1;
    int i;
    if(limite > 0 && array != NULL)
    {

        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty&&array[i].idCliente==id)
            {
                printf("\nDESCRIPCION: %s RUBRO: %d ID PUBLICACION: %d ESTADO: %d - EMPTY: %d\n",array[i].texto,array[i].rubro, array[i].idAviso, array[i].estado, array[i].isEmpty);
                retorno = 0;
            }

        }
    }
    return retorno;
}

/** \brief ALTA PUBLICACION AVISO
 *
 * \param array Aviso* ARRAY DE PUBLICACIONES TRABAJAR
 * \param arrayCliente Cliente* ARRAY DE CLIENTES TRABAJAR
 * \param limiteA int LIMITE DE ARRAY PUBLICACIONES
 * \param limiteC int LIMITE DE ARRAY CLIENTE
 * \return int RETORNO [0] SI EL ALTA SE REALIZO CON EXITO [1] ERROR EN CARGA.
 *
 */
int aviso_alta(Aviso* array,Cliente* arrayCliente,int limiteA,int limiteC)
{
    int retorno = -1;
    int i,rubro,idAux,idAuxResultado;
    char texto[50];
    if(limiteA > 0 && limiteC > 0 && array != NULL && arrayCliente != NULL)
    {
        getNumero(100,0,&idAux,"Ingrese ID Usuario: ","\nID INVALIDO: ");
        idAuxResultado = cliente_buscarPorId(arrayCliente,limiteC,idAux);
        i = buscarLugarLibreAviso(array,limiteA);
        if(i >= 0 && idAuxResultado >=0)
        {
            if(!getCadena(texto,"Ingrese descripcion aviso: ","ERROR!!"))
            {
                if(!getNumero(20,1,&rubro,"Ingrese rubro producto: ","ERROR!!!"))
                {
                    retorno = 0;
                    strcpy(array[i].texto,texto);
                    array[i].idCliente = idAuxResultado;
                    array[i].idAviso = proximoIdAviso();
                    array[i].isEmpty = 0;
                    array[i].estado=0;
                    printf("Aviso publicado con exito!! El id es: %d\n", array[i].idAviso);
                }
            }
        }
    }
    return retorno;
}


/** \brief BAJA DE PUBLICACIONES (AVISOS)
 *
 * \param array Aviso* ARRAY DE PUBLICACIONES TRABAJAR
 * \param limite int LIMITE DE ARRAY PUBLICACIONES
 * \param idCliente int ID A COMPARAR
 * \return int RETORNO [0] SI EL BAJA SE REALIZO CON EXITO [-1] ERROR EN BAJA.
 *
 */
int aviso_baja(Aviso* array,int limite, int idCliente)
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
 * \param array Aviso* ARRAY DE PUBLICACIONES TRABAJAR
 * \param limite int LIMITE DE ARRAY PUBLICACIONES
 * \return int RETORNO [I] SI ENCUENTRA LUGAR EN EL ARRAY
 *
 */
int buscarLugarLibreAviso(Aviso* array,int limite)
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
int proximoIdAviso()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

/** \brief PAUSA PUBLICACION (ID = ID PUBLICACION -> PAUSA)
 *
 * \param array Aviso* ARRAY DE PUBLICACIONES TRABAJAR
 * \param limite int LIMITE DE ARRAY PUBLICACIONES
 * \param id int ID A COMPARAR
 * \return int RETORNA [0] SI SE REALIZO LA PAUSA, [1] ERROR
 *
 */
int aviso_pausa(Aviso* array,int limite, int id)
{
    int retorno = 1;
    char pausa;
    if(limite > 0 && array != NULL)
    {
            if(!array[id].isEmpty && array[id].idAviso==id && array[id].estado!=1)
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
 * \param array Aviso* ARRAY DE PUBLICACIONES TRABAJAR
 * \param limite int LIMITE DE ARRAY PUBLICACIONES
 * \param id int ID A COMPARAR
 * \return int RETORNA [0] SI SE REALIZO LA REANUDACION, [1] ERROR
 *
 */
int aviso_reanudar(Aviso* array,int limite, int id)
{
    int retorno = 1;
    char pausa;
    if(limite > 0 && array != NULL)
    {
            if(!array[id].isEmpty && array[id].idAviso==id && array[id].estado!=0)
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
 * \param array Aviso* ARRAY A TRABAJAR (PUBLICACION)
 * \param arrayCliente Cliente* ARRAY A TRABAJAR (CLIENTE)
 * \param limiteA int LIMITE DE ARRAY PUBLICACIONES
 * \param limiteC int LIMITE ARRAY CLIENTE
 * \param texto char* DESCRIPCION PUBLICACION
 * \param idCliente int ID CLIENTE
 * \param rubro int RUBRO PUBLICACION
 * \return int RETORNO [0] SI SE REALIZO SATISFACTORIAMENTE
 *
 */
int aviso_altaForzada(Aviso* array,Cliente* arrayCliente,int limiteA,int limiteC, char* texto, int idCliente, int rubro)
{
    int retorno = -1;
    int i;
    if(limiteA > 0 && limiteC > 0 && array != NULL && arrayCliente != NULL)
    {
        i = buscarLugarLibreAviso(array,limiteA);
        if(i >= 0)
        {
                retorno = 0;
                strcpy(array[i].texto,texto);
                array[i].idCliente = idCliente;
                array[i].idAviso = proximoIdAviso();
                array[i].isEmpty = 0;
                array[i].estado=0;
                array[i].rubro=rubro;
                printf("\nAviso publicado con exito!! El id es: %d", array[i].idAviso);
        }
    }
    return retorno;
}

/** \brief LISTA CLIENTES JUNTO INCLUYENDO CANTIDAD PUBLICACIONES ACTIVAS
 *
 * \param clientes Cliente* ARRAY A TRABAJAR CLIENTES
 * \param avisos Aviso* ARRAY A TRABAJAR PUBLICACIONES (AVISOS)
 * \param limiteCliente int LIMITE DE ARRAY CLIENTES
 * \param limiteAviso int LIMITE DE ARRAY PUBLICACIONES
 * \return int RETORNA [0] = IMPRIME // [1] ERROR!!!
 *
 */
int listarClientes(Cliente* clientes, Aviso* avisos, int limiteCliente, int limiteAviso)
{
    int i,j,cantidadAvisosActivos,retorno=1;
    if(limiteCliente > 0 && limiteAviso > 0 && clientes != NULL && avisos != NULL)
    {
        for(i=0;i<limiteCliente;i++)
        {
            cantidadAvisosActivos=0;
            for(j=0;j<limiteAviso;j++){
                if(avisos[j].idCliente==clientes[i].idCliente)
                {
                    cantidadAvisosActivos=cantidadAvisosActivos+1;
                }
            }
            if(!avisos[i].estado&&!avisos[i].isEmpty&&!clientes[i].isEmpty)
            {
                retorno=0;
                printf("\nNombre: %s Apellido: %s Cuit: %s ID: %d Cantidad publicaciones activas: %d",clientes[i].nombre,clientes[i].apellido,clientes[i].cuit,clientes[i].idCliente,cantidadAvisosActivos);
            }
        }
    }

    return retorno;
}

/** \brief LISTA PUBLICACIONES ACTIVAS JUNTO A CUIT CLIENTE
 *
 * \param clientes Cliente* ARRAY A TRABAJAR CLIENTES
 * \param avisos Aviso* ARRAY A TRABAJAR PUBLICACIONES (AVISOS)
 * \param limiteCliente int LIMITE DE ARRAY CLIENTES
 * \param limiteAviso int LIMITE DE ARRAY PUBLICACIONES (AVISOS)
 * \return int RETORNA [0] = IMPRIME // [1] ERROR!!!
 *
 */
int listarPublicacionesActivas(Cliente* clientes, Aviso* avisos, int limiteCliente, int limiteAviso)
{
    int i,retorno=1;
        if(limiteCliente > 0 && limiteAviso > 0 && clientes != NULL && avisos!=NULL)
        {
            for(i=0;i<limiteAviso;i++)
            {
                if(!avisos[i].estado&&!avisos[i].isEmpty&&!clientes[i].isEmpty)
                {
                    printf("\nDESCRIPCION: %s RUBRO: %d ID PUBLICACION: %d CUIT: %s ESTADO: %d - EMPTY: %d\n",avisos[i].texto,avisos[i].rubro, avisos[i].idAviso, clientes[avisos[i].idCliente].cuit, avisos[i].estado, avisos[i].isEmpty);
                    retorno=0;
                }
            }
        }
    return retorno;
}
