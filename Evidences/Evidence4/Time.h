#pragma once

#include <sstream>
using namespace std;

struct Time
{
    int minutes;
    
    Time();
    Time(int);
    Time(string& hora);
    Time(int hours, int minutes);

    Time operator+(Time other);
    Time operator+(int minutes);
    Time operator-(Time other);
    Time operator-(int minutes);
    bool operator==(Time other);
    
    operator string();
    string toString();

};

Time::Time(){
    minutes = 0;
}
Time::Time(int min){
    minutes = min;
}

Time::Time(string& hora){
    //Format hh:mm
    stringstream ss(hora);
    string horaPart, minutoPart;

    // Leemos la hora y el minuto separados por ':'
    getline(ss, horaPart, ':');
    getline(ss, minutoPart);

    // Convertimos las partes a enteros
    int horas = stoi(horaPart);
    int minutos = stoi(minutoPart);

    // Calculamos el total de minutos
    this->minutes = horas * 60 + minutos;
}

Time Time::operator+(Time other) {
    
    return Time(minutes + other.minutes);
}

Time Time::operator+(int minutes) {
    return Time(this->minutes + minutes);
}

Time Time::operator-(Time other) {
    
    return Time(minutes + other.minutes);
}

Time Time::operator-(int minutes) {
    return Time(this->minutes + minutes);
}

bool Time::operator==(Time other){
    return minutes == other.minutes;
}
std::ostream& operator<<(std::ostream& os, Time& time) {
    // Calculamos las horas y minutos
    int hours = time.minutes / 60;
    int remainingMinutes = time.minutes % 60;

    // Imprimimos en formato "hh:mm"
    os << hours << ":" << remainingMinutes;

    return os;
}

Time::operator string() {
     // Devuelve la suma de la distancia y el tiempo
    int hours = minutes / 60;
    int remainingMinutes = minutes % 60;
    string min = to_string(remainingMinutes);
    if (remainingMinutes <10){
        min = "0" + min;
    }
    string stringTime =  to_string(hours) + ":" + min;
   
    return stringTime;
}

string Time::toString() {
    // Devuelve la suma de la distancia y el tiempo
    int hours = minutes / 60;
    int remainingMinutes = minutes % 60;
    string min = to_string(remainingMinutes);
    if (remainingMinutes <10){
        min = "0" + min;
    }
    string stringTime =  to_string(hours) + ":" + min;
   
    return stringTime;
}