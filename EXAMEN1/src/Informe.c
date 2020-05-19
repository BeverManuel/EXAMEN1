/*
 * Informe.c
 *
 *  Created on: 9 may. 2020
 *      Author: Manuel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "Publicaciones.h"
#include "Informe.h"
#include "getBibliotecas.h"
#include "getVarios.h"
#include "menu.h"

void info_imprimirAvisoDelRublo(Publicidad* arrayPublicaciones,int limite,int rubloSeleccionado)
{

	if(arrayPublicaciones!=NULL && limite > 0)
		{
			int i;
			for(i=0;i<limite;i++)
			{
				if(arrayPublicaciones[i].isEmty==0)
				{
					if(arrayPublicaciones[i].numeroDeRublo == rubloSeleccionado && arrayPublicaciones[i].EstadoPublicacion == 1)
					{
						switch(arrayPublicaciones[i].EstadoPublicacion)
						{
						case 1:
							printf("ID:%d || Estado publicacion: ACTIVO || Contrador por el ID de cliente: %d || Aviso: %s\n",arrayPublicaciones[i].IDPublicidad,arrayPublicaciones[i].IDCliente,arrayPublicaciones[i].textoAviso);
							break;
						case 2:
							printf("ID:%d || Estado publicacion: PAUSADO || Contrador por el ID de cliente: %d || Aviso: %s\n",arrayPublicaciones[i].IDPublicidad,arrayPublicaciones[i].IDCliente,arrayPublicaciones[i].textoAviso);
							break;
						}
					}
				}
			}
			printf("\n");
		}
}

void info10a_imprimirAvisoDelRublo(Publicidad* arrayPublicaciones,int limite,int rubloSeleccionado)
{

	if(arrayPublicaciones!=NULL && limite > 0)
		{
			int i;
			for(i=0;i<limite;i++)
			{
				if(arrayPublicaciones[i].isEmty==0)
				{
					if(arrayPublicaciones[i].numeroDeRublo == rubloSeleccionado)
					{
						switch(arrayPublicaciones[i].EstadoPublicacion)
						{
						case 1:
							printf("ID:%d || Estado publicacion: ACTIVO || Contrador por el ID de cliente: %d || Aviso: %s\n",arrayPublicaciones[i].IDPublicidad,arrayPublicaciones[i].IDCliente,arrayPublicaciones[i].textoAviso);
							break;
						case 2:
							printf("ID:%d || Estado publicacion: PAUSADO || Contrador por el ID de cliente: %d || Aviso: %s\n",arrayPublicaciones[i].IDPublicidad,arrayPublicaciones[i].IDCliente,arrayPublicaciones[i].textoAviso);
							break;
						}
					}
				}
			}
			printf("\n");
		}
}

int info_calcularCantidadRublos(Publicidad* arrayPublicaciones,int limitePublicaciones,int listaRublo, int* contadorCantidadAvisos)
{
	int retorno = -1;
	int i;
	int contadorAvisos=0;
	if(arrayPublicaciones != NULL && limitePublicaciones > 0)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if(arrayPublicaciones[i].isEmty)
			{
				continue;
			}
			if(arrayPublicaciones[i].numeroDeRublo == listaRublo)
			{
				contadorAvisos = contadorAvisos + 1;
			}
		}
		retorno = 0;
		*contadorCantidadAvisos = contadorAvisos;
	}
	return retorno;
}

int info_imprimirContratacionesConImportePorCliente(Publicidad* arrayPublicaciones,int limitePublicaciones, int seleccion)
{
	int retorno = -1;
	int listaRublo[CANTIDAD_publ];
	int i;
	int j;
	int flagExisteRublo;
	int indiceRubloLibre = 0;
	int contadorCantidadAvisos;
	int avisoMaximo;
	int avisoMinimo;
	int indiceRubloMayorAvisos;
	int indiceRubloMenorAvisos;

	for(i=0;i<limitePublicaciones;i++)
	{
		flagExisteRublo = 0;
		if(arrayPublicaciones[i].isEmty == 0)
		{
			for(j=0;j<indiceRubloLibre;j++)
			{
				if(arrayPublicaciones[i].numeroDeRublo == listaRublo[j] && arrayPublicaciones[i].EstadoPublicacion == 1)
				{
					flagExisteRublo = 1;
					break;
				}
			}
			if(flagExisteRublo == 0 && arrayPublicaciones[i].EstadoPublicacion == 1)
			{
				listaRublo[j] = arrayPublicaciones[i].numeroDeRublo;
				indiceRubloLibre++;
			}
		}
	}

	/*for(j=0;j<indiceRubloLibre;j++)
	{
		printf("\n\nEl numero de rublo %d\n",listaRublo[j]);
		info_imprimirAvisoDelRublo(arrayPublicaciones,limitePublicaciones,listaRublo[j]);
	}*/

	for(j=0;j<indiceRubloLibre;j++)
	{

		info_calcularCantidadRublos(arrayPublicaciones, limitePublicaciones, listaRublo[j], &contadorCantidadAvisos);
		if(j== 0|| (contadorCantidadAvisos > avisoMaximo))
		{
			avisoMaximo = contadorCantidadAvisos;
			indiceRubloMayorAvisos = 	j;
		}
		if(j== 0|| (contadorCantidadAvisos < avisoMinimo))
		{
			avisoMinimo = contadorCantidadAvisos;
			indiceRubloMenorAvisos = 	j;
		}

	}

	switch(seleccion)
	{
	case 1:
		printf("\n\n El rublo con mayor avisos activos es: %d\n",listaRublo[indiceRubloMayorAvisos]);
		info_imprimirAvisoDelRublo(arrayPublicaciones,limitePublicaciones,listaRublo[indiceRubloMayorAvisos]);
		break;
	case 2:
		printf("\n\n El rublo con menos avisos activos es: %d\n",listaRublo[indiceRubloMenorAvisos]);
		info_imprimirAvisoDelRublo(arrayPublicaciones,limitePublicaciones,listaRublo[indiceRubloMenorAvisos]);
		break;
	}
	return retorno;
}

