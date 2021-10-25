/*
 * Menu.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */
#include "Menu.h"

//1.
int MostrarMenuPrincipalOpciones (void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE OPCIONES\n\n");
	printf("1-ALTAS\n");
	printf("2-MODIFICACIONES\n");
	printf("3-BAJAS\n");
	printf("4-CREAR PEDIDO DE RECOLECCION\n");
	printf("5-PROCESAR RESIDUOS\n");
	printf("6-LISTADOS\n");
	printf("7-INFORMES\n");
	/*
		printf("8-\n");
		printf("9-\n");
		printf("10-\n");
	*/
	printf("0-SALIR\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 7, 2);
	return opcion;
}

//2.
int MostrarMenuAltas(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE ALTAS\n\n");
	printf("1-CLIENTES\n");
	/*
	 	printf("2-\n");
		printf("3-\n");
		printf("4-\n");
		printf("5-\n");
	*/
	printf("0-VOLVER\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 1, 2);
	return opcion;
}

//3.
int MostrarMenuBajas(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE BAJAS\n\n");
	printf("1-CLIENTES\n");
	/*
	 	printf("2-\n");
		printf("3-\n");
		printf("4-\n");
		printf("5-\n");
	*/
	printf("0-VOLVER\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 1, 2);
	return opcion;
}

//4.
int MostrarMenuModificaciones(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE MODIFICACIONES\n\n");
	printf("1-CLIENTES\n");
	/*
	 	printf("2-\n");
		printf("3-\n");
		printf("4-\n");
		printf("5-\n");
	*/
	printf("0-VOLVER\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 1, 2);
	return opcion;
}

//4.1
int MostrarMenuModificacionesClientes(void)
{
	int opcion=-1;
	//system("cls");
	printf("		MENU DE MODIFICACIONES CLIENTES\n\n");
	printf("1-DIRECCION\n");
	printf("2-LOCALIDAD\n");
	/*
	 	printf("3-\n");
		printf("4-\n");
		printf("5-\n");
		printf("6-\n");
		printf("7-\n");
	*/
	printf("0-CANCELAR\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 2, 2);
	return opcion;
}

//5.
int MostrarMenuListados(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE LISTADOS\n\n");
	printf("1-LISTADO DE CLIENTES\n");
	printf("2-LISTADO DE PEDIDOS PENDIENTES\n");
	printf("3-LISTADO DE PEDIDOS PROCESADOS\n");
	/*
		printf("4-\n");
		printf("5-\n");
		printf("6-\n");
		printf("7-\n");
	*/
	printf("0-VOLVER\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 3, 2);
	return opcion;
}

//6.
int MostrarMenuInformes(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE INFORMES\n\n");
	printf("1-PEDIDOS PENDIENTES PARA UNA LOCALIDAD\n");
	printf("2-CANTIDAD DE KILOS DE POLIPROPILENO RECICLADO PROMEDIO POR CLIENTE\n");
	printf("3-Cliente con más pedidos pendientes.\n");
	printf("4-Cliente con más pedidos completados\n");
	printf("5-Cliente con más pedidos.\n");
	/*
		printf("6-\n");
		printf("7-\n");
		printf("8-\n");
		printf("9-\n");
		printf("10-\n");
		printf("11-\n");
		printf("12-\n");
		printf("13-\n");
	*/
	printf("0-VOLVER\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 5, 2);
	return opcion;
}

//7.
void AnalizarRetorno(int retorno, char mensaje[], char mensajeError[])
{
	if(mensaje != NULL && mensajeError != NULL)
	{
		if(retorno == -1)
		{
			printf("%s\n", mensajeError);
		}
		else
		{
			printf("%s\n", mensaje);
		}
	}
}
//4.2
/*int MostrarMenuModificacionesTipo(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE MODIFICACIONES TIPO DE PRODUCTO\n\n");
	printf("1-ID\n");
	printf("2-DESCRIPCION\n");
	printf("3-FABRICANTE DE PANTALLA\n");
	printf("0-CANCELAR\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 3, 2);
	return opcion;
}


//4.3
int MostrarMenuModificacionesNacionalidad(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE MODIFICACIONES NACIONALIDAD\n\n");
	printf("1-ID\n");
	printf("2-DESCRIPCION\n");
	printf("0-VOLVER\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 2, 2);
	return opcion;
}
*/
