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
