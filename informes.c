#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "publicacion.h"
#include "informes.h"

/** \brief CLIENTES CON MAS PUBLICACIONES ACTIVAS
 *
 * \param clientes Cliente* ARRAY CLIENTE A TRABAJAR
 * \param publicaciones Publicacion* ARRAY PUBLICACIONES A TRABAJAR
 * \param limiteCliente int LIMITE ARRAY CLIENTE
 * \param limitePublicacion int LIMITE ARRAY PUBLICACIONES
 * \return int RETORNO [0] = IMPRIME // [1] ERROR!!
 *
 */
int informar_clienteMasActivo(Cliente* clientes, Publicacion* publicaciones, int limiteCliente, int limitePublicacion)
{
    int i,j,maximo,cantidadPublicActivas[limiteCliente],retorno=1;
    if(limiteCliente > 0 && limitePublicacion > 0 && clientes != NULL && publicaciones != NULL)
    {
        for(i=0;i<limiteCliente;i++)
        {
            cantidadPublicActivas[i]=0;
            if(!clientes[i].isEmpty)
            {
                for(j=0;j<limitePublicacion;j++)
                {
                    if(!publicaciones[j].isEmpty&&!publicaciones[j].estado&&publicaciones[j].idCliente==clientes[i].idCliente)
                    {
                        cantidadPublicActivas[i]+=1;
                        retorno=0;
                    }
                }
            }

        }
        maximo=cantidadPublicActivas[0];
        for(i=0;i<limiteCliente;i++)
        {
            if(maximo<cantidadPublicActivas[i])
            {
                maximo=cantidadPublicActivas[i];
            }
        }
        if(maximo>0)
        {
            printf("CLIENTE/s CON MAS PUBLICACIONES ACTIVAS: \n");
            for(i=0;i<limiteCliente;i++)
            {
                //for(j=0;j<limitePublicacion;j++)
                //{
                    if(maximo>0&&cantidadPublicActivas[i]==maximo&&!publicaciones[i].isEmpty&&!clientes[i].isEmpty)
                    printf("\nNombre: %s Apellido: %s Cuit: %s ID: %d Cantidad publicaciones activas: %d\n\n",clientes[i].nombre,clientes[i].apellido,clientes[i].cuit,clientes[i].idCliente,cantidadPublicActivas[i]);
                //}

            }
        }

    }
    return retorno;
}

/** \brief INFORMA CLIENTES CON MAS PUBLICACIONES PAUSADAS
 *
 * \param clientes Cliente* ARRAY CLIENTE A TRABAJAR
 * \param publicaciones Publicacion* ARRAY PUBLICACIONES A TRABAJAR
 * \param limiteCliente int LIMITE ARRAY CLIENTE
 * \param limitePublicacion int LIMITE ARRAY PUBLICACIONES
 * \return int RETORNO [0] = IMPRIME // [1] ERROR!!
 *
 */
int informar_clienteMasPausado(Cliente* clientes, Publicacion* publicaciones, int limiteCliente, int limitePublicacion)
{
    int i,j,maximo,cantidadPublicPausadas[limiteCliente],retorno=1;
    if(limiteCliente > 0 && limitePublicacion > 0 && clientes != NULL && publicaciones != NULL)
    {
        for(i=0;i<limiteCliente;i++)
        {
            cantidadPublicPausadas[i]=0;
            if(!clientes[i].isEmpty)
            {
                    for(j=0;j<limitePublicacion;j++)
                    {
                        if(!publicaciones[j].isEmpty&&publicaciones[j].estado==1&&publicaciones[j].idCliente==clientes[i].idCliente)
                        {
                            cantidadPublicPausadas[i]+=1;
                            retorno=0;
                        }
                    }
            }

        }
        maximo=cantidadPublicPausadas[0];
        for(i=0;i<limiteCliente;i++)
        {
            if(maximo<cantidadPublicPausadas[i])
            {
                maximo=cantidadPublicPausadas[i];
            }
        }
        if(maximo>0)
        {
            printf("CLIENTE/s CON MAS PUBLICACIONES PAUSADAS: \n");

            for(i=0;i<limiteCliente;i++)
            {
                //for(i=0;i<limiteCliente;i++)
                //{
                    if(maximo>0&&cantidadPublicPausadas[i]==maximo&&!publicaciones[j].isEmpty&&!clientes[i].isEmpty)
                    printf("\nNombre: %s Apellido: %s Cuit: %s ID: %d Cantidad publicaciones inactivas: %d\n\n",clientes[i].nombre,clientes[i].apellido,clientes[i].cuit,clientes[i].idCliente,maximo);
                //}
            }
        }


    }
    return retorno;
}
/** \brief INFORMA CLIENTES CON MAS AVISOS
 *
 * \param clientes Cliente* ARRAY CLIENTE A TRABAJAR
 * \param publicaciones Publicacion* ARRAY PUBLICACIONES A TRABAJAR
 * \param limiteCliente int LIMITE ARRAY CLIENTE
 * \param limitePublicacion int LIMITE ARRAY PUBLICACIONES
 * \return int RETORNO [0] = IMPRIME // [1] ERROR!!
 *
 */
