/*
 * Publicaciones.h
 *
 *  Created on: 23 abr. 2020
 *      Author: Manuel
 */

#ifndef PUBLICACIONES_H_
#define PUBLICACIONES_H_

#define TAMANO_TEXTO 64

typedef	struct {
	char textoAviso[TAMANO_TEXTO];
	int numeroDeRublo;
	int EstadoPublicacion;
	int isEmty;
	int IDCliente;
	int IDPublicidad;
}Publicidad;

int publicaciones_altaForzadaArray(Publicidad* array,int limite, int indice, int* IDPublicidad, char* textoAviso,int estadoPublicacion, int IDCliente, int rublo);

int publicidad_Inicializar(Publicidad array[],int limite);

void publicidad_Borrar(Publicidad array[],int limite);

void publicidad_Imprimir(Publicidad array[],int limite);

int publicidad_getEmptyIndex(Publicidad* array,int limite);

int publicidad_buscarID(Publicidad array[], int limite, int valorBuscado);

int publicidad_CargarDATOS(Publicidad arrayP[],int limiteP, int indice);

int publicidad_ModificarARRAY(Publicidad array[],int limite, int indice);

int publicidad_Baja(Publicidad array[],int limite, int indice);

int publicidad_Alta(Publicidad array[],int limite, int indice);

#endif /* PUBLICACIONES_H_ */
