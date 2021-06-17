#include "Casilla.h"

casilla::casilla() {
	coordenada corde;
	corde.coordenada_x = 0;
	corde.coordenada_y = 0;
	corde.id_pedido = -1;
	maximo = corde;
	minimo = corde;
	pedidos = new vector<coordenada>;
}

ostream& operator<<(ostream& stream, const casilla& data) {
	// escribir datos al stream
	stream
		<< data.maximo
		<< data.minimo
		<< data.pedidos->size() << ",";

	for (int i = 0; i < data.pedidos->size(); i++) {
		stream << data.pedidos->at(i);
	}

	return stream;
}

istream& operator>>(istream& stream, casilla& data) {
	// leer datos del stream

	//Maximo
	stream >> data.maximo;

	//Minimo
	stream >> data.minimo;

	//Cantidad de pedidos a leer
	int cantidadPedidos = 0;
	char _cantidad[8];
	stream.getline(_cantidad, 8, ',');
	cantidadPedidos = atoi(_cantidad);

	for (int i = 0; i < cantidadPedidos; i++) {
		coordenada aux;
		stream >> aux;

		data.pedidos->push_back(aux);
	}
	
	return stream;
}