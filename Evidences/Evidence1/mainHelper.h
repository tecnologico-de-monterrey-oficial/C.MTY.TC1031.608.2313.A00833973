// Nombre Valeria Pérez Alonso
// Matrícula A00833973
// Carrera Ingeniería en Tecnologías Computacionales
// Fecha 10 / Sep / 2023

//Este archivo contiene las funciones utilizadas en el main
//
//WriteFile(string, string)
//getRange(vector<Log>, vector<Log>&)
//readLogDocument(string, vector<Log>&)

#pragma once

//printVector
//Orden O(1)
//Muestra en pantalla el vector

template <class T>
void printVector(vector<T> list){
    for (auto e: list){
        cout << e;
    }
    cout << endl;
}

//writeFile
//Orden O(n)
//Crea o abre un documento con el nombre _fileName_
//Y escribe sobre él los elementos de _list_
template <class T>
void writeFile(string fileName, vector<T> list){
    ofstream file(fileName);
     if (file.is_open())
    {
        for(int i = 0; i<list.size(); i++){
            file<< list[i];
        }
        file.close();
    }
    else cout << "Unable to open file";
}

//Helper askData
//Orden O(n)
//Muestra el mensaje _text_ 
//Guarda por referencia _data_
//Y valida que el tamaño sea igual a _size_
void askData(string& data, string text, int size){
    int currentSize = 0;
    while (currentSize != size){
        cout << text;
        cin >> data;
        currentSize = data.size();
    }
}

//Helper askLogTime
//Orden == askData == O(n)
//Pide al usuario los datos necesarios para crear 
//un objeto Log para comparar la key
Log askLogTime(){
    string year;
    string month;
    string day;
    string time;

    cout << "Introduce the next data"<<endl;
    cout << "Example: Aug 29 2023 12:43:52" << endl<<endl;
    askData(month,"Month (Mmm): ",3);
    askData(day,"Day (dd): ",2);
    askData(year,"Year (yyyy): ",4);
    askData(time,"Time (hh:mm:ss): ",8);
    cout << endl;
    Log newLog = Log(year, month, day, time, "", "");
    return newLog;
}

//getRange
//Orden O(n)

void getRange(vector<Log> list, vector<Log>& rangeList){
    //Pide los datos del límite inferior y superior donde se realizará la busqueda
    cout << endl;
    cout << "Left limit" << endl<<endl;
    Log left = askLogTime();

    cout << "Right limit" << endl<<endl;
    Log right = askLogTime();

    //Realiza la busqueda con aquellos límites
    cout << "Searching...";
    int leftIndex = binarySearch(list, left);
    int rightIndex = binarySearch(list, right);
    
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
    for (int i = leftIndex ; i < rightIndex + 1; i++){
        rangeList.push_back(list[i]);
    }
    cout << "[READY]"<<endl;
}

//readLogDocument
//Orden O(n)
void readLogDocument(string document, vector<Log>& list){
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