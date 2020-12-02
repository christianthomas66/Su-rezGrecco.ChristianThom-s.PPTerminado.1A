#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief Muestra los tipos cargados en una lista
 *
 * \param tipos[] eTipo El array de tipos
 * \param tamTipo int El tamaño del array
 * \return void
 *
 */
void tipos_MostrarTipos(eTipo tipos[], int tamTipo);

/** \brief Muestra un solo tipo
 *
 * \param unTipo eTipo EL tipo a mostrar
 * \return void
 *
 */
void tipos_MostrarUnTipo(eTipo unTipo);

/** \brief Verifica la existencia de otro tipo con el mismo ID
 *
 * \param id int El ID a buscar
 * \param tipos[] eTipo El array de tipos
 * \param tamTipo int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int tipos_BuscarTipoPorId(int id, eTipo tipos[], int tamTipo);
