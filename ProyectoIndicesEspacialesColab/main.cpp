#include "Pedido.h"
#include "Transacciones.h"
#include <iostream>
#include <chrono>
using namespace std;

int main() {
	Transacciones transa;

	//Recuperar los datos del CSV
	int registros = 0;
	ifstream file("transacciones.csv", ios::in);
	ofstream fileE("transacciones.bin", ios::out);

	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;

	start = std::chrono::steady_clock::now();

	char titulos[256];
	file.getline(titulos, 256, '\n');
	cout << "Titulos: " << titulos;

	while (!file.eof()) {
		pedido _pedidos;
		DelimTextBuffer delim('^', 1000);

		transa.readOriginal(file, _pedidos);
		_pedidos.print();
		_pedidos.Write(fileE, delim);
		registros++;
	}

	cout << "\n\n Total: " << registros;

	end = std::chrono::steady_clock::now();
	std::chrono::duration<float> duration = end - start;

	float tiempo = duration.count();

	cout << "\n\n***RECUPERACION FINALIZADA***\nSe recuperraron los registros.\nEl programa tomo: " << tiempo << " segundos en recuperar los datos y guardarlos en el nuevo archivo.";

	return 0;
}