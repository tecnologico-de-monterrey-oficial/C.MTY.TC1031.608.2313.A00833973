#include <iostream>
#include <vector>
#include "Time.h"
using namespace std;

template <class T>
void printVector(vector<T> list){
    for (auto e: list){
        cout << e << " ";
    }
    cout << endl;
}

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


//SWAP SORT
template <class T>
void swapSort(vector<T>& list, int& comparisons, int& switches){
    int size = list.size();
    for (int i = 0; i < size - 1 ; i++){
        for (int j = i+1; j < size; j++){
            comparisons ++;
            if (list[i] > list[j]){
                // cout << list[i] << "<" << list[j] << " = ";
                swap(list,i,j);
                // cout << list[i] << "<" << list[j] << endl;   
                switches ++;        
            }
        }
    //    cout << "row" <<endl;
    }
}

//BUBLE SORT
template <class T>
void bubleSort(vector<T>& list, int& compar, int& swapN){
    int size = list.size() -1;
    int i = 0;
    bool control = true;

    while (i < size && control){
        control = false;
        for (int j = 1; j < size - i + 1 ; j++){
            if (list[j-1] > list[j]){
                //cout << list[j] << "<" << list[j+1] << " = ";
                swap(list, j-1, j);
                //cout << list[j] << "<" << list[j+1] << endl;   
                swapN ++;
                control = true;
            }
            compar ++;
        }
        size --;
        //cout << "row" <<endl;
    }
}

//SELECTION SORT
template <class T>
void selectionSort(vector<T>& list, int& compar, int& swapN){
    int size = list.size();

    for (int i = 0; i < size -1; i++){
        int min = i;
        bool control = true;
        for (int j = i+1; j < size; j++){
            compar++;
            //cout << list[min] << ">" << list[j] << " = ";
            if (list[min] > list[j]){
                //cout << compar;
                min = j;
                //cout << "1" ;
            }
            //cout << endl;
        }
        if (min != i){
            swapN ++;
            swap(list, i, min);
        }  
        //cout << "cicle" <<endl<< endl;
    }
}

template <class T>
void insertionSort(vector<T>& list, int& compar, int& swapN){
    int size = list.size();

    for( int i = 1; i< size; i++){
        int min = i-1;
        int max = i;
        bool control = true;
        while(max >= 1 && control){
            compar ++;
            //cout << list[min] << ">" << list[max] << " = ";
            if(list[min] > list[max]){
                //cout << "1";
                swapN++;
                swap(list, min, max);
            }else{
                control = false;
            }
            //cout << endl;
            max --;
            min --;
        }
        // cout << "cicle"<< endl;
        // printVector(list);
    }    
}

template <class T>
void merge(vector<T>& list, int left, int mid, int right){
    vector <T> temp1;
    vector <T> temp2;
    //cout << endl<< "Range: " << left << " - " << right;

    //cout << "Temp1: ";
    for (int i = left; i <=mid; i ++){
        //cout << i <<": " << list[i] << " ";
        temp1.push_back(list[i]);
    }
    //cout << endl;

    //cout << "Temp2: ";
    for(int i = mid+1; i<=right; i++){
        //cout << i <<": " << list[i] <<" ";
        temp2.push_back(list[i]);
    }
    //cout << endl;

    int aux = left;
    int i = 0;
    int j = 0;

    int size = temp1.size();
    int size2 = temp2.size();
    
    while(i < size && j < size2){
       if (temp1[i]<= temp2[j]){
            list[aux] = temp1[i];
            i++;
        }
        else{
            list[aux] = temp2[j];
            j++;
        }
        // cout << list[aux]<< endl;
        aux++;
    }
    while(i < size){
        list[aux] = temp1[i];
        i++;
        aux++;
        // cout << list[aux]<< endl;
    }
    while(j < size2){
        list[aux] = temp2[j];
        j++;
        aux++;
        // cout << list[aux]<< endl;
    }
    //cout << endl;
    //printVector(list);
    
}

template <class T>
void mergeSort(vector<T>& list, int left, int right){
    if (left < right){
        int mid =  left + (right - left) / 2;
        mergeSort(list,left,mid);
        mergeSort(list,mid+1, right);

        merge(list,left,mid,right);
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

template <class T>
void heapy (vector <T>& list, int i, int size){
    int max  = i;
    int left = i*2 +1;
    int right = i*2 +2;

    if(left < size && list[left] > list[i]){
        max = left;
    }else{
        max = i;
    }

    if(right < size && list[right]>list[max]){
        max = right;
    }
    if(max != i){
        swap(list, max, i);
        heapy(list,max,size);
    }

}

template <class T>
void heapSort(vector<T> &list){
    int size = list.size();
    int counter = 1;
    for (int i = (size - 1)/2; i>=0; i--){
        heapy(list, i,size);
    }
    for (int i = size -1; i >=1; i-- ){
        size--;
        swap(list,0,i);
        heapy(list,0,size);
    }
}
