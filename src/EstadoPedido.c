/*
 * EstadoPedido.c
 *
 *  Created on: 24 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include "EstadoPedido.h"

//1.
int InicializarEstados(eEstado listaEstados[], int tamEstados)
{
	int retorno=-1;
	if(listaEstados!= NULL && tamEstados >0)
	{
		for(int i=0; i<tamEstados; i++)
		{
			listaEstados[i].isEmpty=1;
			retorno = 0;
		}
	}
	return retorno;
}

//2.
int MostrarUnEstado(eEstado unEstado)
{
	int retorno=-1;
	if(unEstado.isEmpty == 0)
	{
		printf("%4d 	%-20s\n", unEstado.idEstado, unEstado.descripcionEstado);
		retorno = 0;
	}
	return retorno;
}

//3.
int MostrarDescripcionDeUnEstado(eEstado listadoEstados[], int tamEstados, int idEstado)
{
	int retorno=-1;
	int indice=BuscarEstadoPorId(listadoEstados, tamEstados, idEstado);
	if(listadoEstados != NULL && tamEstados > 0 && idEstado >=0 && indice != -1 && listadoEstados[indice].isEmpty == 0 )
	{
		printf("%-20s		",listadoEstados[indice].descripcionEstado);
		retorno = 0;
	}
	return retorno;
}

//4.
int MostrarEstados(eEstado listaEstados[], int tamEstados)
{
	int retorno=-1;
	if(listaEstados!= NULL && tamEstados >0)
	{
		for(int i=0; i<tamEstados; i++)
		{
			if(MostrarUnEstado(listaEstados[i])==0)
			{
				retorno = 0; //con que haya al menos un Estado con isEmpty==0(ocupada)
			}
		}
	}
	return retorno;
}

//5.
int BuscarEstadoPorId(eEstado listaEstados[], int tamEstados, int idEstado)
{
	int retorno=-1;
	if(listaEstados!= NULL && tamEstados >0 && idEstado>=0)
	{
		for(int i=0; i<tamEstados; i++)
		{
			if(listaEstados[i].isEmpty==0 && listaEstados[i].idEstado==idEstado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

//6.
int BuscarPosicionEstadoLibre(eEstado listaEstados[], int tamEstados)
{
	int retorno = -1;
	if(listaEstados != NULL && tamEstados>0)
	{
		for(int i=0; i<tamEstados; i++)
		{
			if(listaEstados[i].isEmpty==1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

//7.
int HardcodearEstados(eEstado listaEstados[], int tamListaEstados, int* pNextIdEstado)
{
	int cantidad = 0;
	char estados [2][20] =
	{
			"Pendiente",
			"Completado"
	};
	if(listaEstados!=NULL && tamListaEstados>0 && pNextIdEstado != NULL)
	{
		for(int i=0; i<2; i++)
		{
			listaEstados[i].idEstado = *pNextIdEstado;
			(*pNextIdEstado)=(*pNextIdEstado)+1;
			strcpy(listaEstados[i].descripcionEstado,estados[i]);
			listaEstados[i].isEmpty=0;
			cantidad++;
		}
	}
	return cantidad;
}


