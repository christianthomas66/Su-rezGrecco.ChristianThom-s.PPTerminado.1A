#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"

int getString(char* message, char* messageError, int min, int max, int tries, char* result)
{
    int ret = -1;
    char bufferString[max+10];

    if(result != NULL && message != NULL && messageError != NULL && min <= max && tries >= 0)
    {
        do
        {
            printf("%s", message);
            setbuf(stdin,NULL);
            fgets(bufferString,sizeof(bufferString),stdin);
            bufferString[strlen(bufferString)-1]='\0';

            if(strlen(bufferString) >= min && strlen(bufferString) <= max)
            {
                strncpy(result,bufferString,max);
                ret = 0;
                break;
            }
            printf("%s", messageError);
            (tries)--;

        }while((tries) >= 0);
    }
    return ret;
}

int getUnsignedInt(int* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries)
{
    int ret = -1;
    char bufferString[maxSize];
    int auxInt;

    if(input != NULL && message != NULL && messageError != NULL && minSize <= maxSize && min <= max && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,tries,bufferString))
            {
                if(isValidNumber(bufferString) == 1)
                {
                    auxInt = atoi(bufferString);
                    if(auxInt >= min && auxInt <= max)
                    {
                        *input = auxInt;
                        ret = 0;
                        break;
                    }
                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}
int isValidNumber(char* string)
{
    int ret = 1;//true

    for(int i=0; string[i]!='\0'; i++)
    {
        if(string[i] < '0' || string[i] > '9')
        {
            ret = 0;//false
            break;
        }
    }
    return ret;
}

int getChar(char* result, char* message, char* messageError, int tries)
{
    int ret = -1;
    char bufferChar[256];

    if(result != NULL && message != NULL && messageError != NULL && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,1,3,tries,bufferChar))
            {
                if(isValidChar(bufferChar[0]) == 1)
                {
                    *result = bufferChar[0];
                    ret = 0;
                    break;
                }

                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}

int isValidChar(char character)
{
    int ret = 1;

    if(character < 'A' || (character > 'Z' && character < 'a') || character > 'z')
    {
        ret = 0;
    }
    return ret;
}

int getTexto(char* input, char* message, char* messageError, int minSize, int maxSize, int tries)
{
    int ret = -1;
    char bufferString[maxSize];

    if(input != NULL && message != NULL && messageError != NULL && minSize <= maxSize && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,tries,bufferString))
            {
                if(isValidText(bufferString, sizeof(bufferString)) == 1)
                {
                    strncpy(input,bufferString,maxSize);
                    ret = 0;
                    break;
                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}

int isValidText(char* string, int lenght)
{
    int ret = -1;

    if(string != NULL && lenght > 0)
    {
        ret = 1;
        for(int i=0; i<lenght && string[i] != '\0'; i++)
        {
            if((string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && (string[i] != ' '))
            {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}

void showTriesOverMessage(int tries)
{
    if(tries == -1)

    {
            printf("\n\n\t\t(!) ERROR. NO HAY INTENTOS DISPONIBLES. LO INGRESADO NO SE CARGO CORRECTAMENTE (!)\n\n");
    }
}

int getFecha(int day, int month, int year, int minYear, int maxYear)
{
    int ret = 1;
    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(year < minYear || year > maxYear)
    {
        ret = 0;
    }

    if (month < 1 || month > 12)
    {
        ret = 0;
    }

    if((month != 2) || (!isLeapYear (year)))	//si no es febrero o no es bisiesto
    {
        if (day < 1 || day > monthDays[month])
        {
            ret = 0;
        }
    }
    else if((month == 2) && (isLeapYear (year))) //si es febrero y es bisiesto
    {
        if (day < 1 || day > monthDays[2]+1) //pongo como dia maximo 28 + 1
        {
            ret = 0;
        }
    }

    return ret;
}

int isLeapYear(int year)
{
  int ret = 0;

    if((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
    {
      ret = 1;
    }
  return ret;
}

int getOption(int maxOption)
{
    int option;

    getUnsignedInt(&option, "\nElija la opcion deseada: ", "\n\t(!) Error. Opcion inexistente\n", 1, sizeof(int),0, maxOption,4);

    return option;
}


int confirm(int menuOption)
{
    char option;
    int confirmed = 0;


    switch(menuOption)
    {
        case 2:
                getChar(&option,"\n\tConfirma la baja? (s/n): ", "\n\t(!) Error. Caracter invalido.\n\tConfirma la baja? (s/n): ",4);

                if(option == 's' || option == 'S')
                {
                    confirmed = 1;
                    printf("\n\n\t\t>>>>> Registro dado de baja exitosamente <<<<<\n\n\n");
                    system("pause");
                }
                else
                {
                    printf("\n\n\t\t>>>>> El registro no fue dado de baja <<<<<\n\n\n");
                    system("pause");
                }
                break;

        case 3:
                getChar(&option,"\n\tConfirma la modificacion? (s/n): ", "\n\t(!) Error. Caracter invalido.\n\tConfirma la modificacion? (s/n): ",4);

                if(option == 's' || option == 'S')
                {
                    confirmed = 1;
                    printf("\n\n\t\t>>>>> Registro modificado exitosamente <<<<<\n\n\n");
                    system("pause");
                }
                else
                {
                    printf("\n\n\t\t>>>>> El registro no fue modificado <<<<<\n\n\n");
                    system("pause");
                }
                break;
        case 11:
                getChar(&option,"\n\tEsta seguro que desea salir? (s/n): ", "\n\t (!) Error. Caracter invalido.\n\tEsta seguro que desea salir? (s/n): ",2);

                if(option == 's' || option == 'S')
                {
                    confirmed = 1;
                }
                break;
    }
    return confirmed;
}

int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError)
{
    int retorno=-1;
    char auxString[limite];

    if(pAux!=NULL && limite >0 && reintentos >=0)
    {
        do
        {
            reintentos--;
            printf("%s",msj);
            if(getCadena(auxString,limite)==0)
            {
                strncpy(pAux,auxString,limite);
                retorno=0;
                break;
            }
            else
            {
                printf("%s",msjError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int getCadena(char* pAux,int limite)
{
    char auxString[2000];
    int todoOk =-1;
    if (pAux != NULL && limite >0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);
        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limite)
        {
            strncpy(pAux,auxString,limite);
            todoOk=0;
        }
    }
    return todoOk;
}


int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max)
{
    int todoOk = -1;
    int auxInt;

    if(pEntero!=NULL&& msg !=NULL && msgError!=NULL && min<= max && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt<=max)
            {
                *pEntero= auxInt;
                todoOk = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}

int getInt(int* pAux)
{
    char auxString[200];
    int todoOk =-1;
    if(getCadena(auxString,200)==0 && isInt(auxString)==0)
    {
        *pAux=atoi(auxString);
        todoOk=0;
    }
    return todoOk;
}



int isInt(char *pAux)
{
    int todoOk=-1;
    int i=0;
    do
    {
        if(*(pAux+i)<48||*(pAux+i)>57)
        {
            break;
        }
        i++;
    }while (i<strlen(pAux));
    if(i==strlen(pAux))
    {
        todoOk=0;
    }
    return todoOk;
}