int informar_clienteMasPublicaciones(Cliente* clientes, Publicacion* publicaciones, int limiteCliente, int limitePublicacion)
{
    int i,j,maximo,cantidadPublicaciones[limiteCliente],retorno=1;
    if(limiteCliente > 0 && limitePublicacion > 0 && clientes != NULL && publicaciones != NULL)
    {
        for(i=0;i<limiteCliente;i++)
        {
            cantidadPublicaciones[i]=0;
            if(!clientes[i].isEmpty)
            {
                    for(j=0;j<limitePublicacion;j++)
                    {
                        if(!publicaciones[j].isEmpty&&publicaciones[j].idCliente==clientes[i].idCliente)
                        {
                            cantidadPublicaciones[i]+=1;
                            retorno=0;
                        }
                    }
            }

        }
        maximo=cantidadPublicaciones[0];
        for(i=0;i<limiteCliente;i++)
        {
            if(maximo<cantidadPublicaciones[i])
            {
                maximo=cantidadPublicaciones[i];
            }
        }
        if(maximo>0)
        {
            printf("CLIENTE/s CON MAS PUBLICACIONES: \n");
            for(i=0;i<limiteCliente;i++)
            {
                    if(maximo>0&&cantidadPublicaciones[i]==maximo&&!publicaciones[i].isEmpty)
                    printf("\nNombre: %s Apellido: %s Cuit: %s ID: %d Cantidad publicaciones : %d\n\n",clientes[i].nombre,clientes[i].apellido,clientes[i].cuit,clientes[i].idCliente,cantidadPublicaciones[i]);
            }
        }
    }
    return retorno;
}

/** \brief IMFORMA CANTIDAD DE PUBLICACIONES DE RUBRO SOLICITADO
 *
 * \param publicaciones Publicacion* ARRAY DE PUBLICACIONES A TRABAJAR
 * \param limitePublicacion int LIMITE DE PUBLICACIONES
 * \param rubro int RUBRO A COMPARAR
 * \return int RETORNO [0] = IMPRIME // [1] ERROR!!
 *
 */
int informar_publicacionRubro(Publicacion* publicaciones, int limitePublicacion,int rubro)
{
    int i,cantidad=0,retorno=1;
    if(limitePublicacion > 0 && publicaciones != NULL)
    {
        for(i=0;i<limitePublicacion;i++)
        {
            if(publicaciones[i].rubro==rubro &&!publicaciones[i].estado&&!publicaciones[i].isEmpty)
            {
                cantidad+=1;
                retorno=0;
            }
        }
        if(cantidad>0)
        {
            printf("\n//------INFORME RUBRO --- CANTIDAD------//");
            printf("\nRubro %d - Cantidad de publicaciones: %d\n",rubro, cantidad);
        }

    }
    return retorno;
}

/** \brief IMPRIME RUBRO/s CON MAS PUBLICACIONES ACTIVAS
 *
 * \param publicaciones Publicacion* ARRAY DE PUBLICACIONES A TRABAJAR
 * \param limitePublicacion int LIMITE DE PUBLICACIONES
 * \param limiterubro int LIMITE RUBROS
 * \return int RETORNO [0] = IMPRIME // [1] ERROR!!
 *
 */
int informar_publicacionRubroAct(Publicacion* publicaciones, int limitePublicacion,int limiterubro)
{
    int i,j,maximo,cantidad[limiterubro],retorno=1;
    if(limitePublicacion > 0 && publicaciones != NULL)
    {
        for(i=0;i<limiterubro;i++)
        {
            cantidad[i]=0;
            for(j=0;j<limitePublicacion;j++)
            {
                if(publicaciones[j].rubro==i &&publicaciones[j].rubro!=-1&&!publicaciones[j].estado&&!publicaciones[j].isEmpty)
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
            printf("\n");
            printf("//-----RUBRO/s CON MAS PUBLICACIONES ACTIVAS----//");
            printf("\n");
            for(i=0;i<limiterubro;i++)
            {
                if(cantidad[i]==maximo)
                printf("\nRUBRO: %d CANTIDAD: %d\n",i,cantidad[i]);
            }
            printf("\n");
        }
    }
    return retorno;
}



/** \brief IMPRIME RUBRO/s CON MENOS PUBLICACIONES ACTIVAS > 0 (NO LISTO RUBRO CON 0 PUBLICACIONES)
 *
 * \param publicaciones Publicacion* ARRAY DE PUBLICACIONES A TRABAJAR
 * \param limitePublicacion int LIMITE DE PUBLICACIONES
 * \param limiterubro int LIMITE RUBROS
 * \return int RETORNO [0] = IMPRIME // [1] ERROR!!
 *
 */
int informar_publicacionRubroMenosAct(Publicacion* publicaciones, int limitePublicacion,int limiterubro)
{
    int i,j,minimo,cantidad[limiterubro],retorno=1;
    if(limitePublicacion > 0 && publicaciones != NULL)
    {
        for(i=0;i<limiterubro;i++)
        {
            cantidad[i]=0;
            for(j=0;j<limitePublicacion;j++)
            {
                if(publicaciones[j].rubro==i &&publicaciones[j].rubro!=-1&&!publicaciones[j].estado&&!publicaciones[j].isEmpty)
                {
                    cantidad[i]+=1;
                    retorno=0;
                }
            }
        }
        minimo=limitePublicacion;
        for(i=0;i<limiterubro;i++)
        {
            if(minimo>cantidad[i] && cantidad[i]>0)
            {
                minimo=cantidad[i];
            }
        }
        if(minimo>0)
        {
            printf("//-----RUBRO/s CON MENOS PUBLICACIONES ACTIVAS----//\n");
            for(i=0;i<limiterubro;i++)
            {
                if(cantidad[i]==minimo)
                printf("\nRUBRO: %d CANTIDAD: %d\n",i,cantidad[i]);
            }
            printf("\n");
        }

    }
    return retorno;
}

