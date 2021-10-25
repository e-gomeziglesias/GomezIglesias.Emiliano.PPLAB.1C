/*
 * TipoDePlastico.c
 *
 *  Created on: 22 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include "TipoDePlastico.h"

//1.
int InicializarTiposDePlastico(eTipoDePlastico listaTiposDePlastico[], int tamTiposDePlastico)
{
	int retorno=-1;
	if(listaTiposDePlastico!= NULL && tamTiposDePlastico >0)
	{
		for(int i=0; i<tamTiposDePlastico; i++)
		{
			listaTiposDePlastico[i].isEmpty=1;
			retorno = 0;
		}
	}
	return retorno;
}

//2.
int MostrarUnTipoDePlastico(eTipoDePlastico unTipoDePlastico)
{
	int retorno=-1;
	if(unTipoDePlastico.isEmpty == 0)
	{
		printf("%4d 	%-20s\n", unTipoDePlastico.idTipoDePlastico, unTipoDePlastico.descripcionTipoDePlastico);
		retorno = 0;
	}
	return retorno;
}

//3.
int MostrarDescripcionDeUnTipoDePlastico(eTipoDePlastico listaTiposDePlastico[], int tamTiposDePlastico, int idTipoDePlastico)
{
	int retorno=-1;
	int indice;
	indice = BuscarTipoDePlasticoPorId(listaTiposDePlastico, tamTiposDePlastico, idTipoDePlastico);
	if(listaTiposDePlastico!= NULL && tamTiposDePlastico>0 && idTipoDePlastico >0 && indice != -1 && listaTiposDePlastico[indice].isEmpty == 0)
	{
		printf("%-20s		",listaTiposDePlastico[indice].descripcionTipoDePlastico);
		retorno = 0;
	}
	return retorno;
}

//4.
int MostrarTiposDePlastico(eTipoDePlastico listaTiposDePlastico[], int tamTiposDePlastico)
{
	int retorno=-1;
	if(listaTiposDePlastico!= NULL && tamTiposDePlastico >0)
	{
		printf("  ID	Descripcion\n");
		for(int i=0; i<tamTiposDePlastico; i++)
		{
			if(MostrarUnTipoDePlastico(listaTiposDePlastico[i])==0)
			{
				retorno = 0; //con que haya al menos una localidad con isEmpty==0(ocupada)
			}
		}
	}
	return retorno;
}

//5.
int BuscarTipoDePlasticoPorId(eTipoDePlastico listaTiposDePlastico[], int tamTiposDePlastico, int idTipoDePlastico)
{
	int retorno=-1;
	if(listaTiposDePlastico!= NULL && tamTiposDePlastico >0 && idTipoDePlastico>0)
	{
		for(int i=0; i<tamTiposDePlastico; i++)
		{
			if(listaTiposDePlastico[i].isEmpty==0 && listaTiposDePlastico[i].idTipoDePlastico==idTipoDePlastico)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

//6.
int BuscarPosicionTiposDePlasticoLibre(eTipoDePlastico listaTiposDePlastico[], int tamTiposDePlastico)
{
	int retorno = -1;
	if(listaTiposDePlastico != NULL && tamTiposDePlastico>0)
	{
		for(int i=0; i<tamTiposDePlastico; i++)
		{
			if(listaTiposDePlastico[i].isEmpty==1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

//7.
int HardcodearTiposDePlasticos(eTipoDePlastico listaTiposDePlasticos[], int tamTiposDePlasticos, int* pNextIdTipoDePlastico)
{
	char tiposDePlasticos[3][60] =
	{
			"Polietileno de Alta Densidad[2]",
			"Polietileno de Baja Densidad[4]",
			"Polipropileno[5]"
	};
	int cantidad = 0;
	if(listaTiposDePlasticos!=NULL && tamTiposDePlasticos>0 && pNextIdTipoDePlastico != NULL)
	{
		for(int i=0; i<3; i++)
		{
			listaTiposDePlasticos[i].idTipoDePlastico=(*pNextIdTipoDePlastico);
			(*pNextIdTipoDePlastico) = (*pNextIdTipoDePlastico)+1;
			strcpy(listaTiposDePlasticos[i].descripcionTipoDePlastico, tiposDePlasticos[i]);
			listaTiposDePlasticos[i].isEmpty=0;
			cantidad++;
		}
	}
	return cantidad;
}

//8.
int ContarTiposDePlastico(eTipoDePlastico listaTiposDePlastico[], int tamListaTiposDePlastico)
{
	int retorno = 0;
	if(listaTiposDePlastico != NULL && tamListaTiposDePlastico>0)
	{
		for (int i=0; i<tamListaTiposDePlastico; i++)
		{
			if(listaTiposDePlastico[i].isEmpty==0)
			{
				retorno++;
			}
		}
	}
	return retorno;
}

