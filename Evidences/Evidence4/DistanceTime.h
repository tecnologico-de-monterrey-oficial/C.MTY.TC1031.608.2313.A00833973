#pragma once

#include "Time.h"
#include <sstream>
using namespace std;



/*Esta estructura es para ser ocupada como elemento de peso a la 
weight dentro de cada uno de los edges

Tienes la sobrecarga de operadores para poder ser ocupada al momento de hacer las 
comparaciones o elementos aritmeticos para calcular el peso total de un nodo a otro.

Contiene el tiepo: las opereaciones hechas con el tiempo deben de tener la sobrecarga de operadores
*/
struct DistanceTime {
    int distance;    // Valor de la conexión para distancia
    Time time;        // Valor de la conexión para tiempo

    DistanceTime();
    DistanceTime(int, string);
    DistanceTime(int,Time);

    // Operadores de comparación
    bool operator<(DistanceTime& other) ;
    bool operator>(DistanceTime& other) ;
    bool operator<=(DistanceTime& other) ;
    bool operator>=(DistanceTime& other) ;

    // Operadores aritméticos
    DistanceTime operator+(DistanceTime& other) ;
    DistanceTime operator-(DistanceTime& other) ;

    // Operadores de igualdad
    bool operator==(DistanceTime& other) ;
    bool operator!=(DistanceTime& other) ;
    operator int() const;
    operator string();

    string toString();

};


DistanceTime::DistanceTime() {
    this->distance = 0;
    this->time = Time();
}


DistanceTime::DistanceTime(int distance, string time) {
    this->distance = distance;
    this->time = Time(time);
}
DistanceTime::DistanceTime(int distance, Time time) {
    this->distance = distance;
    this->time = time;
}


bool DistanceTime::operator<(DistanceTime& other)  {
    return distance < other.distance;
}


bool DistanceTime::operator>(DistanceTime& other)  {
    return distance > other.distance;
}


bool DistanceTime::operator<=(DistanceTime& other)  {
    return distance <= other.distance;
}


bool DistanceTime::operator>=(DistanceTime& other)  {
    return distance >= other.distance;
}


DistanceTime DistanceTime::operator+(DistanceTime& other)  {
    // Suma las distancias y tiempos
    return DistanceTime( distance + other.distance, time + other.time);
}


DistanceTime DistanceTime::operator-(DistanceTime& other)  {
    // Resta las distancias y tiempos
    return DistanceTime( distance - other.distance, time - other.time);
}


bool DistanceTime::operator==(DistanceTime& other)  {
    return (distance == other.distance) && (time == other.time);
}


bool DistanceTime::operator!=(DistanceTime& other)  {
    return !(*this == other);
}

DistanceTime::operator int() const {
    // Devuelve la suma de la distancia y el tiempo
    return distance;
}
DistanceTime::operator string() {
    // Devuelve la suma de la distancia y el tiempo
    string reponse =  "[";
    reponse += to_string(distance);
    reponse += " ";
    reponse += time.toString();
    reponse += "] ";
    return reponse;
}
string DistanceTime::toString() {
    // Devuelve la suma de la distancia y el tiempo
    string reponse =  "[ ";
    reponse += to_string(distance);
    reponse += "km ";
    reponse += time.toString();
    reponse += "h ] ";
    return reponse;
}


std::ostream& operator<<(std::ostream& os, DistanceTime& dtime) {
    
    os << "[ "<< dtime.distance << "km "<< dtime.time << "h ] ";

    return os;
}
