#ifndef Stack_h
#define Stack_h

#include "Node.h"

template <class T>
class Stack {
private:
    Node<T>* head;
    int size; 
public:
    Stack();
    void push(T data); // Agrego un elemento a la pila
    T pop(); // Elimina el elemento de arriba de la pila
    void print(); //Esto imprime el stack
    T top(); // regresa el elemento de arriba de la pila
    bool isEmpty();
};

template<class T> 
Stack<T>::Stack(){
    head = nullptr; 
}

template<class T>
void Stack<T>:: push(T data){
    //Asugnamos a head un nuevo nodo con data y head
    head = new Node<T>(data, head);

    //Incrementamos size
    size++; 
}

template<class T>
T Stack<T>::pop(){
    
    if(head != NULL){
        // Creamos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // Cambiamos el valor de head
        head = head->next;
        // Decrementamos el valor de size
        size--;
        // Liberamos de memoria el node que esta en aux
        T tempo = aux -> data; 
        delete aux;

        return tempo;
    }else{
        throw out_of_range("El elemento no se puede borrar");
    }
}

template<class T>
T Stack<T>::top(){
    if(head != NULL){
        T arriba = head -> data; 
        return arriba;
    }else{
        throw out_of_range("No hay elementos en la lista");
    }
} 

template<class T>
bool Stack<T>::isEmpty(){
    return size == 0; 
}

template <class T >
void Stack<T>::print(){
    //Definimos un apuntador auxiliar que sea igual a head 
    Node<T> *aux = head;
    while (aux != nullptr){
        // Imprimimos el valor 
        cout << aux ->data ;

        if (aux->next != nullptr){
            cout << "->";
        }

        //recorremos el aux al apuntador de next 
        aux = aux ->next; 
    }
    //Imprimimos un salto de linea
    cout << endl; 
}
#endif