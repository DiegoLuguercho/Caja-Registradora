#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Arboles.h"
#include "ArregloDeFilas.h"

void menuPrincipal();
void subMenuArbol();
void funcionSubMenuArbol(nodoArbol*arbol);
void menuCajas();
void funcionMenuCajas(caja A[8], nodoArbol*arbol);
void subMenuCajas();
void funcionSubMenuCajas(caja A[8]);
void menuCliente();
void funcionMenuClientes(caja A[8]);
void subMenuClientesSeleccionCajas();
void funcionSubMenuClientesSeleccionCajas(caja aux);
void nombreIntegrantes();

#endif // MENUS_H_INCLUDED
