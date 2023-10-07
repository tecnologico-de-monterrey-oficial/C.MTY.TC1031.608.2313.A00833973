#ifndef BST_h
#define BST_h

#include "TNode.h"

template <class T>
class BST {
private:
    TNode<T>* root;
    void printTree(TNode<T>* aux, int level);
public:
    BST();
    void insert(T data);
    bool find(T data);
    void print();
    bool isEmpty();
    
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
void BST<T>::insert(T data) {
    
    if (isEmpty()){
        //Se crea el primer nodo
        root = new TNode<T> (data);
        cout << "";
    }
    else{
        TNode<T>* aux = root;
        while (aux != nullptr){
            if(data < aux->data)
            {
                //En caso que el dato sea menor al nodo nos movemos a la izq
                if(aux->left == nullptr){
                    //Se alcanza la punta del nodo
                    aux->left = new TNode<T>(data);
                    return;
                }
                else{
                    //Se recorre el aux a la izquierda
                    aux = aux->left;
                }
            }
            else
            {
                //Igual o mayor se ve a la derecha
                if (aux->right == nullptr){
                    //Se alcanza la punta derecha
                    aux->right = new TNode<T>(data);
                    return;
                }
                else{
                    //Se mueve el aux a la derecha
                    aux = aux->right;
                }
            }
        }
    }
}

template <class T>
bool BST<T>::find(T data){
    TNode<T>* aux = root;
    while (aux != nullptr){
        if (aux->data == data){
            return true;
        }
        if(data < aux->data){
            aux = aux->left;
        }
        else{
            aux = aux->right;
        }
    }
    return false;
}
template<class T>
void BST<T>::printTree(TNode<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BST is empty" << endl << endl;
    }
} 

template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}


#endif 