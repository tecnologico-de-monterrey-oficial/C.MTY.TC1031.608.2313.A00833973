#ifndef MinHeap_h
#define MinHeap_h

#include <vector>

template <class T>
class MinHeap
{
private:
    vector<T> heap;
    void swap(int a, int b);
    void downSort(int father);

public:
    MinHeap();
    MinHeap(vector<T> list);
    MinHeap(initializer_list<T> list);
    T pop();
    T top();
    void push(T data);
    void print();
    int getSize();
    bool isEmpty();
};

template <class T>
MinHeap<T>::MinHeap()
{
}

template <class T>
void MinHeap<T>::swap(int a, int b)
{
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void MinHeap<T>::downSort(int father)
{
    int son1;
    int son2;
    int small;
    // Recorremos el heap en base a si father sigue teniendo hijos
    while (father * 2 + 1 < heap.size())
    {
        // Actualizamos el indice del primer hijo
        son1 = father * 2 + 1;
        // Validamos si tiene otro hijo
        if (father * 2 + 2 < heap.size())
        {
            // Actualizamos el indice del segundo hijo
            son2 = father * 2 + 2;
            // comparamos cual es el más chico de los hijos
            heap[son1] < heap[son2] ? small = son1 : small = son2;
        }
        else
        {
            // son1 va a ser el hijo más chico
            small = son1;
        }
        // Comparamos si el más chico de los hijos es más chico a father
        if (heap[small] < heap[father])
        {
            // intercambiamos father con big
            swap(father, small);
            // Cambiamos el valor del padre por el más chico de los hijos
            father = small;
        }
        else
        {
            // Nos vamos a salir del ciclo
            father = heap.size();
        }
    }
}

template <class T>
MinHeap<T>::MinHeap(vector<T> list)
{
    // Actualizar el vector heap igual a list
    heap = list;
    // Encontramos cual es el último de los padres
    int father = heap.size() / 2 - 1;
    // Recorremos cada uno de los padres hasta el primero
    while (father >= 0)
    {   
        // Hacemos el downSort de father
        downSort(father);
        // Recorremos al padre anterior
        father--;
    }
}

template <class T>
MinHeap<T>::MinHeap(initializer_list<T> list) {
    // Actualizar el vector heap igual a list
    heap = list;
    // Encontramos cual es el último de los padres
    int father = heap.size() / 2 - 1;
    // Recorremos cada uno de los padres hasta el primero
    while (father >= 0)
    {   
        // Hacemos el downSort de father
        downSort(father);
        // Recorremos al padre anterior
        father--;
    }
}

template <class T>
T MinHeap<T>::pop() {
    // Validamos si el heap esta vacío
    if (!isEmpty()) {
        // Guardamos el valro del elemento del mayor prioridad
        T aux = heap[0];
        // Intercambios el primero con el último
        swap(0, heap.size()-1);
        // Eliminamos el último elemento del heap
        heap.pop_back();
        // Reacomodamos hacía abajo el primer elemento
        downSort(0);
        // Regresmos el valor de mayor prioridad que esta guardado en aux
        return aux;
    } else {
        throw out_of_range("El heap está vacío");
    }
}

template <class T>
void MinHeap<T>::push(T data) {
    // Agregamos un elemento al final de la lista
    heap.push_back(data);
    // Creamos un a variable auxiliar que va a ser a la última posición del heap
    int son = heap.size()-1;
    // Comparamos con sus papás
    while (son > 0) {
        // Calculamos cual es su papá
        int father = (son - 1) / 2;
        // Comparamos si el hijo es menor que el padre
        if (heap[son] < heap[father]) {
            // Los intercambiamos
            swap(father, son);
            // Cambiamos el hijo por el padre
            son = father;
        } else {
            // Nos salimos del ciclo
            son = 0;
        }
    }
}
template <class T>
T MinHeap<T>::top(){
    if (isEmpty()){
        throw out_of_range("The list doesn't have elements");
    }else{
        return heap[0];
    }
    
}

template <class T>
bool MinHeap<T>::isEmpty() {
    return heap.empty();
}

template <class T>
void MinHeap<T>::print()
{
    for (auto el : heap)
    {
        cout << el << " ";
    }
    cout << endl;
}

template <class T>
int MinHeap<T>::getSize()
{
    return heap.size();
}

#endif /* MinHeap_h */