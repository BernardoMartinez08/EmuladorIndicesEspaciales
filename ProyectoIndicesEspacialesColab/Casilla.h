#pragma once
#ifndef CASILLA_H
#define CASILLA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include "DelimTextBuffer.h"
#include "Coordenada.h"

using namespace std;

class casilla {
	friend ostream& operator<<(ostream&, const casilla&);
	friend istream& operator>>(istream&, casilla&);
public:
	casilla();

	coordenada minimo;
	coordenada maximo;
	vector<coordenada>* pedidos;
};

#endif // !CASILLA_H
