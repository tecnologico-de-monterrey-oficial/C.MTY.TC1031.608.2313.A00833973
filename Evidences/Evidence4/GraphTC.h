#ifndef GraphTC_h
#define GraphTC_h

#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include "Edge.h"
#include "HashCity.h"
#include "DistanceTime.h"
#include "Time.h"
#include "quickSort.h"

using namespace std;

class GraphTC {
private:
    HashCity hash;
	int size = 101;
	vector<string> cities;
    vector< vector< Edge<int,DistanceTime> > > adjacencyList;
    string dfsr(int vertexIndex, vector<bool> &status);
    int findShortest(vector<bool> &status, vector<DistanceTime> &cost);

public:
    GraphTC();
    GraphTC(HashCity hash, vector< Edge<int,DistanceTime> > edges);
	int findCity(string city);
    void addCity(string city); 
    void addEdge(string CityA, string CityB, DistanceTime weight);

    void removeVertex(string city);
    void removeEdge(string cityA, string cityB);

    string bfs(string city);
    string dfs(string city);
    string dijkstra(string city);
    string dijkstra(string city, string destiny);
	string sort();

    void printVertex();
    void print();
	string adjacency();
    
};

GraphTC::GraphTC() {
	adjacencyList.resize(hash.Size());  
}

GraphTC::GraphTC(HashCity city, vector< Edge<int,DistanceTime> > newEdges) {
    hash=city;
    adjacencyList.resize(hash.Size());                
    for (auto e:newEdges){
		adjacencyList[e.source].push_back(e);
    }
}

//Regresa si se encuentre la ciudad dentro de la tabla de los agregados
//utilizando la funcion find dentro de hashCity
int GraphTC::findCity(string city) {
    return hash.findCity(city);
}

//Depth-First Search Recursive
//algoritmo utilizado para recorrer o buscar en un grafo de manera estructurada, 
//explorando tan lejos como sea posible a lo largo de cada rama antes de retroceder.

string GraphTC::dfsr(int vertexIndex, vector<bool> &status) {
	// Actualizamos su estado en verdadero
	status[vertexIndex] = true;
	string salida;
	// Recorremos los vecinos
	for (auto neighbor : adjacencyList[vertexIndex]) {
		// Buscamos el índice del vecino (En este caso ya se tiene el indice con el edge)
		// Validamos si su estado es falso
		if (!status[neighbor.target]) {
			//Avanzamos a recorrer el target de cada vecino que no haya sido visitado
			salida += dfsr(neighbor.target, status);
		}
	}
	return hash.city(vertexIndex) + " " + salida; 
}

// Encuentra el indice del target con menor peso en su conexión
int GraphTC::findShortest(vector<bool> &status, vector<DistanceTime> &cost) {
	// Creamos un índice y lo inicializamos en -1
	int shortestIndex = -1;
	// Creamos una variable con el costo en infinito
	DistanceTime shortestCost (INT_MAX, "0:00");
	// Iteramos todos los vértices      
	for (int i=0; i<hash.Size(); i++) {
		// Validamos que su estado sea falso
		if (!status[i]) {
			// Validamos si el costo del vértice actual es el de menor costo
			if (cost[i] < shortestCost) {
				// Actualizamos el shortestCost
				shortestCost = cost[i];
				// Actualizamos el índice del vértice con menor costo
				shortestIndex = i;
			}
		}
	}
	// regresamos el shortestIndex
	return shortestIndex;
}


void GraphTC::addCity(string city) {
	// Buscamos si existe
	try
	{
		hash.insert(city);
		cities.push_back(city);
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
	}

}


void GraphTC::addEdge(string CityA, string CityB, DistanceTime weight) {
	try
	{
		int cityA = hash.findCity(CityA);
		int cityB = hash.findCity(CityB);

		if (cityA != -1 && cityB != -1) {
			Edge<int, DistanceTime> newEdge(cityA, cityB, weight);
			// Validamos que no existe el edge 
			for (auto neighbor : adjacencyList[cityA]) {
				if (cityB == neighbor.target) {
					throw invalid_argument("El arco ya existe en el grafo");
				}
			}
			// lo agregamos a la lista de adyacencias
			adjacencyList[cityA].push_back(newEdge);
		} else {
			throw invalid_argument("Alguno de los vértices no existe");
		}
		}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// Validamos que el vértice origen exista
	
}


