#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "motos.h"
#include "tipo.h"
#include "color.h"
#include "servicios.h"
#include "trabajo.h"
#include "informes.h"
#include "menu.h"
#include "utn.h"
#include "clientes.h"

void informar(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eServicio servicios[], int tamServicios, eTrabajo trabajos[], int tamTrabajo, eCliente clientes[], int tamCliente)
{
    char cont = 's';
    system("cls");
    do
    {
        switch(menu_informes())
        {
        case 1:
            informar_MotoPorColor(motos, tamMotos, tipos, tamTipos, colores, tamColor); // BIEN
            break;
        case 2:
            informar_MotoPorTipo(motos, tamMotos, tipos, tamTipos, colores, tamColor); // BIEN
            break;
        case 3:
            informar_MotoPorMayorCilindrada(motos, tamMotos, tipos, tamTipos, colores, tamColor); // BIEN
            break;
        case 4:
            informar_Motos_Todos_Los_Tipo(motos, tamMotos, tipos, tamTipos, colores, tamColor); // BIEN
            break;
        case 5:
            informar_MotoPorColorYTipo(motos, tamMotos, tipos, tamTipos, colores, tamColor); // BIEN
            break;
        case 6:
            informes_Motos_coloresMasElegidos(motos, tamMotos, colores, tamColor); // BIEN
            break;
        case 7:
            informar_MotoPorTrabajo(motos, tamMotos, tipos, tamTipos, colores, tamColor, trabajos, tamTrabajo, servicios, tamServicios); // BIEN
            break;
        case 8:
            informes_servicios_precio(motos, tamMotos, tipos, tamTipos, colores, tamColor, clientes, tamCliente, trabajos, tamTrabajo, servicios, tamServicios); // BIEN
            break;
        case 9:
            informar_ServiciosYMotos(motos, tamMotos, tipos, tamTipos, colores, tamColor, trabajos, tamTrabajo, servicios, tamServicios); // BIEN
            break;
        case 10:
            informar_ServiciosPorFecha(motos, tamMotos, tipos, tamTipos, colores, tamColor, trabajos, tamTrabajo, servicios, tamServicios); // BIEN
            break;
        case 11:
            cont = 'n';
            break;
        }
    }
    while(cont == 'y');
}

void informar_MotoPorColor(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor) // 1
{
    int flag = 0;
    int idColor;

    system("cls");
    printf("\n *** MOTOS POR COLOR *****************************************************************************\n\n");

    color_MostrarColores(colores, tamColor);
    getUnsignedInt(&idColor,"\n\tIngrese ID del color: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,100000,10000,100000,4);

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].estado == 1 && motos[i].idColor == idColor)
        {
            printf("\n\t\t _____________________________________________________________________________\n");
            printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA    ");
            printf("\n\t\t _____________________________________________________________________________\n");

            motos_MostrarUnaMoto(motos[i], tipos, tamTipos, colores, tamColor);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay motos de ese color <<<\n");
    }
}
void informar_MotoPorTipo(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor) // 2
{
    int flag = 0;
    int idTipo;

    system("cls");
    printf("\n *** MOTOS POR TIPO *****************************************************************************\n\n");

    tipos_MostrarTipos(tipos, tamTipos);
    getUnsignedInt(&idTipo,"\n\tIngrese ID del tipo: ", "\n\t(!) Error. Ingrese un valor numerico entero a partir de 1000\n",1,10000,1000,10000,4);

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].estado == 1 && motos[i].idTipo == idTipo)
        {
            printf("\n\t\t _____________________________________________________________________________\n");
            printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA    ");
            printf("\n\t\t _____________________________________________________________________________\n");

            motos_MostrarUnaMoto(motos[i], tipos, tamTipos, colores, tamColor);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay motos de ese tipo <<<\n");
    }
}
void informar_MotoPorMayorCilindrada(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor) // 3
{
    int mayorCilindrada = 0;

    system("cls");
    printf("\n *** MAYOR CILINDRADA *********************************************\n\n");

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].estado == 1)
        {
            if(motos[i].cilindrada > mayorCilindrada)
            {
                mayorCilindrada = motos[i].cilindrada;
            }
        }
    }
    printf("\nLa mayor cilindrada es %d y la/s motos son: ", mayorCilindrada);

    printf("\n\t\t _____________________________________________________________________________\n");
    printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA    ");
    printf("\n\t\t _____________________________________________________________________________\n");

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].cilindrada == mayorCilindrada)
        {
            motos_MostrarUnaMoto(motos[i], tipos, tamTipos, colores, tamColor);
        }
    }
}
void informar_Motos_Todos_Los_Tipo(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor) // 4
{

    system("cls");
    printf("\n *** MOTOS DE TODOS LOS TIPOS *********************************************\n\n");

    for(int i=0; i<tamTipos; i++)
    {

        printf("\n\n\n\n\nTipo: %s", tipos[i].descripcion);

        for(int j=0; j<tamMotos; j++)
        {
            if(motos[j].estado == 1 && motos[j].idTipo == tipos[i].id)
            {
                printf("\n\t\t _____________________________________________________________________________\n");
                printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA    ");
                printf("\n\t\t _____________________________________________________________________________\n");
                motos_MostrarUnaMoto(motos[j], tipos, tamTipos, colores, tamColor);
            }
        }
    }
}
void informar_MotoPorColorYTipo(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor) // 5
{
    int flag = 0;
    int idColor;
    int idTipo;
    int indiceColor;
    int indiceTipo;
    int contador = 0;

    system("cls");
    printf("\n *** CONTADOR DE MOTOS POR COLOR Y TIPO *****************************************************************************\n\n");

    color_MostrarColores(colores, tamColor);
    getUnsignedInt(&idColor,"\n\tIngrese ID del color: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,100000,10000,100000,4);

    tipos_MostrarTipos(tipos, tamTipos);
    getUnsignedInt(&idTipo,"\n\tIngrese ID del tipo: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,10000,1000,10000,4);

    indiceColor = color_BuscarColorPorId(idColor, colores, tamColor);
    indiceTipo = tipos_BuscarTipoPorId(idTipo, tipos, tamTipos);

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].estado == 1 && motos[i].idColor == idColor && motos[i].idTipo == idTipo)
        {
            contador++;
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\n\n\t\t>>> No hay motos de ese color y tipo <<<\n");
    }
    else
    {
        printf("\n\n\t\t>>> Hay %d motos del color %s y del tipo %s <<<\n", contador, colores[indiceColor].colorNombre, tipos[indiceTipo].descripcion);
        system("pause");
    }
}



