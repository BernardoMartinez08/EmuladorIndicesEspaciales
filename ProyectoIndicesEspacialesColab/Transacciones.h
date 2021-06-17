#pragma once
#ifndef TRANSACCIONES_H
#define TRANSACCIONES_H

#include <iostream>
#include "Pedido.h"
#include <vector>
#include <string>
#include <sstream>
#include "Casilla.h"
#include "Coordenada.h"

using namespace std;

class Transacciones
{
public:
	Transacciones();

	vector<pedido> pedidos;

	bool readOriginal(istream&, pedido&);
	vector<coordenada> ordenarMuestra(vector<coordenada>, int);

	vector<vector<coordenada>> generarCuadricula(vector<coordenada>, vector<coordenada>, int);
private:

};

#endif // !TRANSACCIONES_H