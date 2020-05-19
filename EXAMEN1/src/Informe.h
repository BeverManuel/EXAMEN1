/*
 * Informe.h
 *
 *  Created on: 9 may. 2020
 *      Author: Manuel
 */

#ifndef INFORME_H_
#define INFORME_H_

#define CANTIDAD_publ 1000

void info_imprimirAvisoDelRublo(Publicidad* arrayPublicaciones,int limite,int rubloSeleccionado);

int info_calcularCantidadRublos(Publicidad* arrayPublicaciones,int limitePublicaciones,int listaRublo, int* contadorCantidadAvisos);

int info_imprimirContratacionesConImportePorCliente(Publicidad* arrayPublicaciones,int limitePublicaciones, int seleccion);

void info10a_imprimirAvisoDelRublo(Publicidad* arrayPublicaciones,int limite,int rubloSeleccionado);


void cliente_ImprimirBusquedaIDClienteListaPublicaciones(int iDCliente,Publicidad arrayPublicaciones[],int limitePublicaciones);

void publicaciones_ImprimirBusquedaPublicacionIDcliente(int IDPublicacion,Clientes arrayCliente[],int limiteCliente);

int cliente_BajaPublicacion(int iDCliente,Publicidad arrayPublicaciones[],int limitePublicaciones);

void cliente_ImprimirClienteConSusPublicaciones(Clientes arrayCliente[],int limiteCliente,Publicidad arrayPublicaciones[],int limitePublicaciones);

void publicaciones_ImprimirPublicacionConCUIT(Clientes arrayCliente[],int limiteCliente,Publicidad arrayPublicaciones[],int limitePublicaciones);

void cliente_MaximaPublicacionesActivas(Clientes arrayCliente[],int limiteCliente,Publicidad arrayPublicaciones[],int limitePublicaciones);

void cliente_MaximaPublicacionesPausadas(Clientes arrayCliente[],int limiteCliente,Publicidad arrayPublicaciones[],int limitePublicaciones);

void cliente_MaximaPublicaciones(Clientes arrayCliente[],int limiteCliente,Publicidad arrayPublicaciones[],int limitePublicaciones);

void rublo_CantidadPublicacionesActivas(Publicidad arrayPublicaciones[],int limitePublicaciones);

void rublo_ConMasPublicacionesActivas(Publicidad arrayPublicaciones[],int limitePublicaciones);

void rublo_ConMenosPublicacionesActivas(Publicidad arrayPublicaciones[],int limitePublicaciones);

void cliente_Cargar(Clientes arrayCliente[],int limiteCliente,Publicidad arrayPublicaciones[],int limitePublicaciones);

#endif /* INFORME_H_ */
