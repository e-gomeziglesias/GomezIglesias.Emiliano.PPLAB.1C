/*
 * Clientes.h
 *
 *  Created on: 22 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

#define TAM_NOMBRE 20
#define TAM_CUIT 14
#define TAM_DIRECCION 60

#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct
{
	int idCliente;//PK
	char nombreCliente[TAM_NOMBRE];
	char cuitCliente[TAM_CUIT];
	char direccionCliente[TAM_DIRECCION];
	int idLocalidad;//FK
	int isEmpty;

}eCliente;


#endif /* CLIENTES_H_ */


//1.
/// @fn int InicializarClientes(eCliente[], int)
/// @brief permite inicializar un listado de clientes, indicando que el listado esta vacio (isEmpty = 1)
///
/// @param listaClientes listado a inicializar
/// @param tamClientes tamano del listado
/// @return 0 si ok, -1 si error
int InicializarClientes(eCliente listaClientes[], int tamClientes);

//2.
/// @fn int BuscarClientePorId(eCliente[], int, int)
/// @brief dado un id, permite buscar en un array de clientes al cliente cuyo id coincida con el id pasado por paramtero
///
/// @param listaClientes listado donde buscar
/// @param tamClientes tamano del listado
/// @param idCliente id a buscar
/// @return -1 si no lo encuenrtra, el indice si lo encuentra.
int BuscarClientePorId(eCliente listaClientes[], int tamClientes, int idCliente);

//3.
/// @fn int CargarNombreCliente(eCliente*)
/// @brief Permite cargar el nombre de un cliente
///
/// @param pUnCliente direccion de memoria del cliente al cual cargarle el nombre
/// @return 0 si ok, -1 si error
int CargarNombreCliente(eCliente* pUnCliente);

//4.
/// @fn int CargarCuitCliente(eCliente*)
/// @brief Permite cargar el cuit de un cliente
///
/// @param pUnCliente direccion de memoria del cliente al que se le cargara el cuit
/// @return 0 si ok, -1 si error.
int CargarCuitCliente(eCliente* pUnCliente);

//5.
/// @fn int CargarDireccionCliente(eCliente*)
/// @brief permite cargar la direccion de un cliente
///
/// @param pUnCliente direccion de memoria del cliente al que se le cargara la direccion
/// @return 0 si ok, -1 si error
int CargarDireccionCliente(eCliente* pUnCliente);

//6.
/// @fn int BuscarPosicionClienteLibre(eCliente[], int)
/// @brief Permite buscar dentro de un array de clientes si hay alguna posicion libre
///
/// @param listaClientes lista donde buscar el espacio libre
/// @param tamClientes tamano de la lista
/// @return -1 si no encontro lugar, sino devuelve el indice libre
int BuscarPosicionClienteLibre(eCliente listaClientes[], int tamClientes);

//7.
/// @fn int HardcodearClientes(eCliente[], int, int*)
/// @brief Permite hardcodear datos de clientes en un listado de clientes
///
/// @param listaClientes listado a hardcodear
/// @param tamListaClientes taamno del listado
/// @param pNextIdCliente direccion del siguiente id libre
/// @return cantidad de clientes hardcodeados
int HardcodearClientes(eCliente listaClientes[], int tamListaClientes, int* pNextIdCliente);

//8.
/// @fn int ContarClientes(eCliente[], int)
/// @brief Permite contar la cantidad de clientes dados de alta
///
/// @param listaClientes listado a contar
/// @param tamClientes tamano del listado
/// @return cantidad de clientes dados de alta
int ContarClientes(eCliente listaClientes[], int tamClientes);

//9.
/// @fn int MostrarCuitUnCliente(eCliente)
/// @brief Permite mostrar el cuit de un cliente
///
/// @param unCliente cliente cuyo cuit queremos mostrar
/// @return 0 si ok, -1 si error
int MostrarCuitUnCliente(eCliente unCliente);

//10.
/// @fn int MostrarDireccionUnCliente(eCliente)
/// @brief Permite mostrar la direccion de un cliente
///
/// @param unCliente cliente cuya direccion queremos mostrar
/// @return 0 si ok, -1 si error
int MostrarDireccionUnCliente(eCliente unCliente);

