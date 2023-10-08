#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h
#include "DNode.h"
#include "Log.h"
template <class T>
class DoublyLinkedList
{
private:
    DNode<T>* head;
    DNode<T>* tail;
    int size;


public: 
    DoublyLinkedList();
    ~DoublyLinkedList();   

    T getFirst();
    T getLast();
    
    DNode<T>* getHead();
    DNode<T>* getTail();
    void addFirst(T);
    void addLast(T);
    void insert(int, T);
    
    bool deleteData(T);
    bool deleteAt(int);

    T getData(int);

    bool updateData(T,T);
    bool updateAt(int, T);

    int findData(T);

    void clear();
    void sort(bool);
    void duplicate();
    void removeDuplicate();

    void removeFront();
    void removeBack();
    void print();
    void print(bool);
    void printReverse();
    void printForward();
    bool isEmpty();
    int getSize();

    T& operator[](int);
    void operator=(DoublyLinkedList);

};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(/* args */)
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}


template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    DNode<T>* temp;
    for (int i = 0; i<size; i++){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
T DoublyLinkedList<T>::getFirst()
{
    return head->data;
}

template <class T>
T DoublyLinkedList<T>::getLast()
{
    return tail->data;
}

template <class T>
DNode<T>* DoublyLinkedList<T>::getHead(){
    return head;
}
template <class T>
DNode<T>* DoublyLinkedList<T>::getTail(){
    return tail;
}

template <class T>
void DoublyLinkedList<T>::addFirst(T data)
{
    DNode<T>* aux = new DNode<T>;
    aux->data = data;

    if (isEmpty()){
        head = aux;
        tail = aux;
    } 
    else
    {
        aux->next = head;
        head->prev = aux;
        head = aux;
    }
    size++;

}

template <class T>
void DoublyLinkedList<T>::addLast(T data){
    DNode<T>* aux = new DNode<T>;
    aux->data = data;

    if (isEmpty()){
        head = aux;
        tail = aux;
    } 
    else
    {
        aux->prev = tail;
        tail->next = aux;
        tail = aux;
    }
    size++;
}

template <class T>
void DoublyLinkedList<T>::insert(int index, T data){
    DNode<T>* aux;
    try
    {   
        if(isEmpty()){
            throw std::out_of_range("Lista vacía");
        }
        if(index>=0 && index < size){
            if(index == 0){
                addFirst(data);
                return;
            }
            if (index <= (size - 1) / 2) {
                aux = head;
                for (int i = 0; i<index-1; i++){
                    aux = aux->next;
                }
            } else {
                aux = tail;
                for(int i = size-1; i>=index; i--){
                    aux = aux->prev;
                }
            }
        
            DNode<T>* aux2 = new DNode<T>(data, aux, aux->next);
            aux->next = aux2;
                
            if (aux2->next == nullptr) {
                tail = aux2;
            } else {
                aux2->next->prev = aux2;
            }
            size++;
            
        }
        else{
            throw std::out_of_range("Índice fuera de rango");
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}

template <class T>
bool DoublyLinkedList<T>::deleteData(T find)
{
    try
    {
        int index = findData(find);
        if(index == -1){
            throw std::runtime_error("Element not found");
        }
        return deleteAt(index);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return false;
}    

template <class T>
bool DoublyLinkedList<T>::deleteAt(int index){
    try
    {
        if (index < 0 && index >=size){
            throw std::out_of_range("Index of out range");
        }

        DNode<T> *aux = head;
        DNode<T> *del;
        for (int i = 0; i <index; i ++){
            aux = aux->next;
        }
        del = aux;

        //CHECAR SI ES EL PRIMER ELEMENTO
        if (index == 0){
            removeFront();;
            return true;
        }
        //CHECAR SI ES EL ÚLTIMO ELEMENTO
        if(index == size-1){
            removeBack();
            return true;
        }

        aux->prev->next = del->next;
        aux->next->prev = del->prev;
    
        delete del;
        size--;
        
        return true;

    }
    
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return false;

}

template <class T>
bool DoublyLinkedList<T>::updateData(T find, T replace)
{
    try
    {
        int index = findData(find);
        if(index == -1){
            throw std::runtime_error("Element not found");
        }
        return updateAt(index, replace);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return false;
}    

template <class T>
bool DoublyLinkedList<T>::updateAt(int index, T replace){
    try
    {
        if (index < 0 && index >=size){
            throw std::out_of_range("Index of out range");
        }
        DNode<T> *aux = head;
        for (int i = 0; i <index; i ++){
            aux = aux->next;
        }
        aux->data = replace;
        return true;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    return false;
}

template <class T>
int DoublyLinkedList<T>::findData(T data){
    DNode<T>* aux = head;
    try{
        if (isEmpty()){
            throw out_of_range("Empty List");
        }
        int i = 0;
        for (i; i < size; i++){
            if(aux->data == data){
                return i;
            }
            aux = aux->next;
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    return -1;
}



template <class T>
void DoublyLinkedList<T>::clear(){
    DNode<T>* temp;
    for (int i = 0; i<size; i++){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void DoublyLinkedList<T>::sort(bool IP){
    quickSort(head, tail,IP);
}

template <class T>
void DoublyLinkedList<T>::duplicate(){
    DNode<T> *aux = head;
    for (int i = 0; i <size; i+=2){
        T data = aux->data;
        insert(i,data);
        aux = aux->next;
    }
}
template <class T>
void DoublyLinkedList<T>::removeDuplicate(){
    if (size <= 1){
        return;
    }

    DNode <T> *aux = head;
    DNode <T> *aux2;

    for(int i = 1; i < size;i++)
    {
        aux2 = aux->next;
        for(int j = i; j< size; j++)
        {
            if(aux->data==aux2->data)
            {
                DNode<T> * curr = aux2->next;
                deleteAt(j-1);
                aux->next = curr;
                aux2 = aux->next;
            }
            else
            {
                aux2=aux2->next;
            } 
            cout << "";
        }
        aux=aux->next;
    } 
}

template <class T>
void DoublyLinkedList<T>::removeFront(){
    DNode<T> * aux = head;
    head->next->prev = aux->next;
    head = aux -> next;
    head -> prev = nullptr;
    size --;
    delete aux;

}

template <class T>
void DoublyLinkedList<T>::removeBack(){
    DNode<T>* aux = tail;
    
    tail->prev->next = aux->prev;
    tail = tail->prev;
    tail -> next = nullptr;

    size --;
    delete aux;
    
}

template <class T>
void DoublyLinkedList<T>::print(){
    printForward();
}

template <class T>
void DoublyLinkedList<T>::print(bool forward){
    if(forward){
        printForward();
    }
    else{
        printReverse();
    }
}

template <class T>
void DoublyLinkedList<T>::printReverse(){
    DNode<T>* aux = tail;
    for (int i = 0; i<size; i++){

        cout << aux->data ;
        if(i < size -1){
            cout << " <- ";
        }
        aux = aux->prev;
    }   

    cout << endl;
}

template <class T>
void DoublyLinkedList<T>::printForward(){
    DNode<T>* aux = head;
    for (int i = 0; i<size; i++){

        cout << aux->data;
        if(i < size -1){
            cout << " -> ";
        }
        
        aux = aux->next;
    }   

    cout << endl;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
    return size == 0;
}

template <class T>
int DoublyLinkedList<T>::getSize(){
    return size;
}   

template <class T>
T DoublyLinkedList<T>::getData(int index) {
    if (index >= 0 && index < size) {
        DNode<T>* aux;
        if (index <= (size - 1) / 2) {
            int auxIndex = 0;
            aux = head;
            while (auxIndex != index) {
                aux = aux->next;
                auxIndex++;
            } 
        } else {
            int auxIndex = size - 1;
            aux = tail;
            while (auxIndex != index) {
                aux = aux->prev;
                auxIndex--;
            } 
        }
        return aux->data;
    } else {
        throw out_of_range("El índice no se encuentra en la lista");
    }
}

template <class T>
T& DoublyLinkedList<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        DNode<T>* aux;
        if (index <= (size - 1) / 2) {
            int auxIndex = 0;
            aux = head;
            while (auxIndex != index) {
                aux = aux->next;
                auxIndex++;
            } 
        } else {
            int auxIndex = size - 1;
            aux = tail;
            while (auxIndex != index) {
                aux = aux->prev;
                auxIndex--;
            } 
        }
        return aux->data;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}


template <class T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> list){
    clear();
    DNode<T> *b = list.head;
    size = 0;

    while(b != nullptr){
        addLast(b->data);
        b = b->next;
    }
}


//  QUICK SORT

template <class T>
void swap(DNode<T>* a, DNode<T>* b){
    if(a -> data != b -> data){
        T auxData = a -> data;
        a ->data = b->data; 
        b -> data = auxData; 
    }
}

DNode<Log>* getPivot(DNode<Log>* left, DNode<Log>* right,bool IP){
    Log pivot = right->data;
    DNode<Log>* i = left->prev;

    for(DNode<Log>* j = left; j != right; j = j->next){
        if(!IP){
            if(j->data <= pivot){
                i = (i == nullptr) ? left: i->next;
                swap(i,j);
            }
        }
        else{
            if(j->data.keyIP <= pivot.keyIP){
                i = (i == nullptr) ? left: i->next;
                swap(i,j);
            }
        }
        
    }
    i = (i == nullptr) ? left: i->next;
    swap(i,right);

    return i;
}


void quickSort(DNode<Log>* left, DNode<Log>* right, bool IP){
    if(right != nullptr && left != right && left != right->next){
        DNode<Log>* pivot = getPivot(left, right , IP);
        quickSort(left, pivot->prev,IP);
        quickSort(pivot->next, right,IP);
    }
}



#endif