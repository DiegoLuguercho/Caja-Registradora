#include "persona.h"


void mostrarArchivoPersonas(char nombre [])
{
    FILE*archi;
    archi=fopen(nombre, "rb");
    persona aux;
    if(archi!=NULL)
    {
        printf("Lista de las personas:\n\n");
        while(fread(&aux, sizeof(persona), 1, archi)>0)
        {
            printf("Nombre: %s \n",aux.nombreApellido);
            printf("Cantidad de articulos: [%d] \n",aux.cantArticulos);
            if(aux.tipo_cliente==1)
                printf("Tipo de cliente: embarazada \n");
            else if(aux.tipo_cliente==2)
                printf("Tipo de cliente: jubilado \n");
            else if(aux.tipo_cliente==3)
                printf("Tipo de cliente: normal \n");
            if(aux.tipo_pago==1)
                printf("Tipo de pago: efectivo \n");
            else if(aux.tipo_pago==2)
                printf("Tipo de pago: credito/debito\n");
            else if(aux.tipo_pago==3)
                printf("Tipo de pago: todos\n");
            printf("Tiempo de espera: [%d] \n", aux.tiempoDeEspera);
            printf("Tiempo de procesado: [%d] \n" ,aux.tiempoProcesado);
            printf("\n\n");
        }
        printf("\n\n");
    }
    fclose(archi);
}

