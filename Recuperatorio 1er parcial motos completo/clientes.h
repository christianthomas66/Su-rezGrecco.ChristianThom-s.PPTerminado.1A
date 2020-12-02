#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[30];
    char sexo;
}eCliente;

/** \brief hardcodea entidades del tipo eCliente
 *
 * \param clientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void hardcodearClientes(eCliente clientes[], int tamCliente);

/** \brief muestra una entidad de tipo eCliente
 *
 * \param unCliente cliente a mostrar
 *
 */
void mostrarCliente(eCliente unCliente);

/** \brief muestra los clientes ingresados al sistema
 *
 * \param clientes[] array de clientes
 * \param tamClientes tamanio del array
 *
 */
void mostrarClientes(eCliente clientes[], int tamClientes);


int clientes_CargarNombreCliente(char nombre[], int idPersona, eCliente clientes[], int tamClientes);



#endif // CLIENTES_H_INCLUDED
