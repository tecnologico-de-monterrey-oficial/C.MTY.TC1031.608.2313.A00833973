// Nombre Valeria Pérez Alonso
// Matrícula A00833973
// Carrera Ingeniería en Tecnologías Computacionales
// Fecha 10 / Sep / 2023

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "Log.h"
#include "Algorithms.h"
#include "mainHelper.h"

int main() {

    // Archivo de entrada
    string inText = "log608.txt";
    ifstream fileIn(inText);
    // Archivo de salida
    string fileOut = "output608.out";
    string fileRange = "range608.out";

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

    // Lista de elementos
    vector<Log> logs;
    // Variable auxiliar para guardar el contador de registros
    int cont = 0;
    cout << "LOG REGISTER OF ERRORS" << endl << endl;
    cout << "Reading: " << inText << endl;
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

        Log log(year, month, day, time, ip, message);
        logs.push_back(log);

        // Incrementamos el contador de registros
        cont++;

    }
    cout << "Sorting..."<< endl;
    quickSort(logs);
    
    cout << "Amount of logs: " << cont << endl;
    cout << "Writing sorted document..."<<endl;
    writeFile(fileOut,logs);

    char control = 'a';

    cout << "Select by range - [Y/N]: " ;
    cin >> control;
    
    while (control == 'Y' || control == 'y'){

        vector<Log> logRange;


        getRange(logs, logRange);

        cout << "Writing file..."<<endl;
        writeFile(fileRange, logRange);

        cout << "File ready"<<endl<<endl;
        cout << "Select by range again? - [Y/N]: " ;
        cin >> control;
    }
    

    cout << "Close"<<endl;

    return 0;
}