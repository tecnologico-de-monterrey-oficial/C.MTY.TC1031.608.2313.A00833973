#include <iostream>
#include <vector>
using namespace std;

#include "List.h"

int main() {
    List<int> list;

    list.insert(5);
    list.insert(10);
    list.insert(15);

    list.print();

    list.removeLast();
    list.removeLast();
    list.removeLast();
    try {
        list.getData(4);
    }
    catch(const out_of_range& e){
        cout << e.what();
    }
    
    return 0;
}