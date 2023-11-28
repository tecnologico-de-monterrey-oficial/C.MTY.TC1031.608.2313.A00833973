#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

int main() {
	Graph<string> graph;

	while (true) {
		cout << "\nMenu";
		cout << "\n0. Crear ejemplo\n";
		cout << "1. Agregar Vértice\n";
		cout << "2. Agregar Arco\n";
		cout << "3. Eliminar Vértice\n";
		cout << "4. Eliminar Arco\n";
		cout << "5. Recorrido BFS\n";
		cout << "6. Recorrido DFS\n";
		cout << "7. Dijkstra\n";
		cout << "8. Imprimir Grafo\n";
		cout << "9. Salir\n";

		int choice;
		cout << "Ingresa tu elección: ";
		cin >> choice;

		switch (choice) {
			case 0:{

				vector<string> vertices = {"A", "B", "C", "D", "E"};
				vector< Edge<string> > edges;
				edges.emplace_back("A","B",5);
				edges.emplace_back("B","A",4);
				edges.emplace_back("A","C",5);
				edges.emplace_back("C","A",7);
				edges.emplace_back("A","E",9);
				edges.emplace_back("E","A",7);
				edges.emplace_back("B","D",1);
				edges.emplace_back("D","B",2);
				edges.emplace_back("C","D",5);
				edges.emplace_back("D","C",3);
				edges.emplace_back("E","D",3);
				edges.emplace_back("D","E",2);
				for(auto e:vertices){
					graph.addVertex(e);
				}
				for (auto e:edges){
					graph.addEdge(e);
				}
    			graph.print();
				break;
			}
			case 1: {
				string vertex;
				cout << "Ingresa el vértice a agregar: ";
				cin >> vertex;
				graph.addVertex(vertex);
				break;
			}
			case 2: {
				string source, target;
				int weight;
				graph.printVertex();
				cout << "Ingresa el vértice de origen: ";
				cin >> source;
				cout << "Ingresa el vértice de destino: ";
				cin >> target;
				cout << "Ingresa el peso del arco: ";
				cin >> weight;
				Edge<string> edge(source, target, weight);
				graph.addEdge(edge);
				break;
			}
			case 3: {
				string vertex;
				cout << "Ingresa el vértice a eliminar: ";
				graph.printVertex();
				cin >> vertex;
				graph.removeVertex(vertex);
				break;
			}
			case 4: {
				string source, target;
				graph.printVertex();
				cout << "Ingresa el vértice de origen: ";
				cin >> source;
				cout << "Ingresa el vértice de destino: ";
				cin >> target;
				Edge<string> edge(source, target, 0);  // Peso temporal, no se usa en removeEdge
				graph.removeEdge(edge);
				break;
			}
			case 5: {
				string startVertex;
				graph.printVertex();
				cout << "Ingresa el vértice de inicio para BFS: ";
				cin >> startVertex;
				graph.bfs(startVertex);
				break;
			}
			case 6: {
				string startVertex;
				graph.printVertex();
				cout << "Ingresa el vértice de inicio para DFS: ";
				cin >> startVertex;
				graph.dfs(startVertex);
				break;
			}
			case 7: {
				string startVertex;
				graph.printVertex();
				cout << "Ingresa el vértice de inicio para Dijkstra: ";
				cin >> startVertex;
				graph.dijkstra(startVertex);
				break;
			}
			case 8:
				graph.print();
				break;
			case 9:
				return 0;
			default:
				cout << "Opción no válida. Inténtalo de nuevo.\n";
		}
	}

	return 0;
}
