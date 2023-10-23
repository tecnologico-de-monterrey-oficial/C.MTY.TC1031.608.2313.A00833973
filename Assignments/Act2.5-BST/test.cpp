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
    bst.remove(20);
    bst.print();
    bst.remove(30);
    bst.print();
    bst.visit(1);
    bst.visit(2);
    bst.visit(3);
    bst.visit(4);
    bst.insert(5);
    bst.insert(15);
    bst.insert(30);
    bst.insert(25);
    bst.insert(40);
    cout <<bst.find(23213123);
    cout << endl;
    cout << bst.height() <<endl;
    bst.print();
    bst.ancestors(25);
    bst.insert(100);
    bst.ancestors(10540);
    cout << bst.whatLevelAml(100) << endl;
    cout << bst.height() <<endl;
    bst.print();

    return 0;
}