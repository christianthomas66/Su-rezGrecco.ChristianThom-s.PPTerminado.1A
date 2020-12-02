#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "suciedad.h"

void suciedad_MostrarUnaSuciedad(eSuciedad unaSuciedad)
{
    printf(" %d       %-10s        %d hs\n", unaSuciedad.id, unaSuciedad.descripcion, unaSuciedad.tiempo);
}

void suciedad_MostrarSuciedades(eSuciedad suciedades[], int tamSuciedad) // 11
{
    system("cls");
    printf("**** Listado de partes sucias posibles ****\n\n");
    printf(" ID     Descripcion   Tiempo a dedicar \n\n");
    for(int i = 0 ; i < tamSuciedad; i++)
    {
        suciedad_MostrarUnaSuciedad(suciedades[i]);
    }
    printf("\n\n");
}

int suciedad_BuscarSuciedadPorId(int id, eSuciedad suciedades[], int tamSuciedad)
{
    int retorno = -1;

    for(int i=0; i<tamSuciedad; i++)
    {
        if(suciedades[i].id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int suciedad_CargarDescripcionSuciedad(char descripcion[], int idSuc, eSuciedad suciedades[], int tamSuciedad)
{
    int retorno = 0;
    for(int i = 0; i < tamSuciedad; i++)
    {
        if(suciedades[i].id == idSuc)
        {
            strcpy(descripcion, suciedades[i].descripcion);
            retorno = 1;
        }
    }
    return retorno;
}
