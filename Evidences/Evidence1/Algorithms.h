#pragma once
#include <chrono>
#include <bits/stdc++.h>
using namespace std;

template <class T>
int binarySearch(vector<T> list, T find){
    int right = list.size() - 1;
    int left = 0;
    int i;
    
    while ((right - left) >= 0){
        i = left + ( right - left)/2;

        if (list[i] == find){
            return i;
        }
        else if (list[i] < find){
            left = i+1;
        }
        else{
            right = i-1;
        }
    }
    return i;

}

template <class T>
void printVector(vector<T> list){
    for (auto e: list){
        cout << e;
    }
    cout << endl;
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
void quick(vector<T>& list, int left, int right){
    if(left < right){
        int pivot = getPivot(list, left, right);
        quick(list, left, pivot-1);
        quick(list, pivot+1, right);
    }
    
}

template <class T>
void quickSort(vector<T>& list){
    int left = 0;
    int right = list.size() - 1;
    quick(list, left, right);
}
