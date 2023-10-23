#include <iostream>
using namespace std;

#include "Heap.h"
#include "MinHeap.h"

// Heap Sort
template <class T>
void heapSort(vector<T> &list, string order) {
    if (order == "desc") {
        // Creamos un heap en base a la lista
        Heap<T> heap(list);
        // Ciclo para sacar todos los elementos del heao y agregarlos a la lista
        for (int i=0; i<list.size(); i++) {
            list[i] = heap.pop();
        }
    } else {
        if (order == "asc") {
            // Creamos un heap en base a la lista
            MinHeap<T> heap(list);
            // Ciclo para sacar todos los elementos del heao y agregarlos a la lista
            for (int i=0; i<list.size(); i++) {
                list[i] = heap.pop();
            }
        } 
    }
}

// Crea una lista aleatoria de enteros
void createListInt(Heap<int> &list, int quantity)
{
    srand(time(0));
    for (int i = 0; i < quantity; i++)
    {
        int num = rand() % 1000 + 1;
        list.push(num);
    }
}

template <class T>
void print(vector<T> list) {
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}

int main() {

    Heap<int> heap;
    vector<int> ordered;
    int option = -1;
    cout << "HEAP STRUCTURE"  << endl;

    while (option != 7){
        cout << endl;
        cout << "0. Add random values" << endl;
        cout << "1. Add value" << endl;
        cout << "2. Remove value" << endl;
        cout << "3. Get prior value" << endl;
        cout << "4. Is Empty?" << endl;
        cout << "5. Sort" << endl;
        cout << "6. Print" << endl;
        cout << "7. Exit" << endl;
        cout << endl;
        cout << "Option: ";
        cin >> option;
        cout << endl;

        switch (option)
        {
        case 0:{
            cout << "Number of elements: ";
            int amount;
            cin >> amount;
            createListInt(heap, amount);
            break;
        }
        case 1:{
            cout << "Add value: ";
            int value;
            cin >> value;
            heap.push(value);
            break;
        }
        case 2:{
            cout << "Deleted value: " << heap.pop();
            break;
        }
        case 3:{
            cout << "The prior element is " << heap.top() << endl;
            break;
        }
        case 4:{
            if (heap.isEmpty()){
                cout << "The Heap is empty";
            }
            else{
                cout << "The Heap has elements";
            }
            break;
        }
        case 5:{
            cout << "Order [asc] or [desc]: ";
            string op;
            cin >> op;
            ordered = heap.getCopy();
            heapSort(ordered, op);
            print(ordered);
            break;
        }
        case 6:{
            heap.print();
            break;
        }
        default:
            break;
        }
        cout << endl;
    }
    return 0;
}