#include "ArregloDeFilas.h"


void agregarCaja(caja A[8], char nombre[])
{
    FILE*archito;
    archito=fopen(nombre, "rb");
    caja aux;
    int i=0;

    if(archito!=NULL)
    {
        while(fread(&aux, sizeof(caja),1, archito)>0 && i<8)
        {
            A[i]=aux;
            i++;
        }
        fclose(archito);
    }
}

caja abrirOcerrarCaja(caja c)
{
    if(c.abiertaOcerrada==0)
    {
        c.abiertaOcerrada=1;
    }
    else
    {
        if(c.cantidadClientes==0)
        {
            c.abiertaOcerrada=0;
        }
        else
        {
            printf("La caja tiene clientes, no puede cerrarce");
        }
    }
    return c;
}

void abrirOcerrarCajaTodas(caja A[8])
{
    int i=0;

    while(i<8)
    {
        A[i]=abrirOcerrarCaja(A[i]);
        i++;
    }
}

int comprobarAbiertaCerrada(caja A[8])
{
    int i=0, flag=0;

    while(i<8 && flag==0)
    {
        caja c=A[i];

        if(c.abiertaOcerrada==1)
        {
            flag=1;
        }
        else
            i++;
    }

    return flag;
}

caja buscarCaja(caja A[8], int tipoPago)
{
    caja aux;
    int i=0, flag=0;

    while(i<8 && flag==0)
    {
        if(A[i].tipo_pago==tipoPago && (A[i].abiertaOcerrada==1))
        {
            aux=A[i];
            flag=1;
        }
        i++;
    }

    return aux;
}

void mostrarCaja(caja c)
{
    printf("Nro de Caja:  %d \n", c.nro_de_caja);
    printf("Nobre Cajero: %s \n", c.nombreCajero);
    if(c.tipo_pago==1)
        printf("Tipo de pago: efctivo \n");
    else if(c.tipo_pago==2)
        printf("Tipo de pago: credito/debito \n");
    else if(c.tipo_pago==3)
        printf("Tipo de pago: todos \n");
    if(c.abiertaOcerrada==0)
        printf("Caja Cerrada\n");
    else
        printf("Caja Abierta\n");
    printf("Algoritmo de planificacion: %s \n", c.algoritmoPlanificacion);
    printf("Cantidad de clientes: %d \n\n", c.cantidadClientes);
}

void mostrarCajaConFila(caja c)
{
    printf("Nro de Caja:  %d \n", c.nro_de_caja);
    printf("Nobre Cajero: %s \n", c.nombreCajero);
    if(c.tipo_pago==1)
        printf("Tipo de pago: efctivo \n");
    else if(c.tipo_pago==2)
        printf("Tipo de pago: credito/debito \n");
    else if(c.tipo_pago==3)
        printf("Tipo de pago: todos \n");
    if(c.abiertaOcerrada==0)
        printf("Caja Cerrada\n");
    else
        printf("Caja Abierta\n");
    printf("Algoritmo de planificacion: %s \n", c.algoritmoPlanificacion);
    printf("Cantidad de clientes: %d \n\n", c.cantidadClientes);
    mostrar(&c.filita);
}

void mostrarCajasTodas(caja A[8])
{
    int i=0;

    while(i<8)
    {
        mostrarCaja(A[i]);
        i++;
    }
}

void mostrarCajasTodasConFilas(caja A[8])
{
    int i=0;

    while(i<8)
    {
        mostrarCajaConFila(A[i]);
        system("PAUSE");
        system("cls");
        i++;
    }
}

caja fifoYrr(caja c, persona cliente)
{
    agregar(&c.filita, cliente);
    c.cantidadClientes+=1;

    return c;
}

caja sjf(caja c, persona cliente)
{
    agregarCantArt(&c.filita, cliente);
    c.cantidadClientes+=1;

    return c;
}

caja prioridadesAp(caja c, persona cliente)
{
    agregarTipoCli(&c.filita, cliente);
    c.cantidadClientes+=1;

    return c;
}


void agregarClienteACaja(caja A[8], persona cliente, int num)
{
    if(num==0 || num==1)
    {
        A[num]=fifoYrr(A[num],cliente);
    }
    else if(num==2 || num==3)
    {
        A[num]=sjf(A[num], cliente);
    }
    else if(num==4 || num==5)
    {
        A[num]=prioridadesAp(A[num], cliente);
    }
    else if(num==6 || num==7)
    {
        A[num]=fifoYrr(A[num], cliente);
    }
}

