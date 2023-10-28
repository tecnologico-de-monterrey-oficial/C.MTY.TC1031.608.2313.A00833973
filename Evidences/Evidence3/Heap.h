#ifndef Heap_h
#define Heap_h

#include <vector>

template <class T>
class Heap
{
private:
    vector<T> heap;
    void swap(int a, int b);
    void downSort(int father);

public:
    Heap();
    Heap(vector<T> list);
    Heap(initializer_list<T> list);
    T pop();
    void push(T data);
    void print();
    int getSize();
    T top();
    bool isEmpty();
    vector<T> & getCopy();
};
 
template <class T>
Heap<T>::Heap()
{
}

template <class T>
void Heap<T>::swap(int a, int b)
{
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
vector<T> & Heap<T>::getCopy(){
    return heap;
}
template <class T>
void Heap<T>::downSort(int father)
{
    int son1;
    int son2;
    int big;
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
            // comparamos cual es el más grande de los hijos
            heap[son1] > heap[son2] ? big = son1 : big = son2;
        }
        else
        {
            // son1 va a ser el hijo más grande
            big = son1;
        }
        // Comparamos si el más grande de los hijos es más grande a father
        if (heap[big] > heap[father])
        {
            // intercambiamos father con big
            swap(father, big);
            // Cambiamos el valor del padre por el más grande de los hijos
            father = big;
        }
        else
        {
            // Nos vamos a salir del ciclo
            father = heap.size();
        }
    }
}


template <class T>
Heap<T>::Heap(vector<T> list)
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
Heap<T>::Heap(initializer_list<T> list) {
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
T Heap<T>::pop() {
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
void Heap<T>::push(T data) {
    // Agregamos un elemento al final de la lista
    heap.push_back(data);
    // Creamos un a variable auxiliar que va a ser a la última posición del heap
    int son = heap.size()-1;
    // Comparamos con sus papás
    while (son > 0) {
        // Calculamos cual es su papá
        int father = (son - 1) / 2;
        // Comparamos si el hijo es mayor que el padre
        if (heap[son] > heap[father]) {
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
T Heap<T>::top(){
    if (isEmpty()){
        throw out_of_range("The list doesn't have elements");
    }else{
        return heap[0];
    }
    
}
template <class T>
bool Heap<T>::isEmpty() {
    return heap.empty();
}

template <class T>
void Heap<T>::print()
{
    for (auto el : heap)
    {
        cout << el << " ";
    }
    cout << endl;
}

template <class T>
int Heap<T>::getSize()
{
    return heap.size();
}

#endif /* Heap_h */