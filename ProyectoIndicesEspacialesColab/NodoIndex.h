#pragma once
#pragma once
#ifndef NODOINDEX_H
#define NODOINDEX_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include "DelimTextBuffer.h"

using namespace std;

class NodoIndex {
	friend ostream& operator<<(ostream&, const NodoIndex&);
	friend istream& operator>>(istream&, NodoIndex&);
public:
	NodoIndex();
	NodoIndex(int, long);

	int id_pedido;
	long posicion;
};

#endif // !NODOINDEX_H