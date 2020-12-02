#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/// PRINCIPALES

/** \brief Obtiene un string
 *
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error a mostrar
 * \param min int El tamaño minimo
 * \param max int El temaño maximo
 * \param tries int* Intentos que tiene el usuario para ingresar el dato correctamente
 * \param result char* Donde se guardara el string obtenido
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int getString(char* message, char* messageError, int min, int max, int tries, char* result);


/** \brief Obtiene un numero entero sin signo
 *
 * \param input int* Donde se guardara el int obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param min int El numero minimo del rango que se puede ingresar
 * \param max int El numero maximo del rango que se puede ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int getUnsignedInt(int* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries);
/** \brief Valida numeros enteros sin signo de una cadena
 *
 * \param string char* La cadena a validar
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidNumber(char* string);

/** \brief Obtiene un numero caracter
 *
 * \param result char* Donde se guardara el caracter obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int getChar(char* result, char* message, char* messageError, int tries);
/** \brief Valida caracteres de una cadena
 *
 * \param string char* La cadena a validar
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidChar(char character);

/** \brief Obtiene un texto
 *
 * \param input char* Donde se guardara el texto obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int getTexto(char* input, char* message, char* messageError, int minSize, int maxSize, int tries);
/** \brief Valida texto de una cadena
 *
 * \param string char* La cadena a validar
 * \param int lenght El largo de la cadena
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidText(char* string, int lenght);

/** \brief Obtiene un alfanumerico
 *
 * \param input char* Donde se guardara el alfanumerico obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int getAlfanumeric(char* input, char* message, char* messageError, int minSize, int maxSize, int tries);
/** \brief Valida alfanumericos de una cadena
 *
 * \param string char* La cadena a validar
 * \param int lenght El largo de la cadena
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidAlphanumeric(char* string, int lenght);

///

/** \brief Muestra el mensaje que indica que no hay mas intentos disponibles
 *
 * \param tries int Si la variable tries de la funcion que la llama es -1, se muestra el mensaje de esta funcion
 * \return void
 *
 */
void showTriesOverMessage(int tries);

/** \brief Obtiene una fecha valida
 *
 * \param date eDate La fecha a validar
 * \param minYear int El año minimo
 * \param maxYear int El año maximo
 * \return int (1) si es valida, (0) si no lo es
 *
 */
int getFecha(int day, int month, int year, int minYear, int maxYear);
/** \brief Verifica si un año es bisiesto
 *
 * \param year int El año a verificar
 * \return int (1) si es, (0) si no lo es
 *
 */
int isLeapYear(int year);

/**
 * \brief Solicita un numero de opcion y lo valida
 * \param int maxOption La opcion maxima que se puede introducir
 * \return La opcion validada
 */
int getOption(int);

/**
 * \brief Solicita el numero de opcion de un menu para confirmar los cambios de acuerdo a ese menu
 * \param int menuOption El numero de la opcion del menu
 * \return (1) si se confirmaron los cambios, (0) si no se confirmaron
 * Le paso el numero de la opcion del menu y muestra el mensaje de confirmacion adecuado para la accion que vaya a realizar
 */
int confirm(int);



int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError);
int getCadena(char* pAux,int limite);
int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max);
int getInt(int* pAux);
int isInt(char *pAux);



#endif // UTN_H_INCLUDED
