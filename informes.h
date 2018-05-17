#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "cliente.h"
#include "publicacion.h"

int informar_clienteMasActivo(Cliente* clientes, Publicacion* publicaciones, int limiteCliente, int limitePublicacion);
int informar_clienteMasPausado(Cliente* clientes, Publicacion* publicaciones, int limiteCliente, int limitePublicacion);
int informar_clienteMasPublicaciones(Cliente* clientes, Publicacion* publicaciones, int limiteCliente, int limitePublicacion);
int informar_publicacionRubro(Publicacion* publicaciones, int limitePublicacion,int rubro);
int informar_publicacionRubroAct(Publicacion* publicaciones, int limitePublicacion,int limiterubro);
int informar_publicacionRubroMenosAct(Publicacion* publicaciones, int limitePublicacion,int limiterubro);

#endif // INFORMES_H_INCLUDED