/*******************************************************************************************************************************
 * *****************************************************************************************************************************
 * *****************************************************************************************************************************
 * *****************************************************************************************************************************
 * *****************************************************************************************************************************
 * *****************************************************************************************************************************
 * *****************************************************************************************************************************
 */

/**
 * Pide al usuario un ID de los clientes creados y lo da de baja
 */
int cliente_BajaPublicacion(int iDCliente,Publicidad* arrayPublicaciones,int limitePublicaciones){

	int respuesta = -1;
	int j;
	if(arrayPublicaciones!=NULL && limitePublicaciones > 0 && iDCliente>= 0)
	{
		for(j=0;j<limitePublicaciones;j++)
		{
			if(arrayPublicaciones[j].isEmty==0 && arrayPublicaciones[j].IDCliente == iDCliente)
			{
				arrayPublicaciones[j].IDCliente = -1;
			}
		}
		respuesta=0;
	}
	return respuesta;
}

/**
 * Pide al usuario un ID de publicime los clientes asoiados al ID ingresado
 */
void publicaciones_ImprimirBusquedaPublicacionIDcliente(int IDPublicacion,Clientes* arrayCliente,int limiteCliente)
{
	if(arrayCliente!=NULL && limiteCliente > 0 && IDPublicacion>= 0)
		{
			int i;
			for(i=0;i<limiteCliente;i++)
			{
				if(arrayCliente[i].isEmty==0 && arrayCliente[i].IDClientes == IDPublicacion)
				{
					printf("\nID Cliente:%d ||| Nombre: %s ||| Apellido: %s ||| CUIT: %s \n",arrayCliente[i].IDClientes,arrayCliente[i].nombre,arrayCliente[i].apellido,arrayCliente[i].CUIT);
				}
			}
		}
}

/**
 * Pide al usuario un ID de publicaciones eh imprime la lista de clientes con respecto a sus publicaciones
 */
