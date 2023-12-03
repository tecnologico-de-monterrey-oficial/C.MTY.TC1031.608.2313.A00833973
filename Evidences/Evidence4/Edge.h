
#pragma once

/* Para este caso del edge se ocupa un segundo template para tener un peso diferente
*/

template <class T,class D>

struct Edge
{
	T source; // Nodo de donde inicia la conexión
	T target; // Nodo en donde termina la conexión
	D weight; // Valor de la conexión
 
	Edge();
	Edge(T,T);
	Edge(T,T,D);

};


template <class T,class D>
Edge<T,D>::Edge(){
	this->source = nullptr;
	this->target = nullptr;
	this->weight = nullptr;
}

template <class T,class D>
Edge<T,D>::Edge(T source, T target){
	this->source = source;
	this->target = target;
	this->weight = nullptr;
}

template <class T,class D>
Edge<T,D>::Edge(T source, T target, D weight){
	this->source = source;
	this->target = target;
	this->weight = weight;
}