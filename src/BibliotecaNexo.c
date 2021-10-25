/*
 * BibliotecaNexo.c
 *
 *  Created on: 22 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */
#include "BibliotecaNexo.h"
#define PENDIENTE 0
#define COMPLETADO 1

//comienzo nexo cliente-localidad
	//1.
	int CargarLocalidadCliente(eCliente* pUnCliente, eLocalidad listaLocalidades[], int tamListaLocalidades)
	{
		int retorno = -1;
		int idLocalidad;
		if(listaLocalidades != NULL && tamListaLocalidades>0)
		{
			if(MostrarLocalidades(listaLocalidades, tamListaLocalidades)==0)
			{
				CargarEntero(&idLocalidad, "Ingrese el id de la localidad: ", "Id ingresado invalido.", 1, 10000, 2);
				if(BuscarLocalidadPorId(listaLocalidades, tamListaLocalidades, idLocalidad)!=-1)
				{
					pUnCliente->idLocalidad=idLocalidad;
					retorno = 0;
				}
			}
		}
		return retorno;
	}

	//2.
	int AltaCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades, int* pNextIdCliente)
	{
		int retorno=-1;
		int indiceLibre;
		eCliente auxCliente;

		if(listaClientes!=NULL && tamClientes>0 && listaLocalidades!=NULL && tamListaLocalidades>0 && pNextIdCliente!=NULL)
		{
			indiceLibre = BuscarPosicionClienteLibre(listaClientes, tamClientes);
			if(indiceLibre!=-1)
			{
				//id autoincremental
				auxCliente.idCliente = (*pNextIdCliente);
				//nombre empresa
				printf("NOMBRE\n");
				if(CargarNombreCliente(&auxCliente)!=-1)
				{
					//cuit
					printf("CUIT\n");
					if(CargarCuitCliente(&auxCliente)!=-1)
					{
						//direccion
						printf("DIRECCION\n");
						if(CargarDireccionCliente(&auxCliente)!=-1)
						{
							printf("LOCALIDAD\n");
							if(CargarLocalidadCliente(&auxCliente, listaLocalidades, tamListaLocalidades)!=-1)
							{
								auxCliente.isEmpty=0;
								listaClientes[indiceLibre]=auxCliente;
								(*pNextIdCliente)++;
								retorno = indiceLibre;
							}
						}
					}
				}
			}
		}
		return retorno;
	}

	//3.
	int MostrarUnCliente(eCliente unCliente, eLocalidad listaLocalidades[], int tamListaLocalidades)
	{
		int retorno = -1;
		if(unCliente.isEmpty==0 && listaLocalidades!=NULL && tamListaLocalidades>0)
		{
			printf("%4d  	%-20s	%-14s	%-30s		",
					unCliente.idCliente,
					unCliente.nombreCliente,
					unCliente.cuitCliente,
					unCliente.direccionCliente);
			MostrarDescripcionDeUnaLocalidad(listaLocalidades, tamListaLocalidades, unCliente.idLocalidad);
			retorno = 0;
		}
		return retorno;
	}


	//4.
	void ResultadoAltaModificacionCliente(char mensaje[], char mensajeError[], eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades, int retornoFuncion)
	{
		if(mensaje!= NULL && mensajeError!=NULL && listaClientes!=NULL && tamClientes>0 && listaLocalidades!=NULL && tamListaLocalidades>0)
		{
			if(retornoFuncion!=-1)
			{
				printf("%s\n", mensaje);
				MostrarUnCliente(listaClientes[retornoFuncion], listaLocalidades, tamListaLocalidades);
				printf("\n");
			}
			else
			{
				printf("%s\n", mensajeError);
			}

		}
	}

	//5.
	int MostrarClientes(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades)
	{
		int retorno = -1;
		if(listaClientes!=NULL && tamClientes>0 && listaLocalidades!=NULL && tamListaLocalidades>0)
		{
			printf("  ID 	NOMBRE			CUIT			DIRECCION			LOCALIDAD\n");
			for(int i=0; i<tamClientes; i++)
			{
				if(MostrarUnCliente(listaClientes[i], listaLocalidades, tamListaLocalidades)==0)
				{
					retorno = 0;
					printf("\n");
				}

			}
		}
		return retorno;
	}

	//6.
	int ElegirClientePorId(char mensaje[], eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades)
	{
		int retorno = -1;
		int idCliente;
		int auxIndice;

		if(mensaje!= NULL && listaClientes!=NULL && tamClientes>0 && listaLocalidades!=NULL && tamListaLocalidades>0)
		{
			if(MostrarClientes(listaClientes, tamClientes, listaLocalidades, tamListaLocalidades)==0)
			{
				CargarEntero(&idCliente, "Ingrese el id del cliente: ", "El id ingresado es invalido.", 1, 10000, 2);
				auxIndice = BuscarClientePorId(listaClientes, tamClientes, idCliente);
				if(auxIndice!=-1)
				{
					MostrarUnCliente(listaClientes[auxIndice], listaLocalidades, tamListaLocalidades);
					printf("\n");
					printf("%s\n\n", mensaje);
					retorno = auxIndice;
				}
			}
		}
		return retorno;
	}

	//7.
	int ModificarCliente(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades)
	{
		int opcion;
		int indiceCliente;
		int retorno=-1;

		if(listaClientes!=NULL && tamClientes>0 && listaLocalidades!=NULL && tamListaLocalidades>0)
		{
			indiceCliente=ElegirClientePorId("Se modificara el cliente mostrado.", listaClientes, tamClientes, listaLocalidades, tamListaLocalidades);
			if(indiceCliente !=-1)
			{
				do
				{
				system("cls");
				MostrarUnCliente(listaClientes[indiceCliente], listaLocalidades, tamListaLocalidades);
				printf("\n");
				opcion = MostrarMenuModificacionesClientes();
					switch(opcion)
					{
						case 1://MODIFICAR DIRECCION CLIENTE
							printf("MODIFICAR DIRECCION CLIENTE\n");
							retorno = CargarDireccionCliente(&listaClientes[indiceCliente]);
							AnalizarRetorno(retorno, "La direccion se modifico con exito.", "No se modifico la direccion.");
							printf("\n");
							MostrarUnCliente(listaClientes[indiceCliente], listaLocalidades, tamListaLocalidades);
							printf("\n");
							printf("\n");
							system("pause");
						break;
						case 2://MODIFICAR LOCALIDAD CLIENTE
							printf("MODIFICAR LOCALIDAD CLIENTE\n");
							retorno = CargarLocalidadCliente(&listaClientes[indiceCliente], listaLocalidades, tamListaLocalidades);
							AnalizarRetorno(retorno, "La localidad se modifico con exito.", "No se modifico la localidad.");
							printf("\n");
							MostrarUnCliente(listaClientes[indiceCliente], listaLocalidades, tamListaLocalidades);
							printf("\n");
							printf("\n");
							system("pause");
						break;

						case 0://VOLVER MENU MODIFICACIONES
							printf("Volviendo al menu de modificaciones.\n");
							system("pause");
						break;
					}
				}while(opcion!=0);
			}
		}
		return retorno;
	}

	//8.
	int BajaClientes(eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades, ePedido listaPedidos[], int tamPedidos)
	{
		char opcion='n';
		int indiceCliente;
		int retorno=-1;

		if(listaClientes!=NULL && tamClientes>0 && listaLocalidades!=NULL && tamListaLocalidades>0 && listaPedidos != NULL && tamPedidos>0)
		{
			indiceCliente=ElegirClientePorId("Se eliminara el cliente mostrado.", listaClientes, tamClientes, listaLocalidades, tamListaLocalidades);
			if(indiceCliente !=-1)
			{
				CargarChar(&opcion, "Desea eliminar al cliente? (s/n): ", "La respuesta ingresada es invalida.", 0, 2);
				if(opcion=='s')
				{
					printf("\n");
					MostrarUnCliente(listaClientes[indiceCliente], listaLocalidades, tamListaLocalidades);
					printf("\n");
					printf("\n");
					retorno=BajarPedidosPorIdCliente(listaPedidos, tamPedidos, listaClientes, tamClientes, listaClientes[indiceCliente].idCliente);
					printf("Retorno baja pedidos %d\n", retorno);
					if(retorno !=-1)
					{
						listaClientes[indiceCliente].isEmpty=1;
						retorno = indiceCliente;
					}
				}
				else
				{
					printf("Se cancelo la baja por el usuario\n");
				}
			}
		}
		return retorno;
	}
