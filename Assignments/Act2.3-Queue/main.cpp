#include <iostream>

using namespace std; 

#include "Queue.h"

//Funcion para crear numeros aleatorios de tipo int
void createListInt(Queue<int> &list, int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        int num = rand() % 1000000 + 1;
        list.push(num);
    }
}

int main(){

    Queue<int> lista1; 
    int num = 0; 
    int option;

    cout << "Size of the list: "; 
    cin >> num; 

    cout << "Creating aleatory list...  " << endl; 
    createListInt(lista1, num);

    lista1.print(); 
    cout << endl; 

    do {

        cout<< "MENU " << endl; 
        cout << "1. Add element to the queue " << endl; 
        cout << "2. Delete top element " << endl; 
        cout << "3. Get top element" << endl; 
        cout << "4. Salir " << endl; 
        cout << "Op: ";
        cin >> option; 
        cout << endl; 

        switch(option){
            case 1:{
                int elemento = 0; 
                cout << "Value of new element: "; 
                cin >> elemento;
                cout << endl; 
                lista1.push(elemento);
                lista1.print();
                cout << endl; 
                break;
            }
            case 2:{

                try{
                    
                    cout << "Deleted element: " ;
                    cout << lista1.pop();
                    cout << endl; 
                    lista1.print();
                    cout << endl; 

                }catch(out_of_range &e){
                    cout << e.what() << endl; 
                    cout << endl; 
                }
                break;
            }
            case 3:{
                try{
                    cout << "Top element: "; 
                    cout << lista1.front();
                    cout << endl;
                    cout << endl; 
                }catch(out_of_range &e){
                    cout << e.what() << endl; 
                    cout << endl; 
                }
                break;
            }
        }

    }while(option != 4); 


    return 0; 
}