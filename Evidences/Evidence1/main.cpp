// Nombre Valeria Pérez Alonso
// Matrícula A00833973
// Carrera Ingeniería en Tecnologías Computacionales
// Fecha 10 / Sep / 2023

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "Log.h"          // Incluye la definición de la clase Log
#include "Algorithms.h"   // Incluye funciones de algoritmos de ordenamiento
#include "mainHelper.h"   // Incluye funciones auxiliares para el programa principal

int main() {
    // Archivo de entrada
    string inText = "log608.txt";
    // Archivo de salida principal
    string fileOut = "output608.out";
    // Archivo de salida para el rango seleccionado
    string fileRange = "range608.out";

    // Lista de elementos de tipo Log (registros de log)
    vector<Log> logs;

    cout << endl << "LOG REGISTER OF ERRORS" << endl << endl;
    cout << "Reading document (" << inText << ") ... ";
    // Lee los registros de log del archivo de entrada y los almacena en el vector logs
    readLogDocument(inText, logs);
    cout << " [READY]" << endl << endl;

    cout << "Number of logs: " << logs.size() << endl << endl;

    cout << "Sorting...";
    // Ordena los registros de log utilizando el algoritmo de ordenamiento quicksort
    quickSort(logs);
    cout << " [READY]" << endl;

    cout << "Writing sorted document (" << fileOut << ")...";
    // Escribe los registros ordenados en un archivo de salida
    writeFile(fileOut, logs);
    cout << " [READY]" << endl;

    char control = 'a';
    cout << endl;
    cout << "Select by range? - [Y/N]: ";
    cin >> control;

    while (control == 'Y' || control == 'y') {
        vector<Log> logRange;
        // Obtiene un rango específico de registros de log
        getRange(logs, logRange);

        cout << "Writing file (" << fileRange << ")...";
        // Escribe los registros del rango seleccionado en un archivo de salida
        writeFile(fileRange, logRange);
        cout << " [READY]" << endl << endl;

        cout << "Select by range again? - [Y/N]: ";
        cin >> control;
    }

    cout << endl << "Close program" << endl;

    return 0;
}
