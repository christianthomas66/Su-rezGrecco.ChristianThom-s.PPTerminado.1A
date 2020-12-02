#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "motos.h"
#include "tipo.h"
#include "color.h"
#include "servicios.h"
#include "trabajo.h"
#include "menu.h"
#include "informes.h"
#include "clientes.h"

#define TAM_MOTO 10
#define TAM_TIPO 4
#define TAM_COLOR 5
#define TAM_SERVICIO 4
#define TAM_TRABAJO 10
#define TAM_CLIENTES 10

#define HARCODEAR_TAM_MOTO 4
#define HARCODEAR_TAM_CLIENTES 3
#define HARCODEAR_TAM_TRABAJO 4


int main()
{
    eMoto listaMotos[TAM_MOTO];
    eTipo listaTipos[TAM_TIPO] = {{1000,"Enduro"}, {1001,"Chopera"}, {1002, "Scooter"}, {1003, "Ciclomotor"}};
    eColor listaColores[TAM_COLOR] = {{10000,"Gris"}, {10001,"Negro"}, {10002, "Blanco"}, {10003, "Azul"}, {10004, "Rojo"}};
    eServicio listaServicios[TAM_SERVICIO] = {{20000, "Limpieza", 250}, {20001, "Ajuste", 300}, {20002, "Balanceo", 17}, {20003, "Cadena", 190}};
    eTrabajo listaTrabajos[TAM_TRABAJO];
    eCliente listaClientes[TAM_CLIENTES] =
    {
    {1,"Juan",'m',},
    {2,"Roberto",'m'},
    {3,"Alejandra",'f'},
    {4,"Karen",'f'},
    {5,"Jorge",'m'},
    {6,"Clara",'f'},
    {7,"Carla",'f'},
    {8,"Alberto",'f'},
    {9,"Diaz",'f'},
    {10,"Mauro",'f'}
    };
    char cont = 's';
    char aux;
    int idMotoSiguiente = 1000;
    int idClienteSiguiente = 1;
    int idTrabajoSiguiente = 0;
    int flag = 0;


    motos_incializar(listaMotos, TAM_MOTO);
    trabajos_inicializar(listaTrabajos, TAM_TRABAJO);

    motos_harcodear(listaMotos, HARCODEAR_TAM_MOTO);
    idMotoSiguiente += HARCODEAR_TAM_MOTO;

    hardcodearClientes(listaClientes, TAM_CLIENTES);
    idClienteSiguiente += HARCODEAR_TAM_CLIENTES;


    trabajos_hardcodear(listaTrabajos, HARCODEAR_TAM_TRABAJO);
    idTrabajoSiguiente += HARCODEAR_TAM_TRABAJO;




    do
    {
        switch(menu_main())
        {
            case 1:
            printf("%d", TAM_MOTO);
            if(motos_AltaMoto(idMotoSiguiente,listaMotos, TAM_MOTO, listaTipos, TAM_TIPO, listaColores, TAM_COLOR, listaClientes, TAM_CLIENTES) == 1)
            {
                idMotoSiguiente++;
            }
            flag = 1;
            break;
            case 2:
            if(flag == 0)
            {
                printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
            }
            else
            {
                motos_BajaMoto(listaMotos, TAM_MOTO, listaTipos, TAM_TIPO, listaColores, TAM_COLOR);
            }
            break;
            case 3:
            if(flag == 0)
            {
                printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
            }
            else
            {

                motos_ModificarMoto(listaMotos, TAM_MOTO, listaTipos, TAM_TIPO, listaColores, TAM_COLOR);
            }

            break;
            case 4:

            if(flag == 0)
            {
                printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
            }
            else
            {
                motos_MostrarMotos(listaMotos, TAM_MOTO, listaTipos, TAM_TIPO, listaColores, TAM_COLOR);
                system("pause");
            }

            break;
            case 5:
            tipos_MostrarTipos(listaTipos, TAM_TIPO);
            system("pause");
            break;
            case 6:
            color_MostrarColores(listaColores, TAM_COLOR);
            system("pause");
            break;
            case 7:
            servicios_MostrarServicios(listaServicios, TAM_SERVICIO);
            system("pause");
            break;
            case 8:
            if(trabajos_AltaTrabajo(idTrabajoSiguiente, listaTrabajos, TAM_TRABAJO, listaMotos, TAM_MOTO, listaTipos, TAM_TIPO, listaColores, TAM_COLOR, listaServicios, TAM_SERVICIO) == 1)
            {
                idTrabajoSiguiente++;
            }
            break;
            case 9:
            trabajos_MostrarTrabajos(listaTrabajos, TAM_TRABAJO, listaMotos, TAM_MOTO, listaServicios, TAM_SERVICIO);
            system("pause");
            break;
            case 10:
            informar(listaMotos, TAM_MOTO, listaTipos, TAM_TIPO, listaColores, TAM_COLOR, listaServicios, TAM_SERVICIO, listaTrabajos, TAM_TRABAJO, listaClientes, TAM_CLIENTES);
            system("pause");
            break;
            case 11:
            printf("Seguro que desea salir? ");
            fflush(stdin);
            scanf("%c", &aux);
            while(aux != 's' && aux != 'n')
            {
                printf("Opcion incorrecta. Reingrese 's'(si) o 'n'(no)");
                printf(" s/n : \n");
                fflush(stdin);
                scanf("%c", &aux);
            }

            if(aux == 's')
            {
                printf("Gracias. Vuelva pronto!!!\n");
                return 0;
            }
            break;

        }
        system("pause");
        system("cls");
    }
    while(cont == 's');
    return 0;
}