void cliente_ImprimirBusquedaIDClienteListaPublicaciones(int IDPublicacion,Publicidad* arrayPublicaciones,int limitePublicaciones)
{
	if(arrayPublicaciones!=NULL && limitePublicaciones > 0 && IDPublicacion>= 0)
		{
			int j;
			int guardarID[limitePublicaciones];
			int contador=0;
			for(j=0;j<limitePublicaciones;j++)
			{
				if(arrayPublicaciones[j].isEmty==0 && arrayPublicaciones[j].IDCliente == IDPublicacion)
				{
					guardarID[j] = arrayPublicaciones[j].IDPublicidad;
					contador++;
				}
			}
			for(j=0;j<contador;j++)
			{
				if(arrayPublicaciones[j].isEmty==0 && arrayPublicaciones[j].IDPublicidad == guardarID[j])
				{
					switch(arrayPublicaciones[j].EstadoPublicacion)
					{
					case 1:
						printf("Estado publicacion: ACTIVO || Aviso: %s || Rublo: %d\n",arrayPublicaciones[j].textoAviso,arrayPublicaciones[j].numeroDeRublo);
						break;
					case 2:
						printf("Estado publicacion: PAUSADO || Aviso: %s || Rublo: %d\n",arrayPublicaciones[j].textoAviso,arrayPublicaciones[j].numeroDeRublo);
						break;
					}
				}
			}
		}
}

/*
 * Imprime en pantalla las publiciones con los respectivos CUIT los cuales las tenga contratadas
 */
void publicaciones_ImprimirPublicacionConCUIT(Clientes* arrayCliente,int limiteCliente,Publicidad* arrayPublicaciones,int limitePPublicaciones)
{

	if(arrayPublicaciones!=NULL && limitePPublicaciones > 0 && arrayCliente!=NULL && limiteCliente)
		{
			int i;
			int j;
			for(j=0;j<limitePPublicaciones;j++)
			{
				if(arrayPublicaciones[j].isEmty==0 && arrayPublicaciones[j].numeroDeRublo > -1 && arrayPublicaciones[j].EstadoPublicacion > 0)
				{
					printf("\nPublicidad:\n");
					switch(arrayPublicaciones[j].EstadoPublicacion)
					{
					case 1:
						printf("ID:%d || Estado publicacion: ACTIVO || Contrador por el ID de cliente: %d || Aviso: %s || Rublo: %d\n",arrayPublicaciones[j].IDPublicidad,arrayPublicaciones[j].IDCliente,arrayPublicaciones[j].textoAviso,arrayPublicaciones[j].numeroDeRublo);
						break;
					case 2:
						printf("ID:%d || Estado publicacion: PAUSADO || Contrador por el ID de cliente: %d || Aviso: %s || Rublo: %d\n",arrayPublicaciones[j].IDPublicidad,arrayPublicaciones[j].IDCliente,arrayPublicaciones[j].textoAviso,arrayPublicaciones[j].numeroDeRublo);
						break;
					}
					printf("Esta contratado por el CUIT: ");

					for(i=0;i<limiteCliente;i++)
					{
						if(arrayCliente[i].isEmty==0 && arrayCliente[i].IDClientes == arrayPublicaciones[j].IDCliente && arrayPublicaciones[j].numeroDeRublo > -1)
						{
							printf("\nCUIT: %s \n",arrayCliente[i].CUIT);
						}
					}
				}
			}
		}
}

/*
 * Muestra en pantalla // Imprime por pantalla a el cliente con mas publiciones activas
 */
