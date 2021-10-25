/*
 * Clientes.c
 *
 *  Created on: 22 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include "Clientes.h"


//1.
int InicializarClientes(eCliente listaClientes[], int tamClientes)
{
	int retorno=-1;
	if(listaClientes!= NULL && tamClientes >0)
	{
		for(int i=0; i<tamClientes; i++)
		{
			listaClientes[i].isEmpty=1;
			retorno = 0;
		}
	}
	return retorno;
}

//2.
int BuscarClientePorId(eCliente listaClientes[], int tamClientes, int idCliente)
{
	int retorno=-1;
	if(listaClientes!= NULL && tamClientes>0 && idCliente>0)
	{
		for(int i=0; i<tamClientes; i++)
		{
			if(listaClientes[i].isEmpty==0 && listaClientes[i].idCliente==idCliente)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

//3.
int CargarNombreCliente(eCliente* pUnCliente)
{
	int retorno;
	if(pUnCliente!=NULL)
	{
		retorno = CargarStringNormalizado(pUnCliente->nombreCliente, TAM_NOMBRE, "Ingrese el nombre del cliente: ", "Nombre muy largo.",0, 2);
	}
	return retorno;
}

//4.
int CargarCuitCliente(eCliente* pUnCliente)
{
	int retorno;
	if(pUnCliente!=NULL)
	{
		retorno = CargarCuit(pUnCliente->cuitCliente, TAM_CUIT, 2);
	}
	return retorno;
}

//5.
int CargarDireccionCliente(eCliente* pUnCliente)
{
	int retorno;
	if(pUnCliente!=NULL)
	{
		retorno = CargarString(pUnCliente->direccionCliente, TAM_DIRECCION, "Ingrese direccion del cliente: ", "La direccion ingresada es invalida. ", 2);
	}
	return retorno;
}

//6.
int BuscarPosicionClienteLibre(eCliente listaClientes[], int tamClientes)
{
	int retorno = -1;
	if(listaClientes != NULL && tamClientes>0)
	{
		for(int i=0; i<tamClientes; i++)
		{
			if(listaClientes[i].isEmpty==1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

//7.
int HardcodearClientes(eCliente listaClientes[], int tamListaClientes, int* pNextIdCliente)
{
	int cantidad = 0;
	char nombresClientes[10][20]=
	{
		"Cocinero",
		"Taragui",
		"Dos Anclas",
		"Coca Cola",
		"Arcor",
		"Filgo",
		"Pizzini",
		"Ledesma",
		"La Campagnola",
		"Menoyo"
	};
	char cuits[10][14] =
	{
		"30-69480562-7",
		"30-57284972-0",
		"30-62844695-0",
		"30-52539008-6",
		"30-50279317-5",
		"30-71671778-6",
		"30-51685221-2",
		"30-50125030-5",
		"30-52551891-0",
		"30-56973541-2"
	};

	char direcciones[10][50] =
	{
			"Av. Cordoba 1751",
			"Agustin P. Justo 567",
			"Las Heras 434",
			"Av. "
			"Alcorta 3506",
			"Av. Pagani 487",
			"Coronel Diaz 2142",
			"Adolfo Alsina 4282",
			"Av. Corrientes 415",
			"Av. Pagani 493",
			"Av. Mitre 3116"
	};

	int idLocalidades[10] =
	{
			1,
			1,
			10,
			5,
			5,
			8,
			9,
			3,
			2,
			2
	};
	if(listaClientes!=NULL && tamListaClientes>0 && pNextIdCliente!=NULL)
	{
		for(int i=0; i<10; i++)
		{
			listaClientes[i].idCliente=(*pNextIdCliente);
			(*pNextIdCliente)=(*pNextIdCliente)+1;
			strcpy(listaClientes[i].cuitCliente,cuits[i]);
			strcpy(listaClientes[i].nombreCliente,nombresClientes[i]);
			strcpy(listaClientes[i].direccionCliente, direcciones[i]);
			listaClientes[i].idLocalidad = idLocalidades[i];
			listaClientes[i].isEmpty=0;
			cantidad++;
		}
	}
	return cantidad;
}

//8.
int ContarClientes(eCliente listaClientes[], int tamClientes)
{
	int retorno = 0;
	if(listaClientes != NULL && tamClientes>0)
	{
		for (int i=0; i<tamClientes; i++)
		{
			if(listaClientes[i].isEmpty==0)
			{
				retorno++;
			}
		}
	}
	return retorno;
}

//9.
int MostrarCuitUnCliente(eCliente unCliente)
{
	int retorno = -1;
	if(unCliente.isEmpty!=1)
	{
		printf("%-20s 		", unCliente.cuitCliente);
		retorno = 0;
	}
	return retorno;
}

//10.
int MostrarDireccionUnCliente(eCliente unCliente)
{
	int retorno = -1;
	if(unCliente.isEmpty!=1)
	{
		printf("%-20s 		", unCliente.direccionCliente);
		retorno = 0;
	}
	return retorno;
}
