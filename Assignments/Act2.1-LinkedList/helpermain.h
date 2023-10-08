#pragma once
#include "LinkedList.h"


//añade elementos random a la lista, dada cierta cantidad;

template <class T>
void createRandomList(LinkedList<T>& list, int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        int r = rand() % 90 + 33;
        T num = T(r);
        list.addLast(num); 
    }
}


//Menu visual para el usuario sobre la elección del 
//tipo de dato a escoger
void menuDataType(int& type){
    cout << endl;
    cout << "Choose data type"<<endl;
    while (type != 1 &&  type!= 2){
        cout << "1. INT"<<endl;
        cout << "2. CHAR" <<endl;
        cin >> type;
    }
}

//Menu de opciones para el usuario 
void menu(int& option ){
    option = -1;
    while (option < 0 || option>14){
        cout << endl;
        cout << "OPTION MENU"<<endl;
        cout << "--------------"<<endl;
        cout << "0. Create Random List" << endl;
        cout << "1. Add element first"<<endl;
        cout << "2. Add element at the end"<<endl;
        cout << "3. Insert in position" << endl;
        cout << "4. Delete element by data "<< endl;
        cout << "5. Delete element by position"<<endl;
        cout << "6. Get Data by position"<<endl;
        cout << "7. Update Data"<<endl;
        cout << "8. Update data by position"<<endl;
        cout << "9. Find data"<<endl;
        cout << "10. Get data []"<<endl;
        cout << "11. Update data []"<< endl;
        cout << "12. Match list" << endl;
        cout << "13. Print" <<endl;
        cout << "14. Exit"<<endl;
        cin >> option;
    }
}

/// @brief Menu de opciones
/// @tparam T 
/// @param list  LinkedList
/// @param option int
template <class T>
void manipulateList(LinkedList<T>& list, int& option){
    
    switch (option)
    {
    case 0: //Crea elementos random en la lista
    {
        int size;
        cin >> size;
        createRandomList(list,size);
        list.print();
        break;
    }
    case 1:
    { //Agrega un elemento al principio de la lista
        cout << "Ingresa el dato: "<<endl;
        T data;
        cin >> data;
        list.addFirst(data);
        list.print();
        break;
    }
    case 2: // Agrega un elemento al final de lista
    {
        cout << "Ingresa el dato: "<<endl;
        T data;
        cin >> data;
        list.addLast(data);
        list.print();
        break;
    }
    
    case 3: //Inserta un dato en la posición data
    {
        cout << "Ingresa la posición: " <<endl;
        int index;

        cin >> index;
        cout << "Ingresa el dato: "<<endl;

        T data;
        cin >> data;

        list.insert(index,data);
        list.print();
        break;
    }
    
    case 4: // Borra dato dado su valor
    {
        cout << "Ingresa dato a borrar: ";
        T data;
        cin >> data;
        list.deleteData(data);
        list.print();
        break;
    }

    case 5: //Borra dato dada su posición
    {
        cout << "Ingresa índice a borrar: ";
        int index;
        cin >> index;
        list.deleteAt(index);
        list.print();
        break;

    }
    
    case 6: // Obtiene un dato dependiendo del índice dado
    {
        cout << "Ingresa índice de la lista: ";
        int index;
        cin >> index;
        cout << list.getData(index) << endl;
        break;
    }

    case 7: // Remplaza dado dato con uno ingresado por el usuario
    {
        cout << "Ingresa dato a remplazar: ";
        T buscar;
        cin >> buscar;
        cout << "Ingresa dato de remplazo: ";
        T remplazo;
        cin >> remplazo;
        list.updateData(buscar,remplazo);
        list.print();
        break;
    }

    case 8: // Remplaza dato dada la posición con valor ingresado por el usuario
    { 
        cout << "Ingresa posición para remplazar: ";
        int index;
        cin >> index;

        cout << "Ingresa dato para remplazar: ";
        T data;
        cin >> data;

        list.updateAt(index,data);
        list.print();

        break;
    }
    
    case 9: // Busca la posición en la que se encuetra un dato, si no encuentra regresa -1
    {   
        cout << "Ingresa el dato a buscar: ";
        T data;
        cin >> data;
        cout << list.findData(data) << endl;

        break;
    }
    case 10: //Regresa el dato por medio de [] dado en index
    {   
        cout << "Ingresa el índice de la lista: ";
        int index;
        cin >> index;
        cout << list[index] << endl;
        break;
    }
    case 11: // Remplada dato dado un indice [] y lo remplaza por un dato dado por usuario =
    {
        cout << "Ingresa el índice a remplazar: ";
        int index;

        cin >> index;
        cout << "Ingresa dato de remplazo";
        T data;
        cin >> data;

        list[index] = data;
        list.print();
        break;
    }
    case 12: //Iguala una segunda lista con una nueva con 5 valores random
    {    
        LinkedList<T> newCopy;
        createRandomList(newCopy, 5);

        list = newCopy;
        list.print();
        break;
    }
    case 13: // Imprime la lista
        list.print();
        break;
    default:
        break;
    }

}