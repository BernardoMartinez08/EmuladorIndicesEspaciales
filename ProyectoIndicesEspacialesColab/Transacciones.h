#pragma once
#ifndef TRANSACCIONES_H
#define TRANSACCIONES_H

#include <iostream>
#include "Pedido.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Transacciones
{
public:
	Transacciones();

	vector<pedido> pedidos;

	bool readOriginal(istream&, pedido&);
private:

};

#endif // !TRANSACCIONES_H