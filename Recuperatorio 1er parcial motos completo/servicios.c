#include "servicios.h"

#define VACIO 0
#define OCUPADO 1

void servicios_MostrarServicios(eServicio servicios[], int tamServicio)
{
    printf("\n\t\t ****************** SERVICIOS ******************\n\n");
    printf("\t\t _______________________________________________\n\n");
    printf("\t\t      ID         DESCRIPCION          PRECIO    \n");
    printf("\t\t _______________________________________________\n");

    for(int i=0; i<tamServicio; i++)
    {
        servicios_MostrarUnServicio(servicios[i]);
    }
}

void servicios_MostrarUnServicio(eServicio unServicio)
{
    printf("\n\t\t     %d       %10s           %.2f\n", unServicio.id, unServicio.descripcion, unServicio.precio);
}

int servicios_BuscarServicioPorId(int id, eServicio servicios[], int tamServicio)
{
    int retorno = -1;

    for(int i=0; i<tamServicio; i++)
    {
        if(servicios[i].id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
