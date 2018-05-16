#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "aviso.h"
#include "cliente.h"
#include "funciones.h"
#include "utn.h"
#include "informes.h"
#define CLIENTE 100
#define AVISO 1000
#define RUBRO 20

int main()
{
    Cliente clientes[CLIENTE];
    Aviso avisos[AVISO];
    char borrar;
    int menu;
    int auxiliarId;
    cliente_init(clientes,CLIENTE);
    aviso_init(avisos,AVISO);

    cliente_altaForzada(clientes,"Luis","Suarez","14327416",CLIENTE);
    cliente_altaForzada(clientes,"Tomas","Suarez","39113917",CLIENTE);
    cliente_altaForzada(clientes,"Cecilia","Sarobe","16623266",CLIENTE);
    cliente_altaForzada(clientes,"Elisa","Mast","4000000",CLIENTE);
    aviso_altaForzada(avisos,clientes,AVISO,CLIENTE,"Primera publicacion",1,10);
    aviso_altaForzada(avisos,clientes,AVISO,CLIENTE,"Segunda publicacion",1,10);
    aviso_altaForzada(avisos,clientes,AVISO,CLIENTE,"Tercera publicacion",1,6);
    aviso_altaForzada(avisos,clientes,AVISO,CLIENTE,"Cuarta publicacion",1,6);
    aviso_altaForzada(avisos,clientes,AVISO,CLIENTE,"Sexta ALTERNATIVA",1,2);
    aviso_altaForzada(avisos,clientes,AVISO,CLIENTE,"Primera publicacion",0,10);
    aviso_altaForzada(avisos,clientes,AVISO,CLIENTE,"Segunda publicacion",0,5);
    aviso_altaForzada(avisos,clientes,AVISO,CLIENTE,"Tercera publicacion",0,6);
    aviso_altaForzada(avisos,clientes,AVISO,CLIENTE,"Cuarta publicacion",2,6);
    aviso_altaForzada(avisos,clientes,AVISO,CLIENTE,"Septima PRUEBA ALTERNATIVA",1,10);
    do
    {
        fflush(stdin);
        getNumero(11,0,&menu,"1.Alta\n2.Baja\n3.Modificar\n4.Publicar aviso\n5.Pausar aviso\n6.Reanudar aviso\n7.Listar clientes\n8.Listar publicaciones activas\n9.Informar usuario\n10.Publicaciones RUBRO\n11.Informe rubros\n0.Salir\n","\nNo valida\n");
        switch(menu)
        {
            case 1:
                cliente_alta(clientes,CLIENTE);
                break;
            case 2:
                getNumero(CLIENTE,0,&auxiliarId,"\nID: ","\nID INVALIDO");
                if((cliente_buscarPorId(clientes,CLIENTE,auxiliarId))>=0)
                {
                    aviso_mostrar(avisos,auxiliarId,AVISO);
                    borrar=getChar("\nConfirmar baja <S/N>");
                    if(borrar=='s')
                    {
                        aviso_baja(avisos,AVISO,auxiliarId);
                        cliente_baja(clientes,CLIENTE,auxiliarId);
                    }
                }
                break;
            case 3:
                cliente_modificacion(clientes,CLIENTE,auxiliarId);
                break;
            case 4:
                aviso_alta(avisos,clientes,AVISO,CLIENTE);
                break;
            case 5:
                getNumero(AVISO,0,&auxiliarId,"\nID AVISO: ","\nID INVALIDO");
                aviso_pausa(avisos,AVISO,auxiliarId);
                break;
            case 6:
                getNumero(AVISO,0,&auxiliarId,"\nID AVISO: ","\nID INVALIDO");
                aviso_reanudar(avisos,AVISO,auxiliarId);
                break;
            case 7:
                listarClientes(clientes,avisos,CLIENTE,AVISO);
                break;
            case 8:
                listarPublicacionesActivas(clientes,avisos,CLIENTE,AVISO);
                break;
            case 9:
                informar_clienteMasActivo(clientes,avisos,CLIENTE,AVISO);
                informar_clienteMasPausado(clientes,avisos,CLIENTE,AVISO);
                informar_clienteMasAvisos(clientes,avisos,CLIENTE,AVISO);
                break;
            case 10:
                getNumero(RUBRO,0,&auxiliarId,"\nRUBRO: ","\nRUBRO INVALIDO");
                informar_publicacionRubro(avisos,AVISO,auxiliarId);
                break;
            case 11:
                informar_publicacionRubroAct(avisos,AVISO,RUBRO);
                informar_publicacionRubroMenosAct(avisos,AVISO,RUBRO);
                break;
        }

    }while(menu != 0);

    return 0;
}