void cliente_MaximaPublicacionesActivas(Clientes* arrayCliente,int limiteCliente,Publicidad* arrayPublicaciones,int limitePublicaciones)
{
	if(arrayPublicaciones!=NULL && limitePublicaciones > 0 && arrayCliente!=NULL && limiteCliente)
		{
			int j; // -> j para publicaciones
			int i; // -> i para clientes
			int contador=0;
			int IDClienteActivas;
			int maximoActivas;
			for(i=0;i<limiteCliente;i++)
			{
				if(arrayCliente[i].isEmty==0)
				{
					for(j=0;j<limitePublicaciones;j++)
					{
						if(j==0)
						{
							contador=0;
						}
						if(arrayPublicaciones[j].isEmty==0 && arrayPublicaciones[j].IDCliente == arrayCliente[i].IDClientes && arrayPublicaciones[j].EstadoPublicacion == 1)
						{
							contador++;
							//printf("contador: %d",contador);
						}
					}
					if(i==0)
					{
						maximoActivas = contador;
					}
					if(maximoActivas < contador)
					{
						maximoActivas = contador;
						//printf("maximo: %d",maximoActivas);
						IDClienteActivas = arrayCliente[i].IDClientes;
					}
				}
			}
			 printf("\nCliente con mayor publicaciones activas es: ID Cliente:%d ||| Nombre: %s ||| Apellido: %s ||| CUIT: %s \n",arrayCliente[IDClienteActivas].IDClientes,arrayCliente[IDClienteActivas].nombre,arrayCliente[IDClienteActivas].apellido,arrayCliente[IDClienteActivas].CUIT);
		}
}

/*
 * Muestra en pantalla // Imprime por pantalla a el cliente con mas publiciones pausadas
 */
void cliente_MaximaPublicacionesPausadas(Clientes* arrayCliente,int limiteCliente,Publicidad* arrayPublicaciones,int limitePublicaciones)
{
	if(arrayPublicaciones!=NULL && limitePublicaciones > 0 && arrayCliente!=NULL && limiteCliente)
		{
			int j; // -> j para publicaciones
			int i; // -> i para clientes
			int contador=0;
			int IDClienteActivas;
			int maximoPausadas;
			for(i=0;i<limiteCliente;i++)
			{
				if(arrayCliente[i].isEmty==0)
				{
					for(j=0;j<limitePublicaciones;j++)
					{
						if(j==0)
						{
							contador=0;
						}
						if(arrayPublicaciones[j].isEmty==0 && arrayPublicaciones[j].IDCliente == arrayCliente[i].IDClientes && arrayPublicaciones[j].EstadoPublicacion == 2)
						{
							contador++;
						// printf("contador pausdas: %d",contador);
						}
					}
					//printf("\n salgo del for\n");
					if(i==0)
					{
						maximoPausadas = contador;
						//printf("maximo pausdas: %d",maximoPausadas);
					}
					if(maximoPausadas <= contador)
					{
						maximoPausadas = contador;
						//printf("pausdas: %d",maximoPausadas);
						IDClienteActivas = arrayCliente[i].IDClientes;
						//printf("id aguardado: %d",IDClienteActivas);
					}
					//printf("\n salgo del if id\n");
				}
			}
			 printf("\nCliente con mayor publicaciones pausadas es: ID Cliente:%d ||| Nombre: %s ||| Apellido: %s ||| CUIT: %s \n",arrayCliente[IDClienteActivas].IDClientes,arrayCliente[IDClienteActivas].nombre,arrayCliente[IDClienteActivas].apellido,arrayCliente[IDClienteActivas].CUIT);
		}
}


/*
 * Muestra en pantalla // Imprime por pantalla a el cliente con mas publiciones
 */
