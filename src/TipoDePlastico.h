/*
 * TipoDePlastico.h
 *
 *  Created on: 22 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include <string.h>

#define DESCRIP_TIPO 60

#ifndef TIPODEPLASTICO_H_
#define TIPODEPLASTICO_H_

typedef struct
{
	int idTipoDePlastico; //PK
	char descripcionTipoDePlastico[DESCRIP_TIPO];
	int isEmpty;
}eTipoDePlastico;


#endif /* TIPODEPLASTICO_H_ */


//1.
/// @fn int InicializarTiposDePlastico(eLocalidad[], int)
/// @brief Permite inicializar un listado de tipos de plasticos
///
/// @param listaTiposDePlastico listado a inicializar
/// @param tamTiposDePlastico tamano del listado
/// @return 0 si ok, -1 si error
int InicializarTiposDePlastico(eTipoDePlastico listaTiposDePlastico[], int tamTiposDePlastico);

//2.
/// @fn int MostrarUnTipoDePlastico(eTipoDePlastico)
/// @brief Permite mostrar los datos de un tipo de plastico
///
/// @param unTipoDePlastico tipo de plastico a mostrar
/// @return 0 si ok, -1 si error
int MostrarUnTipoDePlastico(eTipoDePlastico unTipoDePlastico);

//3.
/// @fn int MostrarDescripcionDeUnTipoDePlastico(eTipoDePlastico[], int, int)
/// @brief Permite mostrar la descripcion de un tipo de plastico cuyo id pasamos por parametro
///
/// @param listaTiposDePlastico listado de tipos de plastico
/// @param tamTiposDePlastico tamano del listado de tipso de plastico
/// @param idTipoDePlastico id del tipo de plastico que mostraremos la descripcion
/// @return 0 si ok, -1 si error
int MostrarDescripcionDeUnTipoDePlastico(eTipoDePlastico listaTiposDePlastico[], int tamTiposDePlastico, int idTipoDePlastico);

//4.
/// @fn int MostrarTiposDePlastico(eTipoDePlastico[], int)
/// @brief Permite mostrar el listado completo de los tipos de plastico
///
/// @param listaTiposDePlastico listado de tipos de plastico
/// @param tamTiposDePlastico tamano del listado
/// @return 0 si ok, -1 si error
int MostrarTiposDePlastico(eTipoDePlastico listaTiposDePlastico[], int tamTiposDePlastico);

//5.
/// @fn int BuscarTipoDePlasticoPorId(eTipoDePlastico[], int, int)
/// @brief Dado un id de tipo de plastico, permite buscar el tipo de plastico que coincida con dicho id
///
/// @param listaTiposDePlastico listado donde buscar
/// @param tamTiposDePlastico tamano del listado
/// @param idTipoDePlastico id a buscar
/// @return el indice del id en cuestion si lo encuentra, -1 si error.
int BuscarTipoDePlasticoPorId(eTipoDePlastico listaTiposDePlastico[], int tamTiposDePlastico, int idTipoDePlastico);

//6.
/// @fn int BuscarPosicionTiposDePlasticoLibre(eTipoDePlastico[], int)
/// @brief Permite buscar una posicion libre dentro de un array de tipos de plasticos
///
/// @param listaTiposDePlastico listado donde buscar la posicion libre
/// @param tamTiposDePlastico tamano del listado
/// @return -1 si error. Si encuentra lugar, devuelve el indice libre.
int BuscarPosicionTiposDePlasticoLibre(eTipoDePlastico listaTiposDePlastico[], int tamTiposDePlastico);

//7.
/// @fn int HardcodearTiposDePlasticos(eTipoDePlastico[], int, int*)
/// @brief permite hardcodear el listado de tipos de plasticos
///
/// @param listaTiposDePlasticos listado a cargar
/// @param tamTiposDePlasticos tamano del listado
/// @param pNextIdTipoDePlastico direccion del id del siguiente id de tipo de plastico a cargar
/// @return la cantidad de tipos de plasticos hardcodeados
int HardcodearTiposDePlasticos(eTipoDePlastico listaTiposDePlasticos[], int tamTiposDePlasticos, int* pNextIdTipoDePlastico);

//8.
/// @fn int ContarTiposDePlastico(eTipoDePlastico[], int)
/// @brief Permite contar la cantidad de tipos de plasticos dados de alta
///
/// @param listaTiposDePlastico listado a contar
/// @param tamListaTiposDePlastico tamano del listado
/// @return cantidad de tipos de plasticos dados de alta
int ContarTiposDePlastico(eTipoDePlastico listaTiposDePlastico[], int tamListaTiposDePlastico);
