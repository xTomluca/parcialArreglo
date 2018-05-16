#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "aviso.h"
#include "informes.h"

/** \brief CLIENTES CON MAS PUBLICACIONES ACTIVAS
 *
 * \param clientes Cliente* ARRAY CLIENTE A TRABAJAR
 * \param avisos Aviso* ARRAY PUBLICACIONES (AVISOS) A TRABAJAR
 * \param limiteCliente int LIMITE ARRAY CLIENTE
 * \param limiteAviso int LIMITE ARRAY PUBLICACIONES (AVISOS)
 * \return int RETORNO [0] = IMPRIME // [1] ERROR!!
 *
 */
int informar_clienteMasActivo(Cliente* clientes, Aviso* avisos, int limiteCliente, int limiteAviso)
{
    int i,j,maximo,cantidadAvisosActivos[limiteCliente],retorno=1;
    if(limiteCliente > 0 && limiteAviso > 0 && clientes != NULL && avisos != NULL)
    {
        for(i=0;i<limiteCliente;i++)
        {
            cantidadAvisosActivos[i]=0;
            if(!clientes[i].isEmpty)
            {
                for(j=0;j<limiteAviso;j++)
                {
                    if(!avisos[j].isEmpty&&!avisos[j].estado&&avisos[j].idCliente==clientes[i].idCliente)
                    {
                        cantidadAvisosActivos[i]+=1;
                        retorno=0;
                    }
                }
            }

        }
        maximo=cantidadAvisosActivos[0];
        for(i=0;i<limiteCliente;i++)
        {
            if(maximo<cantidadAvisosActivos[i])
            {
                maximo=cantidadAvisosActivos[i];
            }
        }
        for(i=0;i<limiteCliente;i++)
        {
            if(maximo>0&&cantidadAvisosActivos[i]==maximo&&!avisos[i].isEmpty&&!clientes[i].isEmpty)
            printf("\nNombre: %s Apellido: %s Cuit: %s ID: %d Cantidad publicaciones activas: %d\n\n",clientes[i].nombre,clientes[i].apellido,clientes[i].cuit,clientes[i].idCliente,cantidadAvisosActivos[i]);
        }

    }
    return retorno;
}

/** \brief INFORMA CLIENTES CON MAS PUBLICACIONES PAUSADAS
 *
 * \param clientes Cliente* ARRAY CLIENTE A TRABAJAR
 * \param avisos Aviso* ARRAY PUBLICACIONES (AVISOS) A TRABAJAR
 * \param limiteCliente int LIMITE ARRAY CLIENTE
 * \param limiteAviso int LIMITE ARRAY PUBLICACIONES (AVISOS)
 * \return int RETORNO [0] = IMPRIME // [1] ERROR!!
 *
 */
int informar_clienteMasPausado(Cliente* clientes, Aviso* avisos, int limiteCliente, int limiteAviso)
{
    int i,j,maximo,cantidadAvisosPausados[limiteCliente],retorno=1;
    if(limiteCliente > 0 && limiteAviso > 0 && clientes != NULL && avisos != NULL)
    {
        for(i=0;i<limiteCliente;i++)
        {
            cantidadAvisosPausados[i]=0;
            if(!clientes[i].isEmpty)
            {
                    for(j=0;j<limiteAviso;j++)
                    {
                        if(!avisos[j].isEmpty&&avisos[j].estado==1&&avisos[j].idCliente==clientes[i].idCliente)
                        {
                            cantidadAvisosPausados[i]+=1;
                            retorno=0;
                        }
                    }
            }

        }
        maximo=cantidadAvisosPausados[0];
        for(i=0;i<limiteCliente;i++)
        {
            if(maximo<cantidadAvisosPausados[i])
            {
                maximo=cantidadAvisosPausados[i];
            }
        }
        for(i=0;i<limiteCliente;i++)
        {
            if(maximo>0&&cantidadAvisosPausados[i]==maximo&&!avisos[i].isEmpty&&!clientes[i].isEmpty)
            printf("\nNombre: %s Apellido: %s Cuit: %s ID: %d Cantidad publicaciones inactivas: %d\n",clientes[i].nombre,clientes[i].apellido,clientes[i].cuit,clientes[i].idCliente,cantidadAvisosPausados[i]);
        }

    }
    return retorno;
}
/** \brief INFORMA CLIENTES CON MAS AVISOS
 *
 * \param clientes Cliente* ARRAY CLIENTE A TRABAJAR
 * \param avisos Aviso* ARRAY PUBLICACIONES (AVISOS) A TRABAJAR
 * \param limiteCliente int LIMITE ARRAY CLIENTE
 * \param limiteAviso int LIMITE ARRAY PUBLICACIONES (AVISOS)
 * \return int RETORNO [0] = IMPRIME // [1] ERROR!!
 *
 */
