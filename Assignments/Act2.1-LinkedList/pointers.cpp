#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int *p = new int;
    *p = a;

    int *q = &a;

    a = 10;
    
    cout << "a: "<< a << endl;
    cout << "&a:" << &a <<endl;
    cout << "p: " << p << endl;
    cout << "&p: " << &p << endl;
    cout << "*p: " << *p << endl; 

    
    cout << "q: " << q << endl;
    cout << "&q: " << &q << endl;
    cout << "*q: " << *q << endl;
     
    //system("pause");
    return 0;
}
