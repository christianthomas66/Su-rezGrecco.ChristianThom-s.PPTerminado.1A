#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"

void color_MostrarColores(eColor colores[], int tamColor)
{
    printf("\n\t\t ******************** COLORES ********************\n\n");
    printf("\t\t _______________________________________________\n\n");
    printf("\t\t        ID                    NOMBRE            \n");
    printf("\t\t _______________________________________________\n");

    for(int i=0; i<tamColor; i++)
    {
        color_MostrarUnColor(colores[i]);
    }
}

void color_MostrarUnColor(eColor color)
{
    printf("\n\t\t       %d              %10s\n", color.id, color.colorNombre);
}

int color_BuscarColorPorId(int id, eColor colores[], int tamColor)
{
    int retorno = -1;

    for(int i=0; i<tamColor; i++)
    {
        if(colores[i].id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int color_cargarNombre(eColor* colores, int tamColor, int id, char* nombre)
{
    int error = -1;

    if(colores != NULL && nombre != NULL && tamColor > 0)
    {
        for(int i = 0; i < tamColor; i++)
        {
            if(colores[i].id == id)
            {
                strcpy(nombre, colores[i].colorNombre);
                error = 0;
                break;
            }
        }
    }
    return error;
}
