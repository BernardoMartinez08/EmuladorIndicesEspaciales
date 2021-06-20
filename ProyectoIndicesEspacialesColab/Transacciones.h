#pragma once
#ifndef TRANSACCIONES_H
#define TRANSACCIONES_H

#include <iostream>
#include "Pedido.h"
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <math.h>
#include "Casilla.h"
#include "Coordenada.h"
#include "NodoIndex.h"

using namespace std;

class Transacciones
{
public:
	Transacciones();

	//Indices en Memoria
	vector<pedido>* pedidos;
	vector<pedido>* muestra;
	vector<NodoIndex>* mainIndex;
	vector<vector<casilla>>* gridIndex;

	//Leer data del archivo original
	bool readOriginal(istream&, pedido&);

	//Funciones para generar la cuadricula del indice
	vector<coordenada> ordenarMuestra(vector<coordenada>, int);
	bool generarCuadricula(vector<coordenada>, vector<coordenada>, int);

	float calcularHipotenusa(coordenada);

	string fileIndicePrincipal{ "mainIndex.bin" };
	string fileIndiceCoordenadas{ "gridIndex.bin" };

	//Funciones de Indices
	void agregarMainIndex(int, long);
	void agregarGridIndex(float, float, int);

	void guardarMainIndex();
	void guardarGridIndex();
};

#endif // !TRANSACCIONES_H