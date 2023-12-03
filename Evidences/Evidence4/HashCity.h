
#ifndef HashCity_h
#define HashCity_h

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HashCity {
private:
    vector<string> table;
    int hash(string city);
    vector<bool> status;
    int size;
public:
    HashCity();
    int insert(string city);
    void remove(string city);
    int findCity(string city);
    int Size(){return size;}
    string city(int index);
    void print();
};

HashCity::HashCity() {
    size = 101;
    table.resize(size);
    status.resize(size, false);
}

string HashCity::city(int index){
    return table[index];
}

int HashCity::hash(string city){
    int hashValue = 0;
    // Sumamos los códigos ASCII de los caracteres en el nombre de la ciudad
    for (char c : city) {
        hashValue += static_cast<int>(c) + 12;
    }
    hashValue = (hashValue * 314 / 5) % size;

    return hashValue;
}


int HashCity::insert(string city) {
    int find = findCity(city);
    if (find !=-1){
        throw out_of_range("El dato existe en la tabla");
    }
    int index = hash(city);
    // Validamos que el espacio en la tabla en index este vacio
    if (table[index].empty()) {
        table[index] = city;
        status[index] = true;
        return index;
    } else {
        int newIndex = index;
        // Recorro la tabla mientras no le de la vuelta y hasta que ecuentre un espacio vacio
        do{
            if(table[newIndex] == city){
                return -1;
            }
            newIndex = (newIndex + 1) % table.size();
        }
        while (newIndex != index && !table[newIndex].empty());

        // Validamos que si hubo un espacio vacío
        if (newIndex != index) {
            table[newIndex] = city;
            return newIndex;
        } else {
            throw out_of_range("La tabla esta llena");
        }
        
    }
}

int HashCity::findCity(string city) {
    int index = hash(city);
    if (table[index] == city) {
        return index;
    } else {
        // Hay que buscarlo en la tabla
        // Recorremos la tabla hasta encontrarlo o encontrar un elemento vacío o le damos la vuelta
        int newIndex = (index+1)%table.size();
        while (newIndex != index && (!table[newIndex].empty() || status[newIndex])) {
            // Validamos si lo encontramos
            if (table[newIndex] == city) {
                return newIndex;
            } else {
                newIndex = (newIndex+1)%table.size();
            }
        }
        return -1;
    }
}

void HashCity::remove(string city) {
    int index = findCity(city);
    if (index != -1) {
        table[index] = "";
        status[index] = true;
    } else {
        throw invalid_argument("El valor a borrar no se encuentra");
    }
}

void HashCity::print() {
    for (int i=0; i<table.size(); i++) {
        cout << i << ": " << table[i] << endl;
    }
    cout << endl;
}


#endif /* HashCity_h */