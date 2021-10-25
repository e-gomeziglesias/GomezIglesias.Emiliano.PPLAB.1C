/*
 * DatosHardcodeo.h
 *
 *  Created on: 22 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */
#include "Localidad.h"
#include "TipoDePlastico.h"

#ifndef DATOSHARDCODEO_H_
#define DATOSHARDCODEO_H_

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
		"Av. Amancio Alcorta 3506",
		"Av. Pagani 487",
		"Coronel Diaz 2142",
		"Adolfo Alsina 4282",
		"Av. Corrientes 415",
		"Av. Pagani 493",
		"Av. Mitre 3116"
};

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

char tiposDePlasticos[3][60] =
{
		"Polietileno de Alta Densidad[2]",
		"Polietileno de Baja Densidad[4]",
		"Polipropileno[5]"
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

int idTiposDePlasticos[10] =
{
		2,
		2,
		2,
		1,
		2,
		1,
		3,
		2,
		3,
		3
};

char estados [2] =
{
		"Completado",
		"Pendiente"
};


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

#endif /* DATOSHARDCODEO_H_ */
