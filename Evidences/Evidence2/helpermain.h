#include <iostream>
#include <string>
#include "DoublyLinkedList.h"

template <class T>
void readLogDocument(string document, DoublyLinkedList<Log>& list){
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
        list.addLast(log);
    }
}

template <class T>
void writeFile(string fileName, DoublyLinkedList<T>& list, bool asc){
    ofstream file(fileName);
    if (file.is_open())
    {
        DNode<T> * aux = (asc)? list.getHead() : list.getTail();
        
        while (aux != nullptr){
            file<< aux->data;
            aux = (asc)? aux->next : aux->prev;
        }
        file.close();
        return;
    }
    else cout << "Unable to open file";
}

void writeFile(string fileName, DoublyLinkedList<Log>& list){
    writeFile(fileName,list,true);
}


void welcome(){
    cout << "ERROR REGISTER LOG" << endl;
    //system("pause");
}

void menu(int& option){
    cout << endl;
    cout << "MENU"<< endl<<endl;
    cout << "1. Ordenar por fecha y hora" << endl;
    cout << "2. Ordenar por IP, fecha y hora" << endl;
    cout << "3. Obtener IP por rango (ascendente)" << endl;
    cout << "4. Obtener IP por rango (descendente)" << endl;
    cout << "5. Sumar registros" << endl;
    cout << "6. Salir" << endl;
    cout << "Opcion: ";
    cin  >> option;
    cout << endl;
}

Log askLogIP(){
    string ip;

    cout << "Introduce el IP"<<endl;
    cout << "000.000.000.000" << endl << "Dato: ";
    cin  >> ip;
    Log newLog = Log("", "", "", "", ip, "");
    return newLog;
}

//FIND

int findNear(DoublyLinkedList<Log>& list, Log &find){

    DNode<Log>* aux = list.getHead();
    int i = 0;

    while(aux->data.keyIP < find.keyIP){
        if (aux->next == nullptr){
            return i;
        }
        else{
            aux = aux->next;
        }
        i++;
    }
    return i;
}


void getRange(DoublyLinkedList<Log>& list, DoublyLinkedList<Log>& rangeList){
    //Pide los datos del límite inferior y superior donde se realizará la busqueda
    cout << endl;
    cout << "Left limit" << endl<<endl;
    Log left = askLogIP();

    cout << "Right limit" << endl<<endl;
    Log right = askLogIP();
    cout << endl;

    //Realiza la busqueda con aquellos límites
    cout << "Searching...";
    int leftIndex = findNear(list, left);
    int rightIndex = findNear(list, right);

    //En caso que los índices dados se encuentren fuera del rango
    //Se realiza el ajuste correspondiente
    if (list[leftIndex] < left){
        leftIndex++;
    }
    if(list[rightIndex] > right){
        rightIndex--;
    }

    //Se ocupan los índices como límites y se pasan los 
    //registros contando los índices
    DNode<Log>* aux = list.getHead();
    for (int i = 0; i < leftIndex; i++){
        aux = aux->next;
    }

    for (int i = leftIndex ; i < rightIndex + 1; i++){
        rangeList.addLast(aux->data);
        aux = aux->next;
    }
    cout << "[READY]"<<endl;
}


void sumarLogs(DoublyLinkedList<Log> & list, string fileName){
    ofstream file(fileName);
    if (file.is_open())
    {
        DNode<Log> * aux = list.getHead() ;
        int total = 0;
        while (aux != nullptr){
            file << "Logs: " << aux->data.year << " " << aux->data.month;
            int i = 1;
            bool continu = true;
            while(aux->next != nullptr && continu){
                if(aux->data.month == aux->next->data.month){
                    aux = aux->next;
                    i++;
                }
                else{
                    continu = false;
                }
            }
            file << " Registros: " << i << endl;
            aux = aux->next;
            total += i;
        }
        file << "Total de registros " << total << "\n";
        file.close();
        return;
    }
    else cout << "Unable to open file";
}