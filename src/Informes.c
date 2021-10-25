/*
 * Informes.c
 *
 *  Created on: 24 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include "Informes.h"

#define PENDIENTE 0
#define COMPLETADO 1

//1.
int ContarPendientesDeUnaLocalidad(eLocalidad unaLocalidad, eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos)
{
	int retorno=-1;
	int contadorPendientes=0;
	if(listaPedidos!=NULL && tamPedidos>0 && listaClientes != NULL && tamClientes>0)
	{
		if(unaLocalidad.isEmpty!=1)//fijo localidad
		{
			for(int c=0; c<tamClientes; c++)//recorro los clientes
			{
				if(listaClientes[c].idLocalidad==unaLocalidad.idLocalidad)//entro si el cliente pertenece a la localidad
				{
					for(int p=0; p<tamPedidos; p++)//recorro los pedidos
					{
						if(listaPedidos[p].idCliente==listaClientes[c].idCliente)//entro si el pedido pertenece al cliente que pertenece a la localidad que busco
						{
							if(listaPedidos[p].idEstado==PENDIENTE)
							{
								contadorPendientes++;
							}
						}
					}
				}
			}
			retorno = contadorPendientes;
		}
	}
	return retorno;
}

//2.
int MostrarPendientesParaUnaLocalidad(eLocalidad listaLocalidades[], int tamLocalidades, eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos)
{
	int retorno = -1;
	int indiceLocalidad;
	int cantidadPendientes;
	if(listaLocalidades!=NULL && tamLocalidades>0 && listaClientes!=NULL && tamClientes>0 && listaPedidos!=NULL && tamPedidos>0)
	{
		indiceLocalidad = ElegirLocalidad(listaLocalidades, tamLocalidades);
		if(indiceLocalidad!=-1)
		{
			cantidadPendientes=ContarPendientesDeUnaLocalidad(listaLocalidades[indiceLocalidad], listaClientes, tamClientes, listaPedidos, tamPedidos);
			if(cantidadPendientes!=-1)
			{
				MostrarUnaLocalidad(listaLocalidades[indiceLocalidad]);
				printf("Cantidad de pendientes: %d\n", cantidadPendientes);
				retorno = 0;
			}
		}
	}
	return retorno;
}

//3.
int CalcularKilosdePPPromedioPorCliente(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes, float* pPromedio)
{
	int retorno=-1;
	int cantidadClientes;
	float kilosDePP;
	float promedio;
	if(listaPedidos!=NULL && tamPedidos>0 && listaClientes!=NULL && tamClientes>0 && pPromedio!=NULL)
	{
		cantidadClientes=ContarClientes(listaClientes, tamClientes);
		if(cantidadClientes>0)
		{
			kilosDePP=CalcularKilosDePPTotales(listaPedidos, tamPedidos);
			if(kilosDePP!=-1)
			{
				promedio = kilosDePP/cantidadClientes;
				(*pPromedio)=promedio;
				retorno = 0;
			}
		}

	}
	return retorno;
}

//4.
int MostrarKilosDePPPromedioPorCliente(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes)
{
	int retorno = -1;
	float promedio;
	if(listaPedidos!=NULL && tamPedidos>0 && listaClientes!=NULL && tamClientes>0)
	{
		if(CalcularKilosdePPPromedioPorCliente(listaPedidos, tamPedidos, listaClientes, tamClientes, &promedio)!=-1)
		{
			printf("Los kilos de Polipropileno promedio por cliente son: %.2f\n", promedio);
			retorno = 0;
		}
	}
	return retorno;
}

//5.
int ContarPedidosPorCliente(eCliente unCliente, ePedido listaPedidos[], int tamPedidos)
{
	int retorno = -1;
	int contadorPedidos=0;
	if(listaPedidos !=NULL && tamPedidos>0)
	{
		for(int i=0; i<tamPedidos; i++)
		{
			if(unCliente.isEmpty==0 && listaPedidos[i].isEmpty==0 && listaPedidos[i].idCliente==unCliente.idCliente)
			{
				contadorPedidos++;
			}
		}
		retorno = contadorPedidos;
	}
	return retorno;
}

//6
int ContarPedidosPorClienteSegunEstado(eCliente unCliente, ePedido listaPedidos[], int tamPedidos, int estado)
{
	int retorno = -1;
	int contadorPedidos=0;
	if( listaPedidos !=NULL && tamPedidos>0)
	{
		for(int i=0; i<tamPedidos; i++)
		{
			if(unCliente.isEmpty==0 && listaPedidos[i].isEmpty==0 && listaPedidos[i].idCliente==unCliente.idCliente && listaPedidos[i].idEstado==estado)
			{
				contadorPedidos++;
			}
		}
		retorno = contadorPedidos;
	}
	return retorno;
}

//6.
int BuscarMaximoDePendientesPorCliente(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, int* pMaximo)
{
	int retorno=-1;
	int flagMaximo=0;
	int contador;
	if(listaClientes!=NULL && tamClientes>0 && listaPedidos!=NULL && tamPedidos>0 && pMaximo!=NULL)
	{
		for(int c=0; c<tamClientes; c++)
		{
			contador = ContarPedidosPorClienteSegunEstado(listaClientes[c], listaPedidos, tamPedidos, PENDIENTE);
			if(contador!=-1 && (flagMaximo==0 || contador>(*pMaximo)))
			{
				(*pMaximo) = contador;
				flagMaximo=1;
			}
		}
	}
	return retorno;
}

//7.
int MostrarClientesConCantidadDePendientes(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamListaLocalidades, int cantidad)
{
	int retorno=-1;
	if(listaClientes!=NULL && tamClientes>0 && listaPedidos!=NULL && tamPedidos>0)
	{
		for(int c=0; c<tamClientes; c++)
		{
			if(ContarPedidosPendientesPorCliente(listaPedidos, tamPedidos, listaClientes[c])==cantidad)
			{
				MostrarUnCliente(listaClientes[c], listaLocalidades, tamListaLocalidades);
			}
		}
	}
	return retorno;
}

//8.
int MostrarClientesMaximosPendientes(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamListaLocalidades)
{
	int retorno = -1;
	int maximo;
	if(listaClientes!=NULL && tamClientes>0 && listaPedidos!=NULL && tamPedidos>0)
	{
		if(BuscarMaximoDePendientesPorCliente(listaClientes, tamClientes, listaPedidos, tamPedidos, &maximo)!=-1)
		{
			if(MostrarClientesConCantidadDePendientes(listaClientes, tamClientes, listaPedidos, tamPedidos, listaLocalidades, tamListaLocalidades, maximo)!=-1)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

//9.
int BuscarMaximoDeCompletadosPorCliente(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, int* pMaximo)
{
	int retorno=-1;
	int flagMaximo=0;
	int contador;
	if(listaClientes!=NULL && tamClientes>0 && listaPedidos!=NULL && tamPedidos>0 && pMaximo!=NULL)
	{
		for(int c=0; c<tamClientes; c++)
		{
			contador = ContarPedidosPorClienteSegunEstado(listaClientes[c], listaPedidos, tamPedidos, COMPLETADO);
			if(contador!=-1 && (flagMaximo==0 || contador>(*pMaximo)))
			{
				(*pMaximo) = contador;
				flagMaximo=1;
			}
		}
	}
	return retorno;
}

//10.
int MostrarClientesConCantidadDeCompletados(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamListaLocalidades, int cantidad)
{
	int retorno=-1;
	if(listaClientes!=NULL && tamClientes>0 && listaPedidos!=NULL && tamPedidos>0)
	{
		for(int c=0; c<tamClientes; c++)
		{
			if(ContarPedidosPorClienteSegunEstado(listaClientes[c], listaPedidos, tamPedidos, COMPLETADO )==cantidad)
			{
				MostrarUnCliente(listaClientes[c], listaLocalidades, tamListaLocalidades);
			}
		}
	}
	return retorno;
}

//11.
int MostrarClientesMaximosCompletados(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamListaLocalidades)
{
	int retorno = -1;
	int maximo;
	if(listaClientes!=NULL && tamClientes>0 && listaPedidos!=NULL && tamPedidos>0)
	{
		if(BuscarMaximoDeCompletadosPorCliente(listaClientes, tamClientes, listaPedidos, tamPedidos, &maximo)!=-1)
		{
			if(MostrarClientesConCantidadDeCompletados(listaClientes, tamClientes, listaPedidos, tamPedidos, listaLocalidades, tamListaLocalidades, maximo)!=-1)
					{
						retorno = 0;
					}
		}
	}
	return retorno;
}

//12.
int BuscarMaximoDePedidosPorCliente(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, int* pMaximo)
{
	int retorno=-1;
	int flagMaximo=0;
	int contador;
	if(listaClientes!=NULL && tamClientes>0 && listaPedidos!=NULL && tamPedidos>0 && pMaximo!=NULL)
	{
		for(int c=0; c<tamClientes; c++)
		{
			contador = ContarPedidosPorCliente(listaClientes[c], listaPedidos, tamPedidos);
			if(contador!=-1 && (flagMaximo==0 || contador>(*pMaximo)))
			{
				(*pMaximo) = contador;
				flagMaximo=1;
			}
		}
	}
	return retorno;
}

//13.
int MostrarClientesConCantidadDePedidos(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamListaLocalidades, int cantidad)
{
	int retorno=-1;
	if(listaClientes!=NULL && tamClientes>0 && listaPedidos!=NULL && tamPedidos>0)
	{
		for(int c=0; c<tamClientes; c++)
		{
			if(ContarPedidosPorCliente(listaClientes[c], listaPedidos, tamPedidos)==cantidad)
			{
				MostrarUnCliente(listaClientes[c], listaLocalidades, tamListaLocalidades);
			}
		}
	}
	return retorno;
}

//14.
int MostrarClientesMaximos(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamListaLocalidades)
{
	int retorno = -1;
	int maximo;
	if(listaClientes!=NULL && tamClientes>0 && listaPedidos!=NULL && tamPedidos>0)
	{
		if(BuscarMaximoDePedidosPorCliente(listaClientes, tamClientes, listaPedidos, tamPedidos, &maximo)!=-1)
		{
			if(MostrarClientesConCantidadDePedidos(listaClientes, tamClientes, listaPedidos, tamPedidos, listaLocalidades, tamListaLocalidades, maximo)!=-1)
					{
						retorno = 0;
					}
		}
	}
	return retorno;
}
