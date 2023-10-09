#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

#include "helperMain.h"

int main()
{
    string inFile = "log608-2.txt";
    string outFile1 = "output602-1.out";
    string outFile2 = "output602-2.out";
    string iprangea = "iprange602-a.out"; 
    string iprangeb = "iprange602-b.out"; 
    string logsMonth = "logsMoth.out";

    int option = -1;

    DoublyLinkedList<Log> list;
    DoublyLinkedList<Log> listRange;
    bool orderedIP = false;
    welcome();

    
    cout << endl << "Cargando "<< inFile <<" ... "; 
    readLogDocument<Log>( inFile , list);

    while (option != 6){
        menu(option);

        switch (option)
        {
        case 1:
        {
            cout << "Ordenando el archivo" << endl;

            if(orderedIP){
                list.sort(false);
                orderedIP = false;
            }
            

            cout <<"Escribiendo archivo ";
            writeFile(outFile1,list);
            cout << outFile1 << endl;

            break;
        }
        case 2:
        {
            cout << "Ordenando el archivo" << endl;

            if(!orderedIP){
                list.sort(true);
                orderedIP = true;
            }

            cout <<"Escribiendo archivo ";
            writeFile(outFile2,list);
            cout << outFile2 << endl;
            break;
        }
        case 3:
        {
            cout << "Ingresa los IP para los datos"<< endl;
            
            if(!orderedIP){   
                list.sort(true);
                orderedIP = true;
            }
            
            getRange(list, listRange);
            cout << "Escribiendo archivo " << iprangea << endl;
            writeFile(iprangea,listRange,true);

            break;
        }
        case 4:
        {
            cout << "Ingresa los IP para los datos"<< endl;
            
            if(!orderedIP){   
                list.sort(true);
                orderedIP = true;
            }
            
            getRange(list, listRange);
            cout << "Escribiendo archivo " << iprangeb << endl;
            writeFile(iprangeb ,listRange,false);

            break;
        }
        case 5:
        {
            cout << "Sumar Logs por mes" << endl;
            if(!orderedIP){
                list.sort(true);
                orderedIP = true;
            }
            sumarLogs(list,logsMonth);
        }
        default:
            break;
        }
    }
    return 0;
}


