/*
 * Publicaciones.c
 *
 *  Created on: 23 abr. 2020
 *      Author: Manuel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getBibliotecas.h"
#include "menu.h"
#include "Publicaciones.h"
/*
 	char textoAviso[TAMANO_TEXTO];
	int numeroDeRublo;
	int EstadoPublicacion;
	int isEmty;
	int IDCliente;
	int IDPublicidad;
 */
int publicaciones_altaForzadaArray(Publicidad* array,int limite, int indice, int* IDPublicidad, char* textoAviso,int estadoPublicacion, int IDCliente, int rublo)
{
	int respuesta = -1;
	Publicidad bufferPublicaciones;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && IDPublicidad != NULL)
	{
		strncpy(bufferPublicaciones.textoAviso,textoAviso,TAMANO_TEXTO);
		respuesta = 0;
		bufferPublicaciones.EstadoPublicacion = estadoPublicacion;
		bufferPublicaciones.numeroDeRublo = rublo;
		bufferPublicaciones.IDCliente = IDCliente;
		bufferPublicaciones.IDPublicidad = *IDPublicidad;
		bufferPublicaciones.isEmty = 0;
		array[indice] = bufferPublicaciones;
		(*IDPublicidad)++;

	}
	return respuesta;
}

/**
 * \brief Pone el indice de la estructura en 1
 * \return Retorna 0 si se realizo correctamente y -1 si no
 */
int publicidad_Inicializar(Publicidad* array,int limite){

	int retorno=1;

	if(array!=NULL && limite > 0){
		int i;
		for(i=0;i<limite;i++){
			array[i].isEmty=1;  // SI VALE 1 EMPY ESTA VACIO Y SI VALE 0 ESTA CARGADA
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Pide al usuario un ID y Borra el ID la estructura cargada por el USUARIO
 *
 */
void publicidad_Borrar(Publicidad* array,int limite){

	if(array!=NULL && limite > 0)
	{
		int indiceFuncion;
		if(utn_getNumero(&indiceFuncion,"\nIngrese el indice a borrar: ","\nERROR - INIDICE FUERA DE CAMPO\n",0,limite,3)==0)
		{
			printf("\nIndice Correcto.\n");
		}
		array[indiceFuncion].isEmty=1; // SE COLOCA UNO PORQUE SE BORRA
	}
}

/**
 * \brief Previamente el programa solicita al usuario un indice, el cual premitira PAUSAR la publicidad
 *
 */
int publicidad_Baja(Publicidad* array,int limite, int indice)
{

	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmty == 0)
	{
		array[indice].EstadoPublicacion = 2;
		respuesta = 0;
	}
	return respuesta;
}

/**
 * \brief Previamente el programa solicita al usuario un indice, el cual premitira dar de alta a la publicidad
 *
 */
int publicidad_Alta(Publicidad* array,int limite, int indice)
{

	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmty == 0)
	{
		array[indice].EstadoPublicacion = 1;
		respuesta = 0;
	}
	return respuesta;
}

/**
 * \brief Imprime un array de Estructura cargada por el usuario
 * \return Retorna 0 si se realizo correctamente y -1 si no
 */
void publicidad_Imprimir(Publicidad* array,int limite){

	if(array!=NULL && limite > 0)
		{
			int i;
			for(i=0;i<limite;i++)
			{
				if(array[i].isEmty==0)
				{
					switch(array[i].EstadoPublicacion)
					{
					case 1:
						printf("ID:%d || Estado publicacion: ACTIVO || Contrador por el ID de cliente: %d || Aviso: %s || Rublo: %d\n",array[i].IDPublicidad,array[i].IDCliente,array[i].textoAviso,array[i].numeroDeRublo);
						break;
					case 2:
						printf("ID:%d || Estado publicacion: PAUSADO || Contrador por el ID de cliente: %d || Aviso: %s || Rublo: %d\n",array[i].IDPublicidad,array[i].IDCliente,array[i].textoAviso,array[i].numeroDeRublo);
						break;
					}
				}
			}
		}
}

/**
 * \brief Buscar primer posicion vacia
 * \param arrayProductos Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int publicidad_getEmptyIndex(Publicidad* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmty == 1)
			{
				if(i==0)
				{
					respuesta = i;
				}
				if(i>0){
					respuesta = i-11; //Bug encontrado en mi ordenado que hace que salte de 12 en 12
				}
				//respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/** Busca un ID en un array y devuelve la posicion en que se encuentra
* array cliente Array de Publicidad
* limite int es el tamaño del array
* posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado - (0) si encuentra el valor buscado
*
*/
int publicidad_buscarID(Publicidad* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].IDPublicidad == valorBuscado)
			{
				respuesta = 0;
				break;
			}
		}
	}
	return respuesta;
}


/*
 * Se le solicita al usuario un INDICE el cual permitira crear las publiciones
 */
int publicidad_CargarDATOS(Publicidad* arrayP,int limiteP, int indice){

	int retorno = 1;
	if(arrayP != NULL && limiteP > 0 && indice >= 0)
	{
		if((utn_getNombre(arrayP[indice].textoAviso,limiteP,"\nIngrese el aviso publicitario: ","\nERROR - CARGA INCORRECTO\n", 3)==0) &&
			(utn_getNumero(&arrayP[indice].numeroDeRublo,"\nIngrese el numero del rublo: ","\nERROR - CARGA INCORRECTO\n",0,9999,3)==0) &&
			(utn_getNumero(&arrayP[indice].EstadoPublicacion,"\nIngrese el estado del texto:\n1.ACTIVO\n2.PAUSADO" ,"\nERROR - CARGA INCORRECTO\n",1,2,3)==0) &&
			(utn_getNumero(&arrayP[indice].IDCliente,"\nIngrese el ID del cliente destinado a la publicacion" ,"\nERROR - CARGA INCORRECTO\n",0,100,3)==0))
		{
			printf("\nCarga Correcta.\n");
		}
		arrayP[indice].isEmty=0;
		arrayP[indice].IDPublicidad=indice;

		retorno=0;

		publicidad_Imprimir(arrayP,limiteP);
	}
	return retorno;

}

/*
 * Se se solicitara un indice al usuario el cual permitra modificar la publiccaion
 */
int publicidad_ModificarARRAY(Publicidad* array,int limite, int indice){

	int retorno = -1;

	if(array != NULL && limite > 0 && indice >= 0 && array[indice].isEmty == 0)
	{
		if(array != NULL && limite > 0 && indice >= 0)
		{
			if((utn_getNombre(array[indice].textoAviso,limite,"\nIngrese el TEXTO: ","\nERROR - CARGA INCORRECTO\n", 3)==0) &&
			   (utn_getNumero(&array[indice].numeroDeRublo,"\nIngrese unos NUMEROS: ","\nERROR - CARGA INCORRECTO\n",1,9999,3)==0) &&
			   (utn_getNumero(&array[indice].EstadoPublicacion,"\nIngrese el FLOTANTE:" ,"\nERROR - CARGA INCORRECTO\n",1,2,3)==0))
			{
				printf("\nCarga Correcta.\n");
			}
			array[indice].isEmty=0;
			array[indice].IDPublicidad=indice;

			retorno=0;
			}
	}


	return retorno;
}
