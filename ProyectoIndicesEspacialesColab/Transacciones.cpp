#include "Transacciones.h"

Transacciones::Transacciones() {
	pedidos = new vector<pedido>;
	muestra = new vector<pedido>;
	mainIndex = new vector<NodoIndex>;
	gridIndex = new vector<vector<casilla>>;
}

bool Transacciones::readOriginal(istream& stream, pedido& pedido) {
	// leer datos del stream
	char delim = ',';

	//Id
	char _id[13];
	stream.getline(_id, 13, delim);
	pedido.id = atoi(_id);

	//codigo
	char _codigo[260];
	stream.getline(_codigo, 260, delim);
	pedido.codigo = string(_codigo);

	//cliente_id
	char _cliente_id[13];
	stream.getline(_cliente_id, 13, delim);
	pedido.cliente_id = atoi(_cliente_id);

	//conductor_id
	char _conductor_id[13];
	stream.getline(_conductor_id, 13, delim);
	pedido.conductor_id = atoi(_conductor_id);

	//restaurante_id
	char _restaurante_id[13];
	stream.getline(_restaurante_id, 13, delim);
	pedido.restaurante_id = atoi(_restaurante_id);

	//fecha
	char _fecha[12];
	stream.getline(_fecha, 12, delim);
	pedido.fecha = string(_fecha);

	//hora
	char _hora[10];
	stream.getline(_hora, 10, delim);
	pedido.hora = string(_hora);

	//monto
	char _monto[12];
	stream.getline(_monto, 12, delim);
	pedido.monto = atof(_monto);

	//propina
	char _propina[12];
	stream.getline(_propina, 12, delim);
	pedido.propina = atof(_propina);

	//distancia_negocio
	char _distancia_negocio[12];
	stream.getline(_distancia_negocio, 12, delim);
	pedido.distancia_negocio = atof(_distancia_negocio);

	//distancia_cliente
	char _distancia_cliente[12];
	stream.getline(_distancia_cliente, 12, delim);
	pedido.distancia_cliente = atof(_distancia_cliente);

	//tiempo_entrega
	char _tiempo_entrega[12];
	stream.getline(_tiempo_entrega, 12, delim);
	pedido.tiempo_entrega = atof(_tiempo_entrega);

	//coordenada_pedido_x
	char _coordenada_pedido_x[12];
	stream.getline(_coordenada_pedido_x, 12, delim);
	pedido.coordenada_pedido_x = atof(_coordenada_pedido_x);

	//coordenada_pedido_y
	char _coordenada_pedido_y[12];
	stream.getline(_coordenada_pedido_y, 12, delim);
	pedido.coordenada_pedido_y = atof(_coordenada_pedido_y);

	//estado
	char _estado[2];
	stream.getline(_estado, 2, '\n');
	pedido.estado = atoi(_estado);

	return stream.good();
}

void quickSortX(vector<coordenada>& _datos, int primero, int ultimo) {
	int izquierda = primero;
	int derecha = ultimo;
	int centro = (derecha + izquierda) / 2;
	int pivote = _datos[centro].coordenada_x;
	int temp;

	do {
		while (_datos[izquierda].coordenada_x < pivote && izquierda - ultimo) {
			++izquierda;
		}

		while (pivote < _datos[derecha].coordenada_x && derecha > primero) {
			--derecha;
		}

		if (izquierda <= derecha) {
			temp = _datos[izquierda].coordenada_x;
			_datos[izquierda] = _datos[derecha];
			_datos[derecha].coordenada_x = temp;
			++izquierda;
			--derecha;
		}
	} while (izquierda <= derecha);

	if (primero <= derecha) {
		quickSortX(_datos, primero, derecha);
	}

	if (ultimo > izquierda) {
		quickSortX(_datos, izquierda, ultimo);
	}
}

