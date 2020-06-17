#ifndef ARREGLODEFILAS_H_INCLUDED
#define ARREGLODEFILAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "filas.h"

typedef struct
{
    int nro_de_caja;
    char nombreCajero[40];
    int tipo_pago;                      //  1 efectivo, 2 crédito o débito, 3 todos
    int abiertaOcerrada;
    char algoritmoPlanificacion[30];    //debe informar que teipo de alg. de planificacion utiliza la caja
    int cantidadClientes;
    fila filita;
}caja;

void agregarCaja(caja A[8], char nombre[]);    // crea una nueva caja en el arreglo
caja abrirOcerrarCaja(caja c);                // abre o cierra una caja a requerimiento (si hay clientes no puede cerrarse)
void abrirOcerrarCajaTodas(caja A[8]);
int comprobarAbiertaCerrada(caja A[8]);
caja buscarCaja(caja A[8],int tipoPago);      // busca una caja de acuerdo a su tipo de pago y la retorna (si es que está abierta)
void mostrarCaja(caja c);                     // muestra la caja (sus datos) y toda la fila de clientes que esperan
void mostrarCajaConFila(caja c);
void mostrarCajasTodas(caja A[8]);
void mostrarCajasTodasConFilas(caja A[8]);
caja fifoYrr(caja c, persona cliente);
caja sjf(caja c, persona cliente);
caja prioridadesAp(caja c, persona cliente);
void agregarClienteACaja(caja A[8], persona cliente, int num);   //agrega un cliente a la caja de acuerdo al orden que plantea el algoritmo de planificación que aplica la caja, siempre y cuando la caja está abierta
void agregarClienteACajaEnTiempoDeterminado(caja A[8]);       //prgunta al usuario y agrega a la fila correspondiente en el tiempo indicado
void calcularTiempoEspera(nodo2*a);
caja atenderFifoSjfPrio(caja c);
caja atenderRR(caja c);
void atenderClientes(caja c);                               //atiende a los clientes de acuerdo al algoritmo de planificación que aplica la caja, calculando el tiempo de espera de cada cliente
int calcularCantArt(nodo2* sig);
int calcularCantEspera(nodo2* sig);
void promediosProcesado(caja aux);

#endif // ARREGLODEFILAS_H_INCLUDED
