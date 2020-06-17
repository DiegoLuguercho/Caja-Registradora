#include "menus.h"
#

/*-------------------      menu principal    -----------------*/


void menuPrincipal()
{
    printf("\t [ Menu de Tareas ]\n\n");
    printf(" [ 1 ] Mostrar el archivo\n");
    printf(" [ 2 ] Pasar del archivo al arbol\n");
    printf(" [ 3 ] Mostrar el arbol\n");
    printf(" [ 4 ] Admin de CAJAS\n");
    printf(" [ 5 ] Admin de CLIENTES\n");
    printf("\n");
    printf(" [ 0 ] Cerrar cesion \n\n\n");
}

/*-------------------      sub menu mostrar arbol    -----------------*/


void subMenuArbol()
{
    printf("\n\n\n\t Sub Menu Arbol\n\n");
    printf("\t  1 - Mostrar Preorder\n");
    printf("\t  2 - Mostar Inorder\n");
    printf("\t  3 - Mostrar Postorder\n");
    printf("\n");
    printf("\t  0 - Volver al Menu de Tareas \n\n\n");
}

void funcionSubMenuArbol(nodoArbol*arbol)
{
    int rta_menu=0; // es la respuesta del while del menu
    char salir='n';

    while(salir=='n')
    {
        system("cls");
        subMenuArbol();
        printf("\t\t Que opcion desea ejecutar?? ");
        fflush(stdin);
        scanf("%d",&rta_menu);
        switch(rta_menu)
        {
        case 0:
            salir='s';
            break;

        case 1:
            system ("cls");
            mostrarPreorder(arbol);
            system ("PAUSE");
            break;

        case 2:
            system ("cls");
            mostrarInorder(arbol);
            system ("PAUSE");
            break;

        case 3:
            system("cls");
            mostrarPostorder(arbol);
            system ("PAUSE");
            break;

        default:
            break;
        }
    }
}

/*-------------------      menu cajas    -----------------*/


void menuCajas()
{
    printf("\n\n\n\t Menu de cajas\n\n");
    printf("\t  1 - Cargar cajas\n");
    printf("\t  2 - Mostrar cajas\n");
    printf("\t  3 - Abrir cajas\n");
    printf("\t  4 - Pasar del arbol al arreglo\n");
    printf("\n");
    printf("\t  0 - Volver al Menu de Tareas \n\n\n");
}

void funcionMenuCajas(caja A[8], nodoArbol*arbol)
{
    int i=0, flag=0,flag2=0;
    char lista_cajas[]= {"cajas.bin"};
    int rta_menu=0; // es la respuesta del while del menu
    char salir='n';

    while(salir=='n')
    {
        system("cls");
        menuCajas();
        printf("\t\t Que opcion desea ejecutar?? ");
        fflush(stdin);
        scanf("%d",&rta_menu);
        switch(rta_menu)
        {
        case 0:
            salir='s';
            break;

        case 1:
            system ("cls");
            if(flag==1)
            {
                printf("\n\n\t\tLas cajas ya estan cargadas\n\n\n");
                system("PAUSE");
            }

            else
            {
                agregarCaja(A, lista_cajas);
                flag=1;
                printf("\n\n\t\tLas cajas fueron cargadas exitosamente\n\n\n");
                system("PAUSE");
            }
            break;

        case 2:
            system ("cls");
            if(flag==1)
                mostrarCajasTodas(A);
            else
                printf("\n\n\t\tLas cajas no estan cargadas\n\n\n");
            system ("PAUSE");
            break;
        case 3:
            system("cls");
            if(flag==1)
                funcionSubMenuCajas(A);
            else
            {
                printf("\n\n\t\tLas cajas no estan cargadas\n\n\n");
                system ("PAUSE");
            }
            break;

        case 4:
            system("cls");
            if(flag==1)
            {
                flag2=comprobarAbiertaCerrada(A);
                if(flag2==1)
                {
                    printf("\n\nDe que manera desea pasar del arbol a las cajas??\n\n");
                    printf("\t  1 - Inorder\n");
                    printf("\t  2 - Preorder\n");
                    printf("\t  3 - Postorder\n\n");
                    fflush(stdin);
                    scanf("%d", &i);
                    while(i>3)
                    {
                        printf("Opcion no valida, ingrese nuevamente:\n\n");
                        fflush(stdin);
                        scanf("%d", &i);
                    }
                    pasarDeArbolToLineaDeCajas(i,arbol,A);
                    system("cls");
                    printf("\n\n\t\tEl pasaje fue hecho exitosamente\n\n");
                    system("PAUSE");
                }
                else
                {
                    printf("\n\n\t\tNo hay cajas abiertas\n\n\n");
                    system ("PAUSE");
                }
            }
            else
            {
                printf("\n\n\t\tLas cajas no estan cargadas\n\n\n");
                system ("PAUSE");
            }
            break;

        default:
            break;
        }
    }
}

