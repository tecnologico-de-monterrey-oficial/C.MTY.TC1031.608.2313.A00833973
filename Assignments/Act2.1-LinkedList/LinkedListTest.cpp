#include <iostream>
using namespace std;
#include "LinkedList.h"

int main()
{
    LinkedList<string> list;

    list.addLast("Casa");
    list.addFirst("Olla");
    list.addFirst("Petro");
    list.addFirst("Gato");
    list.addFirst("Perro");
    list.addLast("Casa");
    list.insert(3,"-----");
    
    cout << list.findData("Casa")<<endl;
    list.updateData("Casa", "Casita");
    list.deleteData("-----");
    list.deleteAt(5);
    list.updateAt(0,"Hola");

    list.print();

    cout << endl;
    //list[0] = "Holii";
    cout << list[0];
    cout << endl;

    LinkedList<string> newList;
    newList.addFirst("a");
    newList.addLast("b");
    newList.addLast("c");
    newList.addLast("d");
    newList.addLast("e");

    list = newList;
    list.print();

    return 0;
}
