#pragma once
#include "LinkedList.h"

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


void menuDataType(int& type){
    cout << endl;
    cout << "Choose data type"<<endl;
    while (type != 1 &&  type!= 2){
        cout << "1. INT"<<endl;
        cout << "2. CHAR" <<endl;
        cin >> type;
    }
}
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

template <class T>
void manipulateList(LinkedList<T>& list, int& option){
    
    switch (option)
    {
    case 0:
    {
        int size;
        cin >> size;
        createRandomList(list,size);
        list.print();
        break;
    }
    case 1:
    {
        cout << "Ingresa el dato: "<<endl;
        T data;
        cin >> data;
        list.addFirst(data);
        list.print();
        break;
    }
    case 2:
    {
        cout << "Ingresa el dato: "<<endl;
        T data;
        cin >> data;
        list.addLast(data);
        list.print();
        break;
    }
    
    case 3:
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
    
    case 4:
    {
        cout << "Ingresa dato a borrar: ";
        T data;
        cin >> data;
        list.deleteData(data);
        list.print();
        break;
    }

    case 5:
    {
        cout << "Ingresa índice a borrar: ";
        int index;
        cin >> index;
        list.deleteAt(index);
        list.print();
        break;

    }
    
    case 6:
    {
        cout << "Ingresa índice de la lista: ";
        int index;
        cin >> index;
        cout << list.getData(index) << endl;
        break;
    }

    case 7:
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

    case 8:
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
    
    case 9:
    {   
        cout << "Ingresa el dato a buscar: ";
        T data;
        cin >> data;
        cout << list.findData(data) << endl;

        break;
    }
    case 10:
    {   
        cout << "Ingresa el índice de la lista: ";
        int index;
        cin >> index;
        cout << list[index] << endl;
        break;
    }
    case 11:
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
    case 12:
    {    
        LinkedList<T> newCopy;
        createRandomList(newCopy, 5);

        list = newCopy;
        list.print();
        break;
    }
    case 13:
        list.print();
        break;
    default:
        break;
    }

  
}

// void eleccionInt(LinkedList<int> &list){
//     char eleccion; 
//     int tamanio = 0; 
//     int datoInt; 

//     cout << "Quieres hacer una lista random? [Y/n]"; 
//     cin >> eleccion; 

//     if (eleccion == 'Y'  eleccion == 'y'){
//         cout << "Escribe el tamaño de la lista: ";
//         cin >> tamanio; 

//         cout << endl; 
//         cout << "Espere..." << endl; 
//         cout << "Listo" << endl; 

//         cout << "La lista de tipo entero es: " << endl; 
//         createListInt(list, tamanio); 
//         list.print(); 
//         cout << endl; 
//     }else{
//         cout << endl; 
//         cout << "La lista sera con datos capturados"<< endl; 
//         cout << endl; 
//         cout << "Escribe el dato: "; 
//         cin >> datoInt; 
//         list.addLast(datoInt);
//         cout << "Desea escribir otro? [Y/n]" << endl;
//         cin >> eleccion; 
//         while(eleccion =='Y'  eleccion == 'y'){

//             cout << "Escribe el dato: "; 
//             cin >> datoInt; 
//             list.addLast(datoInt); 

//             cout << "Desea escribir otro? [Y/n]" << endl;
//             cin >> eleccion; 
//             }
//         cout << "Listo, la lista es: " << endl; 
//         list.print();
//         cout << endl;
//     }
// }