/*-------------------      sub menu cajas    -----------------*/


void subMenuCajas()
{
    printf("\n\n\n\t Sub Menu de cajas\n\n");
    printf("\t  1 - Abrir/cerrar una caja\n");
    printf("\t  2 - Abrir/cerrar todas las cajas\n");
    printf("\n");
    printf("\t  0 - Volver al Menu de Cajas \n\n\n");
}

void funcionSubMenuCajas(caja A[8])
{
    int num=0;
    caja aux;
    int rta_menu=0; // es la respuesta del while del menu
    char salir='n';

    while(salir=='n')
    {
        system("cls");
        subMenuCajas();
        printf("\t\t Que opcion desea ejecutar?? ");
        fflush(stdin);
        scanf("%d",&rta_menu);
        switch(rta_menu)
        {
        case 0:
            salir='s';
            break;

        case 1:
            system ("cls");
            printf("Que caja desea abrir/cerrar??\n\n");
            fflush(stdin);
            scanf("%d", &num);
            aux=A[num-1];
            A[num-1]=abrirOcerrarCaja(aux);
            system ("cls");
            printf("\n\n\t\tLa caja %d fue abierta/cerrada\n\n", num);
            system("PAUSE");
            break;

        case 2:
            system ("cls");
            abrirOcerrarCajaTodas(A);
            printf("\n\n\t\tTodas las cajas fueron abiertas/cerradas\n\n");
            system("PAUSE");
            break;

        default:
            break;
        }
    }
}

/*-------------------      menu clientes    -----------------*/


void menuCliente()
{
    printf("\n\n\n\t Menu de clientes\n\n");
    printf("\t  1 - Mostrar todas las cajas\n");
    printf("\t  2 - Agregar cliente\n");
    printf("\t  3 - Seleccionar caja\n");
    printf("\n");
    printf("\t  0 - Volver al Menu de Tareas \n\n\n");
}

void funcionMenuClientes(caja A[8])
{
    int nume=0;
    caja aux;
    int rta_menu=0; // es la respuesta del while del menu
    char salir='n';


    while(salir=='n')
    {
        system("cls");
        menuCliente();
        printf("\t\t Que opcion desea ejecutar?? ");
        fflush(stdin);
        scanf("%d",&rta_menu);
        switch(rta_menu)
        {
        case 0:
            salir='s';
            break;

        case 1:
            system ("cls");
            mostrarCajasTodasConFilas(A);
            break;

        case 2:
            system ("cls");
            agregarClienteACajaEnTiempoDeterminado(A);
            break;

        case 3:
            system("cls");
            printf("A que caja desea acceder??\n\n");
            fflush(stdin);
            scanf("%d", &nume);
            aux=A[nume-1];
            system("cls");
            funcionSubMenuClientesSeleccionCajas(aux);
            break;

        default:
            break;
        }
    }
}

/*-------------------      sub menu clientes seleccion cajas    -----------------*/


void subMenuClientesSeleccionCajas()
{
    printf("\n\n\n\t Sub Menu Clientes Seleccion Cajas\n\n");
    printf("\t  1 - Atender caja\n");
    printf("\t  2 - Procesado\n");
    printf("\n");
    printf("\t  0 - Volver al Menu de Clientes \n\n\n");
}

void funcionSubMenuClientesSeleccionCajas(caja aux)
{
    int flag=0;
    int rta_menu=0; // es la respuesta del while del menu
    char salir='n';


    while(salir=='n')
    {
        system("cls");
        subMenuClientesSeleccionCajas();
        printf("\t\t Que opcion desea ejecutar?? ");
        fflush(stdin);
        scanf("%d",&rta_menu);
        switch(rta_menu)
        {
        case 0:
            salir='s';
            break;

        case 1:
            system ("cls");
            atenderClientes(aux);
            flag=1;
            break;

        case 2:
            system ("cls");
            if(flag==1)
            {
            promediosProcesado(aux);
            system ("PAUSE");
            }
            else
            {
                printf("\n\n\t\tLos clientes aun no han sido atendidos.\n\n");
                system("PAUSE");
            }
            break;

        default:
            break;
        }
    }
}

void nombreIntegrantes()
{
    printf("\n\n\t\tFernandez Cavassa Mariano Ezequiel\n");
    printf("\t\tLuguercho Diego\n\n\n\n\n");
}
