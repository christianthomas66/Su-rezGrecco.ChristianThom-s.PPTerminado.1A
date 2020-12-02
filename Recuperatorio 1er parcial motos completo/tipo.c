#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipo.h"

void tipos_MostrarTipos(eTipo tipos[], int tamTipo)
{
    printf("\n\t\t ******************** TIPOS ********************\n\n");
    printf("\t\t _______________________________________________\n\n");
    printf("\t\t        ID                    DESCRIPCION       \n");
    printf("\t\t _______________________________________________\n");

    for(int i=0; i<tamTipo; i++)
    {
        tipos_MostrarUnTipo(tipos[i]);
    }
}

void tipos_MostrarUnTipo(eTipo unTipo)
{
    printf("\n\t\t       %d                  %10s\n", unTipo.id, unTipo.descripcion);
}

int tipos_BuscarTipoPorId(int id, eTipo tipos[], int tamTipo)
{
    int retorno = -1;

    for(int i=0; i<tamTipo; i++)
    {
        if(tipos[i].id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