void agregarClienteACajaEnTiempoDeterminado(caja A[8])
{
    int cajaNum=0;
    persona aux;

    printf("Por favor complete los datos de la persona a ingresar:\n\n");
    printf("Nombre: ");
    fflush(stdin);
    gets(aux.nombreApellido);
    printf("\n");
    printf("Cantidad de articulos: ");
    fflush(stdin);
    scanf("%d", &aux.cantArticulos);
    printf("\n");
    printf("Tipo de cliente (1: embarazada, 2: jubilado y 3: normal): ");
    fflush(stdin);
    scanf("%d", &aux.tipo_cliente);
    printf("\n");
    while(aux.tipo_cliente>3)
    {
        printf("Opcion no valida, ingrese nuevamente:\n");
        fflush(stdin);
        scanf("%d",&aux.tipo_cliente);
    }
    printf("Tipo de pago (1 efectivo, 2 credito o debito, 3 todos): ");
    fflush(stdin);
    scanf("%d", &aux.tipo_pago);
    printf("\n");
    while(aux.tipo_pago>3)
    {
        printf("Opcion no valida, ingrese nuevamente:\n");
        fflush(stdin);
        scanf("%d",&aux.tipo_pago);
    }
    aux.tiempoDeEspera=0;
    aux.tiempoProcesado=0;
    printf("\n\n");

    printf("En que tiempo desea agregarlo?? ");
    fflush(stdin);
    scanf("%d",&aux.tiempoDeEspera);

    cajaNum=buscaMenorFila(A, aux);
    agregarClienteACaja(A, aux, cajaNum);

    system("cls");
    printf("\n\n\t\tEl nuevo cliente ha sido agregado a la caja %d\n\n", cajaNum+=1);
    system("PAUSE");
}

void calcularTiempoEspera(nodo2*a)
{
    nodo2*seg=a;

    while(seg!=NULL)
    {
        seg->cliente.tiempoDeEspera+=1;
        seg=seg->ste;
    }
}

caja atenderFifoSjfPrio(caja c)
{
    persona aux1;
    nodo2*aux2=c.filita.primero;
    caja aux;
    inicFila(&aux.filita);

    while(c.cantidadClientes>0)
    {
        if(c.filita.primero->cliente.cantArticulos>0)
        {
            c.filita.primero->cliente.cantArticulos-=1;
            c.filita.primero->cliente.tiempoProcesado+=1;
            calcularTiempoEspera(aux2->ste);
        }

        else if(c.filita.primero->cliente.cantArticulos==0)
        {
            aux1=extraer(&c.filita);
            agregar(&aux.filita, aux1);
            c.cantidadClientes-=1;
        }

        mostrarCajaConFila(c);
        Sleep(500);
        system("PAUSE");
        system("cls");
    }

    if(c.cantidadClientes==0)
    {
        printf("\n\n\t\tLa caja ha sido atendida completamente\n\n");
        system("PAUSE");
    }

    return aux;
}

caja atenderRR(caja c)
{
    int quantum=6;
    persona cambio, aux1;
    nodo2*aux2=c.filita.primero;
    caja aux;
    inicFila(&aux.filita);

    while(c.filita.primero!=NULL)
    {
        if(c.filita.primero->cliente.cantArticulos>0)
        {
            c.filita.primero->cliente.cantArticulos-=1;
            c.filita.primero->cliente.tiempoProcesado+=1;
            calcularTiempoEspera(aux2->ste);
            quantum-=1;

            if(quantum==0)
            {
                cambio=extraer(&c.filita);
                nodo2*nuevo=crearNodo(cambio);
                c.filita.ultimo=agregarAlFinal(c.filita.primero, nuevo);
                quantum=6;
            }
        }

        else if(c.filita.primero->cliente.cantArticulos==0)
        {
            aux1=extraer(&c.filita);
            agregar(&aux.filita, aux1);
            c.cantidadClientes-=1;
            quantum=6;
        }

        mostrarCajaConFila(c);
        Sleep(500);
        system("PAUSE");
        system("cls");
    }

    if(c.filita.primero==NULL)
    {
        printf("\n\n\t\tLa caja ha sido atendida completamente\n\n");
        system("PAUSE");
    }

    return aux;
}

void atenderClientes(caja c)
{
    if(c.nro_de_caja==7 || c.nro_de_caja==8)
    {
        c=atenderRR(c);
    }
    else
    {
        c=atenderFifoSjfPrio(c);
    }
}

int calcularCantArt(nodo2* sig)
{
    int cantArt=0;

    if(sig!=NULL)
    {
        cantArt=sig->cliente.tiempoProcesado+(calcularCantArt(sig->ste));
    }

    return cantArt;
}

int calcularCantEspera(nodo2* sig)
{
    int cantEspera=0;

    if(sig!=NULL)
    {
        cantEspera=sig->cliente.tiempoDeEspera+(calcularCantEspera(sig->ste));
    }

    return cantEspera;
}

void promediosProcesado(caja aux)
{
    int cantArt=0, cantEspera=0, cantClient=0;
    float promPro=0, promTiemp=0, prom=0;

    cantArt=calcularCantArt(aux.filita.primero);
    cantEspera=calcularCantEspera(aux.filita.primero);
    cantClient=aux.cantidadClientes;

    promPro=cantArt/cantClient;
    promTiemp=cantEspera/cantClient;
    prom=promPro/promTiemp;

    printf("\t\n\nTiempo de procesado: %.2f\n\n", promPro);
    printf("Tiempo de Espera: %.2f\n\n", promTiemp);
    printf("Promedio: %.2f\n\n", prom);
}
/*
procesado=cantidad de articulos/cant clientes
espera=tiempo de espera de todos/cant clientes
*/
