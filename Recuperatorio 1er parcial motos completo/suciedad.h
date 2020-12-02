#ifndef SUCIEDAD_H_INCLUDED
#define SUCIEDAD_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    int tiempo;
}eSuciedad;

#endif // SUCIEDAD_H_INCLUDED


void suciedad_MostrarUnaSuciedad(eSuciedad unaSuciedad);
void suciedad_MostrarSuciedades(eSuciedad suciedades[], int tamSuciedad);
int suciedad_CargarDescripcionSuciedad(char descripcion[], int idSuc, eSuciedad suciedades[], int tamSuciedad);
int suciedad_BuscarSuciedadPorId(int id, eSuciedad suciedades[], int tamSuciedad);

