int informes_Motos_coloresMasElegidos(eMoto motos[], int tamMotos, eColor colores[], int tamColor)
{
    int retorno = -1;
    int contadorGris = 0;
    int contadorNegro = 0;
    int contadorBlanco = 0;
    int contadorAzul = 0;
    int contadorRojo = 0;
    char descripcionColor[21];

    if(motos != NULL && tamMotos > 0 && colores != NULL && tamColor > 0)
    {
        for(int i = 0; i < tamMotos; i++)
        {
            switch(motos[i].idColor)
            {
            case 10000:
                contadorGris++;
                break;
            case 10001:
                contadorNegro++;
                break;
            case 10002:
                contadorBlanco++;
                break;
            case 10003:
                contadorAzul++;
                break;
            case 10004:
                contadorRojo++;
                break;
            }
        }
        system("cls");
        if(contadorGris > contadorNegro && contadorGris > contadorBlanco && contadorGris > contadorAzul && contadorGris > contadorRojo)
        {
            color_cargarNombre(colores, tamColor, 10000, descripcionColor);
            printf("\nEl tipo mas elegido es %s\n", descripcionColor);
        }
        else if(contadorNegro >= contadorGris && contadorNegro > contadorBlanco && contadorNegro > contadorAzul && contadorNegro > contadorRojo)
        {
            color_cargarNombre(colores, tamColor, 10001, descripcionColor);
            printf("\nEl tipo mas elegido es %s\n", descripcionColor);
        }
        else if(contadorBlanco >= contadorNegro && contadorBlanco > contadorGris && contadorBlanco > contadorAzul && contadorBlanco > contadorRojo)
        {
            color_cargarNombre(colores, tamColor, 10002, descripcionColor);
            printf("\nEl tipo mas elegido es %s\n", descripcionColor);
        }
        else if(contadorAzul >= contadorBlanco && contadorAzul > contadorGris && contadorAzul > contadorNegro && contadorAzul > contadorRojo)
        {
            color_cargarNombre(colores, tamColor, 10003, descripcionColor);
            printf("\nEl tipo mas elegido es %s\n", descripcionColor);
        }
        else
        {
            color_cargarNombre(colores, tamColor, 10004, descripcionColor);
            printf("\nEl tipo mas elegido es %s\n", descripcionColor);
        }
        retorno = 0;
    }
    return retorno;
}

