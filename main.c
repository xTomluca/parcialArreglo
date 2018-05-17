#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "cliente.h"
#include "funciones.h"
#include "utn.h"
#include "informes.h"
#define CLIENTE 100
#define PUBLICACION 1000
#define RUBRO 20

int main()
{
    Cliente clientes[CLIENTE];
    Publicacion publicaciones[PUBLICACION];
    cliente_init(clientes,CLIENTE);
    publicacion_init(publicaciones,PUBLICACION);
    char borrar;
    int menu;
    int auxiliarId;

    ///***ALTA FORZADA TEST!
    /*cliente_altaForzada(clientes,"Luis","Suarez","14327416",CLIENTE);
    cliente_altaForzada(clientes,"Tomas","Suarez","39113917",CLIENTE);
    cliente_altaForzada(clientes,"Cecilia","Sarobe","16623266",CLIENTE);
    cliente_altaForzada(clientes,"Elisa","Mast","4000000",CLIENTE);
    publicacion_altaForzada(publicaciones,clientes,PUBLICACION,CLIENTE,"Primera publicacion",1,10);
    publicacion_altaForzada(publicaciones,clientes,PUBLICACION,CLIENTE,"Segunda",1,10);
    publicacion_altaForzada(publicaciones,clientes,PUBLICACION,CLIENTE,"Tercera publicacion",1,6);
    publicacion_altaForzada(publicaciones,clientes,PUBLICACION,CLIENTE,"Cuarta",1,6);
    publicacion_altaForzada(publicaciones,clientes,PUBLICACION,CLIENTE,"Quinta ALTERNATIVA",1,2);
    publicacion_altaForzada(publicaciones,clientes,PUBLICACION,CLIENTE,"Sexta publicacion",0,10);
    publicacion_altaForzada(publicaciones,clientes,PUBLICACION,CLIENTE,"septimaaa",0,5);
    publicacion_altaForzada(publicaciones,clientes,PUBLICACION,CLIENTE,"octava publicacion",0,6);
    publicacion_altaForzada(publicaciones,clientes,PUBLICACION,CLIENTE,"novena",2,6);
    publicacion_altaForzada(publicaciones,clientes,PUBLICACION,CLIENTE,"decima",1,6);*/

    do
    {
        fflush(stdin);
        getNumero(11,0,&menu,"1.Alta\n2.Baja\n3.Modificar\n4.Publicar publicacion\n5.Pausar publicacion\n6.Reanudar publicacion\n7.Listar clientes\n8.Listar publicaciones activas\n9.Informar usuario\n10.Publicaciones RUBRO\n11.Informe rubros\n\n0.Salir\n","\nNo valida\n");
        switch(menu)
        {
            case 1:
                cliente_alta(clientes,CLIENTE);
                break;
            case 2:
                getNumero(CLIENTE,0,&auxiliarId,"\nID: ","\nID INVALIDO");
                if((cliente_buscarPorId(clientes,CLIENTE,auxiliarId))>=0)
                {
                    publicacion_mostrar(publicaciones,auxiliarId,PUBLICACION);
                    borrar=getChar("\nConfirmar baja <S/N>");
                    if(borrar=='s')
                    {
                        publicacion_baja(publicaciones,PUBLICACION,auxiliarId);
                        cliente_baja(clientes,CLIENTE,auxiliarId);
                    }
                }
                break;
            case 3:
                cliente_modificacion(clientes,CLIENTE,auxiliarId);
                break;
            case 4:
                publicacion_alta(publicaciones,clientes,PUBLICACION,CLIENTE);
                break;
            case 5:
                getNumero(PUBLICACION,0,&auxiliarId,"\nID PUBLICACION: ","\nID INVALIDO");
                publicacion_pausa(publicaciones,PUBLICACION,auxiliarId);
                break;
            case 6:
                getNumero(PUBLICACION,0,&auxiliarId,"\nID PUBLICACION: ","\nID INVALIDO");
                publicacion_reanudar(publicaciones,PUBLICACION,auxiliarId);
                break;
            case 7:
                listarClientes(clientes,publicaciones,CLIENTE,PUBLICACION);
                break;
            case 8:
                listarPublicacionesActivas(clientes,publicaciones,CLIENTE,PUBLICACION);
                break;
            case 9:
                informar_clienteMasActivo(clientes,publicaciones,CLIENTE,PUBLICACION);
                informar_clienteMasPausado(clientes,publicaciones,CLIENTE,PUBLICACION);
                informar_clienteMasPublicaciones(clientes,publicaciones,CLIENTE,PUBLICACION);
                break;
            case 10:
                getNumero(RUBRO,0,&auxiliarId,"\nRUBRO: ","\nRUBRO INVALIDO");
                informar_publicacionRubro(publicaciones,PUBLICACION,auxiliarId);
                break;
            case 11:
                informar_publicacionRubroAct(publicaciones,PUBLICACION,RUBRO);
                informar_publicacionRubroMenosAct(publicaciones,PUBLICACION,RUBRO);
                break;
        }

    }while(menu != 0);

    return 0;
}
