#include "motos.h"
#include "servicios.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int estado;
}eTrabajo;


void trabajos_hardcodear(eTrabajo trabajos[], int harcodearTrabajos);

/** \brief Inicializa el array de trabajos en 0 o vacio
 *
 * \param trabajos[] eTrabajo El array de trabajos
 * \param tamTrabajo int El tamaño del array
 * \return void
 *
 */
void trabajos_inicializar(eTrabajo trabajos[], int tamTrabajo);
/** \brief Busca lugar libre en el array de trabajos para guardar nueva informacion
 *
 * \param trabajos[] eTrabajo El array de trabajos
 * \param tamTrabajo int El tamaño del array
 * \return int (El indice) para guardar datos, (-1) si no hay lugar libre
 *
 */
int trabajos_BuscarLibre(eTrabajo trabajos[], int tamTrabajo);
/** \brief Verifica la existencia de otro trabajo con el mismo ID
 *
 * \param id int El ID a buscar
 * \param trabajos[] eTrabajo El array de trabajos
 * \param tamTrabajo int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int trabajos_BuscarTrabajoPorId(int id, eTrabajo trabajos[], int tamTrabajo);

/** \brief Da de alta un trabajo
 *
 * \param id int ID incremental
 * \param trabajos[] eTrabajo El array de trabajos
 * \param tamTrabajo int El tamaño del array de trabajos
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos
 * \param tamTipos int El tamaño del array de tipos
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array de colores
 * \param servicios[] eServicio El array de servicios
 * \param tamServicios int El tamaño del array de servicios
 * \return int (1) si pudo dar de alta, (0) si no pudo
 *
 */
int trabajos_AltaTrabajo(int id, eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eServicio servicios[], int tamServicios);
/** \brief Muestra un listado de trabajos
 *
 * \param trabajos[] eTrabajo El array de trabajos
 * \param tamTrabajo int El tamaño del array de trabajos
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param servicios[] eServicio El array de servicios
 * \param tamServicios int El tamaño del array de servicios
 * \return void
 *
 */
void trabajos_MostrarTrabajos(eTrabajo trabajos[], int tamTrabajo, eMoto motos[], int tamMotos, eServicio servicios[], int tamServicios);
/** \brief Muestra solo un trabajo
 *
 * \param eTrabajo El trabajo a mostrar
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param servicios[] eServicio El array de servicios
 * \param tamServicios int El tamaño del array de servicios
 * \return void
 *
 */
void trabajos_MostrarUnTrabajo(eTrabajo unTrabajo, eMoto motos[], int tamMotos, eServicio servicios[], int tamServicios);


/** \brief Carga el nombre/marca de la moto
 *
 * \param descripcionMoto[] char Donde se cargara la informacion
 * \param id int El id de la estructura Moto
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int trabajos_CargarDescripcionMotoMarca(char descripcionMoto[], int id, eMoto motos[], int tamMotos);
/** \brief Carga la descripcion del servicio
 *
 * \param descripcionServicio[] char Donde se cargara la informacion
 * \param id int El id de la estructura Service
 * \param servicios[] eServicio El array de servicios
 * \param tamServicios int El tamaño del array de servicios
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int trabajos_CargarDescripcionServicio(char descripcionServicio[], int id, eServicio servicios[], int tamServicios);

#endif // TRABAJO_H_INCLUDED
