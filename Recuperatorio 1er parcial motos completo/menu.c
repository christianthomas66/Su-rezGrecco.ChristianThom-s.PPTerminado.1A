#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "utn.h"


int menu_main()
{
    int option;

    printf("\n");
    printf("---------- MENU ----------\n");
    printf("1) ALTA DE MOTO\n");
    printf("2) BAJA DE MOTO\n");
    printf("3) MODIFICACION DE MOTO\n");
    printf("4) LISTAR MOTOS\n");
    printf("5) LISTAR TIPOS\n");
    printf("6) LISTAR COLORES\n");
    printf("7) LISTAR SERVICIOS\n");
    printf("8) ALTA TRABAJO\n");
    printf("9) LISTAR TRABAJOS\n");
    printf("10) INFORMES\n");
    printf("11) SALIR\n");
    printf("\n");
    option = getOption(11);
    system("cls");

	return option;
}

int menu_motoModificar()
{
    int option;

    printf("\n");
    printf("----------- MENU MODIFICAR ----------\n");
    printf("1) COLOR\n");
    printf("2) CILINDRADA\n");
    printf("3) VOLVER\n");
    printf("\n");

    option = getOption(3);

    return option;
}

int menu_informes()
{
    int option;

    printf("---------- INFORMES ----------\n");
    printf("\n");
    printf("1) INFORME MOTOS POR COLOR\n");
    printf("2) INFORME MOTOS POR TIPO\n");
    printf("3) INFORME MOTO CON MAYOR CILINDRADA\n");
    printf("4) INFORME MOTOS SEPARADAS POR TIPOS\n");
    printf("5) INFORME MOTOS CONTADAS POR COLOR Y TIPO\n");
    printf("6) INFORME LOS COLORES MAS ELEGIDOS POR CLIENTES\n");
    printf("7) INFORME TODOS LOS TRABAJOS DE UNA MOTO\n");
    printf("8) INFORME SUMA DE IMPORTES DE LOS SERVICIOS\n");
    printf("9) INFORME MOTOS CON SERVICIOS REALIZADOS\n");
    printf("10) INFORME SERVICIOS DE UNA FECHA\n");
    printf("11) VOLVER\n");

    printf("\n");
    option = getOption(18);


    return option;
}

