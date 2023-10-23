#include <iostream>
using namespace std;
#include "Heap.h"

int main()
{
    vector<int> v1 = {3,8,1,87,3,5,53,4,1,2,3,45,6,6,7,8,5};
    Heap<int> heap1(v1);
    //Heap<int> heap2 = {6,5,4,3,2,1};

    heap1.print();
    //heap2.print();
    
    return 0;
}
