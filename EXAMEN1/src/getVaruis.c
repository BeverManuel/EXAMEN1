/*
 * getVaruis.c
 *
 *  Created on: 4 may. 2020
 *      Author: Manuel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getBibliotecas.h"
#include "getVarios.h"

/** utn_getEmail le solicita un mail al cliente
 * char* mensaje - solicita un mensaje que figura en la consultsa
 * char* mensajeError - en caso de ser negada la pregunta sale el mensaje de error
 * int longitud - tamaño del vector
 * int reintentos - intentos para realizar el programa al quedar sin intentos sale
 * char* pResultado - puntero de la variable donde se guaradara lo cargado
*/
int utn_getEmail(char* mensaje, char* mensajeError, int longitud, int reintentos, char* pResultado)
{
    int retorno=-1;
    char bufferString[longitud];

    if(mensaje!=NULL && mensajeError!=NULL && reintentos>=0 && pResultado!=NULL)
    {
        do
        {
        	printf("%s",mensaje);
        	if(myGets(bufferString,sizeof(bufferString)) == 0) //==0 sin errores !0
            {
                if(isValidEmail(bufferString)==1)
                {
                    strncpy(pResultado,bufferString,longitud);
                    retorno=0;
                    break;
                }
                else
                {
                	printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}


/** validar que sea un email .
*
*char* stringrecibido.
*revisa la cadena cumpla con las condiciones
*retorno  -1 si hay error, 0 si  esta todo bien
*
*/
int isValidEmail(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'-' && stringRecibido[i]!='+') || (stringRecibido[i]>'9' && stringRecibido[i]<'@') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]!='_' && stringRecibido[i]<'a')|| stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}


/*
 *
 *
 *
 *
 *
 *
 *
 *
 */


/* pide cuit valido
*
* char* mensaje indica el mensaje de lo que se pide
* char* mensajeError indica el mensaje de ERROR en la consola en caso de que se falle
* int tamanoMinimo el minimo que tiene que ser la cadena
* int tamanoMaximo el maximo que tiene que ser la cadena
* int reintentos si hay error
* pResultado* puntero donde se guardara lo cargado en caso de estar correcto!
* return retorno -1 si hay error, 0 si  esta todo bien
*
*/
int utn_getCUIT(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    int tamanoMaximo=14; //con guiones 13 elementos
    int tamanoMinimo=11;  // sin puntos
    int retorno=-1;
    char bufferString[tamanoMaximo];

    if(mensaje!=NULL && mensajeError!=NULL && tamanoMinimo<tamanoMaximo && reintentos>=0 && pResultado!=NULL)
    {
        do
        {
        	printf("%s",mensaje);
            if(myGets(bufferString,sizeof(bufferString)) == 0) //==0 sin errores !0
            {
                if(isValidCUIT(bufferString)== 1)
                {
                    strncpy(pResultado,bufferString,tamanoMaximo);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
/* validar que sea un cuit .
*
* char* stringrecibido.
* revisa la cadena cumpla con las condiciones
*\return retorno -1 si hay error, 0 si  esta todo bien
*
*/
int isValidCUIT(char* stringRecibido)
{
    int retorno = 1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    char bufferString[14];
    strncpy(bufferString,stringRecibido,14);

    for(i=0;bufferString[i]!='\0';i++) // RESALIZO UN FORMO HASTA QUE ENCUENTRO EL PUNTO FINAL DEL VECTOR
    {
        if((bufferString[i]<'0' || bufferString[i]>'9') && (bufferString[i]!='-')) // chequeo que solo sean numeros o gion
        {
            retorno=0;
            break;
        }
    }

    return retorno;
}
