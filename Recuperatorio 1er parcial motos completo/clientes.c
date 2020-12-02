#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

void hardcodearClientes(eCliente clientes[], int tamCliente)
{
    int id[5] = {10,11,12,13,14};
    char nombres[5][30] = {"Juan", "Maria", "Alberto", "Mariano", "Marcela"};
    char sexos[5] = {'m', 'f', 'm', 'm', 'f'};

    for(int i=0; i<tamCliente; i++)
    {
        clientes[i].id = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].sexo = sexos[i];
    }
}

int clientes_CargarNombreCliente(char* nombre, int idPersona, eCliente* clientes, int tamClientes)
{
    int retorno = 0;
    for(int i = 0; i < tamClientes; i++)
    {
        if(clientes[i].id == idPersona)
        {
            strcpy(nombre, clientes[i].nombre);
            retorno = 1;
        }
    }
    return retorno;
}


void clientes_MostrarUnCliente(eCliente unCliente)
{
    printf("%d       %-10s        %c\n", unCliente.id, unCliente.nombre, unCliente.sexo);
}

void clientes_MostrarClientes(eCliente clientes[], int tamClientes)
{
    if(clientes != NULL && tamClientes > 0)
    {
        printf("\n  ID       NOMBRE   SEXO\n\n");
        for(int i=0; i<tamClientes; i++)
        {
            clientes_MostrarUnCliente(clientes[i]);
        }
        printf("\n");
    }
}