void cliente_MaximaPublicaciones(Clientes* arrayCliente,int limiteCliente,Publicidad* arrayPublicaciones,int limitePublicaciones)
{
	if(arrayPublicaciones!=NULL && limitePublicaciones > 0 && arrayCliente!=NULL && limiteCliente)
		{
			int j; // -> j para publicaciones
			int i; // -> i para clientes
			int contador=0;
			int IDClienteActivas;
			int maximoTotal;
			for(i=0;i<limiteCliente;i++)
			{
				if(arrayCliente[i].isEmty==0)
				{
					for(j=0;j<limitePublicaciones;j++)
					{
						if(j==0)
						{
							contador=0;
						}
						if(arrayPublicaciones[j].isEmty==0 && arrayPublicaciones[j].IDCliente == arrayCliente[i].IDClientes)
						{
							contador++;
							//printf("contador: %d",contador);
						}
					}
					if(i==0)
					{
						maximoTotal = contador;
					}
					if(maximoTotal < contador)
					{
						maximoTotal = contador;
						//printf("maximo: %d",maximoActivas);
						IDClienteActivas = arrayCliente[i].IDClientes;
					}
				}
			}
			 printf("\nCliente con mas publicaciones es: ID Cliente:%d ||| Nombre: %s ||| Apellido: %s ||| CUIT: %s \n",arrayCliente[IDClienteActivas].IDClientes,arrayCliente[IDClienteActivas].nombre,arrayCliente[IDClienteActivas].apellido,arrayCliente[IDClienteActivas].CUIT);
		}
}

/*
 * Imprime en pantalla la lista de clientes son sus respectivas publicaciones
 */
void cliente_ImprimirClienteConSusPublicaciones(Clientes* arrayCliente,int limiteCliente,Publicidad* arrayPublicaciones,int limitePublicaciones)
{
	if(arrayPublicaciones!=NULL && limitePublicaciones > 0 && arrayCliente!=NULL && limiteCliente)
		{
			int j; // -> j para publicaciones
			int i; // -> i para clientes
			int contador=0;
			printf("\nClientes:");
			 for(i=0;i<limiteCliente;i++)
			{
				if(arrayCliente[i].isEmty==0)
				{

					printf("\nID:%d ||| Nombre: %s ||| Apellido: %s ||| CUIT: %s \n",arrayCliente[i].IDClientes,arrayCliente[i].nombre,arrayCliente[i].apellido,arrayCliente[i].CUIT);
					for(j=0;j<limitePublicaciones;j++)
					{

						if(arrayPublicaciones[j].isEmty==0 && arrayPublicaciones[j].IDCliente == arrayCliente[i].IDClientes && arrayPublicaciones[j].EstadoPublicacion == 1 && arrayPublicaciones[j].numeroDeRublo > -1)
						{
							contador++;
						}
					}
					printf("Cuenta con avisos activos: %d\n",contador);
					contador = 0;
				}
			}
		}
}

/*
 * Muestra en pantalla // Imprime por pantalla a el RUBLO Solicitado y sus PUBLICACIONES ACTIVAS
 */
void rublo_CantidadPublicacionesActivas(Publicidad* arrayPublicaciones,int limitePublicaciones)
{

	int seleccionRublo;
	int contador = 0;
	if(arrayPublicaciones!=NULL && limitePublicaciones > 0)
	{
		int j;
		//preguntar que rublo elegir
		if(utn_getNumero(&seleccionRublo,"\nElegia el rublo a mostrar sus avisos->","\n --- ERROR ---\n",1,9999,3) == 0)
		{
			for(j=0;j<limitePublicaciones;j++)
			{
				if(arrayPublicaciones[j].isEmty==0 && arrayPublicaciones[j].numeroDeRublo == seleccionRublo && arrayPublicaciones[j].EstadoPublicacion == 1)
				{
					contador++;
					//printf("contador: %d",contador);
					}
			}
		}
		printf("\nEl rublo seleccionado %d tiene %d publicaciones activas\n\n",seleccionRublo,contador);
		info10a_imprimirAvisoDelRublo(arrayPublicaciones,limitePublicaciones,seleccionRublo);
	}
}

/*
 * Muestra en pantalla // Imprime por pantalla a el RUBLO CON MAS PUBLICACIONES ACTIVAS
 */
