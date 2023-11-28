#include <iostream>
#include "GraphM.h" 
#include <vector>

using namespace std;

int main() {
	GraphM<string> graph;  // Inicializar el grafo vacío
	int choice;

	while (true) {
		// Mostrar el menú
		cout << "\nMenu:\n";
		cout << "0. Llenar matriz con vértices y arcos de ejemplo\n";
		cout << "1. Agregar vértice\n";
		cout << "2. Agregar arco\n";
		cout << "3. Eliminar vértice\n";
		cout << "4. Eliminar arco\n";
		cout << "5. Imprimir grafo\n";
		cout << "6. Salir\n";
		cout << "Ingrese su elección: ";
		cin >> choice;

		switch (choice) {
			case 0: {
				// Llenar la matriz con vértices y arcos de ejemplo
				vector<string> vertices = {"A", "B", "C", "D"};
				vector<Edge<string>> edges = {{"A", "B", 1}, {"B", "C", 2}, {"C", "A", 3}, {"D","C",4}};
				graph = GraphM<string>(vertices, edges);
				cout << "Matriz llenada con vértices y arcos de ejemplo.\n";
				break;
			}
			case 1: {
				// Agregar vértice
				string vertex;
				cout << "Ingrese el vértice a agregar: ";
				cin >> vertex;
				try {
					graph.addVertex(vertex);
					cout << "Vértice agregado con éxito.\n";
				} catch (const invalid_argument &e) {
					cout << e.what() << endl;
				}
				break;
			}
			case 2: {
				// Agregar arco
				string source, target;
				int weight;
				cout << "Ingrese el vértice de origen: ";
				cin >> source;
				cout << "Ingrese el vértice de destino: ";
				cin >> target;
				cout << "Ingrese el peso del arco: ";
				cin >> weight;
				try {
					graph.addEdge({source, target, weight});
					cout << "Arco agregado con éxito.\n";
				} catch (const invalid_argument &e) {
					cout << e.what() << endl;
				}
				break;
			}
			case 3: {
				// Eliminar vértice
				string vertex;
				cout << "Ingrese el vértice a eliminar: ";
				cin >> vertex;
				try {
					graph.removeVertex(vertex);
					cout << "Vértice eliminado con éxito.\n";
				} catch (const invalid_argument &e) {
					cout << e.what() << endl;
				}
				break;
			}
			case 4: {
				// Eliminar arco
				string source, target;
				cout << "Ingrese el vértice de origen: ";
				cin >> source;
				cout << "Ingrese el vértice de destino: ";
				cin >> target;
				try {
					graph.removeEdge({source, target, 0});  // Puedes colocar cualquier peso, no se usa en la eliminación
					cout << "Arco eliminado con éxito.\n";
				} catch (const invalid_argument &e) {
					cout << e.what() << endl;
				}
				break;
			}
			case 5:
				// Imprimir grafo
				graph.print();
				break;
			case 6:
				// Salir
				cout << "Saliendo del programa.\n";
				return 0;
			default:
				cout << "Opción no válida. Intente de nuevo.\n";
		}
	}

	return 0;
}
