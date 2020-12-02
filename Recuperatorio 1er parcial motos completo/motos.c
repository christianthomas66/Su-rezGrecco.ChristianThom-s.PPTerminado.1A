#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "motos.h"

#include "utn.h"
#include "menu.h"

#define VACIO 0
#define OCUPADO 1




void motos_harcodear(eMoto motos[], int harcodearMotos)
{
    int ids[] = {1000,1001,1002,1003};
    char marca[][20] = {"Honda", "Suzuki", "Harley", "Yamaha"};
    int idTipo[] = {1000,1001,1002,1003};
    int idColor[] = {10000,10001,10002,10003,10004};
    int cilindradas[] = {50,125,500,600,750};
    int idCliente[] = {1,2,3,4};
    int idSuciedad[] = {1,2,3,4};

    for(int i=0; i<harcodearMotos; i++)
    {
        motos[i].id = ids[i];
        strcpy(motos[i].marca, marca[i]);
        motos[i].idTipo = idTipo[i];
        motos[i].idColor = idColor[i];
        motos[i].cilindrada =  cilindradas[i];
        motos[i].estado = OCUPADO;
        motos[i].idSuciedad = idSuciedad[i];
        motos[i].idCliente = idCliente[i];
    }
}

void motos_incializar(eMoto motos[], int tamMotos)
{
    for(int i=0; i<tamMotos; i++)
    {
        motos[i].estado = 0;
    }
}
int motos_BuscarLibre(eMoto motos[], int tamMotos)
{
    int retorno = -1;

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].estado == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int motos_BuscarMotoPorId(int id, eMoto motos[], int tamMotos)
{
    int retorno = -1;

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].id == id && motos[i].estado == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int motos_AltaMoto(int id, eMoto motos[], int tamMotos, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eCliente clientes[], int tamCliente)
{
    eMoto nuevaMoto;
    int indice = motos_BuscarLibre(motos, tamMotos);
    int retorno = 0;

    system("cls");
    printf("\n\t--- ALTA ----------------------------------------------------------\n\n");

    if(indice == -1)
    {
        printf("\n\n\t\t--- Sistema completo ---\n\n\n");
        system("pause");
    }
    else
    {

        nuevaMoto.id = id;

        getTexto(&nuevaMoto, "Ingrese su nombre: ","Error", 1,4, 3);
        getTexto(nuevaMoto.marca,"\n\tIngrese la marca: ", "\n\t(!) Error. Caracteres invalidos.\n", 2, 20, 4);

        tipos_MostrarTipos(tipos, tamTipo);
        getUnsignedInt(&nuevaMoto.idTipo,"\n\tIngrese ID del tipo: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 1000-1003\n",1, 1000, 3, 1003, 4);

        color_MostrarColores(colores, tamColor);
        getUnsignedInt(&nuevaMoto.idColor, "Ingrese el id del color: ","Error", 1, 10000, 3, 10004, 4);

        getUnsignedInt(&nuevaMoto.cilindrada,"\n\tIngrese la cilindrada: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 50-2500\n",1, 2500,50,2500,4);

        nuevaMoto.estado = 1;

        motos[indice] = nuevaMoto;

        printf("\n\n\t\t>>> Se ha dado de alta una moto con exito <<<\n\n\n");
        system("pause");
        system("cls");
        retorno = 1;

    }
    return retorno;
}

void motos_BajaMoto(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int id;
    int indice;

    system("cls");
    printf("\n\t*** BAJA ************************************************************************************\n\n");

    motos_MostrarMotos(motos, tamMotos, tipos, tamTipo, colores, tamColor);

    getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);

    indice = motos_BuscarMotoPorId(id, motos, tamMotos);

    if(indice == -1)
    {
        printf("\n\n\t\t>>> No hay registro de una moto con el Id: %d <<<\n\n\n", id);
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\t\tLa moto que se dara de baja es:");
        printf("\n\t\t _________________________________________________________________________________\n");
        printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA          ");
        printf("\n\t\t _________________________________________________________________________________\n");
        motos_MostrarUnaMoto(motos[indice], tipos, tamTipo, colores, tamColor);
        printf("\n\t\t _________________________________________________________________________________\n\n");

        if(confirm(2))
        {
            motos[indice].estado = VACIO;
        }
    }
}

