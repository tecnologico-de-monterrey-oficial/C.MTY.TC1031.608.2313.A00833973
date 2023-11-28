#pragma once

template <class T>

struct Edge
{
	T source; // Nodo de donde inicia la conexión
	T target; // Nodo en donde termina la conexión
	int weight; // Valor de la conexión
 

	Edge();
	Edge(T,T);
	Edge(T,T,int);

};


template <class T>
Edge<T>::Edge(){
	this->source = nullptr;
	this->target = nullptr;
	weight = 0;
}

template <class T>
Edge<T>::Edge(T source, T target){
	this->source = source;
	this->target = target;
	weight = 0;
}

template <class T>
Edge<T>::Edge(T source, T target, int weight){
	this->source = source;
	this->target = target;
	this->weight = weight;
}