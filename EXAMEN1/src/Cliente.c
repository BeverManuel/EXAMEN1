/*
 * Cliente.c
 *
 *  Created on: 23 abr. 2020
 *      Author: Manuel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "getBibliotecas.h"
#include "getVarios.h"
#include "menu.h"

int cliente_altaForzadaArray(Clientes* array,int limite, int indice, int* idCliente, char* nombre, char* apellido, char* cuit)
{
	int respuesta = -1;
	Clientes bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idCliente != NULL)
	{
		strncpy(bufferCliente.nombre,nombre,TAMANO_NOMBRE);
		strncpy(bufferCliente.apellido,apellido,TAMANO_APELLIDO);
		strncpy(bufferCliente.CUIT,cuit,TAMANO_CUIT);
		respuesta = 0;
		bufferCliente.IDClientes = *idCliente;
		bufferCliente.isEmty = 0;
		array[indice] = bufferCliente;
		(*idCliente)++;

	}
	return respuesta;
}

/**
 * \brief Pone el indice de la estructura en 1
 * \return Retorna 0 si se realizo correctamente y -1 si no
 */
int cliente_Inicializar(Clientes* array,int limite){

	int retorno=1;

	if(array!=NULL && limite > 0){
		retorno = 0;
		int i;
		for(i=0;i<limite;i++){
			array[i].isEmty=1;  // SI VALE 1 EMPY ESTA VACIO Y SI VALE 0 ESTA CARGADA
		}
	}
	return retorno;
}

/**
 * \brief Pide al usuario un ID y Borra el ID la estructura cargada por el USUARIO
 *
 */
int cliente_Borrar(Clientes* array,int limite, int indice){

	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmty == 0)
	{
		array[indice].isEmty = 1;
		respuesta = 0;
	}
	return respuesta;
}

/**
 * \brief Imprime un array de Estructura de Clientes cargada por el usuario
 */
void cliente_Imprimir(Clientes* array,int limite){

	if(array!=NULL && limite > 0)
	{
		int i;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmty==0)
			{
				printf("\nID:%d ||| Nombre: %s ||| Apellido: %s ||| CUIT: %s \n",array[i].IDClientes,array[i].nombre,array[i].apellido,array[i].CUIT);
			}
		}
	}
}

/** Busca un ID en un array y devuelve la posicion en que se encuentra
* array cliente Array de Cliente
* limite int es el tamaño del array
* posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado - (0) si encuentra el valor buscado
*
*/
int estructura_buscarID(Clientes* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].IDClientes == valorBuscado)
			{
				respuesta = 0;
				break;
			}
		}
	}
	return respuesta;
}


/**
 * \brief Buscar primer posicion vacia
 * \param arrayProductos Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int cliente_getEmptyIndex(Clientes* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/*
 * FUNCION PARA CARGAR DATOS SOLICITADOS
 */
int cliente_CargarDATOS(Clientes* array,int limite, int indice){

	int retorno = 1;
	if(array != NULL && limite > 0 && indice >= 0)
	{
		if((utn_getNombre(array[indice].nombre,limite,"\nIngrese el nombre del cliente: ","\nERROR - CARGA INCORRECTO\n", 3)==0) &&
			(utn_getNombre(array[indice].apellido,limite,"\nIngrese el apellido del cliente: ","\nERROR - CARGA INCORRECTO\n", 3)==0) &&
			(utn_getCUIT(array[indice].CUIT,"\nIngrese el CUIT: ","\nERROR - CARGA INCORRECTO\n",3)==0))
		{
			printf("\nCarga Correcta.\n");
		}
		array[indice].isEmty=0;
		array[indice].IDClientes=indice;

		retorno=0;
	}
	return retorno;

}

/*
 * Se se solicita al cliente un INDICE el cual permitira modificar el cliente
 */
int cliente_Modificar(Clientes* array,int limite, int indice){

	int retorno = -1;

	if(array != NULL && limite > 0 && indice >= 0 && array[indice].isEmty == 0)
	{
		if(array != NULL && limite > 0 && indice >= 0)
		{
			if((utn_getNombre(array[indice].nombre,limite,"\nIngrese el nombre del cliente: ","\nERROR - CARGA INCORRECTO\n", 3)==0) &&
				(utn_getNombre(array[indice].apellido,limite,"\nIngrese el apellido del cliente: ","\nERROR - CARGA INCORRECTO\n", 3)==0) &&
				(utn_getCUIT(array[indice].CUIT,"\nIngrese el CUIT: ","\nERROR - CARGA INCORRECTO\n",3)==0))
			{
				printf("\nCarga Correcta.\n");
			}

			retorno=0;
			}
	}


	return retorno;
}
