#include <iostream>
#include <vector>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
float getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return elapsed.count() * 1e-9;
    //printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000000 + 1;
    list.push_back(num);
  }
}

int binarySearch(vector<int> arr, int find){
   int s = arr.size() - 1;
    int c = 0;
    int i;
    
    while ((s - c ) >= 0){
        i = c + ( s - c )/2;

        // cout << "loop ";
        // cout << i << "-"<< arr[i] <<" ";

        if (arr[i] == find){
            return i;
        }
        else if (arr[i] < find){
            c = i+1;
        }
        else{
            s = i-1;
        }
    }
    return -1;

}
int sequencialSearch(vector<int> arr, int find){
  
  for (int i = 0; i < arr.size() - 1; i++){
    if (arr[i] == find){
      return i;
    }
  }
  return -1;
}

int main() {

    // Semilla para generar números aleatorios
    srand(time(0));
    // Variables para calcular el tiempo de ejecución
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    // Crear una lista de 1000000 de enteros
    vector<int> list;
    startTime(begin);
    createListInt(list, 1000000);
    getTime(begin, end);

    //Variables
    int input = -1;
    int binaryIndex = -1;
    int sequentialIndex = -1;
    float binaryTime = 0;
    float sequentialTime = 0;

    // for (int i = 0; i < 100; i++){
    //   cout << list[i] << " ";
    // }

    // for (int i = 0; i < 100; i++){
    //   cout << list[999999 - i] << " ";
    // }

    sort(list.begin(), list.end());

    // for (int i = 0; i < 100; i++){
    //   cout << list[i] << " ";
    // }

    // for (int i = 0; i < 100; i++){
    //   cout << list[999999 - i] << " ";
    // }

    while (input != 0){
      cout << endl << "Guest a number between 1 and 1 000 000"<< endl;
      cout << "Write 0 to exit" << endl << endl; 
      cout << "Number:\t"; 
      cin >> input;
      cout << endl;

      
      startTime(begin);
      binaryIndex = binarySearch(list,input);
      binaryTime = getTime(begin, end);

      startTime(begin);
      sequentialIndex = sequencialSearch(list,input);
      sequentialTime = getTime(begin, end);
      
      
      if (binaryIndex != -1){
        cout << "Binary Search"<< endl;
        cout << "Number found in index: " << binaryIndex << " Time: "<< binaryTime <<   endl;
        input = 0;
      }

      
      if (sequentialIndex != -1){
        cout << "Sequential Search" << endl;
        cout << "Number found in index: " << sequentialIndex << " Time: "<< sequentialTime <<   endl;
        input = 0;
      }

    } 

    return 0;

}