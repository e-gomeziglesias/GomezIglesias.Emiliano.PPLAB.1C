/*
 * Menu.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

#ifndef MENU_H_
#define MENU_H_



#endif /* MENU_H_ */

//1.
/// @fn int MostrarMenuPrincipalOpciones(void)
/// @brief Muestra el menu principal de opciones
///
/// @return La opcion elegida si ok, -1 si error
int MostrarMenuPrincipalOpciones (void);

//2.
/// @fn int MostrarMenuAltas(void)
/// @brief Muestra el menu de opciones de altas
///
/// @return La opcion elegida si ok, -1 si error
int MostrarMenuAltas(void);

//3.
/// @fn int MostrarMenuBajas(void)
/// @brief Muestra el menu de opciones de bajas
///
/// @return La opcion elegida si ok, -1 si error
int MostrarMenuBajas(void);

//4.
/// @fn int MostrarMenuModificaciones(void)
/// @brief Muestra el menu de opciones de modificaciones
///
/// @return La opcion elegida si ok, -1 si error
int MostrarMenuModificaciones(void);

//4.1
/// @fn int MostrarMenuModificacionesClientes(void)
/// @brief Muestra el menu de opciones de modificaciones de clientes
///
/// @return La opcion elegida si ok, -1 si error
///
int MostrarMenuModificacionesClientes(void);

//5.
/// @fn int MostrarMenuListados(void)
/// @brief Muestra el menu de opciones de listados
///
/// @return La opcion elegida si ok, -1 si error
int MostrarMenuListados(void);

//6.
/// @fn int MostrarMenuInformes(void)
/// @brief Muestra el menu de opciones de informes
///
/// @return La opcion elegida si ok, -1 si error
int MostrarMenuInformes(void);

//7.
/// @fn void AnalizarRetorno(int, char[], char[])
/// @brief permite imprimir mensajes por pantalla en funcion del valor de retorno de una funcion
///
/// @param retorno parametro que se le debe indicar a la funcion
/// @param mensaje mensaje de exito si el retorno es distinto de -1
/// @param mensajeError mensaje de error si el retorno es igual a -1
void AnalizarRetorno(int retorno, char mensaje[], char mensajeError[]);

/*
	//4.2
	/// @fn int MostrarMenuModificacionesTipo(void)
	/// @brief Muestra el menu de opciones de modificaciones de tipos
	///
	/// @return La opcion elegida si ok, -1 si error
	int MostrarMenuModificacionesTipo(void);

	//4.3
	/// @fn int MostrarMenuModificacionesNacionalidad(void)
	/// @brief Muestra el menu de opciones de modificaciones de nacionalidades
	///
	/// @return La opcion elegida si ok, -1 si error
	int MostrarMenuModificacionesNacionalidad(void);
*/
