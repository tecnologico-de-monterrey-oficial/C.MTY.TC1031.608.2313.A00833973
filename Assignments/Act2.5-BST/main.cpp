#include <iostream>
using namespace std;

#include "BST.h"

int main() {

    BST<int> bst;
    bst.insert(20);
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(30);
    bst.insert(25);
    bst.insert(40);
    bst.print();
    bst.find(76);
    
    return 0;
}