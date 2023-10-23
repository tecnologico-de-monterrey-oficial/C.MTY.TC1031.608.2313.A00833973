#ifndef AVL_h
#define AVL_h

#include "TNode.h"
#include <queue>
 ///NO TERMINADO
template <class T>
class AVL {
private:
    TNode<T>* root;
    int FB;
    void printTree(TNode<T>* aux, int level);
    int children(TNode<T>* aux);
    void preOrder(TNode<T>* aux);
    void inOrder(TNode<T>* aux);
    void postOrder(TNode<T>* aux);
    void levelByLevel(TNode<T>* aux);
    int nodeHeight(TNode<T>* aux);
    void calcFB();
    void rotate();
    void RotateIzq();
    void RotateRight();
    void RotateIzqD();
    void RotateRightD();
public:
    AVL();
    void insert(T data);
    bool find(T data);
    bool remove(T data);
    void visit(int order);
    void print();
    bool isEmpty();

    int height();
    void ancestors(T data);
    int whatLevelAml(T data);
    
};

template <class T>
AVL<T>::AVL() {
    root = nullptr;
    FB = 0;
}

template <class T>
void AVL<T>::insert(T data) {
    // Validamos si el bst esta vacío
    if (isEmpty()) {
        // si está vacío
        // asignamos un nuevo nodo con el valor de data a root
        root = new TNode<T>(data);
    } else {
        // No está vacía
        // Creamos una apuntador auxiliar igual a root
        TNode<T>* aux = root;
        // Iteramos el arbol hasta encontrar donde insertar el valor de data (aux != nullptr)
        while (aux != nullptr) {
            // Comparamos si data es menor que aux->data
            if (data < aux->data) {
                // si es menor
                // Comparamos si el apuntador del lado izquierdo de aux es nulo
                if (aux->left == nullptr) {
                    // si es nulo
                    // agregamos un nuevo nodo con el valor de data al auntador del lado izquierdo de aux
                    aux->left = new TNode<T>(data);
                    // nos salimos de la función
                    return;
                } else {
                    // no es nulo
                    // asignamos a aux el aunptador del lado izquierdo de aux
                    aux = aux->left;
                }
            } else {
                // no es menor
                // Comparamos si el apuntador del lado derecho de aux es nulo
                if (aux->right == nullptr) {
                    // si es nulo
                    // agregamos un nuevo nodo con el valor de data al auntador del lado derecho de aux
                    aux->right = new TNode<T>(data);
                    // nos salimos de la función
                    return;
                } else {
                    // no es nulo
                    // asignamos a aux el aunptador del lado derecho de aux
                    aux = aux->right;
                }
            }
        }
    }
}

