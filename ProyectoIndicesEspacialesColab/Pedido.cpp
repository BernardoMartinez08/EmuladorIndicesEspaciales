#include "Pedido.h"

pedido::pedido() {
	id = -1;
	codigo = "";
	cliente_id = 0;
	conductor_id = 0;
	restaurante_id = 0;
	fecha = "";
	hora = "";
	monto = 0;
	propina = 0;
	distancia_negocio = 0;
	distancia_cliente = 0;
	tiempo_entrega = 0;
	coordenada_pedido_x = 0;
	coordenada_pedido_y = 0;
	estado = 0;
}

void pedido::print() {
	cout
		<< "\n\nId = " << id << endl
		<< "Id Cliente = " << cliente_id << endl
		<< "Id Conductor = " << conductor_id << endl
		<< "Id Restaurante = " << restaurante_id << endl
		<< "Fecha = " << fecha << endl
		<< "hora = " << hora << endl
		<< "Monto = " << monto << endl
		<< "Propina = " << propina << endl
		<< "Distancia del Negocio = " << distancia_negocio << endl
		<< "Distancia del Cliente = " << distancia_cliente << endl
		<< "Tiempo de Entrega = " << tiempo_entrega << endl
		<< "Cordenadas (X,Y) = (" << coordenada_pedido_x << " , " << coordenada_pedido_y << ")" << endl
		<< "Estado = " << estado << endl;
}

//Funciones de escritura y lectura con Buffer
int pedido::Pack(DelimTextBuffer& _buffer) {
	int resultado;
	std::string tmp = std::to_string(id);
	resultado = _buffer.Pack(tmp.c_str());
	resultado = resultado && _buffer.Pack(codigo.c_str());
	tmp = std::to_string(cliente_id);
	resultado = resultado && _buffer.Pack(tmp.c_str());
	tmp = std::to_string(conductor_id);
	resultado = resultado && _buffer.Pack(tmp.c_str());
	tmp = std::to_string(restaurante_id);
	resultado = resultado && _buffer.Pack(tmp.c_str());
	resultado = resultado && _buffer.Pack(fecha.c_str());
	resultado = resultado && _buffer.Pack(hora.c_str());
	tmp = std::to_string(monto);
	resultado = resultado && _buffer.Pack(tmp.c_str());
	tmp = std::to_string(propina);
	resultado = resultado && _buffer.Pack(tmp.c_str());
	tmp = std::to_string(distancia_negocio);
	resultado = resultado && _buffer.Pack(tmp.c_str());
	tmp = std::to_string(distancia_cliente);
	resultado = resultado && _buffer.Pack(tmp.c_str());
	tmp = std::to_string(tiempo_entrega);
	resultado = resultado && _buffer.Pack(tmp.c_str());
	tmp = std::to_string(coordenada_pedido_x);
	resultado = resultado && _buffer.Pack(tmp.c_str());
	tmp = std::to_string(coordenada_pedido_y);
	resultado = resultado && _buffer.Pack(tmp.c_str());
	tmp = std::to_string(estado);
	resultado = resultado && _buffer.Pack(tmp.c_str());

	return resultado;
}

int pedido::Unpack(DelimTextBuffer& _buffer) {
	int resultado = 1;
	resultado = id = atoi(_buffer.Unpack());
	string tmp = _buffer.Unpack();
	codigo = tmp;
	resultado = cliente_id = atoi(_buffer.Unpack());
	resultado = conductor_id = atoi(_buffer.Unpack());
	resultado = restaurante_id = atoi(_buffer.Unpack());
	tmp = _buffer.Unpack();
	fecha = tmp;
	tmp = _buffer.Unpack();
	hora = tmp;
	resultado = monto = atof(_buffer.Unpack());
	resultado = propina = atof(_buffer.Unpack());
	resultado = distancia_negocio = atof(_buffer.Unpack());
	resultado = distancia_cliente = atof(_buffer.Unpack());
	resultado = tiempo_entrega = atof(_buffer.Unpack());
	resultado = coordenada_pedido_x = atof(_buffer.Unpack());
	resultado = coordenada_pedido_y = atof(_buffer.Unpack());
	resultado = estado = atoi(_buffer.Unpack());

	return resultado;
}

int pedido::Read(istream& file, DelimTextBuffer& _delim) {
	int resultado = 0;
	resultado = _delim.Read(file);
	resultado = resultado && this->Unpack(_delim);
	return resultado;
}

int pedido::Write(ostream& file, DelimTextBuffer& _delim) {
	int resultado = 0;
	resultado = this->Pack(_delim);
	resultado = resultado && _delim.Write(file);
	return resultado;
}