void GraphTC::removeVertex(string city) {
	try
	{
		// Buscamos el índice del vértice a eliminar
		int vertexIndex = hash.findCity(city);
		// Verificamos si el vértice existe en el grafo
		if (vertexIndex != -1) {
			// Eliminamos el vértice de la lista de vértices
			hash.remove(city);
			// Eliminamos los arcos que contienen el vértice
			adjacencyList[vertexIndex].clear();

			// Eliminamos las apariciones del vértice en la lista de adyacencias de otros vértices
			for (auto &adjList : adjacencyList) {
				auto it = remove_if(adjList.begin(), adjList.end(), [vertexIndex](const Edge<int,DistanceTime> &edge) {
					return edge.target == vertexIndex;
				});
				adjList.erase(it, adjList.end());
			}
		} else {
			throw invalid_argument("El vértice no existe en el grafo");
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}


void GraphTC::removeEdge(string cityA, string cityB) {

	try
	{
		// Buscamos los índices de los vértices origen y destino del arco
		int indexA = hash.findCity(cityA);
		int indexB = hash.findCity(cityB);

		// Verificamos que los vértices existan en el grafo
		if (indexA != -1 && indexB != -1) {
			// Buscamos el arco en la lista de adyacencias del vértice origen
			auto it = remove_if(
				adjacencyList[indexA].begin(),
				adjacencyList[indexA].end(),
				[indexB](const Edge<int,DistanceTime> &existingEdge) {
					return existingEdge.target == indexB;
				});

			// Eliminamos el arco físicamente
			adjacencyList[indexA].erase(it, adjacencyList[indexA].end());
		} else {
			throw invalid_argument("Alguno de los vértices del arco no existe en el grafo");
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}


string GraphTC::bfs(string city) {
	try
	{
		string salida = "";
		int vertexIndex = hash.findCity(city);
		// Validamos si el vértice de inicio existe en la lista de vértices
		if (vertexIndex != -1) {
		// Creamos una lista del tamaño de vértices e inicializada en falso
		vector<bool> status(hash.Size(), false);
		// Creamos una fila de enteros vacía
		queue<int> bfsQueue;
		// Agregamos el índice del vértice de inicio a la fila
		bfsQueue.push(vertexIndex);
		// Cambiamos el estado en la lista de estado del vértice de inicio en verdadero
		status[vertexIndex] = true;
		// Hacemos un ciclo mientra la fila no este vacía
		while (!bfsQueue.empty()) {
			// Recorremos cada uno de los vecinos del vértice que se encuentra al inicio de la fila
			for (auto neighbor : adjacencyList[bfsQueue.front()]) {
			// Buscamos el índice del vecino
			int neighborIndex = neighbor.target;
			// Validamos si el estado del vecino sea falso
			if (!status[neighborIndex]) {
				// Agregamos el índice del vecino a la fila
				bfsQueue.push(neighborIndex);
				// Cambiamos el estado del vecino en la lista de estados 
				status[neighborIndex] = true;
			}
			}
			// Imprimimos el primer elemento de la fila
			salida += hash.city(bfsQueue.front()) + " ";
			// Removemos el primer elemento de la fila
			bfsQueue.pop();
		}
		return salida;
		} else {
		// Genreamos una excepción de que el vértice de inicio no existe
		throw invalid_argument("El vértice de inicio no existe");
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}


string GraphTC::dfs(string city) {
    // Validamo si el vértice existe
    int vertexIndex = hash.findCity(city);
    if (vertexIndex != -1) {
		// Creamos una lista de estdos
		vector<bool> status(hash.Size(), false);
		// Llamamos a la función de recirsividad
		return dfsr(vertexIndex, status);
    }
}


string GraphTC::dijkstra(string city) {
    // Validamos que el vértice de inicio exista
	
	try
	{
		int vertexIndex = hash.findCity(city);
		if (vertexIndex != -1) {
			// Creamos la lista de estado
			vector<bool> status(hash.Size(), false);
			// Creamos la lista de costo
			DistanceTime dt(INT_MAX,"0:00");
			vector<DistanceTime> cost(hash.Size(), dt);
			// Creamos la lista de paths
			vector<int> path(hash.Size(), -1);
			// Actualizamos en 0 el costo del vertexIndex (vértice inicial)
			dt.distance = 0 ;
			cost[vertexIndex] = dt;
			// Creamos un índice para almacenar el índice del vértice con menor costo
			int shortestIndex = vertexIndex;
			// Iteramos mientras existean vértices en falso y con valores menor a infinito
			while (shortestIndex != -1) {
				// Actualizamos el estado del vértice con el costo menor
				status[shortestIndex] = true;
				// Iteramos los vecinos del vértice con el costo menor
				for (auto neighbor : adjacencyList[shortestIndex]) {
					// Buscamos el índice del vecino
					int neighborIndex = neighbor.target;
					// Validamos si el estado del vecino es falso
					if (!status[neighborIndex]) {
						// Comparamos si el costo del vecino es mayor al costo del vértice con menor costo + el peso // Por el INT_MAX
						if (cost[neighborIndex] > cost[shortestIndex] + neighbor.weight) {
							// Actualizamos el costo del vecino con el costo del vértice con menor costo + el peso
							cost[neighborIndex] = cost[shortestIndex] + neighbor.weight;
							// Actualizamos el path del vértice vécino con el indice del vértice con menor costo
							path[neighborIndex] = shortestIndex;
						}
					}
				}
				// Actualizamos el shortest Index
				shortestIndex = findShortest(status, cost);
			}
			// Aquí termina la prinera parte del algoritmo
			// Inicializamos una lista de pilas vacías
			vector< stack<int> > shortestPaths(hash.Size());
			// Iteramos todos los vértices
			for (int i=0; i<hash.Size(); i++) {
				// Agregamos a la pila el índice 
				shortestPaths[i].push(i);
				// Creamos una variable con el valor del path del vértice actual
				int pathIndex = path[i];
				// Iteramos mientas el path index sea diferente de -1
				while (pathIndex != -1) {
				// Agregamos a la pila el valor del pathIndex
				shortestPaths[i].push(pathIndex);
				// Actualizamos el pathIndex
				pathIndex = path[pathIndex];
				}
			}
			// Imprimimos el resultado del shortest path
			// Iteramos la lista de stacks

			string respon = "";
			for (auto city:cities){
				int index = hash.findCity(city);
				
				respon += hash.city(index) +  ": ";
				if (cost[index].distance != INT_MAX) {
					// Iteramos la pila mientras no este vacía
					while (!shortestPaths[index].empty()) {
						// Imprimimos el valor de arriba de la pila
						respon += hash.city(shortestPaths[index].top()) + " ";
						// Sacamos el valor de arriba de la pila
						shortestPaths[index].pop();
					}

					respon += "-> " + cost[index].toString();
					respon.append(" \n");
				} else {
				 	respon += "La ruta no existe\n";
				}
			}
			return respon;
			// for (int i=0; i<hash.Size(); i++) {
			// 	// Imprimimos el vértice actual
			// 	respon += hash.city(i) +  ": ";
			// 	// Validamos si el costo de vértice actual es igual no es infinito
			// 	if (cost[i] != INT_MAX) {
			// 		// Iteramos la pila mientras no este vacía
			// 		while (!shortestPaths[i].empty()) {
			// 			// Imprimimos el valor de arriba de la pila
			// 			respon += hash.city(shortestPaths[i].top()) + " ";
			// 			// Sacamos el valor de arriba de la pila
			// 			shortestPaths[i].pop();
			// 		}
			// 		respon += "-> " + to_string(cost[i]) + " \t";
			// 	} else {
			// 	throw invalid_argument("La ruta no existe");
			// 	}
			// }
		} 
		else {
			throw invalid_argument("Vértice no existe");
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
string GraphTC::dijkstra(string city, string destiny) {
    // Validamos que el vértice de inicio exista
	try
	{
		int vertexIndex = hash.findCity(city);
		if (vertexIndex != -1) {
			// Creamos la lista de estado
			vector<bool> status(hash.Size(), false);
			// Creamos la lista de costo
			DistanceTime dt(INT_MAX,"0:00");
			vector<DistanceTime> cost(hash.Size(), dt);
			// Creamos la lista de paths
			vector<int> path(hash.Size(), -1);
			// Actualizamos en 0 el costo del vertexIndex (vértice inicial)
			dt.distance = 0 ;
			cost[vertexIndex] = dt;
			// Creamos un índice para almacenar el índice del vértice con menor costo
			int shortestIndex = vertexIndex;
			// Iteramos mientras existean vértices en falso y con valores menor a infinito
			while (shortestIndex != -1) {
				// Actualizamos el estado del vértice con el costo menor
				status[shortestIndex] = true;
				// Iteramos los vecinos del vértice con el costo menor
				for (auto neighbor : adjacencyList[shortestIndex]) {
					// Buscamos el índice del vecino
					int neighborIndex = neighbor.target;
					// Validamos si el estado del vecino es falso
					if (!status[neighborIndex]) {
						// Comparamos si el costo del vecino es mayor al costo del vértice con menor costo + el peso // Por el INT_MAX
						if (cost[neighborIndex] > cost[shortestIndex] + neighbor.weight) {
							// Actualizamos el costo del vecino con el costo del vértice con menor costo + el peso
							cost[neighborIndex] = cost[shortestIndex] + neighbor.weight;
							// Actualizamos el path del vértice vécino con el indice del vértice con menor costo
							path[neighborIndex] = shortestIndex;
						}
					}
				}
				// Actualizamos el shortest Index
				shortestIndex = findShortest(status, cost);
			}
			// Aquí termina la prinera parte del algoritmo
			// Inicializamos una lista de pilas vacías
			vector< stack<int> > shortestPaths(hash.Size());
			// Iteramos todos los vértices
			for (int i=0; i<hash.Size(); i++) {
				// Agregamos a la pila el índice 
				shortestPaths[i].push(i);
				// Creamos una variable con el valor del path del vértice actual
				int pathIndex = path[i];
				// Iteramos mientas el path index sea diferente de -1
				while (pathIndex != -1) {
					// Agregamos a la pila el valor del pathIndex
					shortestPaths[i].push(pathIndex);
					// Actualizamos el pathIndex
					pathIndex = path[pathIndex];
				}
			}
			// Imprimimos el resultado del shortest path
			// Iteramos la lista de stacks

			string respon = "";
			int indexDest = hash.findCity(destiny);

			// Imprimimos el vértice actual
			//respon += hash.city(indexDest) +  ": ";
			// Validamos si el costo de vértice actual es igual no es infinito
			if (cost[indexDest].distance != INT_MAX) {
				// Iteramos la pila mientras no este vacía
				while (!shortestPaths[indexDest].empty()) {
					// Imprimimos el valor de arriba de la pila
					respon += hash.city(shortestPaths[indexDest].top()) + " -> ";
					// Sacamos el valor de arriba de la pila
					shortestPaths[indexDest].pop();
				}
				respon += "\n" + cost[indexDest].toString() ;
				respon.append(" \n");
			} 
			else {
			throw invalid_argument("La ruta no existe");
			}
			
			return respon;
		} 
		else {
			throw invalid_argument("Vértice no existe");
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


string GraphTC::sort(){
	vector<string> ordered = cities;
	quickSort(ordered);
	string sortString = "Ciudades ordenadas a - z \n\n";
	for(auto city:ordered){
		int i = hash.findCity(city);
		sortString += city;
		sortString += "\n";
	}
	return sortString;
}
void GraphTC::printVertex(){
    cout << "Vertices: ";
    for(auto city:cities){
		cout << city << " ";
	}
    cout << endl;
}

void GraphTC::print() {
    for (auto city:cities) {
	int i = hash.findCity(city);
	cout << hash.city(i) << " - ";
	for (int j=0; j<adjacencyList[i].size(); j++) {
	    cout << hash.city(adjacencyList[i][j].target) << " " << adjacencyList[i][j].weight;
	    if (j < adjacencyList[i].size()-1) {
		cout << " - ";
	    }
	}
	cout << endl;
    }
}

string GraphTC::adjacency() {
	string salida = "";
    for (auto city:cities) {
		int i = hash.findCity(city);
		salida += hash.city(i) + "\n";
		for (int j=0; j<adjacencyList[i].size(); j++) {
			salida += "\t" + hash.city(adjacencyList[i][j].target) + " " + adjacencyList[i][j].weight.toString() + "\n";
		}
		salida += "\n";
    }
	return salida;
}





#endif /* GraphTC_h */