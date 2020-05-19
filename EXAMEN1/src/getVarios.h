/*
 * getVerificarVarios.h
 *
 *  Created on: 30 abr. 2020
 *      Author: Manuel
 */

#ifndef GETVARIOS_H_
#define GETVARIOS_H_

/*
 * CARGAR CUIT
 * CARGAR DNI
 */

int utn_getEmail(char* mensaje, char* mensajeError, int longitud, int reintentos, char* pResultado);

int isValidEmail(char* stringRecibido);

int utn_getCUIT(char* pResultado, char* mensaje, char* mensajeError, int reintentos);

int isValidCUIT(char* stringRecibido);

#endif /* GETVARIOS_H_ */