void motos_ModificarMoto(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    int id;
    int indice;
    int nuevaCilindrada;
    int nuevoIdColor;

    system("cls");
    printf("\n\t*** MODIFICACION ****************************************************************************\n\n");

    motos_MostrarMotos(motos, tamMotos, tipos, tamTipo, colores, tamColor);

    getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);

    indice = motos_BuscarMotoPorId(id, motos, tamMotos);

    if(indice == -1)
    {
        printf("\n\n\t\t>>> No hay registro de una moto con el Is: %d <<<\n\n\n", id);
        system("pause");
    }
    else
    {
        system("cls");
        //printf("\n\t\tLa moto que se modificara es:");
        //printf("\n\t\t __________________________________________________________________________________\n");
        //printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA            ");
        //printf("\n\t\t __________________________________________________________________________________\n");
        //motos_MostrarUnaMoto(motos[indice], tipos, tamTipo, colores, tamColor);
        //printf("\n\t\t __________________________________________________________________________________\n\n");

        switch(menu_motoModificar())
        {
        case 1:
            color_MostrarColores(colores, tamColor);
            getUnsignedInt(&nuevoIdColor,"\n\tIngrese ID del color: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,100000,10000,100000,4);
            if(confirm(3))
            {
                motos[indice].idColor = nuevoIdColor;
            }
            break;
        case 2:
            getUnsignedInt(&nuevaCilindrada,"\n\tIngrese la cilindrada: ", "\n\t(!) Error. Ingrese un valor numerico entero desde 50 hasta 2500.\n",1,2500,50,2500,4);
            if(confirm(3))
            {
                motos[indice].cilindrada = nuevaCilindrada;
            }
            break;
        }

        printf("\n");
        printf("\n\t\t __________________________________________________________________________________\n");
        printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA          ");
        printf("\n\t\t __________________________________________________________________________________\n");
        motos_MostrarUnaMoto(motos[indice], tipos, tamTipo, colores, tamColor);
        printf("\n\t\t __________________________________________________________________________________\n\n");

        system("pause");
    }
}

void motos_MostrarMotos(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)//, eCliente clientes[], int tamClientes)
{
    int flag = 0;

    printf("\n\t\t ______________________________________________________________________________________\n");
    printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTES       ");
    printf("\n\t\t ______________________________________________________________________________________\n");
    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].estado == 1)
        {
            motos_MostrarUnaMoto(motos[i], tipos, tamTipo, colores, tamColor);
            flag = 1;
        }
    }
    printf("\n");
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay elementos para mostrar <<<\n\n\n");
    }
}

void motos_MostrarUnaMoto(eMoto unaMoto, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)//, eCliente clientes[], int tamCliente)
{
    char tipoDescripcion[20];
    char colorNombre[20];

    motos_CargarDescripcionTipo(tipoDescripcion, unaMoto.idTipo, tipos, tamTipo);
    motos_CargarDescripcionColor(colorNombre, unaMoto.idColor, colores, tamColor);


    printf("\n\t\t    %5d  %15s   %15s  %10s         %5d         \n", unaMoto.id, unaMoto.marca, tipoDescripcion, colorNombre, unaMoto.cilindrada);
}

void motos_OrdenarMotos(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipo, eColor colores[], int tamColor)
{
    eMoto auxMoto;

    for(int i=0; i<tamMotos-1; i++)
    {
        for(int j=i+1; i<tamMotos; i++)
        {
            if(motos[i].idTipo > motos[j].idTipo)
            {
                auxMoto = motos[i];
                motos[i] = motos[j];
                motos[j] = auxMoto;
            }
            else if(motos[i].idTipo == motos[j].idTipo && motos[i].id > motos[j].id)
            {
                auxMoto = motos[i];
                motos[i] = motos[j];
                motos[j] = auxMoto;
            }
        }
    }
}

int motos_CargarDescripcionTipo(char descripcionTipo[], int id, eTipo tipos[], int tamTipo)
{
    int retorno = 0;

    for(int i=0; i<tamTipo; i++)
    {
        if(tipos[i].id == id)
        {
            strcpy(descripcionTipo, tipos[i].descripcion);
            retorno = 1;
        }
    }
    return retorno;
}

int motos_CargarDescripcionColor(char descripcionColor[], int id, eColor colores[], int tamColor)
{
    int retorno = 0;

    for(int i=0; i<tamColor; i++)
    {
        if(colores[i].id == id)
        {
            strcpy(descripcionColor, colores[i].colorNombre);
            retorno = 1;
        }
    }
    return retorno;
}

