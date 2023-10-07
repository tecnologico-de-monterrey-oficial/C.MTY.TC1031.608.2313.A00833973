#pragma once
#include "Node.h"

template <class T>
class DoublyLinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

    //Private methods
   

public: 
    void swap(Node<T>*, Node<T>*);
    int getPivot(int, int);
    void quickSort(int, int);
    
    DoublyLinkedList();
    ~DoublyLinkedList();

    T getFisrt();
    T getLast();
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
    void sort();
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
    Node<T>* temp;
    for (int i = 0; i<size; i++){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
T DoublyLinkedList<T>::getFisrt()
{
    return head->data;
}

template <class T>
T DoublyLinkedList<T>::getLast()
{
    return tail->data;
}

template <class T>
void DoublyLinkedList<T>::addFirst(T data)
{
    Node<T>* aux = new Node<T>;
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
    print();

}

template <class T>
void DoublyLinkedList<T>::addLast(T data){
    Node<T>* aux = new Node<T>;
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
    print();
}

template <class T>
void DoublyLinkedList<T>::insert(int index, T data){
    Node<T>* newNode = new Node<T>;
    Node<T>* aux = head;
    newNode->data = data;
    // hacer del lado abajo a ariiba si el index está en la segunda mitad
    try
    {   
        if(isEmpty()){
            
            throw std::out_of_range("Lista vacía");
        }
        if(index>=0 && index < size){
            if (index == 0){
                addFirst(data);
            }
            else
            {
                for (int i = 0; i <index-1; i++){
                    aux = aux->next;
                }
                newNode->next = aux->next;
                aux->next = newNode;
                newNode->prev = aux;

                if (newNode->next != nullptr){
                    newNode->next->prev = newNode;
                }
    
                size++;
                print();
            }
        }
        else{
            throw std::out_of_range("Índice fuera de rango");
        }
    }
    catch(const std::exception& e)
    {
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

        Node<T> *aux = head;
        Node<T> *del;
        for (int i = 0; i <index; i ++){
            aux = aux->next;
        }
        del = aux;

        //CHECAR SI ES EL PRIMER ELEMENTO
        if (index == 0){
            removeFront();
            print();
            return true;
        }
        //CHECAR SI ES EL ÚLTIMO ELEMENTO
        if(index == size-1){
            removeBack();
            print();
            return true;
        }

        aux->prev->next = del->next;
        aux->next->prev = del->prev;
    
        delete del;
        size--;
        
        print();
        return true;

    }
    
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return false;

}

template <class T>
T DoublyLinkedList<T>::getData(int index){

    try
    {
        if (index < 0 || index >= size){
            throw out_of_range("Index out of range");
        }
        Node<T>*  aux = head;
        for(int i = 0; i< index; i++){
            aux = aux->next;
        }
        T data = aux ->data;
        return data;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        
    }
    return nullptr;
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
        Node<T> *aux = head;
        for (int i = 0; i <index; i ++){
            aux = aux->next;
        }
        aux->data = replace;
        print();
        return true;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    return false;
}

template <class T>
int DoublyLinkedList<T>::findData(T data){
    Node<T>* aux = head;
    try
    {
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
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return -1;
}

template <class T>
void DoublyLinkedList<T>::clear(){
    Node<T>* temp;
    for (int i = 0; i<size; i++){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void DoublyLinkedList<T>::sort(){
    quickSort(0,size-1);
}

template <class T>
void DoublyLinkedList<T>::duplicate(){
    Node<T> *aux = head;
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

    Node <T> *aux = head;
    Node <T> *aux2;

    for(int i = 1; i < size;i++)
    {
        aux2 = aux->next;
        for(int j = i; j< size-1; j++)
        {
            if(aux->data==aux2->data)
            {
                Node<T> * curr = aux2->next;
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
    Node<T> * aux = head;
    head->next->prev = aux->next;
    head = aux -> next;
    head -> prev = nullptr;
    size --;
    delete aux;

}

template <class T>
void DoublyLinkedList<T>::removeBack(){
    Node<T>* aux = tail;
    
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
    Node<T>* aux = tail;
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
    Node<T>* aux = head;
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
T& DoublyLinkedList<T>::operator[](int index){
    return getData(index);
}

template <class T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> list){
    clear();

    head = new Node<T> *(list.head-> data);
    Node<T> *a = head ;
    Node<T> *b = list.head;

    while(b ->next =! nullptr){
        a ->next = new Node<T>(b ->next ->data);
        a = a -> next; 
        b = b -> next;
    }

}


//PRIVATE METHODS

template <class T>
void DoublyLinkedList<T>::swap(Node<T>* a, Node<T>* b){
    
    T aD = getData(a);
    T bD = getData(b);
    if (aD != bD){
        a->data = bD;
        b->data = aD;
    }
}

template <class T>
int DoublyLinkedList<T>::getPivot(int left, int right){
    Node<T>* pivote = tail;
    int pivot = right;
    int aux = left - 1 ;
    //left - 1
    for (int i = left; i < right; i++){
        if(getData(i) < getData(pivot)){
            aux++;
            swap(i,aux);
        }
    }
    aux++;
    swap(pivot,aux);

    return aux;
}

template <class T>
void DoublyLinkedList<T>::quickSort(int left, int right){

     if(left < right){
        int pivot = getPivot(left, right);
        quickSort(left, pivot-1);
        quickSort(pivot+1, right);
    }
}
