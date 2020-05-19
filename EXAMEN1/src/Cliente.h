/*
 * Cliente.h
 *
 *  Created on: 23 abr. 2020
 *      Author: Manuel
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define TAMANO_NOMBRE 50
#define TAMANO_APELLIDO 50
#define TAMANO_CUIT 14

typedef	struct {
	char nombre[TAMANO_NOMBRE];
	char apellido[TAMANO_APELLIDO];
	char CUIT[TAMANO_CUIT];
	int isEmty;
	int IDClientes;
}Clientes;

int cliente_altaForzadaArray(Clientes* array,int limite, int indice, int* idCliente, char* nombre, char* apellido, char* cuit);

int cliente_Inicializar(Clientes array[],int limite);

int cliente_Borrar(Clientes array[],int limite, int indice);

void cliente_Imprimir(Clientes array[],int limite);

int cliente_getEmptyIndex(Clientes* array,int limite);

int cliente_CargarDATOS(Clientes array[],int limite, int indice);

int cliente_Modificar(Clientes array[],int limite, int indice);

int estructura_buscarID(Clientes array[], int limite, int valorBuscado);

#endif /* CLIENTE_H_ */
