#include <iostream>
using namespace std;
#include "Node.h"

int main()
{  
    Node<int>* node1;
    node1 = new Node<int>(5);
    Node<int>* node2;
    node2 = new Node<int>(10, node1);

    cout << node1->data ; 
    return 0;
}
