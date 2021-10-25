/*
 * Informes.h
 *
 *  Created on: 24 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "Menu.h"
#include "Clientes.h"
#include "Localidad.h"
#include "TipoDePlastico.h"
#include "EstadoPedido.h"
#include "Pedido.h"
#include "BibliotecaNexo.h"

#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */

//1.
/// @fn int ContarPendientesDeUnaLocalidad(eLocalidad, eCliente[], int, ePedido[], int)
/// @brief dada una localidad, cuenta los pedidos pendientes que pertenecen a los clientes que pertenecen a la localidad en cuestion
///
/// @param unaLocalidad localidad de la que quiero conoccer los pendientes
/// @param listaClientes listado clientes
/// @param tamClientes tamano listado clientes
/// @param listaPedidos lsitado pedidos
/// @param tamPedidos tamano lsitado pediidos
/// @return cantidad de pendientes si ok, -1 si error
int ContarPendientesDeUnaLocalidad(eLocalidad unaLocalidad, eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

//2.
/// @fn int MostrarPendientesParaUnaLocalidad(eLocalidad[], int, eCliente[], int, ePedido[], int)
/// @brief Despliega el listado de localidades y permite al usuario elegir una. Muestra la cantidad de pendientes para esa localidad
///
/// @param listaLocalidades lista localidades
/// @param tamLocalidades tamano de la lista de localidades
/// @param listaClientes lista de clientes
/// @param tamClientes tamano de la lista de clientes
/// @param listaPedidos lista de pedidos
/// @param tamPedidos tamano de la lista de pedidos
/// @return 0 si ok, -1 si error
int MostrarPendientesParaUnaLocalidad(eLocalidad listaLocalidades[], int tamLocalidades, eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos);

//3.
/// @fn int CalcularKilosdePPPromedioPorCliente(ePedido[], int, eCliente[], int, float*)
/// @brief Permite calcular el promedio, si fuera posible, de la cantidad de kilos de pp por cliente
///
/// @param listaPedidos listado de pedidos
/// @param tamPedidos tamano del listado de pedidos
/// @param listaClientes listado de clientes
/// @param tamClientes tamano del listado de clientes
/// @param pPromedio direccion donde se almacenara el promedio
/// @return 0 si ok, -1 si error
int CalcularKilosdePPPromedioPorCliente(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes, float* pPromedio);

//4.
/// @fn int MostrarKilosDePPPromedioPorCliente(ePedido[], int, eCliente[], int)
/// @brief Muestra por pantalla los kilos de PP promedio por cliente
///
/// @param listaPedidos listado de pedidos
/// @param tamPedidos tamano del listado de pedidos
/// @param listaClientes listado de clientes
/// @param tamClientes tamano del listado de clientes
/// @return 0 si ok, -1 si error
int MostrarKilosDePPPromedioPorCliente(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes);
