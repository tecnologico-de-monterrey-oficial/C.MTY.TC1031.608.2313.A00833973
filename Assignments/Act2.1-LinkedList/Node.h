template <class T>
struct Node
{
    T data;
    Node<T>* next;
    
    Node(T data);
    Node(T data, Node<T>* next);
    void operator=(T data);
    /* data */
};

template <class T>
Node<T>::Node(T data){
    this -> data = data;
    this -> next = nullptr;
};

template <class T>
Node<T>::Node(T data, Node<T>* next){
    this -> data = data;
    this -> next = next;
};

template <class T>
void Node<T>::operator=(T data){
    this->data = data;
}