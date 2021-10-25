/*
 * Localidad.c
 *
 *  Created on: 22 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */
#include "Localidad.h"

//1.
int InicializarLocalidades(eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	if(listaLocalidades!= NULL && tamLocalidades >0)
	{
		for(int i=0; i<tamLocalidades; i++)
		{
			listaLocalidades[i].isEmpty=1;
			retorno = 0;
		}
	}
	return retorno;
}

//2.
int MostrarUnaLocalidad(eLocalidad unaLocalidad)
{
	int retorno=-1;
	if(unaLocalidad.isEmpty == 0)
	{
		printf("%4d 	%-20s\n", unaLocalidad.idLocalidad, unaLocalidad.descripcionLocalidad);
		retorno = 0;
	}
	return retorno;
}

//3.
int MostrarDescripcionDeUnaLocalidad(eLocalidad listadoLocalidades[], int tamLocalidades, int idLocalidad)
{
	int retorno=-1;
	int indice=BuscarLocalidadPorId(listadoLocalidades, tamLocalidades, idLocalidad);
	if(listadoLocalidades != NULL && tamLocalidades > 0 && idLocalidad >0 && indice != -1 && listadoLocalidades[indice].isEmpty == 0 )
	{
		printf("%-20s		",listadoLocalidades[indice].descripcionLocalidad);
		retorno = 0;
	}
	return retorno;
}

//4.
int MostrarLocalidades(eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno=-1;
	if(listaLocalidades!= NULL && tamLocalidades >0)
	{
		for(int i=0; i<tamLocalidades; i++)
		{
			if(MostrarUnaLocalidad(listaLocalidades[i])==0)
			{
				retorno = 0; //con que haya al menos una localidad con isEmpty==0(ocupada)
			}
		}
	}
	return retorno;
}

//5.
int BuscarLocalidadPorId(eLocalidad listaLocalidades[], int tamLocalidades, int idLocalidad)
{
	int retorno=-1;
	if(listaLocalidades!= NULL && tamLocalidades >0 && idLocalidad>0)
	{
		for(int i=0; i<tamLocalidades; i++)
		{
			if(listaLocalidades[i].isEmpty==0 && listaLocalidades[i].idLocalidad==idLocalidad)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

//6.
int BuscarPosicionLocalidadLibre(eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno = -1;
	if(listaLocalidades != NULL && tamLocalidades>0)
	{
		for(int i=0; i<tamLocalidades; i++)
		{
			if(listaLocalidades[i].isEmpty==1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

//7.
int HardcodearLocalidades(eLocalidad listaLocalidades[], int tamListaLocalidades, int* pNextIdLocalidad)
{
	char localidades[10][60]=
	{
			"CABA",
			"Quilmes",
			"Berazategui",
			"Lanus",
			"Avellaneda",
			"Lomas de Zamora",
			"Florencio Varela",
			"Wilde",
			"Almirante Brown",
			"Esteban Echeverria",
	};

	int cantidad = 0;
	if(listaLocalidades!=NULL && tamListaLocalidades>0 && pNextIdLocalidad != NULL)
	{
		for(int i=0; i<10; i++)
		{
			listaLocalidades[i].idLocalidad = *pNextIdLocalidad;
			(*pNextIdLocalidad)=(*pNextIdLocalidad)+1;
			strcpy(listaLocalidades[i].descripcionLocalidad,localidades[i]);
			listaLocalidades[i].isEmpty=0;
			cantidad++;
		}
	}
	return cantidad;
}

//8.
int ContarLocalidades(eLocalidad listaLocalidades[], int tamListaLocalidades)
{
	int retorno = 0;
	if(listaLocalidades != NULL && tamListaLocalidades>0)
	{
		for (int i=0; i<tamListaLocalidades; i++)
		{
			if(listaLocalidades[i].isEmpty==0)
			{
				retorno++;
			}
		}
	}
	return retorno;
}

//9.
int ElegirLocalidad(eLocalidad listaLocalidades[], int tamLocalidades)
{
	int retorno = -1;
	int idLocalidad;
	int indiceLocalidad;
	if(listaLocalidades!=NULL && tamLocalidades>0)
	{
		if(MostrarLocalidades(listaLocalidades, tamLocalidades)!=-1)
		{
			if(CargarEntero(&idLocalidad, "Ingrese id localidad: ", "El id ingresado es invalido.", 1, 10000, 2)!=-1)
			{
				indiceLocalidad=BuscarLocalidadPorId(listaLocalidades, tamLocalidades, idLocalidad);
				if(indiceLocalidad!=-1)
				{
					retorno = indiceLocalidad;
				}
			}
		}
		return retorno;
	}
	return retorno;
}
