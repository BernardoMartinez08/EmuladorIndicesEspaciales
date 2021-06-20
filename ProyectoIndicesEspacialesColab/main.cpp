#include "Pedido.h"
#include "Transacciones.h"
#include <iostream>
#include <chrono>
#include <string>
using namespace std;

int main() {
	Transacciones Manager;

	int opcionPrincipal = 0;
	while (opcionPrincipal != 6) {
		cout << "\n\t**** INDIZADO DE DATOS ESPACIALES *********\n\n";

		cout << "1. Importar archivo de transacciones.\n2. Generar indice espacial de transacciones.\n"
			<< "3. Guardar indice espacial.\n4. Cargar indice espacial.\n5. Consultar transacciones.\n6. Salir."
			<< "\nIngrese una opcion:";
		cin >> opcionPrincipal;

		cout << "\n";

		switch (opcionPrincipal)
		{
		case 1: {
			cout << "\n\n1. Importar archivo de transacciones\n\n";

			string pathOrigen = " ";
			string pathDestino = " ";

			cout << "\nIngrese el nombre del archivo original:";
			cin >> pathOrigen;

			cout << "\nIngrese el nombre del archivo destino:";
			cin >> pathDestino;

			int registros = 0;
			ifstream file(pathOrigen, ios::in);
			ofstream fileE(pathDestino, ios::out);

			std::chrono::steady_clock::time_point start;
			std::chrono::steady_clock::time_point end;

			start = std::chrono::steady_clock::now();

			char titulos[256];
			file.getline(titulos, 256, '\n');
			cout << "\nRecuperado y Copiando los Registros........";

			while (!file.eof()) {
				pedido _pedidos;
				DelimTextBuffer delim('^', 1000);

				Manager.readOriginal(file, _pedidos);
				_pedidos.Write(fileE, delim);
				registros++;
			}

			cout << "\n\n Total: " << registros - 1;

			end = std::chrono::steady_clock::now();
			std::chrono::duration<float> duration = end - start;

			float tiempo = duration.count();

			cout << "\n\n***RECUPERACION FINALIZADA***\nSe recuperraron los registros.\nEl programa tomo: " << tiempo << " segundos en recuperar los datos y guardarlos en el nuevo archivo.";

			break;
		}
		case 2: {
			cout << "\n\n2. Generar índice espacial de transacciones\n\n";

			float tiempoTotal = 0;
			string pathOrigen = " ";
			string nameMainIndex = " ";
			string nameGridIndex = " ";

			cout << "\nIngrese el nombre del archivo que contiene las transacciones:";
			cin >> pathOrigen;

			cout << "\nIngrese un nombre para el archivo de indice principal:";
			cin >> nameMainIndex;

			cout << "\nIngrese un nombre para el archivo de indice principal:";
			cin >> nameGridIndex;

			Manager.fileIndicePrincipal = nameMainIndex;
			Manager.fileIndiceCoordenadas = nameGridIndex;

			cout << "\nRecuperado los Registros......";
			int registros = 0;
			ifstream file(pathOrigen, ios::in);
			
			std::chrono::steady_clock::time_point start;
			std::chrono::steady_clock::time_point end;

			start = std::chrono::steady_clock::now();

			while (registros <= 300000) {
				pedido _pedido;
				DelimTextBuffer delim('^', 5000);

				_pedido.posicion = file.tellg();
				_pedido.Read(file,delim);
				Manager.pedidos->push_back(_pedido);

				if (registros >= 50000 && registros < 60000)
					Manager.muestra->push_back(_pedido);

				registros++;
			}
			file.close();

			cout << "\n\n Total: " << registros - 1;
			cout << "\n\n Total en la muestra: " << Manager.muestra->size();

			end = std::chrono::steady_clock::now();
			std::chrono::duration<float> duration = end - start;

			float tiempo = duration.count();
			tiempoTotal += tiempo;

			cout << "\n\n***CARGA FINALIZADA***\nSe cargaron los registros.\nEl programa tomo: " << tiempo << " segundos.";
			cout << "\n\n****ORDENANDO LAS MUESTRAS****\n";

			start = std::chrono::steady_clock::now();

			vector<coordenada> muestraCoordenadas;
			for (int i = 0; i < Manager.muestra->size(); i++) {
				coordenada _punto;
				_punto.coordenada_x = Manager.muestra->at(i).coordenada_pedido_x;
				_punto.coordenada_y = Manager.muestra->at(i).coordenada_pedido_y;
				_punto.id_pedido = Manager.muestra->at(i).id;
				muestraCoordenadas.push_back(_punto);
			}
			vector<coordenada> ordenadaX = Manager.ordenarMuestra(muestraCoordenadas, 0);
			vector<coordenada> ordenadaY = Manager.ordenarMuestra(muestraCoordenadas, 1);

			end = std::chrono::steady_clock::now();
			duration = end - start;

			tiempo = duration.count();
			tiempoTotal += tiempo;

			cout << "\n\n***Se Ordenaron las Muestras***\nEl programa tomo: " << tiempo << " segundos.";
			cout << "\n\n****CREANDO CUADRICULA****\n";

			start = std::chrono::steady_clock::now();

			int numCasillas = 0;
			cout << "\nIngrese el casillas del grid:";
			cin >> numCasillas;

			if (!Manager.generarCuadricula(ordenadaX, ordenadaY, numCasillas))
				cout << "\n\n***Se Genero la Cuadricula***";
			else
				cout << "\n\n***Hubo un problema para generar la cuadricula***";

			end = std::chrono::steady_clock::now();
			duration = end - start;

			tiempo = duration.count();
			tiempoTotal += tiempo;

			cout << "\nEl programa tomo : " << tiempo << " segundos.";
			cout << "\n\n****CREANDO INDICES****\n";

			start = std::chrono::steady_clock::now();

			for (int i = 0; i < Manager.pedidos->size(); i++) {
				Manager.agregarMainIndex(Manager.pedidos->at(i).id, Manager.pedidos->at(i).posicion);
				Manager.agregarGridIndex(Manager.pedidos->at(i).coordenada_pedido_x, Manager.pedidos->at(i).coordenada_pedido_y, Manager.pedidos->at(i).id);
			}

			end = std::chrono::steady_clock::now();
			duration = end - start;

			tiempo = duration.count();
			tiempoTotal += tiempo;

			cout << "\n\n***Se Crearon los Indices con Exito***\nEl programa tomo: " << tiempo << " segundos.";
			cout << "\nEl programa tomo: " << tiempoTotal << " segundos en todo el proceso de creacion de indices.";
			break;
		}
		case 3: {
			cout << "\n\n3. Guardar índice espacial.\n\n***GUARDANDO***\n";
			std::chrono::steady_clock::time_point start;
			std::chrono::steady_clock::time_point end;

			start = std::chrono::steady_clock::now();
			Manager.guardarMainIndex();
			Manager.guardarGridIndex();

			end = std::chrono::steady_clock::now();
			std::chrono::duration<float> duration = end - start;

			float tiempo = duration.count();

			cout << "\n\n***GUARDADO FINALIZADO***\nSe Guardaron los indices.\nEl programa tomo: " << tiempo << " segundos.";
			break;
		}
		case 4: {
			cout << "\n\n4. Cargar índice espacial.\n\n";
			break;
		}
		case 5: {
			cout << "\n\n5. Consultar transacciones.\n\n";
			break;
		}
		case 6:
			cout << "\n...Saliendo....";
			break;
		default:
			cout << "\nOPCION NO VALIDA";
			break;
		}
	}	

	return 0;
}