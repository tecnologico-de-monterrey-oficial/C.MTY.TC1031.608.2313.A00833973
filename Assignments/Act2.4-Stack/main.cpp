#include <iostream>

using namespace std; 

#include "Stack.h"

//Funcion para crear numeros aleatorios de tipo int
void createListInt(Stack<int> &list, int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        int num = rand() % 1000000 + 1;
        list.push(num);
    }
}

int main(){

    Stack<int> lista1; 
    int num = 0; 
    char opciones;

    cout << "Ingresa la cantidad de elementos que conformaran  la lista: "; 
    cin >> num; 

    cout << "Se creara la lista aleatoria: " << endl; 
    createListInt(lista1, num);

    lista1.print(); 
    cout << endl; 

    do {

        cout<< "Que deseas hacer con la lista: " << endl; 
        cout << "a) Agregamos un elemento a la pila " << endl; 
        cout << "b) Elimina el elemento arriba de la pila " << endl; 
        cout << "c) Regresa elelemento arriba de la pila " << endl; 
        cout << "d) Salir " << endl; 
        cout << "Elige: ";
        cin >> opciones; 
        cout << endl; 

        switch(opciones){
            case 'a':{
                int elemento = 0; 
                cout << "Escribe el elemento que deseas agregar: "; 
                cin >> elemento;
                cout << endl; 
                lista1.push(elemento);
                lista1.print();
                cout << endl; 
                break;
            }
            case 'b':{

                try{
                    
                    cout << "El elemento borrado es: " ;
                    cout << lista1.pop();
                    cout << endl; 
                    cout << "Lista con el dato borrado: " << endl;
                    lista1.print();
                    cout << endl; 
                }catch(out_of_range &e){
                    cout << e.what() << endl; 
                    cout << endl; 
                }
                break;
            }
            case 'c':{
                try{
                    cout << "El elemento arriba de la lista es: "; 
                    cout << lista1.top();
                    cout << endl;
                    cout << endl; 
                }catch(out_of_range &e){
                    cout << e.what() << endl; 
                    cout << endl; 
                }
                break;
            }
        }

    }while(opciones != 'd'); 


    return 0; 
}