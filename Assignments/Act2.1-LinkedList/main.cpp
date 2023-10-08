//Valeria Pérez Alonso 
//A00833973
//PROGRAMA PRINCIPAL ACT2.1

#include <iostream>
using namespace std;
#include "helpermain.h"
#include <string>

int main()
{
    int  dataType = 0;
    int option = 0;

    cout << "Linked List"<< endl;
    menuDataType(dataType);
    bool showMenu = true; 
    
    switch (dataType)
        {
        case 1: // Menu con tipo de dato int
        {
            LinkedList<int> list;
            while (option != 14) // 14 salida del programa
            {
                menu(option);  // Obtener acción
                manipulateList(list, option); // Hacer la acción
            }  
            break;   
        }
            
        case 2: // Menu con tipo de dato char
        {
            LinkedList<char> list;
            while (option != 14)
            {
                menu(option);
                manipulateList(list, option);
            }
            break;
        }
    
        default:
            break;
        }
 
    return 0;
}
