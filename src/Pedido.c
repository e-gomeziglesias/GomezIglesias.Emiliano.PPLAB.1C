/*
 * Pedido.c
 *
 *  Created on: 24 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include "Pedido.h"

//1.
int InicializarPedidos(ePedido listaPedidos[], int tamPedidos)
{
	int retorno=-1;
	if(listaPedidos!= NULL && tamPedidos >0)
	{
		for(int i=0; i<tamPedidos; i++)
		{
			listaPedidos[i].isEmpty=1;
			retorno = 0;
		}
	}
	return retorno;
}

//2.
int BuscarPedidoPorId(ePedido listaPedidos[], int tamPedidos, int idPedido)
{
	int retorno=-1;
	if(listaPedidos!= NULL && tamPedidos>0 && idPedido>0)
	{
		for(int i=0; i<tamPedidos; i++)
		{
			if(listaPedidos[i].isEmpty==0 && listaPedidos[i].idPedido==idPedido)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

//3.
int HardcodearPedidos(ePedido listaPedidos[], int tamListaPedidos, int* pNextIdPedido)
{
	int cantidad = 0;

	int idClientes[10] =
	{
			1,
			4,
			4,
			5,
			10,
			3,
			3,
			6,
			9,
			2
	};

	float kilos[10] =
	{
			100,
			150,
			655,
			900,
			432,
			275,
			865,
			212,
			670,
			300
	};

	float HDPE[10]=
	{
			50,
			0,
			0,
			300,
			432,
			0,
			0,
			12,
			0,
			100,
	};

	float LDPE[10] =
	{
			50,
			0,
			0,
			300,
			0,
			0,
			0,
			200,
			0,
			100,
	};

	float PP[10]=
	{
			0,
			0,
			0,
			300,
			0,
			0,
			0,
			0,
			0,
			100,

	};

	int idEstados[10] =
	{
			1,
			0,
			0,
			1,
			1,
			0,
			0,
			1,
			0,
			1,
	};
	if(listaPedidos!=NULL && tamListaPedidos>0 && pNextIdPedido!=NULL)
	{
		for(int i=0; i<10; i++)
		{
			listaPedidos[i].idPedido = (*pNextIdPedido);
			(*pNextIdPedido)=(*pNextIdPedido)+1;
			listaPedidos[i].idCliente=idClientes[i];
			listaPedidos[i].kilosTotales = kilos[i];
			listaPedidos[i].idEstado = idEstados[i];
			listaPedidos[i].kilosHDPE=HDPE[i];
			listaPedidos[i].kilosLDPE=LDPE[i];
			listaPedidos[i].kilosPP=PP[i];
			listaPedidos[i].kilosDesecho=0;
			listaPedidos[i].isEmpty=0;
			cantidad++;
		}
	}
	return cantidad;
}

//4.
int CargarKilos(ePedido* pUnPedido)
{
	int retorno = -1;
	if(pUnPedido!=NULL)
	{
		retorno = CargarFlotante(&(*pUnPedido).kilosTotales, "Ingrese los kilos totales a recolectar.(mayor a 10 y menor a 10000): ", "La cantidad de kilos ingresada es invalida.", 10, 10000, 2);
	}
	return retorno;
}

//5.
int BuscarPosicionPedidoLibre(ePedido listaPedidos[], int tamPedidos)
{
	int retorno = -1;
	if(listaPedidos!= NULL && tamPedidos>0)
	{
		for(int i=0; i<tamPedidos; i++)
		{
			if(listaPedidos[i].isEmpty==1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

//6.
int CalcularKilosDePPTotales(ePedido listaPedidos[], int tamPedidos)
{
	int retorno = -1;
	float kilosTotalesPP=0;
	if(listaPedidos!=NULL && tamPedidos>0)
	{
		for(int i=0; i<tamPedidos; i++)
		{
			if(listaPedidos[i].isEmpty==0)
			{
				kilosTotalesPP=kilosTotalesPP+listaPedidos[i].kilosPP;
			}
		}
		retorno = kilosTotalesPP;
	}
	return retorno;
}