void informar_MotoPorTrabajo(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicios) // 7
{
    int flag = 0;
    int idMoto;

    system("cls");
    printf("\n *** TODOS LOS TRABAJOS DE UNA MOTO *****************************************************************************\n\n");

    motos_MostrarMotos(motos, tamMotos, tipos, tamTipos, colores, tamColor);
    getUnsignedInt(&idMoto,"\n\tIngrese ID de la moto: ", "\n\t(!) Error. Ingrese un valor numerico entero a partir de 1000\n",1,10000,1000,10000,4);

    for(int i=0; i<tamTrabajo; i++)
    {
        if(trabajos[i].estado == 1 && trabajos[i].idMoto == idMoto)
        {
            printf("\n\t\t ________________________________________________________________________\n");
            printf("\n\t\t     ID              MARCA           SERVICIO            FECHA          ");
            printf("\n\t\t ________________________________________________________________________\n");
            trabajos_MostrarUnTrabajo(trabajos[i], motos, tamMotos, servicios, tamServicios);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay trabajos realizados en esta moto <<<\n");
    }
}


int informes_servicios_precio(eMoto* motos, int tamMotos, eTipo* tipos, int tamTipos, eColor* colores, int tamColor, eCliente* clientes, int tamClientes, eTrabajo* trabajos, int tamTrabajos, eServicio* servicios, int tamServicios)
{
    int error = -1;
    int motoValida;
    int motoIdValida;
    int idServicioActual;
    float acumPrecio = 0;

    if(
        motos != NULL &&
        tamMotos > 0 &&
        tipos != NULL &&
        tamTipos > 0 &&
        colores != NULL &&
        tamColor > 0 &&
        clientes != NULL &&
        tamClientes > 0 &&
        trabajos != NULL &&
        tamTrabajos > 0 &&
        servicios != NULL &&
        tamServicios > 0
    )
    {
        //Pedir bici
        system("cls");
        printf("\n Ingrese ID bicicleta\n");
        motos_MostrarMotos(motos, tamMotos, tipos, tamTipos, colores, tamColor);
        printf("\nIngrese ID: ");
        fflush(stdin);
        scanf("%d", &motoValida);
        motoIdValida = motos_BuscarMotoPorId(motoValida, motos, tamMotos);
        while(motoIdValida < 0)
        {
            printf("\n Dato invalido. Ingrese ID bicicleta: ");
            fflush(stdin);
            scanf("%d", &motoValida);
            motoIdValida = motos_BuscarMotoPorId(motoValida, motos, tamMotos);
        }
        for(int i = 0; i < tamTrabajos; i++)
        {
            if(trabajos[i].idMoto == motoValida)
            {
                idServicioActual = trabajos[i].idServicio;
                for(int j = 0; j < tamServicios; j++)
                {
                    if(servicios[j].id == idServicioActual)
                    {
                        acumPrecio += servicios[j].precio;
                    }
                }
            }
        }
        printf("\nTotal trabajos realizados en esta bicicleta: $ %.2f\n", acumPrecio);
        error = 0;
    }
    return error;
}

void informar_ServiciosYMotos(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicios) // 9
{
    int flag = 0;
    int idServicio;

    system("cls");
    printf("\n *** MOTOS CON SERVICIOS REALIZADOS *****************************************************************************\n\n");

    servicios_MostrarServicios(servicios, tamServicios);
    getUnsignedInt(&idServicio,"\n\tIngrese ID del servicio: ", "\n\t(!) Error. Ingrese un valor numerico entero a partir de 20000\n",1,30000,20000,30000,4);

    for(int i=0; i<tamTrabajo; i++)
    {
        if(trabajos[i].estado == 1 && trabajos[i].idServicio == idServicio)
        {
            trabajos_MostrarUnTrabajo(trabajos[i], motos, tamMotos, servicios, tamServicios);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay motos a las que se les haya realizado ese servicio <<<\n");
    }
}
void informar_ServiciosPorFecha(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicios) // 10
{
    int flag = 0;
    eTrabajo auxTrabajo;

    system("cls");
    printf("\n *** SERVICIOS POR FECHA *****************************************************************************\n\n");

    getUnsignedInt(&auxTrabajo.fecha.dia,"\n\tIngrese dia: ", "\n\t(!) Error. Ingrese un valor numerico entero. Dia inexistente.\n",1,31,1,31,4);
    getUnsignedInt(&auxTrabajo.fecha.mes,"\n\tIngrese mes: ", "\n\t(!) Error. Ingrese un valor numerico entero. Mes inexistente.\n",1,12,1,12,4);
    getUnsignedInt(&auxTrabajo.fecha.anio,"\n\tIngrese anio: ", "\n\t(!) Error. Ingrese un valor numerico entero. El anio debe ser entre 1990 y 2020.\n",1,2020,1,2020,4);

    while(getFecha(auxTrabajo.fecha.dia, auxTrabajo.fecha.mes, auxTrabajo.fecha.anio, 1990, 2020) == 0)
    {
        printf("\n\t(!) Error. Fecha no valida. \n");
        getUnsignedInt(&auxTrabajo.fecha.dia,"\n\n\tIngrese dia: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,31,1,31,4);
        getUnsignedInt(&auxTrabajo.fecha.mes,"\n\tIngrese mes: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,12,1,12,4);
        getUnsignedInt(&auxTrabajo.fecha.anio,"\n\tIngrese anio: ", "\n\t(!) Error. Ingrese un valor numerico entero entre 1990 y 2020.\n",1,2020,1,2020,4);
    }

    for(int i=0; i<tamTrabajo; i++)
    {
        if(trabajos[i].estado == 1 && (trabajos[i].fecha.dia == auxTrabajo.fecha.dia) && (trabajos[i].fecha.mes == auxTrabajo.fecha.mes) && (trabajos[i].fecha.anio == auxTrabajo.fecha.anio))
        {
            trabajos_MostrarUnTrabajo(trabajos[i], motos, tamMotos, servicios, tamServicios);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\n\t\t>>> No se realizaron servicios en esa fecha <<<\n");
    }
}