//fin nexo cliente-localidad

//comienzo nexo pedido-cliente-localidad
	//9.
	int CargarIdCliente(ePedido* pUnPedido, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades)
	{
		int retorno = -1;
		int auxIndiceCliente;
		if(pUnPedido != NULL && listaClientes != NULL && tamClientes>0 && listaLocalidades != NULL && tamListaLocalidades>0)
		{
			auxIndiceCliente = ElegirClientePorId("Se cargara el pedido al cliente mostrado.", listaClientes, tamClientes, listaLocalidades, tamListaLocalidades);
			if(auxIndiceCliente!=-1)
			{
				(*pUnPedido).idCliente = listaClientes[auxIndiceCliente].idCliente;
				retorno = 0;
			}
		}
		return retorno;
	}

	//10.
	int AltaPedido(ePedido listaPedidos[], int tamPedidos, eEstado listaEstados[], int tamEstados, eCliente listaClientes[], int tamClientes, eLocalidad listaLocalidades[], int tamListaLocalidades, int* pNextIdPedido)
	{
		int retorno = -1;
		int auxIndice;
		ePedido auxPedido;
		if(listaPedidos!=NULL && tamPedidos>0 && listaEstados != NULL && tamEstados >0 && listaClientes!= NULL && tamClientes>0 && listaLocalidades!= NULL && tamListaLocalidades>0 && pNextIdPedido!=NULL)
		{
			auxIndice=BuscarPosicionPedidoLibre(listaPedidos, tamPedidos);
			if(auxIndice!=-1)
			{
				if(CargarIdCliente(&auxPedido, listaClientes, tamClientes, listaLocalidades, tamListaLocalidades)!=-1)
				{
					if(CargarKilos(&auxPedido)!=-1)
					{
						//asigno el valor del siguiente id de pedido
						auxPedido.idPedido=(*pNextIdPedido);
						//autoincremento el valor del id de pedido
						(*pNextIdPedido)=(*pNextIdPedido)+1;
						//asigno el estado de pendiente
						auxPedido.idEstado = PENDIENTE;
						auxPedido.isEmpty=0;
						listaPedidos[auxIndice]=auxPedido;
						printf("\n");
						printf("ID PEDIDO 	CUIT CLIENTE			DIRECCION			KILOS A RECOLECTAR	ESTADO\n");
						MostrarUnPedidoConEstado(listaPedidos[auxIndice], listaEstados, tamEstados, listaClientes, tamClientes);
						printf("\n");
						retorno = auxIndice;
					}
				}

			}
		}
		return retorno;
	}

	//11.
	int MostrarUnPedido(ePedido unPedido, eCliente listaClientes[], int tamClientes)
	{
		int retorno = -1;
		int indiceCliente;
		if(listaClientes!=NULL && tamClientes>0 && unPedido.isEmpty==0)
		{
			indiceCliente=BuscarClientePorId(listaClientes, tamClientes, unPedido.idCliente);
			printf("%4d		", unPedido.idPedido);
			MostrarCuitUnCliente(listaClientes[indiceCliente]);
			MostrarDireccionUnCliente(listaClientes[indiceCliente]);
			printf("%.2f\n", unPedido.kilosTotales);
			retorno = 0;
		}
		return retorno;
	}

	//12.
	int MostrarUnPedidoConEstado(ePedido unPedido, eEstado listaEstados[], int tamEstados, eCliente listaClientes[], int tamClientes)
	{
		int retorno = -1;
		int indiceCliente;
		if(listaEstados!=NULL && tamEstados>0 && listaClientes!=NULL && tamClientes>0 && unPedido.isEmpty==0)
		{
			indiceCliente=BuscarClientePorId(listaClientes, tamClientes, unPedido.idCliente);
			printf("%4d		", unPedido.idPedido);
			MostrarCuitUnCliente(listaClientes[indiceCliente]);
			MostrarDireccionUnCliente(listaClientes[indiceCliente]);
			printf("%.2f			", unPedido.kilosTotales);
			MostrarDescripcionDeUnEstado(listaEstados, tamEstados, unPedido.idEstado);
			printf("\n");
		}
		return retorno;
	}

	//13.
	int ContarPedidosPendientesPorCliente(ePedido listaPedidos[], int tamPedidos, eCliente unCliente)
	{
		int retorno = -1;

		if(listaPedidos!=NULL && tamPedidos>0 && unCliente.isEmpty==0)
		{
			int cantidadPendientes=0;
			for(int i=0; i<tamPedidos; i++)
			{
				if(listaPedidos[i].idCliente==unCliente.idCliente)
				{
					cantidadPendientes++;
				}
			}
			retorno = cantidadPendientes;
		}
		return retorno;
	}

	//14.
	int MostrarClientesConPendientes(eCliente listaClientes[], int tamClientes, ePedido listaPedidos[], int tamPedidos, eLocalidad listaLocalidades[], int tamListaLocalidades)
	{
		int retorno = -1;
		int cantidadPendientes;
		if(listaClientes!=NULL && tamClientes >0 && listaPedidos!=NULL && tamPedidos>0 && listaLocalidades!=NULL && tamListaLocalidades >0)
		{
			printf("  ID 	NOMBRE			CUIT			DIRECCION			LOCALIDAD		PENDIENTES\n");
			for(int i=0; i<tamClientes; i++)
			{
				cantidadPendientes=ContarPedidosPendientesPorCliente(listaPedidos, tamPedidos, listaClientes[i]);
				if(MostrarUnCliente(listaClientes[i], listaLocalidades, tamListaLocalidades)!=-1)
				{
					printf("%-4d\n", cantidadPendientes);
					retorno = 0;
				}
			}

		}
		return retorno;
	}

	//15.
	int CargarKilosDePlasticoProcesado(ePedido* pUnPedido)
	{
		int retorno=-1;
		ePedido auxPedido;
		float auxKilosRestantes;
		float auxHDPE;
		float auxLDPE;
		float auxPP;
		float kilosDesecho;

		if(pUnPedido!=NULL)
		{
			auxPedido=(*pUnPedido);
			auxKilosRestantes = auxPedido.kilosTotales;
			printf("\nKilos restantes por procesar: %.2f", auxKilosRestantes);
			if((*pUnPedido).isEmpty==0 && (*pUnPedido).idEstado==PENDIENTE)
			{
				if(CargarFlotante(&auxHDPE, "Ingrese los kilos de HDPE procesados: ", "La cantidad de kilos es invalida.", 0, auxKilosRestantes, 2)!=-1)
				{
					auxKilosRestantes=auxKilosRestantes - auxHDPE;
					printf("\nKilos restantes por procesar: %.2f", auxKilosRestantes);
					if(CargarFlotante(&auxLDPE, "Ingrese los kilos de LDPE procesados: ", "La cantidad de kilos es invalida.", 0, auxKilosRestantes, 2)!=-1)
					{
						auxKilosRestantes=auxKilosRestantes - auxLDPE;
						printf("\nKilos restantes por procesar: %.2f", auxKilosRestantes);
						if(CargarFlotante(&auxPP, "Ingrese los kilos de PP procesados: ", "La cantidad de kilos es invalida.", 0, auxKilosRestantes, 2)!=-1)
						{
							kilosDesecho = auxKilosRestantes;
							auxPedido.kilosDesecho = kilosDesecho;
							auxPedido.kilosHDPE=auxHDPE;
							auxPedido.kilosLDPE=auxLDPE;
							auxPedido.kilosPP=auxPP;
							auxPedido.idEstado=COMPLETADO;
							(*pUnPedido)=auxPedido;

							retorno = 0;
						}
					}
				}
			}

		}
		return retorno;
	}

	//16.
	int ElegirIdPedidoSegunEstado(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes, int estado)
	{
		int retorno = -1;
		int indicePedido;
		int idPedido;
		if(listaPedidos!= NULL && tamPedidos>0 && listaClientes!=NULL && tamClientes>0)
		{
			if(MostrarPedidosSegunEstado(listaPedidos, tamPedidos, listaClientes, tamClientes, estado)!=-1)
			{
				if(CargarEntero(&idPedido, "Ingrese el id del pedido: ", "El id ingresado es invalido.", 1, 10000, 2)!=-1)
				{
					indicePedido=BuscarPedidoPorId(listaPedidos, tamPedidos, idPedido);
					if(indicePedido!=-1)
					{
						if(listaPedidos[indicePedido].idEstado==estado)
						{
							retorno = indicePedido;
						}
					}
				}
			}
		}
		return retorno;
	}

	//17.
	int ProcesarResiduos(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes)
	{
		int retorno=-1;
		int indicePedido;
		if(listaPedidos!= NULL && tamPedidos>0 && listaClientes!=NULL && tamClientes>0)
		{
			indicePedido = ElegirIdPedidoSegunEstado(listaPedidos, tamPedidos, listaClientes, tamClientes, PENDIENTE);
			if(indicePedido!=-1)
			{
				if(CargarKilosDePlasticoProcesado(&listaPedidos[indicePedido])!=-1)
				{
					printf("  ID PEDIDO		CUIT				DIRECCION		HDPE  	LDPE  	PP\n");
					MostrarUnPedidoProcesado(listaPedidos[indicePedido], listaClientes, tamClientes);
					printf("\n");
					retorno = 0;
				}
			}
		}
		return retorno;
	}

