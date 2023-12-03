#include <iostream>
#include "mainHelper.h"
#include "GraphTC.h"
using namespace std;

int main(){
    string fileRead = "EuropeCities.csv";
    GraphTC graphTrain;
    GraphTC graphCar;

    cout << "Europe Cities" << endl;
    readFile(fileRead,graphTrain,graphCar);
    cout << "Archivo leido" << endl;

    int choice;

    while (true) {
        // Mostrar el menú
        cout << "\nMenu:" << endl;
        cout << "1. Ordenar nombre de ciudades\n";
        cout << "2. Ver lista de ciudades conectadas (adjacencias)\n";
        cout << "3. Ver recorridos de grafo\n";
        cout << "4. Ruta más corta\n";
        cout << "5. Salir\n\n";
        cout << "Ingrese su elección: ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
            case 1: {

                string outputFile = "output608-1";
                string text = graphTrain.sort();
                writeFile(outputFile,text);
                cout << "Elementos escritos en " << outputFile << endl;
                break;
            }
            case 2: {
                string outputFile = "output608-2";
                string text = graphTrain.adjacency();
                writeFile(outputFile,text);
                cout << "Elementos escritos en " << outputFile << endl;
                
                break;
            }
            case 3: {
                string ciudad;
                cout << "Escribe el nombre de la ciudad: " ;
                cin >> ciudad;
                string cabeza = "Recorrido BFS para " + ciudad + "\n\n"; 
                string outputFile = "output608-3";
                string text = cabeza + graphTrain.bfs(ciudad);
                writeFile(outputFile,text);
                cout << "Elementos escritos en " << outputFile << endl;
                

                cabeza = "Recorrido DFS para " + ciudad + "\n\n"; 
                outputFile = "output608-4";
                text = cabeza + graphTrain.dfs(ciudad);
                writeFile(outputFile,text);
                cout << "Elementos escritos en " << outputFile << endl;
               
                break;
            }
            case 4:{
                string ciudadA, ciudadB;
                cout << "Escribe el nombre de la ciudad de salida: " ;
                cin>> ciudadA;
                cout << "Escribe el nombre de la ciudad de llegada: ";
                cin >> ciudadB;

                cout << endl;
                cout << "Recorrido por tren " << endl;
                cout << graphTrain.dijkstra(ciudadA,ciudadB);
                cout << endl;

                cout << "Recorrido por carro" << endl;
                cout << graphCar.dijkstra(ciudadA,ciudadB);
                cout << endl;

                break;
            }
            case 5:{
                // Salir
                cout << "Saliendo del programa.\n";
                return 0;
            }
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    return 0;
}
