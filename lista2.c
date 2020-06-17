#include <string.h>
#include "lista2.h"


nodo2*inicLista()
{
    return NULL;
}

nodo2*crearNodo(persona cliente)
{
    nodo2*aux=(nodo2 *)malloc(sizeof(nodo2));
    strcpy(aux->cliente.nombreApellido, cliente.nombreApellido);
    aux->cliente.cantArticulos=cliente.cantArticulos;
    aux->cliente.tiempoDeEspera=cliente.tiempoDeEspera;
    aux->cliente.tiempoProcesado=cliente.tiempoProcesado;
    aux->cliente.tipo_cliente=cliente.tipo_cliente;
    aux->cliente.tipo_pago=cliente.tipo_pago;
    aux->ante=NULL;
    aux->ste=NULL;
    return aux;
}
nodo2*nuevodato()
{
    persona cliente;

    nodo2*nuevonodo=crearNodo(cliente);
    return nuevonodo;
}
nodo2*agregarAlPrincipio(nodo2*lista, nodo2*nuevoNodo)
{
    nuevoNodo->ste=lista;

    if(lista!=NULL)
    {
        lista->ante=nuevoNodo;
    }
    return nuevoNodo;
}

// recursivo
nodo2*buscarUltimoR(nodo2*lista)
{
    nodo2*rta=NULL;

    if(lista!=NULL)
    {
        if(lista->ste==NULL)
        {
            rta=lista;
        }
        else
        {
            rta=buscarUltimoR(lista->ste);
        }
    }
    return rta;
}

nodo2*agregarAlFinal(nodo2*lista, nodo2*nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nodo2*ultimo=buscarUltimoR(lista);
        ultimo->ste=nuevoNodo;
        nuevoNodo->ante=ultimo;
    }
    return lista;
}

nodo2*agregarEnOrdenTipoCli(nodo2*lista, nodo2*nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else if (nuevoNodo->cliente.tipo_cliente<lista->cliente.tipo_cliente)
    {
        lista=agregarAlPrincipio(lista, nuevoNodo);
    }
    else
    {
        nodo2*anterior=lista;
        nodo2*seg=lista->ste;

        while(seg!=NULL && seg->cliente.tipo_cliente < nuevoNodo->cliente.tipo_cliente)
        {
            anterior=seg;
            seg=seg->ste;
        }

        anterior->ste=nuevoNodo;

        nuevoNodo->ante=anterior;
        nuevoNodo->ste=seg;

        if(seg!=NULL)
        {
            seg->ante= nuevoNodo;
        }
    }
    return lista;
}

nodo2*agregarEnOrdenPorCant(nodo2*lista, nodo2*nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else if (nuevoNodo->cliente.cantArticulos<lista->cliente.cantArticulos)
    {
        lista=agregarAlPrincipio(lista, nuevoNodo);
    }
    else
    {

        nodo2*anterior=lista;
        nodo2*seg=lista->ste;

        while(seg!=NULL && seg->cliente.cantArticulos<nuevoNodo->cliente.cantArticulos)
        {
            anterior=seg;
            seg=seg->ste;
        }

        anterior->ste=nuevoNodo;

        nuevoNodo->ante=anterior;
        nuevoNodo->ste=seg;

        if(seg!=NULL)
        {
            seg->ante= nuevoNodo;
        }
    }
    return lista;
}

void mostrarNodo(nodo2*aux)
{
    puts("---------------------------------------------");
    printf("Nombre: %s\n", aux->cliente.nombreApellido);
    printf("Cantidad de articulos: %d\n", aux->cliente.cantArticulos);
    printf("Tiempo de espera: %d\n", aux->cliente.tiempoDeEspera);
    printf("Tiempo de procesado: %d\n", aux->cliente.tiempoProcesado);
    if(aux->cliente.tipo_cliente==1)
        printf("Tipo de cliente: embarazada\n");
    else if(aux->cliente.tipo_cliente==2)
        printf("Tipo de cliente: jubilado\n");
    else if(aux->cliente.tipo_cliente==3)
        printf("Tipo de cliente: normal\n");
    if(aux->cliente.tipo_pago==1)
        printf("Tipo de pago: efectivo\n");
    else if(aux->cliente.tipo_pago==2)
        printf("Tipo de pago: credito/debito\n");
    else if(aux->cliente.tipo_pago==3)
        printf("Tipo de pago: todos\n");
    puts("---------------------------------------------\n");
}

void recorrerYmostrar(nodo2*lista)
{
    nodo2*seg=lista;

    printf("\nContenido de la fila:\n\n");

    if(seg==NULL)
    {
        printf("\t\t////////////////////////////////\n");
        printf("\t\t//No hay clientes en esta fila//\n");
        printf("\t\t////////////////////////////////\n\n");
    }
    else
    {
        while(seg!=NULL)
        {
            mostrarNodo(seg);
            seg=seg->ste;
        }
        printf("\n");
    }
}

nodo2*borrarNodo(nodo2*lista, char nombre[40])
{
    nodo2*aBorrar=NULL;
    nodo2*seg=NULL;

    if(lista!=NULL)
    {
        if(strcmp(lista->cliente.nombreApellido, nombre)==0)
        {
            aBorrar=lista;

            lista=lista->ste;
            if(lista!=NULL)
                lista->ante=NULL;

            free(aBorrar);
        }
        else
        {
            seg=lista->ste;
            while(seg!=NULL && (strcmp(seg->cliente.nombreApellido,nombre!=0)))
            {
                seg=seg->ste;
            }

            if( seg!= NULL)
            {
                nodo2*anterior=seg->ante;

                anterior->ste = seg->ste;

                if(seg->ste)
                {
                    nodo2*siguiente = seg->ste;
                    siguiente->ante=anterior;
                }
                free(seg);
            }
        }
    }

    return lista;
}

nodo2*borrarPrimero(nodo2*lista)
{
    nodo2*aux=lista;
    lista=lista->ste;
    free(aux);

    return lista;
}
