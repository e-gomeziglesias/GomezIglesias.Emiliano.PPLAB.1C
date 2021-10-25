/*
 * Localidad.h
 *
 *  Created on: 22 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include <string.h>
#define TAM_DESCRIPCION 100

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

typedef struct
{
	int idLocalidad; //PK
	char descripcionLocalidad[TAM_DESCRIPCION];
	int isEmpty;
}eLocalidad;

#endif /* LOCALIDAD_H_ */

//1.
/// @fn int InicializarLocalidades(eLocalidad[], int)
/// @brief Permite inicializar un array del tipo eLocalidad, colocando en 1 el campo isEmpty, indicando que esta vacio
///
/// @param listaLocalidades array de eLocalidad
/// @param tamLocalidades tamano del array
/// @return 0 si ok, -1 si error
int InicializarLocalidades(eLocalidad listaLocalidades[], int tamLocalidades);

//2.
/// @fn int MostrarUnaLocalidad(eLocalidad)
/// @brief Permite mostrar id y descripcion de una localidad
///
/// @param unaLocalidad localidad a mostrar
/// @return 0 si ok, -1 si error
int MostrarUnaLocalidad(eLocalidad unaLocalidad);

//3.
/// @fn int MostrarDescripcionDeUnaLocalidad(eLocalidad[], int, int)
/// @brief Permite mostrar la descripcion de una localidad, pasando su id por parametro
///
/// @param listadoLocalidades listado donde buscar la descripcion
/// @param tamLocalidades tamano del listado
/// @param idLocalidad id de la localidad que le mostraremos la descripcion
/// @return 0 si ok, -1 si error
int MostrarDescripcionDeUnaLocalidad(eLocalidad listadoLocalidades[], int tamLocalidades, int idLocalidad);

//4.
/// @fn int MostrarLocalidades(eLocalidad[], int)
/// @brief Permite mostrar el listado de localidades actualizado
///
/// @param listaLocalidades listado a mostrar
/// @param tamLocalidades tamano del listado
/// @return 0 si ok; -1 si error
int MostrarLocalidades(eLocalidad listaLocalidades[], int tamLocalidades);

//5.
/// @fn int BuscarLocalidadPorId(eLocalidad[], int, int)
/// @brief pasado un id por parametro, permite buscar una localidad dentro de un array de localidades
///
/// @param listaLocalidades listado donde buscar
/// @param tamLocalidades tamano del listado
/// @param idLocalidad id a buscar
/// @return -1 si error o si no encuentra, el indice del i si encuentra ok.
int BuscarLocalidadPorId(eLocalidad listaLocalidades[], int tamLocalidades, int idLocalidad);

//6.
/// @fn int BuscarPosicionLocalidadLibre(eLocalidad[], int)
/// @brief Permite buscar si hay alguna posicion libre dentro de un array de localidades
///
/// @param listaLocalidades listado donde buscar
/// @param tamLocalidades tamano del listado
/// @return si encuentra espacio libre, devuelve el indice. Sino, devuelve -1
int BuscarPosicionLocalidadLibre(eLocalidad listaLocalidades[], int tamLocalidades);

//7.
/// @fn void HardcodearLocalidades(eLocalidad[], int, int*)
/// @brief permite hardcodear un listado de prueba de localidades
///
/// @param listaLocalidades listado a cargar
/// @param tamListaLocalidades tamano del listado
/// @param pNextIdLocalidad direccion del siguiente id de localidad que se podra cargar.
/// @return la cantidad de localidades hardcodeadas
int HardcodearLocalidades(eLocalidad listaLocalidades[], int tamListaLocalidades, int* pNextIdLocalidad);

//8.
/// @fn int ContarLocalidades(eLocalidad[], int)
/// @brief Permite contar la cantidad de localidades dadas de alta
///
/// @param listaLocalidades listado donde contar las localidades
/// @param tamListaLocalidades tamano de la lista
/// @return cantidad de localidades cargadas.
int ContarLocalidades(eLocalidad listaLocalidades[], int tamListaLocalidades);

//9.
/// @fn int ElegirLocalidad(eLocalidad[], int)
/// @brief Despliega el listado de localidades y permite elegir una por su id
///
/// @param listaLocalidades listado de localidades
/// @param tamLocalidades tamano del listado
/// @return el indice de la localidad si lo encuentra. Sino devuelve -1
int ElegirLocalidad(eLocalidad listaLocalidades[], int tamLocalidades);
