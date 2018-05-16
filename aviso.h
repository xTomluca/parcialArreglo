#ifndef AVISO_H_INCLUDED
#define AVISO_H_INCLUDED
#include "cliente.h"
typedef struct
{
    char texto[64];
    //------------
    int idAviso;
    int rubro;
    int idCliente;
    int estado;
    int isEmpty;
}Aviso;
#endif // AVISO_H_INCLUDED


int aviso_init(Aviso* array,int limite);
int aviso_mostrar(Aviso* array,int id,int limite);
int aviso_mostrarDebug(Aviso* array,int limite);
int aviso_altaForzada(Aviso* array,Cliente* arrayCliente,int limiteA,int limiteC, char* texto, int idCliente,int rubro);
int aviso_alta(Aviso* array,Cliente* arrayCliente,int limiteA,int limiteC);
int aviso_baja(Aviso* array,int limite, int idCliente);
int aviso_modificacion(Aviso* array,int limite, int id);
int aviso_ordenar(Aviso* array,int limite, int orden);
int buscarLugarLibreAviso(Aviso* array,int limite);
int aviso_reanudar(Aviso* array,int limite, int id);
int aviso_pausa(Aviso* array,int limite, int id);
int proximoIdAviso();
int listarClientes(Cliente* clientes, Aviso* avisos, int limiteCliente, int limiteAviso);
int listarPublicacionesActivas(Cliente* clientes, Aviso* avisos, int limiteCliente, int limiteAviso);


