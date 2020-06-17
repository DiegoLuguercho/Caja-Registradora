#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombreApellido [40];
    int cantArticulos;            // es el tiempo de ejecuci�n
    int tiempoDeEspera;           // es eltiempo de respuesta
    int tiempoProcesado;           // es eltiempo que ya fue procesado en la l�nea de caja
    int tipo_cliente;             //  prioridad (1: embarazada, 2: jubilado y 3: normal)
    int tipo_pago;                //  1 efectivo, 2 cr�dito o d�bito, 3 todos
}persona;

void mostrarArchivoPersonas(char nombre []);

#endif // PERSONA_H_INCLUDED
