#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char colorNombre[20];
}eColor;

#endif // COLOR_H_INCLUDED

/** \brief Muestra los colores cargados en una lista
 *
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array
 * \return void
 *
 */
void color_MostrarColores(eColor colores[], int tamColor);

/** \brief Muestra un solo color
 *
 * \param color eColor El color a mostrar
 * \return void
 *
 */
void color_MostrarUnColor(eColor color);

/** \brief Verifica la existencia de otro color con el mismo ID
 *
 * \param id int El ID a buscar
 * \param colores[] eColor El array de colores
 * \param tamColor int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int color_BuscarColorPorId(int id, eColor colores[], int tamColor);



int color_cargarNombre(eColor* colores, int tamColor, int Id, char* nombre);

