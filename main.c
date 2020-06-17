#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arboles.h"
#include "lista2.h"
#include "filas.h"
#include "persona.h"
#include "ArregloDeFilas.h"
#include "menus.h"


int main()
{
    char lista_personas[]= {"personas.bin"};
    char lista_cajas[]= {"cajas.bin"};

    nodoArbol*arbol=inicArbol();

    int dim=8;
    caja A[dim];

    int rta_menu=0, flag=0, flag2=0;
    char salir='n';

    while(salir=='n')
    {
        system("cls");
        printf("\n\n\t\t Bienvenidos al sistema de atencion de cajas \n\n\n");
        menuPrincipal();
        printf("\t\t Que opcion desea ejecutar?? ");
        fflush(stdin);
        scanf("%d",&rta_menu);
        switch(rta_menu)
        {
        case 0:
            printf("\n Seguro que desea salir?? <S/N> \n");
            fflush(stdin);
            scanf("%c",&salir);
            break;

        case 1:
            //system("cls");
            mostrarArchivoPersonas(lista_personas);
            system("PAUSE");
            break;

        case 2:
            system("cls");
            arbol=pasarArchivoToArbol(lista_personas, arbol);
            flag=1;
            printf("\n\n\t\tEl archivo fue pasado al arbol exitosamente\n\n\n");
            system("PAUSE");
            break;

        case 3:
            system("cls");
            if(flag==1)
                funcionSubMenuArbol(arbol);
            else
            {
                printf("\n\n\t\tEl arbol no contiene datos\n\n\n");
                system ("PAUSE");
            }
            break;

        case 4:
            system("cls");
            if(flag==1)
            {
                funcionMenuCajas(A, arbol);
                flag2=1;
            }
            else
            {
                printf("\n\n\t\tLas opciones de cajas no estan disponibles\n\n\n");
                system ("PAUSE");
            }
            break;

        case 5:
            system("cls");
            if(flag==1 && flag2==1)
                funcionMenuClientes(A);
            else
            {
                printf("\n\n\t\tLas opciones de clientes no estan disponibles\n\n\n");
                system ("PAUSE");
            }
            break;

        default:
            break;
        }
    }
    system("cls");
    nombreIntegrantes();
    system("PAUSE");

    return 0;
}
