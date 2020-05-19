/*
 * menu.c
 *
 *  Created on: 12 abr. 2020
 *      Author: Manuel
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "menu.h"

void menuPrincipal(){
	printf("\n1. Alta de Cliente\n");
	printf("2. Modificar datos de cliente\n");
	printf("3. Baja de cliente\n");
	printf("4. Crear Publicacion\n");
    printf("5. Pausar Publicacion\n");
	printf("6. Reanudar publicacion\n");
	printf("7. Imprimir Clientes\n");
	printf("8. Imprimir publicaciones\n");
	menu_PNueve();
	menu_PDiez();
	printf("11. SALIR");
}

void menu_PNueve(){
	printf("9. Informar clientes\n"
		   "   a) Cliente con mas avisos activos\n"
		   "   b) Cliente con mas avisos pausados\n"
		   "   c) Cliente con mas avisos\n");
}

void menu_PDiez(){
	printf("10. Informar publicaciones\n"
		   "    a) Cantidad de publicaciones de un rubro\n"
		   "    b) Rubro con más publicaciones activas\n"
		   "    c) Rubro con menos publicaciones activas\n");
}