void quickSortY(vector<coordenada>& _datos, int primero, int ultimo) {
	int izquierda = primero;
	int derecha = ultimo;
	int centro = (derecha + izquierda) / 2;
	int pivote = _datos[centro].coordenada_y;
	int temp;

	do {
		while (_datos[izquierda].coordenada_y < pivote && izquierda - ultimo) {
			++izquierda;
		}

		while (pivote < _datos[derecha].coordenada_y && derecha > primero) {
			--derecha;
		}

		if (izquierda <= derecha) {
			temp = _datos[izquierda].coordenada_y;
			_datos[izquierda] = _datos[derecha];
			_datos[derecha].coordenada_y = temp;
			++izquierda;
			--derecha;
		}
	} while (izquierda <= derecha);

	if (primero <= derecha) {
		quickSortY(_datos, primero, derecha);
	}

	if (ultimo > izquierda) {
		quickSortY(_datos, izquierda, ultimo);
	}
}

void quickSort(vector<coordenada>& _datos, int casilla) {
	if(casilla == 0)
		quickSortX(_datos, 0, _datos.size() - 1);
	else
		quickSortY(_datos, 0, _datos.size() - 1);
}

vector<coordenada> Transacciones::ordenarMuestra(vector<coordenada> _muestra, int casilla) {
	quickSort(_muestra, casilla);
	return _muestra;
}

bool Transacciones::generarCuadricula(vector<coordenada> ordenadoX, vector<coordenada> ordenadoY, int cuadriculas) {
	double  porcentaje = 0;
	porcentaje = 100 / cuadriculas;
	int valores = 10000 / cuadriculas;

	vector<vector<casilla>>* tabla = new vector<vector<casilla>>;

	for (double i = 0; i < 10000; i + valores) {
		vector<casilla> fila;
		for (double j = 0; j < 10000; j + valores) {
			coordenada minimo(ordenadoX[j].coordenada_x, ordenadoY[i].coordenada_y, -1);
			coordenada maximo(ordenadoX[(j + valores) - 1].coordenada_x, ordenadoY[(i + valores) - 1].coordenada_y, -1);

			casilla aux;
			aux.maximo = maximo;
			aux.minimo = minimo;

			fila.push_back(aux);
		}
		tabla->push_back(fila);
	}

	if (!tabla->empty())
		gridIndex = tabla;

	return gridIndex->empty();
}

float Transacciones::calcularHipotenusa(coordenada _coordenada) {
	float a = _coordenada.coordenada_x;
	float b = _coordenada.coordenada_y;

	float c = sqrt(pow(a,2) + pow(b,2));
	return c;
}

void Transacciones::agregarMainIndex(int _id_pedido, long _posicion) {
	NodoIndex nuevo(_id_pedido, _posicion);

	mainIndex->push_back(nuevo);
}

void Transacciones::agregarGridIndex(float _x, float _y, int _id_pedido) {
	coordenada nuevo(_x, _y, _id_pedido);

	for (int i = 0; i < gridIndex->size(); i++) {
		for (int j = 0; j < gridIndex->at(i).size(); j++) {
			if (_x >= gridIndex->at(i).at(j).minimo.coordenada_x && _x <= gridIndex->at(i).at(j).maximo.coordenada_x) {
				if (_y >= gridIndex->at(i).at(j).minimo.coordenada_y && _y <= gridIndex->at(i).at(j).maximo.coordenada_y) {
					gridIndex->at(i).at(j).pedidos->push_back(nuevo);
				}
			}
		}
	}
}

void Transacciones::guardarMainIndex() {
	ofstream indicePrincipal(fileIndicePrincipal, ios::out | ios::app | ios::binary);
	for (int i = 0; i < mainIndex->size(); i++) {
		indicePrincipal << mainIndex->at(i);
	}
	indicePrincipal.close();
}

void Transacciones::guardarGridIndex() {
	ofstream indiceSecundario(fileIndiceCoordenadas, ios::out | ios::app | ios::binary);
	for (int i = 0; i < gridIndex->size(); i++) {
		for (int j = 0; j < gridIndex->at(i).size(); j++) {
			for (int k = 0; k < gridIndex->at(i).at(j).pedidos->size(); k++) {
				indiceSecundario << gridIndex->at(i).at(j).pedidos->at(k);
			}
			indiceSecundario << "/";
		}
		indiceSecundario << "^";
	}
	indiceSecundario.close();
}