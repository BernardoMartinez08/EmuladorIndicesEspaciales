#pragma once
#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include "DelimTextBuffer.h"

using namespace std;

class pedido {
public:
	pedido();

	void print();

	//Funciones de Lectura y Escritura con Buffers
	int Write(ostream&, DelimTextBuffer&);
	int Read(istream&, DelimTextBuffer&);
	int Pack(DelimTextBuffer&);
	int Unpack(DelimTextBuffer&);

	int id;
	string codigo;
	int cliente_id;
	int conductor_id;
	int restaurante_id;
	string fecha;
	string hora;
	float monto;
	float propina;
	float distancia_negocio;
	float distancia_cliente;
	float tiempo_entrega;
	float coordenada_pedido_x;
	float coordenada_pedido_y;
	bool estado;
	long posicion;
};

#endif // !PEDIDO_H