//18.
int MostrarPedidosSegunEstado(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes, int estado)
{
	int retorno = -1;
	if(listaPedidos!=NULL && tamPedidos>0 && listaClientes!=NULL && tamClientes>0)
	{
		for(int i=0; i<tamPedidos; i++)
		{
			if(listaPedidos[i].idEstado==estado)
			{
				if(MostrarUnPedido(listaPedidos[i], listaClientes, tamClientes)!=-1)
				{
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
//19.
int MostrarUnPedidoProcesado(ePedido unPedido, eCliente listaClientes[], int tamClientes)
{
	int retorno = -1;
	int indiceCliente;
	if(unPedido.isEmpty==0 && unPedido.idEstado==COMPLETADO && listaClientes!=NULL && tamClientes>0)
	{
		indiceCliente=BuscarClientePorId(listaClientes, tamClientes, unPedido.idCliente);
		printf("%4d		", unPedido.idPedido);
		MostrarCuitUnCliente(listaClientes[indiceCliente]);
		MostrarDireccionUnCliente(listaClientes[indiceCliente]);
		printf("%.2f	%.2f	%.2f\n", unPedido.kilosHDPE, unPedido.kilosLDPE, unPedido.kilosPP);
		retorno = 0;
	}
	return retorno;
}

//20.
int MostrarPedidosProcesados(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes)
{
	int retorno = -1;
	if(listaPedidos!= NULL && tamPedidos>0 && listaClientes!=NULL && tamClientes>0)
	{
		printf("  ID PEDIDO		CUIT				DIRECCION		HDPE  	LDPE  	PP\n");
		for(int i=0; i<tamPedidos; i++)
		{
			if(MostrarUnPedidoProcesado(listaPedidos[i], listaClientes, tamClientes)!=-1)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

//21.
int BajarPedidosPorIdCliente(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes, int idCliente)
{
	int retorno=-1;
	int indiceCliente;
	if(listaPedidos!=NULL && tamPedidos>0 && listaClientes!= NULL && tamClientes>0)
	{
		indiceCliente=BuscarClientePorId(listaClientes, tamClientes, idCliente);
		if(indiceCliente!=-1)
		{
			for(int i=0; i<tamPedidos; i++)
			{
				if(listaPedidos[i].idCliente==listaClientes[indiceCliente].idCliente)
				{
					listaPedidos[i].isEmpty=1;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
//fin nexo pedido-cliente


