#pragma once
#ifndef COORDENADA_H
#define COORDENADA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include "DelimTextBuffer.h"

using namespace std;

class coordenada {
	friend ostream& operator<<(ostream&, const coordenada&);
	friend istream& operator>>(istream&, coordenada&);
public:
	coordenada();
	coordenada(int,int,int);

	int coordenada_x;
	int coordenada_y;
	int id_pedido;
};

#endif // !COORDENADA_H