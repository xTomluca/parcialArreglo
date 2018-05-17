#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
#include "cliente.h"
typedef struct
{
    char texto[64];
    //------------
    int idPublicacion;
    int rubro;
    int idCliente;
    int estado;
    int isEmpty;
}Publicacion;
#endif // PUBLICACION_H_INCLUDED


int publicacion_init(Publicacion* array,int limite);
int publicacion_mostrar(Publicacion* array,int id,int limite);
int publicacion_mostrarDebug(Publicacion* array,int limite);
int publicacion_altaForzada(Publicacion* array,Cliente* arrayCliente,int limiteP,int limiteC, char* texto, int idCliente,int rubro);
int publicacion_alta(Publicacion* array,Cliente* arrayCliente,int limiteP,int limiteC);
int publicacion_baja(Publicacion* array,int limite, int idCliente);
int publicacion_modificacion(Publicacion* array,int limite, int id);
int publicacion_ordenar(Publicacion* array,int limite, int orden);
int buscarLugarLibrePublicacion(Publicacion* array,int limite);
int publicacion_reanudar(Publicacion* array,int limite, int id);
int publicacion_pausa(Publicacion* array,int limite, int id);
int proximoIdPublicacion();
int listarClientes(Cliente* clientes, Publicacion* publicaciones, int limiteCliente, int limitePublicacion);
int listarPublicacionesActivas(Cliente* clientes, Publicacion* publicaciones, int limiteCliente, int limitePublicacion);


