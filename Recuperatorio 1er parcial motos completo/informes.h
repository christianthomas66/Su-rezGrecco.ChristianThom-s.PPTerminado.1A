#include "clientes.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief Muestra el menu de informes y hace lo indicado en la opcion
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos
 * \param tamTipos int El tamaño del array de tipos
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array de colores
 * \param servicios[] eServicio El array de servicios
 * \param tamServicios int El tamaño del array de servicios
 * \param trabajos[] eTrabajo El array de trabajos
 * \param tamTrabajo int El tamaño del array de trabajos
 * \return void
 *
 */
void informar(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eServicio servicios[], int tamServicios, eTrabajo trabajos[], int tamTrabajo, eCliente clientes[], int tamCliente);


/** \brief Muestra las motos del color seleccionado por el usuario
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos
 * \param tamTipos int El tamaño del array de tipos
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array de colores
 * \return void
 *
 */
void informar_MotoPorColor(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor); // 1
/** \brief Muestra las motos del tipo seleccionado por el usuario
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos
 * \param tamTipos int El tamaño del array de tipos
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array de colores
 * \return void
 *
 */
void informar_MotoPorTipo(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor); // 2
/** \brief Informa la o las motos de mayor cilindrada
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos
 * \param tamTipos int El tamaño del array de tipos
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array de colores
 * \return void
 *
 */
void informar_MotoPorMayorCilindrada(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor); // 3
/** \brief Muestra un listado de las motos separadas por tipo
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos
 * \param tamTipos int El tamaño del array de tipos
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array de colores
 * \return void
 *
 */
 void informar_Motos_Todos_Los_Tipo(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor);

int informes_Motos_coloresMasElegidos(eMoto motos[], int tamMotos, eColor colores[], int tamColor); // 4
/** \brief Informa la cantidad de motos que hay de un tipo y color ingresado por el usuario
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos
 * \param tamTipos int El tamaño del array de tipos
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array de colores
 * \return void
 *
 */
void informar_MotoPorColorYTipo(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor); // 5

/** \brief Muestra las motos por color seleccionado
 *
 * \param motos[] eMoto array de motos
 * \param tamMotos int tamaño del array de motos
 * \param colores[] eColor array de colores
 * \param tamColor int tamaño del array de colores
 * \return return -1 si se produjo un error, 0 si esta todo ok
 *
 */
int informar_MotosColoresMasElegidos(eMoto motos[], int tamMotos, eColor colores[], int tamColor); // 6

/** \brief Muestra todos los trabajos realizados en una moto ingresada por el usuario
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos
 * \param tamTipos int El tamaño del array de tipos
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array de colores
 * \param trabajos[] eTrabajo El array de trabajos
 * \param tamTrabajo int El tamaño del array de trabajos
 * \param servicios[] eServicio El array de servicios
 * \param tamServicios int El tamaño del array de servicios
 * \return void
 *
 */

void informar_MotoPorTrabajo(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int sizeService);
/** \brief Informa la suma de los importes de los servicios que se le hicieron a una moto y la fecha
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos
 * \param tamTipos int El tamaño del array de tipos
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array de colores
 * \param trabajos[] eTrabajo El array de trabajos
 * \param tamTrabajo int El tamaño del array de trabajos
 * \param servicios[] eServicio El array de servicios
 * \param tamServicios int El tamaño del array de servicios
 * \return void
 *
 */
int informar_ServiciosSumaImportes(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicios);
/** \brief Muestra las motos a las que se le realizo un servicio ingresado por el usuario
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos
 * \param tamTipos int El tamaño del array de tipos
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array de colore
 * \param trabajos[] eTrabajo El array de trabajos
 * \param tamTrabajo int El tamaño del array de trabajos
 * \param servicios[] eServicio El array de servicios
 * \param tamServicios int El tamaño del array de servicios
 * \return void
 *
 */
void informar_ServiciosYMotos(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicios);
/** \brief Muestra todos los servicios realizados en una fecha ingresada por el usuario
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos
 * \param tamTipos int El tamaño del array de tipos
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array de colores
 * \param trabajos[] eTrabajo El array de trabajos
 * \param tamTrabajo int El tamaño del array de trabajos
 * \param servicios[] eServicio El array de servicios
 * \param tamServicios int El tamaño del array de servicios
 * \return void
 *
 */
void informar_ServiciosPorFecha(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipos, eColor colores[], int tamColor, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicios);



