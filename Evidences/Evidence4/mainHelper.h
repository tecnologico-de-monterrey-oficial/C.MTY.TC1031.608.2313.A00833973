#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "GraphTC.h"
#include "Edge.h"
#include "Time.h"
#include "DistanceTime.h"
// Tu clase HashCity y cualquier otra declaración necesaria

//readFile

void readFile(string filename, GraphTC& graphTrain, GraphTC& graphCar){

    ifstream fileIn(filename);
    if (fileIn.is_open()) {
        // Leer la primera línea (encabezado) para ignorarla
        std::string header;
        getline(fileIn, header);

        // Leer cada línea restante del archivo
        std::string line;
        while (getline(fileIn, line)) {
            // Utilizar stringstream para dividir la línea en campos
            std::stringstream ss(line);
            std::string cityA, cityB, timeTrain, distTrain, timeCar, distCar;

            // Leer los nombres de las ciudades (City A y City B)
            getline(ss, cityA, ',');
            getline(ss, cityB, ',');
            getline(ss, timeTrain, ',');
            getline(ss, distTrain, ',');
            getline(ss, timeCar, ',');
            getline(ss, distCar, ',');

            try
            {
                graphTrain.addCity(cityA);
                graphTrain.addCity(cityB);

                graphCar.addCity(cityB); 
                graphCar.addCity(cityA);
            }
            catch(const std::exception& e)
            {
                //std::cerr << e.what() << '\n';
            }

            try
            {
                DistanceTime dtT(stoi(distTrain),timeTrain);
                DistanceTime dtC(stoi(distCar),timeCar);
                graphTrain.addEdge(cityA,cityB, dtT);
                graphCar.addEdge(cityA,cityB, dtC);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }

        // Cerrar el archivo después de leer
        fileIn.close();
    } else {
        std::cerr << "No se pudo abrir el archivo ciudades.csv" << std::endl;
    }

}

void writeFile(string fileName, string write) {
    ofstream file(fileName); // Abre el archivo

    if (file.is_open()) { // Comprueba si el archivo se abrió correctamente.
        file << write;
        file.close();
        return; 
    } else {
        cout << "Unable to open file"; // En caso de que no se pueda abrir el archivo, muestra un mensaje de error.
    }
    file.close();
}