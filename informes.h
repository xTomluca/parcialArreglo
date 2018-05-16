#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "cliente.h"
#include "aviso.h"

int informar_clienteMasActivo(Cliente* clientes, Aviso* avisos, int limiteCliente, int limiteAviso);
int informar_clienteMasPausado(Cliente* clientes, Aviso* avisos, int limiteCliente, int limiteAviso);
int informar_clienteMasAvisos(Cliente* clientes, Aviso* avisos, int limiteCliente, int limiteAviso);
int informar_publicacionRubro(Aviso* avisos, int limiteAviso,int rubro);
int informar_publicacionRubroAct(Aviso* avisos, int limiteAviso,int limiterubro);
int informar_publicacionRubroMenosAct(Aviso* avisos, int limiteAviso,int limiterubro);

#endif // INFORMES_H_INCLUDED