int informar_clienteMasAvisos(Cliente* clientes, Aviso* avisos, int limiteCliente, int limiteAviso)
{
    int i,j,maximo,cantidadAvisos[limiteCliente],retorno=1;
    if(limiteCliente > 0 && limiteAviso > 0 && clientes != NULL && avisos != NULL)
    {
        for(i=0;i<limiteCliente;i++)
        {
            cantidadAvisos[i]=0;
            if(!clientes[i].isEmpty)
            {
                    for(j=0;j<limiteAviso;j++)
                    {
                        if(!avisos[j].isEmpty&&avisos[j].idCliente==clientes[i].idCliente)
                        {
                            cantidadAvisos[i]+=1;
                            retorno=0;
                        }
                    }
            }

        }
        maximo=cantidadAvisos[0];
        for(i=0;i<limiteCliente;i++)
        {
            if(maximo<cantidadAvisos[i])
            {
                maximo=cantidadAvisos[i];
            }
        }
        for(i=0;i<limiteCliente;i++)
        {
            if(maximo>0&&cantidadAvisos[i]==maximo&&!avisos[i].isEmpty)
            printf("\nNombre: %s Apellido: %s Cuit: %s ID: %d Cantidad publicaciones : %d\n",clientes[i].nombre,clientes[i].apellido,clientes[i].cuit,clientes[i].idCliente,cantidadAvisos[i]);
        }

    }
    return retorno;
}

/** \brief IMFORMA CANTIDAD DE PUBLICACIONES DE RUBRO SOLICITADO
 *
 * \param avisos Aviso* ARRAY DE PUBLICACIONES (AVISOS) A TRABAJAR
 * \param limiteAviso int LIMITE DE PUBLICACIONES (AVISOS)
 * \param rubro int RUBRO A COMPARAR
 * \return int RETORNO [0] = IMPRIME // [1] ERROR!!
 *
 */
int informar_publicacionRubro(Aviso* avisos, int limiteAviso,int rubro)
{
    int i,cantidad=0,retorno=1;
    if(limiteAviso > 0 && avisos != NULL)
    {
        for(i=0;i<limiteAviso;i++)
        {
            if(avisos[i].rubro==rubro &&!avisos[i].estado&&!avisos[i].isEmpty)
            {
                cantidad+=1;
                retorno=0;
            }
        }
        if(cantidad>0)
        {
            printf("\n//------INFORME RUBRO --- CANTIDAD------//");
            printf("\nRubro %d - Cantidad de publicaciones: %d\n\n",rubro, cantidad);
        }

    }
    return retorno;
}

/** \brief IMPRIME RUBRO/s CON MAS PUBLICACIONES ACTIVAS
 *
 * \param avisos Aviso* ARRAY DE PUBLICACIONES (AVISOS) A TRABAJAR
 * \param limiteAviso int LIMITE DE PUBLICACIONES (AVISOS)
 * \param limiterubro int LIMITE RUBROS
 * \return int RETORNO [0] = IMPRIME // [1] ERROR!!
 *
 */
int informar_publicacionRubroAct(Aviso* avisos, int limiteAviso,int limiterubro)
{
    int i,j,maximo,cantidad[limiterubro],retorno=1;
    for(i=0;i<limiterubro;i++)
    {
        cantidad[i]=0;
        for(j=0;j<limiteAviso;j++)
        {
            if(avisos[j].rubro==i &&avisos[j].rubro!=-1&&!avisos[j].estado&&!avisos[j].isEmpty)
            {
                cantidad[i]+=1;
                retorno=0;
            }
        }
    }
    maximo=cantidad[0];
    for(i=0;i<limiterubro;i++)
    {
        if(maximo<cantidad[i])
        {
            maximo=cantidad[i];
        }
    }
    if(maximo>0)
    {
        printf("//-----RUBRO/s CON MAS PUBLICACIONES ACTIVAS----//");
        for(i=0;i<limiterubro;i++)
        {
            if(cantidad[i]==maximo)
            printf("\nRUBRO %d PUBLICACIONES ACTIVAS: %d\n",i,cantidad[i]);
        }
    }
    return retorno;
}



/** \brief IMPRIME RUBRO/s CON MENOS PUBLICACIONES ACTIVAS
 *
 * \param avisos Aviso* ARRAY DE PUBLICACIONES (AVISOS) A TRABAJAR
 * \param limiteAviso int LIMITE DE PUBLICACIONES (AVISOS)
 * \param limiterubro int LIMITE RUBROS
 * \return int RETORNO [0] = IMPRIME // [1] ERROR!!
 *
 */
int informar_publicacionRubroMenosAct(Aviso* avisos, int limiteAviso,int limiterubro)
{
    int i,j,minimo,cantidad[limiterubro],retorno=1;
    for(i=0;i<limiterubro;i++)
    {
        cantidad[i]=0;
        for(j=0;j<limiteAviso;j++)
        {
            if(avisos[j].rubro==i &&avisos[j].rubro!=-1&&!avisos[j].estado&&!avisos[j].isEmpty)
            {
                cantidad[i]+=1;
                retorno=0;
            }
        }
    }
    minimo=limiteAviso;
    for(i=0;i<limiterubro;i++)
    {
        if(minimo>cantidad[i])
        {
            minimo=cantidad[i];
        }
    }
    printf("//-----RUBRO/s CON MENOS PUBLICACIONES ACTIVAS----//");
    for(i=0;i<limiterubro;i++)
    {
        if(cantidad[i]==minimo)
        printf("\nRUBRO MENOS PUBLICACIONES ACTIVAS: %d\n",i);
    }
    return retorno;
}

