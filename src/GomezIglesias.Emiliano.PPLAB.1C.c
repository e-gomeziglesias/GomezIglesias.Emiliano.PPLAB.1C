/*
 ============================================================================
 Name        : GomezIglesias.Emiliano.PPLAB.1C.c
 Author      : Gomez Iglesias, Emiliano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "Menu.h"
#include "Clientes.h"
#include "Localidad.h"
#include "TipoDePlastico.h"
#include "BibliotecaNexo.h"
#include "EstadoPedido.h"
#include "Pedido.h"
#include "Informes.h"

#define CANT_LOCALIDADES 20
#define CANT_PLASTICOS 10
#define CANT_CLIENTES 100
#define CANT_PEDIDOS 1000
#define CANT_ESTADOS 2
#define PENDIENTE 0
#define COMPLETADO 1

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int opcionAux;
	int flagClientes=0;
	int flagPedidos=0;
	int retorno;

	eLocalidad listaLocalidades[CANT_LOCALIDADES];
	eTipoDePlastico listaTiposDePlastico[CANT_PLASTICOS];
	eCliente listaClientes[CANT_CLIENTES];
	ePedido listaPedidos[CANT_PEDIDOS];
	eEstado listaEstados[CANT_ESTADOS];

	int nextIdCliente = 1;
	int nextIdPedido = 1;
	int nextIdLocalidad = 1;
	int nextIdTipoDePlastico = 1;
	int nextIdEstado = 0;

	InicializarLocalidades(listaLocalidades, CANT_LOCALIDADES);
	InicializarTiposDePlastico(listaTiposDePlastico, CANT_PLASTICOS);
	InicializarClientes(listaClientes, CANT_CLIENTES);
	InicializarPedidos(listaPedidos, CANT_PEDIDOS);

	HardcodearLocalidades(listaLocalidades, CANT_LOCALIDADES, &nextIdLocalidad);
	HardcodearTiposDePlasticos(listaTiposDePlastico, CANT_PLASTICOS, &nextIdTipoDePlastico);
	HardcodearEstados(listaEstados, CANT_ESTADOS, &nextIdEstado);
	//MostrarEstados(listaEstados, CANT_ESTADOS);

	//Como los datos estan hardcodeados, este if me permite simular que se realizo una carga y habilitar el flagCliente
	if(HardcodearClientes(listaClientes, CANT_CLIENTES, &nextIdCliente)!=0)
	{
		flagClientes=1;
	}

	//Como los datos estan hardcodeados, este if me permite simular que se realizo una carga y habilitar el flagPedidos
	if(HardcodearPedidos(listaPedidos, CANT_PEDIDOS, &nextIdPedido)!=0)
	{
		flagPedidos=1;
	}

	do
	{
		opcion = MostrarMenuPrincipalOpciones();
		switch(opcion)
		{
			case 1://ALTAS
				do
				{
					opcionAux = MostrarMenuAltas();
					switch(opcionAux)
					{
						case 1://ALTA CLIENTES
							printf("ALTA CLIENTES\n");
							retorno = AltaCliente(listaClientes, CANT_CLIENTES, listaLocalidades, CANT_LOCALIDADES, &nextIdCliente);
							//si se dio de alta con exito, muestra los datos del cliente cargado. Sino muestra mensaje error.
							ResultadoAltaModificacionCliente("El cliente fue dado de alta con exito.", "No se realizo el alta del cliente", listaClientes, CANT_CLIENTES, listaLocalidades, CANT_LOCALIDADES, retorno);
							if(retorno == 0)
							{
								flagClientes = 1;
							}
							system("pause");
						break;

						case 0://VOLVER MENU PRINCIPAL
							printf("Volviendo al menu principal\n");
							system("pause");
						break;
					}
				}while(opcionAux!=0);
				system("pause");
			break;
			case 2://MODIFICACIONES
					do
					{
					opcionAux = MostrarMenuModificaciones();
						switch(opcionAux)
						{

							case 1://MODIFICAR CLIENTES
								printf("MODIFICAR CLIENTES\n");
								if(flagClientes==1)//hay clientes cargados
								{
									retorno = ModificarCliente(listaClientes, CANT_CLIENTES, listaLocalidades, CANT_LOCALIDADES);
									//modificar siempre muestra el estado final del cliente para tranquilidad del usuario, se hayan o no modificado campos
									ResultadoAltaModificacionCliente("El cliente se modifico con exito", "Uno o varios campos no fueron modificados.", listaClientes, CANT_CLIENTES, listaLocalidades, CANT_LOCALIDADES, retorno);
								}
								else
								{
									printf("Se deben cargar clientes primero.\n");
								}
									system("pause");
								break;

							case 0://VOLVER MENU PRINCIPAL
								printf("Volviendo al menu principal\n");
								system("pause");
							break;
						}
					}while(opcionAux!=0);
				system("pause");
			break;

			case 3://BAJAS
				do
				{
					opcionAux = MostrarMenuBajas();
					switch(opcionAux)
					{
						case 1://BAJAS CLIENTES
							printf("BAJAS CLIENTES\n");
							if(flagClientes==1)
							{
								retorno = BajaClientes(listaClientes, CANT_CLIENTES, listaLocalidades, CANT_LOCALIDADES, listaPedidos, CANT_PEDIDOS);
								AnalizarRetorno(retorno, "La baja del cliente se completo con exito. Tambien se dieron de baja los pedidos asociados a dicho cliente.", "No se realizo la baja de cliente");
							}
							else
							{
								printf("Se deben cargar clientes primero.\n");
							}
							system("pause");
						break;

						case 0://VOLVER MENU PRINCIPAL
							printf("Volviendo al menu principal\n");
							system("pause");
						break;
					}
				}while(opcionAux!=0);
				system("pause");
			break;

			case 4://CREAR PEDIDO DE RECOLECCION
				printf("CREAR PEDIDO DE RECOLECCION\n");
				if(flagClientes==1)
				{
					retorno = AltaPedido(listaPedidos, CANT_PEDIDOS, listaEstados, CANT_ESTADOS, listaClientes, CANT_CLIENTES, listaLocalidades, CANT_LOCALIDADES, &nextIdPedido);
					AnalizarRetorno(retorno, "El pedido se recoleccion se dio de alta con exito.", "El pedido de recoleccion no se cargo al sistema");
				}
				else
				{
					printf("Se deben cargar clientes primero.\n");
				}
				system("pause");
			break;

			case 5://PROCESAR RESIDUOS
				printf("PROCESAR RESIDUOS\n");
				if(flagPedidos==1)
				{
					retorno = ProcesarResiduos(listaPedidos, CANT_PEDIDOS, listaClientes, CANT_CLIENTES);
					AnalizarRetorno(retorno, "Se cargo el procesamiento con exito.", "No se completo la carga del procesamiento");
				}
				else
				{
					printf("Se deben cargar pedidos primero.\n");
				}
				system("pause");
			break;

			case 6://LISTADOS
				do
				{
				opcionAux = MostrarMenuListados();
					switch(opcionAux)
					{
						case 1://LISTADO DE CLIENTES
							printf("LISTADO DE CLIENTES\n");
							retorno = MostrarClientesConPendientes(listaClientes, CANT_CLIENTES, listaPedidos, CANT_PEDIDOS, listaLocalidades, CANT_LOCALIDADES);
							AnalizarRetorno(retorno, "", "No hay clientes cargados para mostrar.");
							system("pause");
						break;
						case 2://LISTADO DE PEDIDOS PENDIENTES
							printf("LISTADO DE PEDIDOS PENDIENTES\n");
							if(flagClientes==1 && flagPedidos == 1)
							{
								retorno = MostrarPedidosSegunEstado(listaPedidos, CANT_PEDIDOS, listaClientes, CANT_CLIENTES, PENDIENTE);
								AnalizarRetorno(retorno, "Se muestran los pedidos pendientes", "No hay pedidos pendientes para mostrar.");
							}
							else
							{
								printf("Antes deben cargarse pedidos y clientes.\n");
							}
							system("pause");
						break;
						case 3://LISTADO DE PEDIDOS PROCESADOS
							printf("LISTADO DE PEDIDOS PROCESADOS\n");
							if(flagClientes==1 && flagPedidos == 1)
							{
								retorno = MostrarPedidosProcesados(listaPedidos, CANT_PEDIDOS, listaClientes, CANT_CLIENTES);
								AnalizarRetorno(retorno, "Se muestran los pedidos procesados", "No hay pedidos pendientes para mostrar.");
							}
							else
							{
								printf("Antes deben cargarse pedidos y clientes.\n");
							}
							system("pause");
						break;

						case 0://VOLVER MENU PRINCIPAL
							printf("Volviendo al menu principal\n");
							system("pause");
						break;
					}
				}while(opcionAux!=0);
				system("pause");
			break;

			case 7://INFORMES
				do
				{
				opcionAux = MostrarMenuInformes();
					switch(opcionAux)
					{
						case 1://CANTIDAD DE PEDIDOS PENDIENTES PARA UNA LOCALIDAD
							printf("CANTIDAD DE PEDIDOS PENDIENTES PARA UNA LOCALIDAD\n");
							if(flagPedidos==1 && flagClientes==1)
							{
								retorno = MostrarPendientesParaUnaLocalidad(listaLocalidades, CANT_LOCALIDADES, listaClientes, CANT_CLIENTES, listaPedidos, CANT_PEDIDOS);
								AnalizarRetorno(retorno, "Se muestran las cantidades de pedidos pendientes para la localidad elegida", "No se pudo completar la solicitud");
							}
							else
							{
								printf("Antes deben cargarse pedidos y clientes.\n");
							}
							system("pause");
						break;
						case 2://CANTIDAD DE KILOS DE POLIPROPILENO RECICLADO PROMEDIO POR CLIENTE
							printf("CANTIDAD DE KILOS DE POLIPROPILENO RECICLADO PROMEDIO POR CLIENTE\n");
							if(flagPedidos==1 && flagClientes==1)
							{
								retorno = MostrarKilosDePPPromedioPorCliente(listaPedidos, CANT_PEDIDOS, listaClientes, CANT_CLIENTES);
								AnalizarRetorno(retorno, "Se muestran los kilos de PP promedio por cliente", "No se pudo completar la solicitud");
							}
							else
							{
								printf("Antes deben cargarse pedidos y clientes.\n");
							}
							system("pause");
						break;
						case 3:
							if(flagPedidos==1 && flagClientes==1)
							{
								retorno = MostrarClientesMaximosPendientes(listaClientes, CANT_CLIENTES, listaPedidos, CANT_PEDIDOS, listaLocalidades, CANT_LOCALIDADES);
								AnalizarRetorno(retorno, "Se muestran los kilos de PP promedio por cliente", "No se pudo completar la solicitud");
							}
							else
							{
								printf("Antes deben cargarse pedidos y clientes.\n");
							}
							system("pause");
							break;

						case 4:
							if(flagPedidos==1 && flagClientes==1)
							{
								retorno = MostrarClientesMaximosCompletados(listaClientes, CANT_CLIENTES, listaPedidos, CANT_PEDIDOS, listaLocalidades, CANT_LOCALIDADES);
								AnalizarRetorno(retorno, "Se muestran los kilos de PP promedio por cliente", "No se pudo completar la solicitud");
							}
							else
							{
								printf("Antes deben cargarse pedidos y clientes.\n");
							}
							system("pause");
							break;
						case 5:
							if(flagPedidos==1 && flagClientes==1)
							{
								retorno = MostrarClientesMaximos(listaClientes, CANT_CLIENTES, listaPedidos, CANT_PEDIDOS, listaLocalidades, CANT_LOCALIDADES);
								AnalizarRetorno(retorno, "Se muestran los kilos de PP promedio por cliente", "No se pudo completar la solicitud");
							}
							else
							{
								printf("Antes deben cargarse pedidos y clientes.\n");
							}
							system("pause");
							break;
						case 0://VOLVER MENU PRINCIPAL
							printf("Volviendo al menu principal\n");
							system("pause");
						break;
					}
				}while(opcionAux!=0);
				system("pause");
			break;

			case 0://SALIR DEL PROGRAMA
				printf("Usted ha salido del programa.\n");
				system("pause");
			break;
		}
	}while(opcion != 0);

	return EXIT_SUCCESS;
}
