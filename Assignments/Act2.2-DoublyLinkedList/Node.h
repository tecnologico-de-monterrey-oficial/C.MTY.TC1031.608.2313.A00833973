template <class T>
struct Node
{
    T data;
    Node<T>* prev;
    Node<T>* next;
    Node();
    
    void operator=(T data);
    /* data */
};

template <class T>
Node<T>::Node(){
    prev = nullptr;
    next = nullptr;
}
template <class T>
void Node<T>::operator=(T data){
    this->data = data;
}