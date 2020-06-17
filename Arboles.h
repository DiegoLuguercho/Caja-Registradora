#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "arregloDeFilas.h"

typedef struct
{
    persona p;
    struct nodoArbol*izq;
    struct nodoArbol*der;
}nodoArbol;

nodoArbol*inicArbol();
nodoArbol*crearNodoArbol(persona p);
nodoArbol*insertarNodoArbol(nodoArbol*arbol, persona p);
void mostrarPreorder(nodoArbol*arbol);
void mostrarInorder(nodoArbol*arbol);
void mostrarPostorder(nodoArbol*arbol);
nodoArbol*nodoMasDerecho(nodoArbol*arbol);
nodoArbol*nodoMasIzquierdo(nodoArbol*arbol);
nodoArbol*borrarUnNodoArbol(nodoArbol*arbol, char nombre);
int buscaMenorFila(caja A[8], persona p);
void pasarArbolADF(caja A[8], persona p);
void pasarPreorder(nodoArbol*arbol, caja A[8]);
void pasarInorder(nodoArbol*arbol, caja A[8]);
void pasarPosorder(nodoArbol*arbol, caja A[8]);
void pasarDeArbolToLineaDeCajas(int i, nodoArbol*arbol, caja A[8]);
nodoArbol*pasarArchivoToArbol(char nombre[], nodoArbol*arbol);

#endif // ARBOLES_H_INCLUDED
