#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "HashStudentId.h"
using namespace std;

template <class T>
void printVector(vector<T> list){
    for(auto e:list){
        cout << e << endl;
    }
}

int main()
{
    ifstream fileIn("matriculas.txt");
    vector<string> list;
    string matricula;
    HashStudentId matri;
    while (getline(fileIn,matricula)) { 
        
        // Creamos una variable auxiliar ss para recorrer campo por campo
        stringstream ss(matricula);
        // Guardamos la información de cada campo en la variable auxiliar correspondiente
        ss >> matricula;
        list.push_back(matricula);
    }

    for (auto e:list){
       matri.insert(e);
    }

    matri.print();
    
    matri.erase("A00836129");
    
    for (auto e:list){
        cout << matri.FindStudentId(e) << endl;
    }
    // printVector(list); 
    // string text = "A0012232";
    // text = text.erase(0,1);
    // cout << stoi(text);

    cout << endl;
    //matri.print();
    return 0;
}
