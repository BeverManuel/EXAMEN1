/*
 ============================================================================
 Name        : EXAMEN.c
 Author      : MANUEL I. BEVER
 Version     :
 Copyright   : Your copyright notice
 Description : Examen 1 - Programacion
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Cliente.h"
#include "Publicaciones.h"
#include "Informe.h"
#include "getVarios.h"
#include "getBibliotecas.h"
#include "menu.h"

#define CANTIDAD_clientes 100
#define CANTIDAD_publ 1000

int main(void)
{
	Clientes clientes[CANTIDAD_clientes];
	Publicidad publicaciones[CANTIDAD_publ];

	int idClientes=0;
	int idPublicidad=0;

	if(cliente_Inicializar(clientes,CANTIDAD_clientes)==0)
		{
				printf("Los campos estan vacios\n");
		}
	if(publicidad_Inicializar(publicaciones,CANTIDAD_publ)==0)
	{
			printf("Los campos estan vacios\n");
	}

	//PRE-CARGA DE CLIENTES
	cliente_altaForzadaArray(clientes,CANTIDAD_clientes,0,&idClientes,"MANUEL","BEVER","20-38870085-9");
	cliente_altaForzadaArray(clientes,CANTIDAD_clientes,1,&idClientes,"RYNLZER","RAYEN","20-22222222-9");
	cliente_altaForzadaArray(clientes,CANTIDAD_clientes,2,&idClientes,"WURF","NYN","30-1111111-2");

	//PRE-CARGA DE PUBLICIDADES
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,0,&idPublicidad,"Aviso 1",	2,	0,	2);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,1,&idPublicidad,"Aviso 2",	2,	0,	3);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,2,&idPublicidad,"Aviso 3",	1,	0,	3);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,3,&idPublicidad,"Aviso 4",	1,	0,	3);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,4,&idPublicidad,"Aviso 5",	1,	0,	2);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,5,&idPublicidad,"Aviso 6",	1,	0,	3);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,6,&idPublicidad,"Aviso 7",	1,	1,	5);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,7,&idPublicidad,"Aviso 8",	1,	1,	3);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,8,&idPublicidad,"Aviso 9",	1,	1,	3);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,9,&idPublicidad,"Aviso 10",	1,	1,	5);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,10,&idPublicidad,"Aviso 11", 1,	2,	5);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,11,&idPublicidad,"Aviso 12", 1,	2,	5);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,12,&idPublicidad,"Aviso 13", 1,	2,	5);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,13,&idPublicidad,"Aviso 14", 1,	2,	5);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,14,&idPublicidad,"Aviso 15", 1,	2,	5);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,15,&idPublicidad,"Aviso 16", 2,	2,	4);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,16,&idPublicidad,"Aviso 17", 2,	1,	1);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,17,&idPublicidad,"Aviso 18", 2,	1,	1);
	publicaciones_altaForzadaArray(publicaciones,CANTIDAD_publ,18,&idPublicidad,"Aviso 19", 2,	0,	1);


	cliente_Cargar(clientes,CANTIDAD_clientes,publicaciones,CANTIDAD_publ);

	return EXIT_SUCCESS;
}

