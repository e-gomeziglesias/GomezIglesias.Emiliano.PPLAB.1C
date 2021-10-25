/*
 * BibliotecaNexo.h
 *
 *  Created on: 22 oct. 2021
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

#ifndef BIBLIOTECANEXO_H_
#define BIBLIOTECANEXO_H_



#endif /* BIBLIOTECANEXO_H_ */

//1.
/// @fn int CargarLocalidadCliente(eCliente*, eLocalidad[], int)
/// @brief Muestra el listado de localidades actualizado y permite cargar una de estas localidades al cliente
///
/// @param unCliente cliente al que se le cargara la localidad
/// @param listaLocalidades listado de localidades
/// @param tamListaLocalidades tamano del listado
/// @return 0 si ok, -1 si error.
int CargarLocalidadCliente(eCliente* pUnCliente, eLocalidad listaLocalidades[], int tamListaLocalidades);

//2.
/// @fn int AltaCliente(eCliente[], int, eLocalidad[], int, int*)
/// @brief permite dar un cliente de alta y cargar todos sus campos. El id es autoincremental
///
/// @param listaClientes listado donde se cargara el cliente
/// @param tamClientes tamano del listado
/// @param listaLocalidades listado de localidades
/// @param tamListaLocalidades tamano del listado de localiddes
/// @param pNextIdCliente direccion al id que puede tomar el cliente nuevo y que luego de dada el alta, incrementara.
/// @return 0 si ok, -1 si error.
int AltaCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades, int* pNextIdCliente);

//3.
/// @fn int MostrarUnCliente(eCliente, eLocalidad[], int)
/// @brief Permite mostrar todos los datos de un cliente
///
/// @param unCliente cliente cuyos datos se mostraran
/// @param listaLocalidades listado de localidades actualizado
/// @param tamListaLocalidades tamano del listado de localidades
/// @return 0 si ok, -1 si error
int MostrarUnCliente(eCliente unCliente, eLocalidad listaLocalidades[], int tamListaLocalidades);

//4.
/// @fn void ResultadoAltaModificacionCliente(char[], char[], eCliente[], int, eLocalidad[], int, int)
/// @brief Permite mostrar un mensaje por pantalla indicando el resultado de un alta/modificacion
///
/// @param mensaje mensaje de exito
/// @param mensajeError mensaje de error
/// @param listaClientes listado de clientes
/// @param tamClientes tamano del listado
/// @param listaLocalidades listado de localidades
/// @param tamListaLocalidades tamano del listado de localiddes
/// @param retornoFuncion retorno de la funcion alta/modificacion
void ResultadoAltaModificacionCliente(char mensaje[], char mensajeError[], eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades, int retornoFuncion);


//5.
/// @fn int MostrarClientes(eCliente[], int, eLocalidad[], int)
/// @brief Permite mostrar el listado de clientes cargados en el programa
///
/// @param listaClientes listado a mostrar
/// @param tamClientes tamano del listado
/// @param listaLocalidades listado de las localidades
/// @param tamListaLocalidades tamano de la lista de localidades
/// @return 0 si ok, -1 si error
int MostrarClientes(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades);

//6.
/// @fn int ElegirClientePorId(char[], eCliente[], int, eLocalidad[], int)
/// @brief Despliega el listado de los clientes cargados y pide al usuario el id de un cliente y muestra los datos de ese cliente por pantalla
///
/// @param mensaje mensaje de confirmacion de eleccion
/// @param listaClientes listado donde buscar al cliente
/// @param tamClientes tamano del listado
/// @param listaLocalidades listado de localidades
/// @param tamListaLocalidades tamano del listado de localdades
/// @return el indice si encuentra el id -1 si no encuentra el id
int ElegirClientePorId(char mensaje[], eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades);

//7.
/// @fn int ModificarCliente(eCliente[], int, eLocalidad[], int)
/// @brief Permite modificar determinados campos de un cliente
///
/// @param listaClientes listado de clientes
/// @param tamClientes tamano del listado
/// @param listaLocalidades listado de localidades
/// @param tamListaLocalidades tamano de listado de localidades
/// @return 0 si ok, -1 si error
int ModificarCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades);

//8.
/// @fn int BajaClientes(eCliente[], int, eLocalidad[], int)
/// @brief Permite realizar la baja logica de un cliente
///
/// @param listaClientes listado de clientes
/// @param tamClientes tamano del listado de clientes
/// @param listaLocalidades listado de localidades
/// @param tamListaLocalidades tamano de la lista de localidades
/// @param listaPedidos lista de los pedidos
/// @param tamPedidos tamano de la lista de pedidos
/// @return si la baja fue exitosa, devuelve el indice del cliente dado de baja. Si no se completo la baja devuelve -1
int BajaClientes(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades, ePedido listaPedidos[], int tamPedidos);

//9.
/// @fn int CargarIdCliente(ePedido*, eCliente[], int, eLocalidad, int)
/// @brief Despliega el listado con la informacion de los clientes y permite elegir uno y cargarlo a un pedido
///
/// @param pUnPedido direccion de memoria del pedido
/// @param listaClientes listado de clientes
/// @param tamClientes tamano del listado de clientes
/// @param listaLocalidades listado de las localidades
/// @param tamListaLocalidades tamano del listado de localidades
/// @return 0 si ok, -1 si error
int CargarIdCliente(ePedido* pUnPedido, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades);

