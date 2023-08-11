#include <iostream>
using namespace std;

#include "Fraccion.h"

// Función para sumar 2 entero
int sumInt(int a, int b) {
    return a + b;
}

// Función para sumar 2 flotantes
float sumFloat(float a, float b) {
    return a + b;
}

// Función para sumar 2 srtings
string sumString(string a, string b) {
    return a + b;
}

// Fuinción para sumar 2 fracciones
Fraccion sumFraccion(Fraccion a, Fraccion b) {
    return a + b;
}

template<class T>
T sum(T a, T b) {
    return a + b;
}

int main()
{
    
    int a = 5;
    int b = 10;
    // int c = sumInt(a, b);
    int c = sum(a, b);
    cout << "a: " << a << " + b: " << b << " = c: " << c << endl;

    float x = 5.5;
    float y = 10.5;
    // float z = sumFloat(x,y);
    float z = sum(x,y);
    cout << "x: " << x << " + y: " << y << " = z: " << z << endl;

    string s1 = "5";
    string s2 = "10";
    // string s3 = sumString(s1,s2);
    string s3 = sum(s1,s2);
    cout << "s1: " << s1 << " + s2: " << s2 << " = s3: " << s3 << endl;

    Fraccion f1(1,2);
    Fraccion f2(1,3);
    Fraccion f3 = sum(f1,f2);

    cout << "f1: " << f1 << " + f2: " << f2 << " = f3: " << f3 << endl;


    return 0;
}