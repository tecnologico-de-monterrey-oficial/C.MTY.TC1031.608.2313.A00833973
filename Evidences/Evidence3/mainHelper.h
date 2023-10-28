#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

#include "Log.h"
#include "IPAmount.h"
#include "AmountIP.h"
#include "Heap.h"
#include "MinHeap.h"
#include "BST.h"


void readFile(string document, vector<Log>& list){
    // Variable auxiliar para guardar el contenido del renglón leido
    string line;
    // Variable auxiliar para guardar el contenido de cada palabra del campo message
    string word;
    // Variables auxiliares para guardar el contenido de cada campo del archivo
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;

    ifstream fileIn(document);
    // Ciclo para leer todo los renglones del archivo de entrada
    while (getline(fileIn,line)) { 

        // Creamos una variable auxiliar ss para recorrer campo por campo
        stringstream ss(line);
        // Guardamos la información de cada campo en la variable auxiliar correspondiente
        ss >> month >> day >> year >> time >> ip >> message;
        // Ciclo para recorrer cada palabra del campo message
        while (ss >> word) {
            message = message + " " + word;
        }
        //Se crea el objeto y se agrega a la lista
        Log log(year, month, day, time, ip, message);
        list.push_back(log);
    }
}

template <class T>
void print(vector<T> list) {
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}

/**
 * @brief Escribe los datos de una lista doblemente enlazada en un archivo.
 * @param fileName Nombre del archivo en el que se escribirán los datos.
 * @param list Lista doblemente enlazada que contiene los datos a escribir.
 * Complejidad: O(n) 
 */
template <class T>
void writeFile(string fileName, vector<T> list) {
    ofstream file(fileName); // Abre el archivo

    if (file.is_open()) { // Comprueba si el archivo se abrió correctamente.
        for (auto e:list){
            file << e;
        }
        file.close();
        return; 
    } else {
        cout << "Unable to open file"; // En caso de que no se pueda abrir el archivo, muestra un mensaje de error.
    }
    file.close();
}
template <class T>
void print(vector<T> list, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
}

// Heap Sort
template <class T>
void heapSort(vector<T> &list, string order) {
    if (order == "desc") {
        // Creamos un heap en base a la lista
        Heap<T> heap(list);
        // Ciclo para sacar todos los elementos del heao y agregarlos a la lista
        for (int i=0; i<list.size(); i++) {
            list[i] = heap.pop();
        }
    } else {
        if (order == "asc") {
            // Creamos un heap en base a la lista
            MinHeap<T> heap(list);
            // Ciclo para sacar todos los elementos del heao y agregarlos a la lista
            for (int i=0; i<list.size(); i++) {
                list[i] = heap.pop();
            }
        } 
    }
}




//Sumar logs
/**
 * @brief Calcula y escribe en un archivo la suma de registros por mes en una lista de registros de log.
 * Complejidad O(n^2)
 * @param list Lista de registros de log en la que se realizará la suma de registros por mes.
 * @param fileName Nombre del archivo en el que se escribirá el resultado.
 */
void sumLogs(vector<Log> list, vector<IPAmount> & amountList){
    int amount = 0;
    for (int i = 0; i < list.size(); i++){
        amount ++;
        if (list[i+1].ip != list[i].ip){
            IPAmount element(list[i].ip,amount);
            amountList.push_back(element);
            amount = 0;
        }
    }
}

void sumLogsIP(vector<Log> list, vector<AmountIP> & amountList){
    int amount = 0;
    for (int i = 0; i < list.size(); i++){
        amount ++;
        if (list[i+1].ip != list[i].ip){
            AmountIP element(list[i].ip,amount);
            amountList.push_back(element);
            amount = 0;
        }
    }
}
//Get 10 IP

void top10(vector<Log>& list, vector<IPAmount> & amountList){
    sumLogs(list, amountList);
    heapSort(amountList, "desc");

    //print(amountList, 10);
}


//Cantidad de elementos por busqueda binaria en un BST
template <class T> 
void createBST(vector<T> list, BST<T> & bst){
    for (auto e: list){
        bst.insert(e);
    }
}


int findBST(BST<AmountIP> bst, string ip){
    TNode<AmountIP>* aux = bst.getRoot();
    while(aux != nullptr){
         if (ip == aux->data.ip) {
            return aux->data.amount;
        } else {
            ip < aux->data.ip ? aux = aux->left : aux = aux->right;
        }
    }
    return -1;

}

void find(vector<Log> list){
    vector<AmountIP> amount_list;
    BST<AmountIP> bst;
    string ip; 
    int amount;

    sumLogsIP(list, amount_list);
    createBST(amount_list, bst);
    cout << "Ip: " ;
    cin >> ip;
    amount = findBST(bst, ip);

    cout << endl;
    if (amount != -1){
        cout << "El IP "<< ip << " tiene " << amount << " registros" << endl;
    }
    else{
        cout << "No se encontraron registros para el IP " << ip << endl;
    }

}