template <class T>  
bool AVL<T>::find(T data) {
    // Creamos un apuntador auxiliar igual a root
    TNode<T>* aux = root;
    // Recorremos el árbol para buscarlo
    while (aux != nullptr) {
        // Validamos si data es igual a aux-data
        if (data == aux->data) {
            return true;
        } else {
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    // no lo encontramos
    return false;
}

template <class T>
int AVL<T>::children(TNode<T>* aux) {
    if (aux->left == nullptr && aux->right == nullptr) {
        return 0;
    }
    if (aux->left != nullptr && aux->right != nullptr) {
        return 2;
    }
    return 1;
}

template <class T>
bool AVL<T>::remove(T data) {
    // buscar el nodo a borrar (debemos mantener un apuntador al papa del nodo a borrar)
    // Creamos un apuntador auxiliar padre igual a root
    TNode<T>* auxFather = root;
    // Creamos un apuntador auxiliar igual a root
    TNode<T>* aux = root;
    // Recorremos el árbol para buscar el nodo
    // hacemos una variable booleana para saber si encontramos el nodo
    bool found = false;
    while (!found) {
        // Validamos si data es igual a aux->data
        if (data == aux->data) {
            // hacemo found igual a true
            found = true;
        } else {
            // Recorremos aux Father
            auxFather = aux;
            // Recorremos aux
            data < aux->data ? aux = aux->left : aux = aux->right;
            if (aux == nullptr) {
                // No se encuentra en el arbol
                return false;
            }
        }
    }
    // Buscamos cuantos hijos tiene el nodo
    int numChildren = children(aux);
    // 0 hijos
    if (numChildren == 0) {
        // Si el nodo a borrar es root
        if (aux == root) {
            // le asignamos nulos a root
            root = nullptr;
        } else { // El nodo no es root (else)
            aux->data < auxFather->data ? auxFather-> left = nullptr : auxFather-> right = nullptr;
            // Si el valor a borrar es menor al valor del padre
                // le asignamos nulos al apuntador del lado izquierdo del padre
            // Si el el valor es mayor o igual al valor del padre
                // le asignamos nulos al apuntador del lado derecho del padre
        }
        // borramos el nodo
        delete aux;
    }
    // 1 hijo
    if (numChildren == 1) {
        // Si el nodo a borrar es root
        if (aux == root) {
            aux->left != nullptr ? root = aux->left : root = aux->right;
            // Si el apuntador del lado izquierdo de root no es nulo (el hijo esta del lado izquierdo)
                // root va a ser igual al apuntador del lado izquierdo de root
            // si el apuntador del lado derecho de root no es nulo (el hijo esta del lado derecho)
                // root va a ser igual al apuntador del lado derecho de root
            // borramos el nodo que estaba en root
        } else { // Si el nodo a borrar no es root (else)
            // Si el valor del nodo a borrar es menor al valor del padre
            if (data < auxFather->data) {
                aux->left != nullptr ? auxFather->left = aux->left : auxFather->left = aux->right;
                // Si el apuntador del lado izquierdo del nodo a borrar no es nulo
                    // El apuntador del lado izquierdo del padre va a ser igual al apuntador del lado izquierdo del nodo a borrar
                // Si el apuntador del lado derecho del nodo a borrar no es nulo (else)
                    // El apuntador del lado izquierdo del padre va a ser igual al apuntador del lado derecho del nodo a borrar
            } else {                    
            // Si el valor del nodo a borrar es mayor o igual al valor del padre (else)
                aux->left != nullptr ? auxFather->right = aux->left : auxFather->right = aux->right;
                // Si el apuntador del lado izquierdo del nodo a borrar no es nulo
                    // El apuntador del lado derecho del padre va a ser igual al apuntador del lado izquierdo del nodo a borrar
                // Si el apuntador del lado derecho del nodo a borrar no es nulo (else)
                    // El apuntador del lado derecho del padre va a ser igual al apuntador del lado derecho del nodo a borrar
            }
        }
        // borramos el nodo
        delete aux;
    }
    // 2 hijos
    if (numChildren == 2) {
        // Si el apuntador del lado derecho del hijo del lado izquierdo del nodo a borrar es nulo (El hijo del lado izquierdo es el mayor)
        if (aux->left->right == nullptr) {
            // El valor del nodo a borrar va a ser igual al valor del hijo del lado izquierdo
            aux->data = aux->left->data;
            // Borramos el hijo del lado izquierdo del nodo a borrar
            TNode<T>* auxRemove = aux->left;
            // El apuntador del lado izquierdo del nodo a borrar va a ser igual al apuntador del lado izquierdo del hijo del lado izquierdo
            aux->left = aux->left->left;
            // Borramos el nodo
            delete auxRemove;
        } else {
        // Si el apuntador del lado derecho del hijo del lado izquierdo del nodo a borrar no es nulo (El hijo del lado izquierdo no es el mayor)
            // Creamos un apuntador auxiliar padre igual al hijo del lado izquierdo del nodo a borrar
            auxFather = aux->left;
            // Creamos un apuntador auxiliar hijo igual al apuntador del lado derecho del nodo auxiliar padre
            TNode<T>* auxChild = auxFather->right;
            // Iteramos mientras el apuntador del lado derecho del apuntador auxiliar hijo es diferente de nulo
            while (auxChild->right != nullptr) {
                // Reccorremos los apuntadores auxiliares
                // El apuntador auxiliar padre va a ser igual al apuntador auxiliar hijo
                auxFather = auxChild;
                // El apuntador auxiliar hijo va a ser igual al apuntador del lado derecho del apuntador auxiliar hijo
                auxChild = auxChild->right;
            }
            // El valor del nodo a borrar va a ser igual al valor del apuntador auxiliar hijo
            aux->data = auxChild->data;
            // El apuntador del lado derecho del auxiliar padre va a ser igual al apuntador del lado izquierdo del apuntador auxiliar hijo
            auxFather->right = auxChild->left;
            // Borramos el apuntador auxiliar hijo
            delete auxChild;
        }
    }
    return true;
}

template <class T>
void AVL<T>::preOrder(TNode<T>* aux) {
    // condición de control
    if (aux != nullptr) {
        // Visita el nodo raíz del arbol
        cout << aux->data << " ";
        // Recorre el preorden el subárbol izquierdo del nodo raíz
        preOrder(aux->left);
        // Recorre el preorden el subárbol derecho del nodo raíz
        preOrder(aux->right);
    }
}


template <class T>
void AVL<T>::inOrder(TNode<T>* aux) {
    // condición de control
    if (aux != nullptr) {
        // Recorre el en orden el subárbol izquierdo del nodo raíz
        inOrder(aux->left);
        // Visita el nodo raíz del arbol
        cout << aux->data << " ";
        // Recorre el en orden el subárbol derecho del nodo raíz
        inOrder(aux->right);
    }
}

template <class T>
void AVL<T>::postOrder(TNode<T>* aux) {
    // condición de control
    if (aux != nullptr) {
        // Recorre el en post orden el subárbol izquierdo del nodo raíz
        postOrder(aux->left);
        // Recorre el en post orden el subárbol derecho del nodo raíz
        postOrder(aux->right);
        // Visita el nodo raíz del arbol
        cout << aux->data << " ";
    }
}

template <class T>
void AVL<T>::levelByLevel(TNode<T>* aux) {
    queue< TNode<T>* > q;
    q.push(aux);
    while (!q.empty()) {
        TNode<T>* aux2 = q.front();
        cout << aux2->data << " ";
        q.pop();
        if (aux2->left != nullptr) {
            q.push(aux2->left);
        }
        if (aux2->right != nullptr) {
            q.push(aux2->right);
        }
    }
}

template <class T>
void AVL<T>::visit(int order) {
    switch (order) {
    case 1:
        preOrder(root);
        cout << endl;
        break;
    case 2:
        inOrder(root);
        cout << endl;
        break;
    case 3:
        postOrder(root);
        cout << endl;
        break;
    case 4:
        levelByLevel(root);
        cout << endl;
        break;
    
    default:
        break;
    }
}

template<class T>
void AVL<T>::printTree(TNode<T>* aux, int level) {
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
void AVL<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The AVL is empty" << endl << endl;
    }
} 

template <class T>
bool AVL<T>::isEmpty() {
    return root == nullptr;
}

template <class T> 
int AVL<T>::nodeHeight(TNode<T>* aux){
    if(aux == nullptr){
        return 0;
    }
    int leftH = nodeHeight(aux->left);
    int rightH = nodeHeight(aux->right);

    return (leftH > rightH) ? leftH + 1 : rightH + 1;
}

template <class T>
int AVL<T>::height() {
    // Creamos un apuntador auxiliar igual a root
    TNode<T>* aux = root;
    return nodeHeight(aux);
    
}

template <class T>
void AVL<T>::ancestors(T data){
    TNode<T>* aux = root;
    AVL<T> anc;
    bool found = false;
    // Creamos un apuntador auxiliar igual a root
    // Recorremos el árbol para buscarlo
    while (aux != nullptr && !found) {
    
        // Validamos si data es igual a aux-data
        if (data == aux->data) {
            found = true;
        } else { 
            //Insertamos ancestro
            anc.insert(aux->data);
            //Recorremos
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    if(found){
        anc.print();
    }
    else{
        cout << "Value not found" << endl;
    }
}

template <class T>
int AVL<T>::whatLevelAml(T data){
    TNode<T>* aux = root;
    int level = 0;

    // Creamos un apuntador auxiliar igual a root
    // Recorremos el árbol para buscarlo
    while (aux != nullptr ) {
        level ++;
        // Validamos si data es igual a aux-data
        if (data == aux->data) {
            return level;
        } else { 
            //Recorremos
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    return -1;
}

template <class T>
void AVL<T>::calcFB(){
    int leftH = nodeHeight(root->left);
    int rightH = nodeHeight(root->right);
    FB =  rightH - leftH;
}
template <class T>
void AVL<T>::rotate(){
    calcFB();
    switch (FB)
    {
    case -2:
    {
        break;
    }
    case 2:{
        break;
    }
    default:
        break;
    }
}

template <class T>
void AVL<T>::RotateIzq(){
    TNode<T>* aux = root;
}
template <class T>
void AVL<T>::RotateIzqD(){
    
}
template <class T>
void AVL<T>::RotateRight(){
    
}
template <class T>
void AVL<T>::RotateRightD(){
    
}
#endif 