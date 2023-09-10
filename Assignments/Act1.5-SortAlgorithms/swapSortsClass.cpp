#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T>
void swapSort(vector<T>& list, int& comparisons, int& switches){
    int size = list.size();
    for (int i = 0; i < size - 1 ; i++){
        for (int j = i+1; j < size; j++){
            comparisons ++;
            if (list[i] > list[j]){
                // cout << list[i] << "<" << list[j] << " = ";
                T aux = list[i];
                list[i] = list[j];
                list[j] = aux;
                // cout << list[i] << "<" << list[j] << endl;   
                switches ++;        
            }
        }
    //    cout << "row" <<endl;
    }

}
template <class T>
void printVector(vector<T> list){
    for (auto e: list){
        cout << e << " ";
    }
}

int main()
{
    vector<int> list = {15,7,9,3,2,12};
    int compar = 0;
    int swit = 0;
    printVector(list);

    cout << endl;

    swapSort(list, compar, swit);
    printVector(list);

    cout <<endl << "Comparisons: " << compar << " Switches: " <<swit << endl;
    cout << endl;


    vector<string> list2 = {"s","e","r","g","h","p"};
    int compar2 = 0;
    int swit2 = 0;

    printVector(list2);
    cout << endl;
    swapSort(list2, compar2, swit2);
    printVector(list2);

    cout << endl <<  "Comparisons: " << compar2 << " Switches: " <<swit2 << endl;
    
    return 0;
}
