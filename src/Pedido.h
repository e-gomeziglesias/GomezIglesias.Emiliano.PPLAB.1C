/*
 * Pedido.h
 *
 *  Created on: 24 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */
#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

#ifndef PEDIDO_H_
#define PEDIDO_H_

typedef struct
{
	int idPedido; //PK
	int idCliente; //FK
	float kilosHDPE;
	float kilosLDPE;
	float kilosPP;
	float kilosDesecho;
	float kilosTotales;
	int idEstado; //FK
	int isEmpty;
}ePedido;

#endif /* PEDIDO_H_ */

//1.
/// @fn int InicializarPedidos(ePedido[], int)
/// @brief Permite inicializar el isEmpty en una lista de ePedidos
///
/// @param listaPedidos lista de peiddos a inicializar
/// @param tamPedidos tamano de la lista
/// @return 0 si ok, -1 si error
int InicializarPedidos(ePedido listaPedidos[], int tamPedidos);

//2.
/// @fn int BuscarPedidoPorId(ePedido[], int, int)
/// @brief Permite buscar un pedido, dado su id por parametro
///
/// @param listaPedidos listado de pedidos
/// @param tamPedidos tamano del listado
/// @param idPedido id del pedido a buscar
/// @return si encuentra el id retorna el indice, -1 si error
int BuscarPedidoPorId(ePedido listaPedidos[], int tamPedidos, int idPedido);

//3.
/// @fn int HardcodearPedidos(ePedido[], int, int*)
/// @brief permite hardcodear un listado de datos de pedidos
///
/// @param listaPedidos listado a hardcodear
/// @param tamListaPedidos tamano del listado
/// @param pNextIdPedido direccion del id del siguiente pedido
/// @return -1 si error, cantidad de datos hardcodeados si ok.
int HardcodearPedidos(ePedido listaPedidos[], int tamListaPedidos, int* pNextIdPedido);

//4.
/// @fn int CargarKilos(ePedido*)
/// @brief Permite cargar los kilos totales a recolectar de un cliente
///
/// @param pUnPedido puntero a la direcccion de memoria de la estructura del pedido
/// @return 0 si ok, -1 si error
int CargarKilos(ePedido* pUnPedido);

//5.
/// @fn int BuscarPosicionPedidoLibre(ePedido[], int)
/// @brief Permite buscar si hay una posicion libre dentro de un array de pedidos (isEmpty=1)
///
/// @param listaPedidos listado de pedidos donde buscar la posicion libre
/// @param tamPedidos tamano del listado
/// @return si encuentra lugar, devuelve el indice libre, sino devuelve -1
int BuscarPosicionPedidoLibre(ePedido listaPedidos[], int tamPedidos);

//6.
/// @fn int CalcularKilosDePPTotales(ePedido[], int)
/// @brief Permite calcular los kilos totales de pp
///
/// @param listaPedidos listado de pedidos
/// @param tamPedidos tamano del listado de pedidos
/// @return cant de kilos si ok, -1 si error
int CalcularKilosDePPTotales(ePedido listaPedidos[], int tamPedidos);
