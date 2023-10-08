#include <iostream>
#include <string>
using namespace std;

#include "helperMain.h"

int main()
{
    DoublyLinkedList<string> list;
    DoublyLinkedList<string> list2;
    //cout << "Add first" <<endl;
    list.addFirst("a");
    list.addFirst("b");
    list.addFirst("a");
    list.addFirst("b");
    //cout << "Add Last"<<endl;
    list.addLast("c");

    cout << "Insert"<< endl;
    list.print();
    list.insert(0,"2");
    list.insert(1,"2");
    list.insert(4,"3");

    //cout << "Find data"<<endl;

    cout << list.findData("c")<< endl;

    list.deleteAt(0);
    list.deleteAt(3);
    list.deleteAt(5);
    list.removeBack();
    list.removeFront();

    list.updateData("b","a");
    list.updateAt(2,"5");

    list.addFirst("z");
    list.addLast("q");
    list.addLast("p");
    list.addLast("h");

    list.sort();
    list.print();

    cout << "Duplicate"<< endl;
    list.duplicate();
    list.print();
    list.removeDuplicate();
    list.print();
    
    list2 = list;
    list2.print();
    return 0;
}