void rublo_ConMasPublicacionesActivas(Publicidad* arrayPublicaciones,int limitePublicaciones)
{

	int contador = 0;
	int maximo = 0;
	int auxiliarRublo;
	if(arrayPublicaciones!=NULL && limitePublicaciones > 0)
	{
		int j;
		for(j=0;j<limitePublicaciones;j++)
		{
			if(arrayPublicaciones[j].isEmty==0 && arrayPublicaciones[j].EstadoPublicacion == 1 && arrayPublicaciones[j].IDCliente == arrayPublicaciones[j+1].IDCliente)
			{
				contador++;
				//printf("contador: %d",contador);
			}
			if(j==0){
				maximo = contador;
				//printf("maximo%d\n",maximo);
			}
			if(maximo < contador)
			{
				maximo = contador;
				//printf("maximo%d",maximo);
				auxiliarRublo = arrayPublicaciones[j].numeroDeRublo;
			}
		}
		printf("El rublo con mas publicaciones activas es: %d\n",auxiliarRublo);
	}
}

/*
 * Muestra en pantalla // Imprime por pantalla a el RUBLO CON MENOS PUBLICACIONES ACTIVAS
 */
void rublo_ConMenosPublicacionesActivas(Publicidad* arrayPublicaciones,int limitePublicaciones)
{

	int contador = 0;
	int minimo;
	int auxiliarRublo;
	if(arrayPublicaciones!=NULL && limitePublicaciones > 0)
	{
		int j;
		for(j=0;j<limitePublicaciones;j++)
		{
			if(arrayPublicaciones[j].isEmty==0 && arrayPublicaciones[j].EstadoPublicacion == 1)
			{
				contador++;
				//printf("contador: %d\n",contador);
			}
			if(j==0){
				minimo = contador;
				//printf("maximo%d\n",maximo);
			}
			if(minimo > contador)
			{
				minimo = contador;
				//printf("minimo%d",minimo);
				auxiliarRublo = arrayPublicaciones[j].numeroDeRublo;
			}
		}
		printf("El rublo con menos publicaciones activas es: %d\n",auxiliarRublo);
	}
}


/*
 * FUNCION CENTRAL DEL PROGRAMA
 * arrayC corresponde a un puntero de una estrucctura Cliente
 * limiteC es el Limite de la estructtura Cliente a manejar
 * arrayP corresponde a un puntero de una estructura Publicidad
 * limiteP es el Limite de la estructtura Publicidad a manejar
 */
