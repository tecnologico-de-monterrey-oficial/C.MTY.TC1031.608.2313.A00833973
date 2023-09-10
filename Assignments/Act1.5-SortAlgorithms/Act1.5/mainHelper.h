#include <iostream>
#include <vector>
#include <chrono>
#include <bits/stdc++.h>

#include "SortAlgorithms.h"
#include "SearchAlgorithms.h"
#include "Time.h"


void menuSearch(int& alg){
    string searchA[] = {"Sequential", "Binary"};
    cout << endl;
    cout << "Choose the search algorithm" << endl;
    cout << "1. " << searchA[0] << endl;
    cout << "2. " << searchA[1] << endl;
    cout << endl;

    cout << "Option: ";
    cin >> alg;
    cout << endl;
    cout << searchA[alg-1] <<" Search"<<endl;

}

void menuType(int& type, int& size){
    cout << endl;
    cout << "SORT ALGORITHMS"<<endl<<endl;
    cout << "Choose the type of data" << endl;
    cout << "1. int" << endl;
    cout << "2. char" << endl;
    cout << "3. Hour" << endl;
    cout << "-1. Exit"<< endl<<endl;
    cout << "NOTE: hour is made by 3 int (hour, minute, second). "<<endl;
    cout << "Search the hour by giving 3 values" <<endl;
    cout << endl;
    cout << "Type: ";
    cin >> type;

    if(type > 0){
        cout << "Size: ";
        cin >> size;
        cout << endl;
        cout << "Vector data: "<<endl;
    }
    
}

void menuAlg(int& option){

    string sorts[] = {"Swap", "Buble", "Selection", "Insertion", "Merge", "Quick", "Heap"};

    cout << endl;
    cout << "Choose the sort algorithm method:" <<endl;
    for (int i = 0; i<7; i++){
        cout << (i+1) << ". " << sorts[i] << " Sort" <<endl; 
    }
    cout << "Option: ";
    cin >> option;
    cout << endl;
    cout << sorts[(option-1)] << " Sort" << endl;
}

template <class T>
void sortHelper(vector<T> & list, int option, int& comparison, int& swaps){

    switch (option)
    {
    case 1:
        swapSort(list, comparison, swaps);
        break;
    case 2:
        bubleSort(list, comparison, swaps);
        break;
    case 3:
        selectionSort(list, comparison, swaps);
        break;
    case 4:
        insertionSort(list, comparison, swaps);
        break;
    case 5:
        mergeSort(list, 0, list.size()-1);
        break;
    case 6:
        quickSort(list, 0, list.size()-1);
        break;
    case 7: 
        heapSort(list);
        break;
    default:
        break;
    }
}

template <class T>
void sort(vector<T> & list, int option){
    int comparison = 0;
    int swap = 0;

    float time = 0;
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    startTime(begin);

    sortHelper(list, option, comparison, swap);

    time = getTime(begin, end);

    if(comparison + swap > 0){
        printCiclesRestart(comparison, swap);
    }
    printTime(time);

}

template <class T>
int search(vector< T> list, int alg){
    T value;
    int index;

    cout<<endl;
    cout<<"Write the value"<< endl;
    cin >> value;
    cout << endl;
    
    float time = 0;
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    startTime(begin);
    switch (alg)
    {
    case 1:
        index = sequentialSearch(list, value);
        break;

    case 2: 
        index = binarySearch(list,value);
        break;
    default:
        index = -1;
        break;
    }
    time = getTime(begin, end);
    printTime(time);

    if (index == -1){
        cout << "Not found" << endl;
    }
    else{
        cout << "Index\t Value"<< endl;
        cout << index << "\t" << list[index] << endl;
    }
    return index;
}


template <class T>
void sortAndSearch(vector<T> list, int& sortAlg, int& searchAlg, int& index){
    
    printVector(list);
    menuAlg(sortAlg);
    sort(list, sortAlg);
    printVector(list);

    menuSearch(searchAlg);
    index = search(list, searchAlg);
        
}