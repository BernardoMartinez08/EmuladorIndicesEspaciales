#include "Transacciones.h"

Transacciones::Transacciones() {

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