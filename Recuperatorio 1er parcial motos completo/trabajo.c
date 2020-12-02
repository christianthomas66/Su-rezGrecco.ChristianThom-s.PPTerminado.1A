#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"

#include "utn.h"
#include "menu.h"

#define VACIO 0
#define OCUPADO 1


void trabajos_hardcodear(eTrabajo trabajos[], int harcodearTrabajos)
{
    int idMotos[] = {1000,1001,1002,1003};//,1004,1005,1006,1007};
    int idServicio[] = {20000,20001,20002,20003};//,20004,20005,20006,20007};
    int idTrabajo[] = {0, 1, 2, 3,};// 4, 5, 6, 7};
    int dias[] = {21,1,2,6};//,8,19,21,29};
    int meses[] = {12,3,5,7};//,2,2,12,9};
    int anios[] = {2010,2010,2013,2019};//,2008,2016,2017,2016};

    for(int i=0; i<harcodearTrabajos; i++)
    {
        trabajos[i].id = idTrabajo[i];
        trabajos[i].idMoto = idMotos[i];
        trabajos[i].idServicio = idServicio[i];
        trabajos[i].fecha.dia = dias[i];
        trabajos[i].fecha.mes = meses[i];
        trabajos[i].fecha.anio = anios[i];
        trabajos[i].estado = OCUPADO;
    }
}
void trabajos_inicializar(eTrabajo trabajos[], int tamTrabajo)
{
    for(int i=0; i<tamTrabajo; i++)
    {
        trabajos[i].estado = VACIO;
    }
}
int trabajos_BuscarLibre(eTrabajo trabajos[], int tamTrabajo)
{
    int retorno = -1;

    for(int i=0; i<tamTrabajo; i++)
    {
        if(trabajos[i].estado == VACIO)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int trabajos_BuscarTrabajoPorId(int id, eTrabajo trabajos[], int tamTrabajo)
{
    int retorno = -1;

    for(int i=0; i<tamTrabajo; i++)
    {
        if(trabajos[i].id == id && trabajos[i].estado == OCUPADO)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int trabajos_AltaTrabajo(int id, eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eServicio servicios[], int tamServicios)
{
    eTrabajo nuevoTrabajo;
    int indice = trabajos_BuscarLibre(trabajos, tamTrabajo);
    int retorno = 0;
    int motoExistente;
    int servicioExistente;

    system("cls");
    printf("\n\t*** ALTA ************************************************************************************\n\n");

    if(indice == -1)
    {
        printf("\n\n\t\t>>> Sistema completo <<<\n\n\n");
        system("pause");
    }
    else
    {
        motos_MostrarMotos(motos, tamMotos, tipos, tamTipos, colores, tamColor);
        getUnsignedInt(&nuevoTrabajo.idMoto,"\n\tIngrese ID de la moto: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);
        motoExistente = motos_BuscarMotoPorId(nuevoTrabajo.idMoto, motos, tamMotos);
        if(motoExistente == -1)
        {
            printf("\n\n\t\t>>> No existe una moto con el ID ingresado <<<\n\n\n");
            system("pause");
        }
        else
        {
            servicios_MostrarServicios(servicios, tamServicios);
            getUnsignedInt(&nuevoTrabajo.idServicio,"\n\tIngrese ID del servicio: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango 20000-20003\n",1,20003,20000,20003,4);
            servicioExistente = servicios_BuscarServicioPorId(nuevoTrabajo.idServicio, servicios, tamServicios);

            if(servicioExistente == -1)
            {
                printf("\n\n\t\t>>> No existe un servicio con el ID ingresado <<<\n\n\n");
                system("pause");
            }
            else
            {
                getUnsignedInt(&nuevoTrabajo.fecha.dia,"\n\tIngrese dia: ", "\n\t(!) Error. Ingrese un valor numerico entero. Dia inexistente.\n",1,31,1,31,4);
                getUnsignedInt(&nuevoTrabajo.fecha.mes,"\n\tIngrese mes: ", "\n\t(!) Error. Ingrese un valor numerico entero. Mes inexistente.\n",1,12,1,12,4);
                getUnsignedInt(&nuevoTrabajo.fecha.anio,"\n\tIngrese año: ", "\n\t(!) Error. Ingrese un valor numerico entero. El anio debe ser entre 1990 y 2020.\n",1,2020,1,2020,4);

                while(getFecha(nuevoTrabajo.fecha.dia, nuevoTrabajo.fecha.mes, nuevoTrabajo.fecha.anio, 1990, 2020)==0)
                {
                    printf("\n\t(!) Error. Fecha no valida. \n");
                    getUnsignedInt(&nuevoTrabajo.fecha.dia,"\n\n\tIngrese dia: ", "\n\t(!) Error. Ingrese un valor numerico entero. Dia inexistente.\n",1,31,1,31,4);
                    getUnsignedInt(&nuevoTrabajo.fecha.mes,"\n\tIngrese mes: ", "\n\t(!) Error. Ingrese un valor numerico entero. Mes inexistente.\n",1,12,1,12,4);
                    getUnsignedInt(&nuevoTrabajo.fecha.anio,"\n\tIngrese año: ", "\n\t(!) Error. Ingrese un valor numerico entero entre 1990 y 2020.\n",1,2020,1,2020,4);
                }

                nuevoTrabajo.id = id;
                nuevoTrabajo.estado = OCUPADO;

                trabajos[indice] = nuevoTrabajo;

                printf("\n\n\t\t>>> Cargado exitosamente <<<\n\n\n");
                system("pause");

                retorno = 1;
            }
        }
    }
    return retorno;
}
void trabajos_MostrarTrabajos(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamMotos, eServicio servicios[], int tamServicios)
{
    int flag = 0;

    printf("\n\t\t ________________________________________________________________________\n");
    printf("\n\t\t     ID              MARCA           SERVICIO            FECHA          ");
    printf("\n\t\t ________________________________________________________________________\n");

    for(int i=0; i<tamTrabajo; i++)
    {
        if(trabajos[i].estado == OCUPADO)
        {
            trabajos_MostrarUnTrabajo(trabajos[i], motos, tamMotos, servicios, tamServicios);
            flag = 1;
        }
    }
    printf("\n");
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay elementos para mostrar <<<\n\n\n");
    }
}
void trabajos_MostrarUnTrabajo(eTrabajo unTrabajo, eMoto motos[], int tamMotos, eServicio servicios[], int tamServicios)
{
    char descripcionServicio[20];
    char descripcionMarca[20];

    trabajos_CargarDescripcionServicio(descripcionServicio, unTrabajo.idServicio, servicios, tamServicios);
    trabajos_CargarDescripcionMotoMarca(descripcionMarca, unTrabajo.idMoto, motos, tamMotos);

    printf("\n\t\t     %d     %15s         %10s           %2d / %2d / %4d   \n", unTrabajo.id, descripcionMarca, descripcionServicio, unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio);
}




int trabajos_CargarDescripcionMotoMarca(char descripcionMarca[], int id, eMoto motos[], int tamMotos)
{
    int retorno = 0;

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].id == id)
        {
            strcpy(descripcionMarca, motos[i].marca);
            retorno = 1;
        }
    }
    return retorno;
}
int trabajos_CargarDescripcionServicio(char descripcionServicio[], int id, eServicio servicios[], int tamServicios)
{
    int retorno = 0;
    for(int i=0; i<tamServicios; i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(descripcionServicio, servicios[i].descripcion);
            retorno = 1;
        }
    }
    return retorno;
}
