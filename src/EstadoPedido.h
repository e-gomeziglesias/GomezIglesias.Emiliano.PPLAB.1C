/*
 * EstadoPedido.h
 *
 *  Created on: 24 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Input.h"


#ifndef ESTADOPEDIDO_H_
#define ESTADOPEDIDO_H_

typedef struct
{
	int idEstado;
	char descripcionEstado[50];
	int isEmpty;
}eEstado;

#endif /* ESTADOPEDIDO_H_ */

//1.
/// @fn int InicializarEstados(eEstado[], int)
/// @brief inicializa un listado de estados
///
/// @param listaEstados listado a inicializar
/// @param tamEstados tamano del listado
/// @return 0 si ok, -1 si error
int InicializarEstados(eEstado listaEstados[], int tamEstados);

//2.
/// @fn int MostrarUnEstado(eEstado)
/// @brief Permite mostrar los datos completos para un estado
///
/// @param unEstado estado a mostrar
/// @return 0 si ok, -1 si error
int MostrarUnEstado(eEstado unEstado);

//3.
/// @fn int MostrarDescripcionDeUnEstado(eEstado[], int, int)
/// @brief muestra la descripcion de un estado, cuyo id se pasa por parametro
///
/// @param listadoEstados listado de estados donde buscar el id
/// @param tamEstados tamano del listado
/// @param idEstado id a buscar
/// @return 0 si ok, -1 si error
int MostrarDescripcionDeUnEstado(eEstado listadoEstados[], int tamEstados, int idEstado);

//4.
/// @fn int MostrarEstados(eEstado[], int)
/// @brief permite mostrar el listado completo de estados dados de alta
///
/// @param listaEstados listado de estados
/// @param tamEstados tamano del listad
/// @return 0 si ok, -1 si error
int MostrarEstados(eEstado listaEstados[], int tamEstados);

//5.
/// @fn int BuscarEstadoPorId(eEstado[], int, int)
/// @brief Dado un id, busca el estado que se corresponde con dicho id
///
/// @param listaEstados listado de estados donde buscar la coincidencia
/// @param tamEstados tamano del listado
/// @param idEstado id a buscar
/// @return si encuntra el id, retorna el indice, sino retorna -1
int BuscarEstadoPorId(eEstado listaEstados[], int tamEstados, int idEstado);

//6.
/// @fn int BuscarPosicionEstadoLibre(eEstado[], int)
/// @brief Permite buscar posiciones libres en un listado de estadod
///
/// @param listaEstados listado donde buscar la posicion libre
/// @param tamEstados tamano del listado
/// @return el indice de la posicion libre si la hay, sino retorna -1
int BuscarPosicionEstadoLibre(eEstado listaEstados[], int tamEstados);

//7.
/// @fn int HardcodearEstados(eEstado[], int, int*)
/// @brief permite hardcodear los estados posibles
///
/// @param listaEstados listado a hardcodear
/// @param tamListaEstados tamano el listado
/// @param pNextIdEstado id direcccion del siguiente id disponible
/// @return si error -1, sino retorna la cantidad de datos hardcodeados
int HardcodearEstados(eEstado listaEstados[], int tamListaEstados, int* pNextIdEstado);


