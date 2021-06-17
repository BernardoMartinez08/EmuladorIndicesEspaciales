#include "Coordenada.h"

coordenada::coordenada() {
	coordenada_x = 0;
	coordenada_y = 0;
	id_pedido = -1;
}

coordenada::coordenada(int _x, int _y, int _k) {
	coordenada_x = _x;
	coordenada_y = _y;
	id_pedido = _k;
}


ostream& operator<<(ostream& stream, const coordenada& data) {
	// escribir datos al stream
	stream
		<< data.coordenada_x << ","
		<< data.coordenada_y << ","
		<< data.id_pedido << ",";

	return stream;
}

istream& operator>>(istream& stream, coordenada& data) {
	// leer datos del stream

	//Coordenada X
	char _CX[8];
	stream.getline(_CX, 8, ',');
	data.coordenada_x = atoi(_CX);

	//Coordenada Y
	char _CY[8];
	stream.getline(_CY, 8, ',');
	data.coordenada_y = atoi(_CY);

	//ID del pedido
	char _id[8];
	stream.getline(_id, 8, ',');
	data.id_pedido = atoi(_id);

	//stream.ignore(1);

	return stream;
}