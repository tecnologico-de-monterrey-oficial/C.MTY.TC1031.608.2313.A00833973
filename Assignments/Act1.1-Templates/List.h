#ifndef List_h
#define List_h

template <class T>
class List {
private:
    vector<T> list;
    int size;
public:
    List();
    void insert(T data);
    void removeLast();
    T getData(int i);
    int getSize();
    T getMax();
    void print();

};

// Constructor
template <class T>
List<T>::List() {
    size = 0;
}

// Insert
template <class T>
void List<T>::insert(T data) {
    list.push_back(data);
    size++;
}
template <class T>
void List<T>::removeLast(){
    if (size < 0){
        cout << "NO HAY ELEMENTOS";
    }
    else{
        cout << "El último elemento de mi lista: " << list[size - 1] << endl;
        list.pop_back();
        size--;
    }
}

template <class T>
T List<T>::getData(int i){
    if (i >= 0 && i < size){
       return list[i];
    }
    else{
        throw out_of_range("Índice fuera de rango ");
    }
}

template <class T>
int List<T>::getSize(){
    return size;
}

template<class T>
T List<T>::getMax(){
    if (size > 0){
        T max = list[0];
        for (int i = 1; i < size; i++){
            if (list[i] > max){
                max =list[i];
            } 
        } 
        return max;
    }
    else{
        throw out_of_range("La lista no tiene elementos");
    }
}

// Print
template <class T>
void List<T>::print() {
    // Iteramos de manera tradicional
    // for (int i = 0; i < size; i++) {
    //     cout << list[i] << " ";
    // }
    // Iteramos de manera moderna
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}

#endif