void cliente_Cargar(Clientes* arrayClientes,int limiteCliente,Publicidad* arrayPublicaciones,int limitePublicaciones){

	if(arrayClientes!=NULL && limiteCliente > 0)
	{
		int opcionMenu;
		int indiceModificar;
		int indiceBorrar;
		int auxiliarIndiceClientes=-1;
		int auxiliarIndicePublicaciones=-1;

		char menuNueve;
		char menuDiez;

		while(opcionMenu != 11){

			menuPrincipal();
			if(utn_getNumero(&opcionMenu,"\n Eliga ->","\n - ERROR - \n",1,11,3)==0)
			{
				switch(opcionMenu)
				{
				case 1:
					printf("\n\nCarga Cliente\n");
					auxiliarIndiceClientes = cliente_getEmptyIndex(arrayClientes,limiteCliente);
					//printf("%d INDICE\n",indiceFuncion);
					if(auxiliarIndiceClientes >= 0)
					{
						if(cliente_CargarDATOS(arrayClientes,limiteCliente,auxiliarIndiceClientes) == 0)
						{
							printf("\nCarga OK -- ");
							printf("En el ID %d",arrayClientes[auxiliarIndiceClientes].IDClientes);
						}
						else
						{
							printf("\nNO HAY MAS LUGAR\n");
						}
					}
					break;

				case 2:
					printf("\n\nModificar Cliente\n");
					if(auxiliarIndiceClientes >= 0)
					{
						cliente_Imprimir(arrayClientes,limiteCliente);
						if(utn_getNumero(&indiceModificar,"\nIngrese el ID a modificar: ","\nERROR - INIDICE FUERA DE CAMPO\n",0,limiteCliente,3)==0)
						{
							if(estructura_buscarID(arrayClientes,limiteCliente,indiceModificar)==0)
							{
								printf("\nIndice Correcto.\n");
								if(cliente_Modificar(arrayClientes,limiteCliente,indiceModificar) == 0)
								{
									printf("\nModificacion realizada con exito\n");
								}
							}
							else
							{
								printf("\n\nID elegido incorrecto\n\n");
							}
						}
					}
					else
					{
						printf("\n NO HAY CLIENTES CARGADOS\n");
					}
					break;

				case 3:
					printf("\n\nBaja Cliente\n");
					cliente_Imprimir(arrayClientes,limiteCliente);
					if(utn_getNumero(&indiceBorrar,"\nIngrese el ID a dar de baja: ","\nERROR - INIDICE FUERA DE CAMPO\n",0,limiteCliente,3)==0)
					{
						if(estructura_buscarID(arrayClientes,limiteCliente,indiceBorrar)==0)
						{
							printf("\nIndice Correcto.\n");
							int pregunta;
							/*
							 * MOSTRAR PUBLICACIONES DEL CLIENTE
							 */
							cliente_ImprimirBusquedaIDClienteListaPublicaciones(indiceBorrar,arrayPublicaciones,limitePublicaciones);

							/*
							 * confirmacion si quiere borrar o no
							 */
							if(utn_getNumero(&pregunta,"Seguro que quiere borrar al cliente:\n1.SI\n2.NO","\nERROR\n",1,2,3)==0)
							{
								if(pregunta == 1 &&
									cliente_Borrar(arrayClientes,limiteCliente,indiceBorrar) == 0 &&
									cliente_BajaPublicacion(indiceBorrar,arrayPublicaciones,limitePublicaciones) == 0)
								{
									printf("\nCLIENTE BORRADO CON EXITO\n");
									//publicidad_Imprimir(arrayP,limiteP);
								}
								else
								{
									printf("\nBorrado de cliente anulado\n");
								}
							}
						}
						else
						{
							printf("\n\nID elegido incorrecto\n\n");
						}
					}
					break;

				case 4:
					printf("\n\nCrear Publicacion\n");
					auxiliarIndicePublicaciones = publicidad_getEmptyIndex(arrayPublicaciones,limitePublicaciones);
					printf("%d INDICE\n",auxiliarIndicePublicaciones);
					if(auxiliarIndicePublicaciones >= 0)
					{
						if(publicidad_CargarDATOS(arrayPublicaciones,limitePublicaciones,auxiliarIndicePublicaciones) == 0)
						{
							printf("\nCarga OK -- ");
						}
						else
						{
							printf("\nNO HAY MAS LUGAR\n");
						}
					}
					break;

				case 5:
					printf("\n\nPausar Publicacion\n\n");
					publicidad_Imprimir(arrayPublicaciones,limitePublicaciones);
					//indiceBajaPublicacion
					if(utn_getNumero(&indiceBorrar,"\nIngrese el ID de la publicacion a pausar: ","\nERROR - INIDICE FUERA DE CAMPO\n",0,limitePublicaciones,3)==0)
					{
						if(publicidad_buscarID(arrayPublicaciones,limitePublicaciones,indiceBorrar)==0)
						{
							printf("\nIndice Correcto.\n");
							int pregunta;
							/*
							 * MOSTRAR CUENTAS DE LAS PUBLICACIONES
							 */
							publicaciones_ImprimirBusquedaPublicacionIDcliente(indiceBorrar,arrayClientes,limiteCliente);
							/*
							 * PREGUNTA DE PROSEGUIR O NO
							 */
							if(utn_getNumero(&pregunta,"Seguro que quiere dar de baja la publicacion:\n1.SI\n2.NO","\nERROR\n",1,2,3)==0)
							{//publicidad_Baja(Publicidad array[],int limite, int indice)
								if(pregunta == 1 &&
									publicidad_Baja(arrayPublicaciones,limitePublicaciones,indiceBorrar) == 0)
								{
									printf("\nPublicacion pausada\n");
									//publicidad_Imprimir(arrayP,limiteP);
								}
								else
								{
									printf("\nBorrado de cliente anulado\n");
								}
							}
						}
					}
					break;

				case 6:
					printf("\n\nReanudar publicacion\n\n");
					publicidad_Imprimir(arrayPublicaciones,limitePublicaciones);
					//indiceBajaPublicacion
					if(utn_getNumero(&indiceBorrar,"\nIngrese el ID de la publicacion a reanudad: ","\nERROR - INIDICE FUERA DE CAMPO\n",0,limitePublicaciones,3)==0)
					{
						if(publicidad_buscarID(arrayPublicaciones,limitePublicaciones,indiceBorrar)==0)
						{
							printf("\nIndice Correcto.\n");
							int pregunta;
							/*
							 * MOSTRAR CUENTAS DE LAS PUBLICACIONES
							 */
							publicaciones_ImprimirBusquedaPublicacionIDcliente(indiceBorrar,arrayClientes,limiteCliente);
							/*
							 * PREGUNTA DE PROSEGUIR O NO
							 */
							if(utn_getNumero(&pregunta,"Seguro que quiere reanudar la publicacion:\n1.SI\n2.NO","\nERROR\n",1,2,3)==0)
							{//publicidad_Baja(Publicidad array[],int limite, int indice)
								if(pregunta == 1 &&
									publicidad_Alta(arrayPublicaciones,limitePublicaciones,indiceBorrar) == 0)
								{
									printf("\nPublicacion pausada\n");
									//publicidad_Imprimir(arrayP,limiteP);
								}
								else
								{
									printf("\nBorrado de cliente anulado\n");
								}
							}
						}
					}
					break;

				case 7:
					printf("\n\nImprimir Clientes\n\n");
					cliente_ImprimirClienteConSusPublicaciones(arrayClientes,limiteCliente,arrayPublicaciones,limitePublicaciones);
					break;

				case 8:
					printf("\n\nImprimir publicaciones\n\n");
					publicaciones_ImprimirPublicacionConCUIT(arrayClientes,limiteCliente,arrayPublicaciones,limitePublicaciones);
					break;

				case 9:
					while(menuNueve != 'd')
					{
						menu_PNueve();
						printf("    d)Volver\n");
						if(utn_getChar(&menuNueve,"\n   d)Volver.\n Eliga ->","\n - ERROR - \n",97,100,3)==0)
						{
							switch(menuNueve)
							{
							case 'a':
								cliente_MaximaPublicacionesActivas(arrayClientes,limiteCliente,arrayPublicaciones,limitePublicaciones);
								break;
							case 'b':
								cliente_MaximaPublicacionesPausadas(arrayClientes,limiteCliente,arrayPublicaciones,limitePublicaciones);
								break;
							case 'c':
								cliente_MaximaPublicaciones(arrayClientes,limiteCliente,arrayPublicaciones,limitePublicaciones);
								break;
							case 'd':
								break;
							}
						}
					}
					menuNueve = 'z';
					break;

				case 10:
					while(menuDiez != 'd')
					{
						menu_PDiez();
						printf("    d)Volver\n");
						if(utn_getChar(&menuDiez,"Eliga ->","\n - ERROR - \n",97,100,3)==0)
						{
							switch(menuDiez)
							{
							case 'a':
								rublo_CantidadPublicacionesActivas(arrayPublicaciones,limitePublicaciones);
								break;
							case 'b':
								info_imprimirContratacionesConImportePorCliente(arrayPublicaciones,limitePublicaciones,1);
								//rublo_ConMasPublicacionesActivas(arrayPublicaciones,limitePublicaciones);
								break;
							case 'c':
								info_imprimirContratacionesConImportePorCliente(arrayPublicaciones,limitePublicaciones,2);
								//rublo_ConMenosPublicacionesActivas(arrayPublicaciones,limitePublicaciones);
								break;
							case 'd':
								break;
							}
						}
					}
					menuDiez = 'z';
					break;

				case 11:
					// SALIR
					break;
				}
			}
		}
	}
}

