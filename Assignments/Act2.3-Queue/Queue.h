#ifndef Queue_h
#define Queue_h

#include "Node.h"

template <class T>
class Queue {
private:
    Node<T> *head, *rear;
    int size; 
public:
    Queue();

    void push(T data); 
    T pop(); 
    T front(); 

    void print(); 
    bool isEmpty();
};

template<class T> 
Queue<T>::Queue(){
    head = nullptr; 
    rear = nullptr;
    size = 0;
}

template<class T>
void Queue<T>:: push(T data){
    rear = new Node<T> (data,nullptr,rear);
    if (rear->prev == nullptr){
        head = rear;
    }
    else{
        rear->prev->next = rear; 
    }
    size++; 
}

template<class T>
T Queue<T>::pop(){
    
    if(head != nullptr){
        Node<T>* aux = head;

        head = head->next;
        size--;

        T temp = aux -> data; 
        delete aux;
        return temp;
    }else{
        throw out_of_range("El elemento no se puede borrar");
    }
}

template<class T>
T Queue<T>::front(){
    if(rear != NULL){
        T data = head -> data; 
        return data;
    }else{
        throw out_of_range("No hay elementos en la lista");
    }
} 

template<class T>
bool Queue<T>::isEmpty(){
    return size == 0; 
}

template <class T >
void Queue<T>::print(){
    Node<T> *aux = head;
    while (aux != nullptr){
        cout << aux ->data ;
        if (aux->next != nullptr){
            cout << "->";
        }
        aux = aux ->next; 
    }
    cout << endl; 
}
#endif