#include <iostream>
#include <string>
#include "DoublyLinkedList.h"

/**
 * @brief Lee un archivo de registro de log y lo almacena en una lista doblemente enlazada.
 * 
 * @param document Nombre del archivo de registro de log.
 * @param list Lista doblemente enlazada donde se almacenarán los registros de log..
 */
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

/**
 * @brief Escribe los datos de una lista doblemente enlazada en un archivo.
 * @param fileName Nombre del archivo en el que se escribirán los datos.
 * @param list Lista doblemente enlazada que contiene los datos a escribir.
 * @param asc Indica si los datos se deben escribir en orden ascendente (true) o descendente (false).
 * Complejidad: O(n) 
 */
template <class T>
void writeFile(string fileName, DoublyLinkedList<T>& list, bool asc) {
    ofstream file(fileName); // Abre el archivo

    if (file.is_open()) { // Comprueba si el archivo se abrió correctamente.
        DNode<T>* aux = (asc) ? list.getHead() : list.getTail(); // Inicializa el puntero auxiliar al principio o al final de la lista.

        while (aux != nullptr) { 
            file << aux->data; // Escribe el nodo en el archivo.

            // Mueve el puntero auxiliar hacia el siguiente nodo, dependiendo del orden especificado.
            aux = (asc) ? aux->next : aux->prev;
        }

        file.close();
        return; 
    } else {
        cout << "Unable to open file"; // En caso de que no se pueda abrir el archivo, muestra un mensaje de error.
    }
    file.close();
}


void writeFile(string fileName, DoublyLinkedList<Log>& list){
    writeFile(fileName,list,true);
}


void welcome(){
    cout << "ERROR REGISTER LOG" << endl;
}

//Complejidad O(1)
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

/**
 * @brief Solicita al usuario un valor de IP y crea un objeto Log con ese valor.
 * Complejidad O(1)
 * @return Objeto Log creado a partir del valor de IP proporcionado por el usuario.
 */
Log askLogIP(){
    string ip;

    cout << "Introduce el IP Formato 000.000.000.000" << endl << "IP: ";
    cin  >> ip;
    Log newLog = Log("", "", "", "", ip, "");
    return newLog;
}


/**
 * @brief Busca el índice del nodo en una lista doblemente enlazada que tenga el valor de IP más cercano
 * o igual al valor de IP en el objeto "find".
 * Complejidad O(n)
 * @param list Lista doblemente enlazada en la que se realizará la búsqueda.
 * @param find Objeto Log con el valor de IP a buscar.
 * @return Índice del nodo en la lista que contiene el valor de IP más cercano o igual al valor de IP en "find".
 */
int findNear(DoublyLinkedList<Log>& list, Log &find){

    DNode<Log>* aux = list.getHead();
    int i = 0;

    while(aux->data.keyIP < find.keyIP) //Aumenta el apuntador mientras el valor no sobrepase al de la busqueda
    { 
        if (aux->next == nullptr){
            return i;
        }
        else{
            aux = aux->next;
        }
        i++;
    }
    return i; //Regresa el indice hasta donde realizó la busqueda
}



/**
 * @brief Obtiene una lista de registros de log que se encuentran en el rango de IP especificado por el usuario.
 * Complejidad O(n)
 * @param list Lista de registros de log en la que se buscarán los registros en el rango de IP.
 * @param rangeList Lista de registros de log donde se almacenarán los registros encontrados en el rango.
 */
void getRange(DoublyLinkedList<Log>& list, DoublyLinkedList<Log>& rangeList){ 
    
    rangeList.clear(); //Limpia la lista por si cuenta con elementos

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


/**
 * @brief Calcula y escribe en un archivo la suma de registros por mes en una lista de registros de log.
 * Complejidad O(n^2)
 * @param list Lista de registros de log en la que se realizará la suma de registros por mes.
 * @param fileName Nombre del archivo en el que se escribirá el resultado.
 */
void sumarLogs(DoublyLinkedList<Log> & list, string fileName){
    ofstream file(fileName);
    if (file.is_open())
    {
        DNode<Log> * aux = list.getHead() ;
        int total = 0;
        while (aux != nullptr){
            //Escribe el año y mes 
            file << "Date: " << aux->data.year << " " << aux->data.month;
            int i = 1;
            bool continu = true;

            //Mientras no cambie el mes se aumentará el contador 
            while(aux->next != nullptr && continu){
                if(aux->data.month == aux->next->data.month){
                    aux = aux->next;
                    i++;
                }
                else{
                    continu = false; //Stop del bucle
                }
            }

            file << " Logs: " << i << endl;
            aux = aux->next;
            total += i;
        }
        file << "Total de registros " << total << "\n";
        file.close();
        return;
    }
    else cout << "Unable to open file";
}