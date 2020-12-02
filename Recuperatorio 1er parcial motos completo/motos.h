#include "tipo.h"
#include "color.h"
#include "clientes.h"

#ifndef MOTOS_H_INCLUDED
#define MOTOS_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int estado;

    int idCliente;
    int idSuciedad;

}eMoto;

void motos_harcodear(eMoto motos[], int harcodearMotos);

/** \brief Hardcodea las motos
 *
 * \param motos[] eMoto El array de motos
 * \param harcodearMotos int La cantidad de motos a harcodear
 * \return void
 *
 */
/** \brief Inicializa el array de motos en 0 o vacio
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array
 * \return void
 *
 */
void motos_incializar(eMoto motos[], int tamMotos);
/** \brief Busca lugar libre en el array de motos para guardar nuevos datos
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array
 * \return int (El indice) para guardar datos, (-1) si no hay lugar libre
 *
 */
int motos_BuscarLibre(eMoto motos[], int tamMotos);
/** \brief Verifica la existencia de otra moto con el mismo Id
 *
 * \param id int El Id a buscar
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int motos_BuscarMotoPorId(int id, eMoto motos[], int tamMotos);


/** \brief Da de alta una moto
 *
 * \param int id El id que se le asignara a la moto
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param types[] eTipo El array de tipos de moto
 * \param tamTipo int El tamaño del array de tipos
 * \param colores[] eColor El array de colores de moto
 * \param tamColor int El tamaño del array de colores
 * \return void
 *
 */
int motos_AltaMoto(int id, eMoto motos[], int tamMotos, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eCliente clientes[], int tamCliente);
/** \brief Da de baja una moto
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos de motos
 * \param tamTipo int El tamaño del array de tipos
 * \param colores[] eColor El array de colores de motos
 * \param tamColor int El tamaño del array de colores
 * \return void
 *
 */
void motos_BajaMoto(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);
/** \brief Modifica una moto
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos de motos
 * \param tamTipo int El tamaño del array de tipos
 * \param colores[] eColor El array de colores de motos
 * \param tamColor int El tamaño del array de colores
 * \return void
 *
 */
void motos_ModificarMoto(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);
/** \brief Muestra las motos cargadas en una lista
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos de motos
 * \param tamTipo int El tamaño del array de tipos
 * \param colores[] eColor El array de colores de motos
 * \param tamColor int El tamaño del array de colores
 * \return void
 *
 */
void motos_MostrarMotos(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);
/** \brief Muestra solo una moto
 *
 * \param eMoto La moto a mostrar
 * \param tipos[] eTipo El array de tipos de motos
 * \param tamTipo int El tamaño del array de tipos
 * \param colores[] eColor El array de colores de motos
 * \param tamColor int El tamaño del array de colores
 * \return void
 *
 */
void motos_MostrarUnaMoto(eMoto, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);
/** \brief Ordena las motos
 *
 * \param motos[] eMoto El array de motos
 * \param tamMotos int El tamaño del array de motos
 * \param tipos[] eTipo El array de tipos de motos
 * \param tamTipo int El tamaño del array de tipos
 * \param colores[] eColor El array de colores de motos
 * \param tamColor int El tamaño del array de colores
 * \return void
 *
 */
void motos_OrdenarMotos(eMoto motos[], int tamMotos, eTipo tipos[], int tamTipo, eColor colores[], int tamColor);

/** \brief Carga la descripcionTipo de los tipos de motos
 *
 * \param descripcionTipo[] char Donde se cargara la informacion
 * \param id int El id de la estructura Type
 * \param tipos[] eTipo El array de tipos de motos
 * \param tamTipo int El tamaño del array de tipos
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int motos_CargarDescripcionTipo(char descripcionTipo[], int id, eTipo tipos[], int tamTipo);
/** \brief Carga el nombre de los colores de motos
 *
 * \param descripcionColor[] char Donde se cargara la informacion
 * \param id int El id de la estructura Color
 * \param colores[] eColor El array de colores de motos
 * \param tamColor int El tamaño del array de colores
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int motos_CargarDescripcionColor(char descripcionColor[], int id, eColor colores[], int tamColor);


#endif // MOTOS_H_INCLUDED
