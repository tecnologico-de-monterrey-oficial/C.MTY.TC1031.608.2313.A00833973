#include <iostream>
using namespace std;


void printCiclesRestart(int& comparisions, int& swaps ){
    cout << "Comparisions: "<< comparisions << " Swaps: " << swaps <<endl ;
    comparisions = 0;
    swaps = 0;
}

template <class T>
void swap(vector<T>& list, int a, int b){
    if (list[a] != list[b]){
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}


template <class T>
int getPivot(vector<T>& list, int left, int right){
    int pivot = right;
    int aux = left - 1 ;
    //left - 1
    for (int i = left; i < right; i++){
        if(list[i] < list[pivot]){
            aux++;
            swap(list,i,aux);
        }
    }
    aux++;
    swap(list, pivot,aux);

    return aux;
}


template <class T>
void quickSort(vector<T>& list, int left, int right){
    if(left < right){
        int pivot = getPivot(list, left, right);
        quickSort(list,left, pivot-1);
        quickSort(list,pivot+1, right);
    }
    
}
