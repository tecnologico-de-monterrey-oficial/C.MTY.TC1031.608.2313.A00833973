#ifndef LinkedList_h
#define LinkedList_h
#include "Node.h"

template <class T>

class LinkedList
{
private:
    Node<T>* head;
    int size;
public:
    LinkedList();
    int getSize();

    void addFirst(T data);
    void addLast(T data);
    void insert(int, T);
    bool deleteData(T);
    bool deleteAt(int);
    T getData(int);
    void updateData(T,T);
    void updateAt(int, T);
    int findData(T);

    T& operator[](int);
    void  operator = (LinkedList<T>);

    void print();
    bool isEmpty();
    void clear();
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    size = 0;

}

template <class T>
int LinkedList<T>::getSize()
{
    return size;
}

template <class T>
void LinkedList<T>::addFirst(T data){
    
    //cout << head << endl;
    //Asignar un nuevo nodo a head este va a contener el valor de data y va a apaturar a head;
    head = new Node(data, head);

    // cout << head << endl;
    // cout << head->data << " " << head->next << endl;
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data){

    Node<T> *aux = head;
    if (isEmpty()){
        addFirst(data);
    }else{
        while (aux->next != nullptr){
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
        size++;
    }
    
}

template <class T>
void LinkedList<T>::insert(int index, T data){
    if (size > index && index >= 0){
        Node<T> *aux = head;
        if(index == 0){
            addFirst(data);
        }
        else{
            for(int i = 0; i < index-1 ; i++){
            aux = aux->next;
            }
            aux->next = new Node(data, aux->next);
        }
        size++;
        
    }
    else{
        throw std::out_of_range("Índice fuera de rango");
    }
    
}

template <class T>
bool LinkedList<T>::deleteData(T data){
    int index = findData(data);
    if (index >= 0 && index < size){
        Node<T> *aux = head;
        Node<T> *aux2 = aux->next;
        for (int i = 0; i <index-1 ; i ++){
            aux = aux->next;
            aux2 = aux2->next;
        }
        if (aux2->next!= nullptr){
            aux->next = aux2->next;
        }else{
        aux->next = nullptr;  
        }
        delete aux2;
        size --;
        return true;
    }
    else{
        throw std::out_of_range("Índice fuera de rango");
    }
    return false;
    
}

template <class T>
bool LinkedList<T>::deleteAt(int index){
    if (index < size && index >= 0){
        Node<T> *aux = head;
        Node<T> *aux2 = aux->next;

        for (int i = 0; i <index-1; i ++){
            aux = aux->next;
            aux2 = aux2->next;
        }
        if (aux2->next != nullptr){
            aux->next = aux2->next;
        }else{
        aux->next = nullptr;  
        }
        delete aux2;
        size--;
        return true;

    }
    else{
        throw std::out_of_range("Índice fuera de rango");
    }
    return false;
}

template <class T>
int LinkedList<T>::findData(T data){
    Node<T> *aux = head;
    int i = 0;
    for (i; i<size; i++){
        if(aux->data == data){
            return i;
        }
        aux = aux-> next;
    }
    return -1;
}

template <class T>
void LinkedList<T>::updateData(T find, T data){
    int index = findData(find);
    Node<T> *aux = head;
    
    for (int i = 0; i<index; i++){
        aux = aux -> next;
    }
    aux->data = data;

}

template <class T>
void LinkedList<T>::updateAt(int index, T data){
    if(index >=0 && index <size){
        Node<T> *aux = head;
        for (int i = 0; i<index; i++){
            aux = aux -> next;
        }
        aux->data = data;
    }
    else{
        throw std::out_of_range("Índice fuera de rango");
    }
}

template <class T>
T LinkedList<T>::getData(int index){
    Node<T> *aux = head;
    if (index >= 0  && index<size){
        for (int i = 0; i < index; i++){
            aux = aux->next;
        }
        return aux->data;
    }
    else{
        throw std::out_of_range("Índice fuera de rango");
    }
}

template <class T>
T& LinkedList<T>::operator[](int index){
    Node<T> *aux = head;
    if (index >= 0  && index<size){
        for (int i = 0; i < index; i++){
            aux = aux->next;
        }
        return aux->data;
    }
    else{
        throw std::out_of_range("Índice fuera de rango");
    }
}
template <class T>
void LinkedList<T>::operator=(LinkedList<T> list){
    clear();
    head = list.head;
}


template <class T>
void  LinkedList<T>::print(){
   Node<T> *aux = head;
   while (aux != nullptr){
    cout << aux->data;
    if (aux->next != nullptr){
        cout << " -> " ;
    }
    aux = aux-> next;
   }
   cout << endl;
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return size == 0;
}

template <class T>
void LinkedList<T>::clear(){
    Node<T>* temp;
      while(head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
      }
     // cout<<"All nodes are deleted successfully." << endl;  
}

#endif