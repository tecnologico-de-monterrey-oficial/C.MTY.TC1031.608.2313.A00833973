#include <iostream>
#include "mainHelper.h"
using namespace std;

int main()
{
    
    string logFile = "log608-3.txt";
    vector<Log> list;
    vector<IPAmount> ip_amount;
    int option = -1;
    bool orderasc = false;
    bool orderdesc = false;

    cout << "LOG REPORT" << endl;
    cout << endl;
    cout << "Leyendo archivo";
    readFile(logFile, list);
    cout << " [Completado]" << endl;
    cout << "Hay " << list.size() << " registros"<<  endl;
    cout << endl;
    
    while (option != 5){
        cout << endl; 
        cout << "Menu" << endl;
        cout << "1. Ordena los datos por IP, fecha y hora de mayor a menor." << endl;
        cout << "2. Ordena los datos por IP, fecha y hora de mayor a menor." << endl;
        cout << "3. 10 ip's con mayor número de registros " << endl;
        cout << "4. Búsqueda de una ip en un árbol binario de búsqueda" << endl;
        cout << "5. Salir" << endl;
        cout << endl;
        cout << "Opción: " ;
        cin >> option;
        cout << endl;

        switch (option)
        {
        case 1:{
                //Ordenar asc
            if (orderasc){
                cout << "Ya se encuentra ordenado de manera ascendente." << endl;
            }else{
                heapSort(list,"asc");
                writeFile("output608-1.out", list);
            }
            cout << "Archivo escrito (output608-1.out)"<< endl;
            orderasc = true;
            orderdesc = false;
            break;
        }
        case 2:{
            if (orderdesc){
                cout << "Ya se encuentra ordenado de manera descendente." << endl;
            }
            else{
                heapSort(list,"desc");
                writeFile("output608-2.out", list);  
            }
            cout << "Archivo escrito (output608-2.out)"<< endl;
            orderasc = false;
            orderdesc = true;
            break;
        }
        case 3:{
            cout << "Registros" << endl << endl;
            cout << " ";
            if (!(orderasc || orderdesc)){
                heapSort(list,"desc");
            }
            top10(list, ip_amount);
            print(ip_amount,10);

            break;
        }
        case 4:{
            if (!(orderasc || orderdesc)){
                heapSort(list,"desc");
            }
            find(list);
            break;
        }
        case 5:{
            cout << "Saliendo." << endl;
            break;
        }
        default:
            cout << "Opción no reconocida." << endl; 
            break;
        }
    }
    
    return 0;
}
