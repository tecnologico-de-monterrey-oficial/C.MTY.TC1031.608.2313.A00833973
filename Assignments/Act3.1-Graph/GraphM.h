#ifndef GraphM_h
#define GraphM_h

#include "Edge.h"
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class GraphM {
private:
	vector<T> vertices;
	vector< vector<int> >  matrix;
	int findVertex(T vertex);
public:
	GraphM();
	GraphM(vector<T> vertices, vector< Edge<T> > edges);

	void addVertex(T vertex);
	void addEdge(Edge<T> edge);
	void removeVertex(T vertex);
	void removeEdge(Edge<T> edge);

	void print();
};

template <class T>
GraphM<T>::GraphM() {

}

template <class T>
int GraphM<T>::findVertex(T vertex) {
  typename vector<T>::iterator it;

  it = find(vertices.begin(), vertices.end(), vertex);
  if (it != vertices.end()) {
	return it - vertices.begin();
  } else {
	return -1;
  }
}

template <class T>
GraphM<T>::GraphM(vector<T> vertices, vector< Edge<T> > edges) {
	// Actualizar los vértices de la clase
	this->vertices = vertices;
	// Inicializar la matriz con valor por default en false
	vector<int> row(vertices.size(), 0);
	matrix.assign(vertices.size(), row);
	// Recorremos la lista de edges
	for (auto edge : edges) {
		// Buscar la posición donde se encuentra en la lista de vertices el vértice origen (sourceIndex)
		int sourceIndex = findVertex(edge.source);
		// Buscar la posición donce se encuentra en la lista de vértices el vértice destino (targetIndex)
		int targetIndex = findVertex(edge.target);
		if (sourceIndex != -1 && targetIndex != -1) {
			// Actualizo en verdadero la posición dada en la matriz (matrix[sourceIndex][targetIndex] = true)
			matrix[sourceIndex][targetIndex] = edge.weight;
		}
	}
}


template <class T>
void GraphM<T>::print() {
	cout << "   ";
	for (auto vertex : vertices) {
		cout << " " << vertex;
	}
	cout << endl;
	for (int i=0; i<vertices.size(); i++) {
		cout << vertices[i] << " - ";
		for (int j=0; j<vertices.size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

template <class T>
void GraphM<T>::addVertex(T vertex) {
	// Verificar si el vértice ya existe
	int vertexIndex = findVertex(vertex);
	if (vertexIndex == -1) {
		// Agregar el vértice a la lista de vértices
		vertices.push_back(vertex);

		// Agregar una nueva fila y columna en la matriz
		vector<int> row(vertices.size(), 0);
		matrix.push_back(row);
		for (auto &row : matrix) {
			row.push_back(0);
		}
	} else {
		throw invalid_argument("El vértice ya existe");
	}
}

template <class T>
void GraphM<T>::addEdge(Edge<T> edge) {
	// Encontrar los índices de los vértices origen y destino
	int sourceIndex = findVertex(edge.source);
	int targetIndex = findVertex(edge.target);

	// Verificar si los vértices existen en el grafo
	if (sourceIndex != -1 && targetIndex != -1) {
		// Agregar el arco a la matriz
		matrix[sourceIndex][targetIndex] = edge.weight;
	} else {
		throw invalid_argument("Alguno de los vértices no existe");
	}
}

template <class T>
void GraphM<T>::removeVertex(T vertex) {
	// Encontrar el índice del vértice a eliminar
	int vertexIndex = findVertex(vertex);

	// Verificar si el vértice existe en el grafo
	if (vertexIndex != -1) {
		// Eliminar el vértice de la lista de vértices
		vertices.erase(vertices.begin() + vertexIndex);

		// Eliminar la fila correspondiente a ese vértice
		matrix.erase(matrix.begin() + vertexIndex);

		// Eliminar la columna correspondiente a ese vértice
		for (auto &row : matrix) {
			row.erase(row.begin() + vertexIndex);
		}
	} else {
		throw invalid_argument("El vértice no existe en el grafo");
	}
}

template <class T>
void GraphM<T>::removeEdge(Edge<T> edge) {
	// Encontrar los índices de los vértices origen y destino
	int sourceIndex = findVertex(edge.source);
	int targetIndex = findVertex(edge.target);

	// Verificar si los vértices existen en el grafo
	if (sourceIndex != -1 && targetIndex != -1) {
		// Eliminar el arco de la matriz
		matrix[sourceIndex][targetIndex] = 0;
	} else {
		throw invalid_argument("Alguno de los vértices del arco no existe en el grafo");
	}
}

#endif /* GraphM_h */