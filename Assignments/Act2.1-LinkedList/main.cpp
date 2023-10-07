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
        case 1:
        {
            LinkedList<int> list;
            while (option != 14)
            {
                menu(option);
                manipulateList(list, option);
            }  
            break;   
        }
            
        case 2:
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
