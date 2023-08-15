#include <iostream>
#include "recursiveFunctions.h"
using namespace std;
int main()
{
    int value = 3; 
    float amount = 10;
    cout << "Iteractive / Recursive / Formula" << endl;
   
    cout << "Factorial" << endl;
    cout << factorialIterative(value) << "\t" << factorial(value) << endl;
    cout << endl;

    cout << "Sum" << endl;
    cout << sumIterative(value) << "\t" << sumRecursive(value) << "\t" << sumFormula(value) <<endl;
    cout << endl;

    cout << "Fibonnaci"<< endl;
    for (int i = 1; i <= 6; i++){
        cout << fibonnacciIterative(i) << "\t" << fibonnacciIterative(i)<< endl;
    }
    cout << endl;

    cout << "Bacterias" << endl;
    cout << bacteriasIterative(value) << "\t" << bacteriasRecursive(value) <<endl;
    cout << endl;

    cout << "Investment" << endl;
    cout << investmentIteractive(amount, 10) << "\t" << investmentRecursive(amount, 10)  <<endl;
    cout << endl;

    cout << "Pow" << endl;
    cout << powIteractive(10, 3) << "\t" << powRecursive(10, 3)  <<endl;
    cout << endl;
    return 0;
}
