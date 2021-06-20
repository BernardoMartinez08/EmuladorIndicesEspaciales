#include "NodoIndex.h"

NodoIndex::NodoIndex() {
	id_pedido = -1;
	posicion = 0;
}

NodoIndex::NodoIndex(int _id_pedido, long _posicion) {
	id_pedido = _id_pedido;
	posicion = _posicion;
}


ostream& operator<<(ostream& stream, const NodoIndex& data) {
	// escribir datos al stream
	stream
		<< data.id_pedido << ","
		<< data.posicion << ",";

	return stream;
}

istream& operator>>(istream& stream, NodoIndex& data) {
	// leer datos del stream

	//ID del pedido
	char _id[8];
	stream.getline(_id, 8, ',');
	data.id_pedido = atoi(_id);

	//Posicion en el archivo
	char _posicion[10];
	stream.getline(_posicion, 10, ',');
	data.posicion = atol(_posicion);

	//stream.ignore(1);

	return stream;
}