//10.
/// @fn int AltaPedido(ePedido[], int, eCliente[], int, eLocalidad, int, int*)
/// @brief Permite dar de alta un pedido de recoleccion
///
/// @param listaPedidos listado de pedidos
/// @param tamPedidos tamano del listadod de pedidos
/// @param listaEstados listado de estados de pedido
/// @param tamEstados tamano del lsitado de estados de pedido
/// @param listaClientes listado de clientes
/// @param tamClientes tamano del listado de clientes
/// @param listaLocalidades listado de localidades
/// @param tamListaLocalidades tamano del listado de localidades
/// @param pNextIdPedido direccion del siguiente id de pedido disponible.
/// @return el indice dado de alta si ok, -1 si error
int AltaPedido(ePedido listaPedidos[], int tamPedidos, eEstado listaEstados[], int tamEstados, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades, int* pNextIdPedido);

//11.
/// @fn int MostrarUnPedido(ePedido, eCliente[], int)
/// @brief Permite mostrar la informacion de un pedido (sin su estado)
///
/// @param unPedido pedido a mostrar
/// @param listaClientes listado de clientes
/// @param tamClientes tamano de listado de clientes
/// @return 0 si ok, -1 si error
int MostrarUnPedido(ePedido unPedido, eCliente listaClientes[], int tamClientes);

//12.
/// @fn int MostrarUnPedidoConEstado(ePedido, eEstado[], int, eCliente[], int)
/// @brief Permite mostrar la informacion completa de un pedido, incluido su estado
///
/// @param unPedido pedido a mostrar
/// @param listaEstados lista de estados
/// @param tamEstados tamano de estados
/// @param listaClientes lista de clientes
/// @param tamClientes tamano de lista de clientes
/// @return 0 si ok, -1 si error
int MostrarUnPedidoConEstado(ePedido unPedido, eEstado listaEstados[], int tamEstados, eCliente listaClientes[], int tamClientes);

//13.
/// @fn int ContarPedidosPendientesPorCliente(ePedido[], int, eCliente)
/// @brief Dado un cliente, cuenta cuantos pedidos pendientes tiene
///
/// @param listaPedidos lista de pedidos
/// @param tamPedidos tamano del listado de pedidos
/// @param unCliente cliente al que contara los pedidos pendientes
/// @return cantidad de pedidos pendientes si ok, -1 si error
	int ContarPedidosPendientesPorCliente(ePedido listaPedidos[], int tamPedidos, eCliente unCliente);

//14.
/// @fn int MostrarClientesConPendientes(eCliente[], int, ePedido[], int, eLocalidad[], int)
/// @brief Muestra el listado completo de clientes y tambien la cantidad de pedidos pendientes que tiene cadad uno
///
/// @param listaClientes listado de clientes
/// @param tamClientes tamano del listado
/// @param listaPedidos lista de pedidos
/// @param tamPedidos tamano del listado de pedidos
/// @param listaLocalidades lista de localidades
/// @param tamListaLocalidades tamano de la lista de localiddes
/// @return 0 si ok, -1 si error
int MostrarClientesConPendientes(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamListaLocalidades);

//15.
/// @fn int CargarKilosDePlasticoProcesado(ePedido*)
/// @brief Permite cargar los kilos procesados de cada uno de los plasticos que procesa la empresa
///
/// @param pUnPedido pedido al que se le cargaran los kilos
/// @return 0 si ok, -1 si error
int CargarKilosDePlasticoProcesado(ePedido* pUnPedido);

//16.
/// @fn int ElegirIdPedidoSegunEstado(ePedido[], int, eCliente[], int, int)
/// @brief Dado un estado (pendiente o completado) despliega el listado de pedidos que cumplen con ese estado y permite elegir el id de uno de ellos
///
/// @param listaPedidos listado de pedidos
/// @param tamPedidos tamano del listado
/// @param listaClientes listado de clientes
/// @param tamClientes tamano del listado de clientes
/// @param estado 0 pendiente - 1 completado
/// @return -1 si error, sino devuelve el indice del pedido encontrado
int ElegirIdPedidoSegunEstado(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes, int estado);

//17.
/// @fn int ProcesarResiduos(ePedido[], int, eCliente[], int)
/// @brief Permite cargar el procesado de un pedido(cargar los kilos de cada plastico procesado)
///
/// @param listaPedidos listado de pedidos
/// @param tamPedidos tamano del listado
/// @param listaClientes listado de clientes
/// @param tamClientes tamano del listado de clientes
/// @return 0 si ok, -1 si error
int ProcesarResiduos(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes);

//18.
/// @fn int MostrarPedidosSegunEstado(ePedido[], int, eCliente[], int, int)
/// @brief Permite mostrar  el listado de los pedidos segun su estado de proceso
///
/// @param listaPedidos listado de todos los pedidos
/// @param tamPedidos tamano listado
/// @param listaClientes listado clientes
/// @param tamClientes tamano clientes
/// @param estado estado de proceso (0 pendiente - 1 completado)
/// @return
int MostrarPedidosSegunEstado(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes, int estado);

//19.
/// @fn int MostrarUnPedidoProcesado(ePedido, eCliente[], int)
/// @brief Permite mostrar un pedido cuyo estado es completo(procesado)
///
/// @param unPedido pedido a mostrar
/// @param listaClientes lsitado de clientes
/// @param tamClientes tamano del listado
/// @return '0 si ok, -1 si error
int MostrarUnPedidoProcesado(ePedido unPedido, eCliente listaClientes[], int tamClientes);

//20.
/// @fn int MostrarPedidosProcesados(ePedido[], int, eCliente[], int)
/// @brief Permite mostrar el listado de pedidos procesados, con los kilos de cada plastico discriminados
///
/// @param listaPedidos lista de pedidos
/// @param tamPedidos tamano listado de pedidos
/// @param listaClientes listado de clientes
/// @param tamClientes tamano del listado de clientes
/// @return 0 si ok, -1 si error
int MostrarPedidosProcesados(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes);

//21.
int BajarPedidosPorIdCliente(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes, int idCliente);
