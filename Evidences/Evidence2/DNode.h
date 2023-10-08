template <class T>
struct DNode
{
    T data;
    DNode<T>* prev;
    DNode<T>* next;
    DNode();
    DNode(T);
    DNode(T,DNode*, DNode*);
    
    void operator=(T data);
    /* data */
};

template <class T>
DNode<T>::DNode(){
    prev = nullptr;
    next = nullptr;
}

template <class T>
DNode<T>::DNode(T data){
    this->data = data;
    prev = nullptr;
    next = nullptr;
}

template <class T>
DNode<T>::DNode(T data, DNode* prev, DNode* next){
    this->data = data;
    this->prev = prev;
    this->next = next;
}

template <class T>
void DNode<T>::operator=(T data){
    this->data = data;
}