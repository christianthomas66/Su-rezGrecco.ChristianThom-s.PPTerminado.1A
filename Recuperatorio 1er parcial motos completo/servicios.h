#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIOS_H_INCLUDED


/** \brief Muestra los servicios cargados en una lista
 *
 * \param servicios[] eServicio El array de servicios
 * \param tamServicio int El tamaño del array
 * \return void
 *
 */
void servicios_MostrarServicios(eServicio servicios[], int tamServicio);

/** \brief Muestra un solo servicio
 *
 * \param unServicio eServicio El servicio a mostrar
 * \return void
 *
 */
void servicios_MostrarUnServicio(eServicio unServicio);

/** \brief Verifica la existencia de otro servicio con el mismo ID
 *
 * \param id int El ID a buscar
 * \param servicios[] eServicio El array de servicios
 * \param tamServicio int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int servicios_BuscarServicioPorId(int id, eServicio servicios[], int tamServicio);
