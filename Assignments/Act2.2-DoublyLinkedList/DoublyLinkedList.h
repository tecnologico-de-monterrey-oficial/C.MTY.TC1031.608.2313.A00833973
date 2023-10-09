#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h
#include "DNode.h"
template <class T>
class DoublyLinkedList
{
private:
    DNode<T>* head;
    DNode<T>* tail;
    int size;


public: 
    //Constructor
    DoublyLinkedList();
    ~DoublyLinkedList();   

    //Getters
    T getData(int);
    T getFirst();
    T getLast();
    int getSize();
    
    //Add elements
    void addFirst(T);
    void addLast(T);
    void insert(int, T);
    
    //Delete
    bool deleteData(T);
    bool deleteAt(int);
    void removeFront();
    void removeBack();
    void clear();

    //Update
    bool updateData(T,T);
    bool updateAt(int, T);

    //Index
    int findData(T);

    //Duplicated
    void duplicate();
    void removeDuplicate();

    //Prints
    void print();
    void print(bool);
    void printReverse();
    void printForward();

    //
    bool isEmpty();
    void sort();

    //Operators
    T& operator[](int);
    void operator=(DoublyLinkedList);

};

//Inicializa en nulo todos los elementos 
/// @complexity O(1)
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/// @brief Destructor de la clase DoublyLinkedList.
/// @complexity O(n)
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    DNode<T>* temp; // Declarar un puntero auxiliar para eliminar nodos.

    // Iterar a través de la lista mientras haya nodos para eliminar.
    while (head != nullptr)
    {
        temp = head;     // Almacenar una referencia al nodo actual.
        head = head->next; // Avanzar al siguiente nodo.
        delete temp;      // Liberar la memoria del nodo actual.
    }

    // Establecer `head` y `tail` en `nullptr` y el tamaño en 0.
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/// @brief Obtiene el primer elemento de la lista.
/// @return T: El valor del primer elemento de la lista.
/// @complexity O(1)
template <class T>
T DoublyLinkedList<T>::getFirst()
{
    return head->data; // Retorna el valor almacenado en el nodo `head`.
}

/// @brief Obtiene el último elemento de la lista.
/// @return T: El valor el último elemento de la lista.
/// @complexity O(1)
template <class T>
T DoublyLinkedList<T>::getLast()
{
    return tail->data; // Retorna el valor almacenado en el nodo `tail`.
}

/**
 * @brief Agrega un elemento al principio de la lista.
 * @param data (T): El valor del elemento que se va a agregar.
 * @complexity O(1)
 */
template <class T>
void DoublyLinkedList<T>::addFirst(T data)
{
    // Crear un nuevo nodo para el nuevo elemento.
    DNode<T>* aux = new DNode<T>;
    aux->data = data;

    if (isEmpty())
    {
        // Si la lista está vacía, el nuevo nodo se convierte en el único elemento.
        head = aux;
        tail = aux;
    }
    else
    {
        // Si la lista no está vacía, el nuevo nodo se agrega antes del nodo actual `head`.
        aux->next = head;
        head->prev = aux;
        head = aux;
    }

    size++; // Aumentar el tamaño de la lista.
}

/**
 * @brief Agrega un elemento al final de la lista.
 * @param data (T): El valor del elemento que se va a agregar.
 * @complexity O(1)
 */
template <class T>
void DoublyLinkedList<T>::addLast(T data)
{
    // Crear un nuevo nodo para el nuevo elemento.
    DNode<T>* aux = new DNode<T>;
    aux->data = data;

    if (isEmpty())
    {
        // Si la lista está vacía, el nuevo nodo se convierte en el único elemento.
        head = aux;
        tail = aux;
    }
    else
    {
        // Si la lista no está vacía, el nuevo nodo se agrega después del nodo actual `tail`.
        aux->prev = tail;
        tail->next = aux;
        tail = aux;
    }

    size++; // Aumentar el tamaño de la lista.
}

/**
 * @brief Inserta un elemento en una posición específica de la lista.
 * @param index (int): La posición en la que se va a insertar el elemento.
 * @param data (T): El valor del elemento que se va a insertar.
 * @complexity O(n)
 */
template <class T>
void DoublyLinkedList<T>::insert(int index, T data)
{
    DNode<T>* aux;

    try
    {
        if (isEmpty())
        {
            throw std::out_of_range("Lista vacía"); // Excepción si la lista está vacía.
        }

        if (index >= 0 && index < size)
        {
            if (index == 0)
            {
                addFirst(data); // Insertar al principio si la posición es 0.
                return;
            }

            if (index <= (size - 1) / 2)
            {
                aux = head;
                for (int i = 0; i < index - 1; i++)
                {
                    aux = aux->next; // Avanzar hacia el nodo anterior al índice.
                }
            }
            else
            {
                aux = tail;
                for (int i = size - 1; i >= index; i--)
                {
                    aux = aux->prev; // Retroceder desde el final hacia el nodo en el índice.
                }
            }

            // Crear un nuevo nodo y enlazarlo en la posición dada.
            DNode<T>* aux2 = new DNode<T>(data, aux, aux->next);
            aux->next = aux2;

            if (aux2->next == nullptr)
            {
                tail = aux2; // Actualizar el puntero `tail` si es necesario.
            }
            else
            {
                aux2->next->prev = aux2;
            }

            size++; // Incrementar el tamaño de la lista.
        }
        else
        {
            throw std::out_of_range("Índice fuera de rango"); // Excepción si el índice está fuera de rango.
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


/**
 * @brief Elimina la primera instancia de un elemento con un valor específico.
 * @param find (T): El valor del elemento que se desea eliminar.
 * @return bool: `true` si se eliminó correctamente, `false` si no se encontró el elemento.
 * @complexity O(n)
 */
template <class T>
bool DoublyLinkedList<T>::deleteData(T find)
{
    try
    {
        int index = findData(find); // Buscar la posición del elemento con el valor especificado.

        if (index == -1)
        {
            throw std::runtime_error("Elemento no encontrado"); // Lanzar una excepción si no se encuentra el elemento.
        }

        return deleteAt(index); // Llamar a la función de eliminación en la posición encontrada.
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return false; // Devolver `false` si no se encontró el elemento.
}
 

/**
 * @brief Elimina un elemento en una posición específica de la lista.
 * @param index (int): La posición del elemento que se va a eliminar.
 * @return bool: `true` si se eliminó correctamente, `false` si ocurrió un error.
 * @complexity O(n)
 */
template <class T>
bool DoublyLinkedList<T>::deleteAt(int index)
{
    try
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Índice fuera de rango"); // Excepción si el índice está fuera de rango.
        }

        DNode<T>* aux = head;
        DNode<T>* del;

        for (int i = 0; i < index; i++)
        {
            aux = aux->next; // Avanzar hacia el nodo en el índice.
        }

        del = aux; // Almacenar una referencia al nodo a eliminar.

        // Comprobar si es el primer elemento.
        if (index == 0)
        {
            removeFront(); // Llamar a la función para eliminar el primer elemento.
            return true;
        }

        // Comprobar si es el último elemento.
        if (index == size - 1)
        {
            removeBack(); // Llamar a la función para eliminar el último elemento.
            return true;
        }

        aux->prev->next = del->next; // Actualizar punteros para saltar el nodo a eliminar.
        aux->next->prev = del->prev;

        delete del; // Liberar la memoria del nodo eliminado.
        size--; // Reducir el tamaño de la lista.

        return true;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return false; // Devolver `false` en caso de error.
}


/**
 * @brief Actualiza la primera instancia de un elemento con un valor específico.
 * @param find (T): El valor del elemento que se desea encontrar y reemplazar.
 * @param replace (T): El nuevo valor con el que se desea reemplazar el elemento.
 * @return bool: `true` si se actualizó correctamente, `false` si no se encontró el elemento.
 * @complexity O(n)
 */
template <class T>
bool DoublyLinkedList<T>::updateData(T find, T replace)
{
    try
    {
        int index = findData(find); // Buscar la posición del elemento con el valor especificado.

        if (index == -1)
        {
            throw std::runtime_error("Elemento no encontrado"); // Lanzar una excepción si no se encuentra el elemento.
        }

        return updateAt(index, replace); // Llamar a la función de actualización en la posición encontrada.
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return false; // Devolver `false` si no se encontró el elemento.
}


/**
 * @brief Actualiza el elemento en una posición específica de la lista.
 * @param index (int): La posición del elemento que se desea actualizar.
 * @param replace (T): El nuevo valor con el que se desea reemplazar el elemento.
 * @return bool: `true` si se actualizó correctamente, `false` si ocurrió un error.
 * @complexity O(n)
 */
template <class T>
bool DoublyLinkedList<T>::updateAt(int index, T replace)
{
    try
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Índice fuera de rango"); // Excepción si el índice está fuera de rango.
        }

        DNode<T>* aux = head;

        for (int i = 0; i < index; i++)
        {
            aux = aux->next; // Avanzar hacia el nodo en el índice.
        }

        aux->data = replace; // Actualizar el valor del elemento en la posición especificada.

        return true; // Devolver `true` para indicar que la actualización se realizó correctamente.
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return false; // Devolver `false` en caso de error.
}


/**
 * @brief Busca la primera instancia de un elemento con un valor específico en la lista.
 * @param data (T): El valor del elemento que se desea buscar.
 * @return int: La posición del elemento si se encuentra, o -1 si no se encontró.
 * @complexity O(n)
 *
 */
template <class T>
int DoublyLinkedList<T>::findData(T data)
{
    DNode<T>* aux = head; // Iniciar desde el primer nodo.
    
    try
    {
        if (isEmpty())
        {
            throw std::out_of_range("Lista vacía"); // Lanzar una excepción si la lista está vacía.
        }

        int i = 0; // Inicializar una variable para almacenar la posición.

        while (i < size)
        {
            if (aux->data == data)
            {
                return i; // Devolver la posición de la primera instancia del elemento encontrado.
            }

            aux = aux->next; // Avanzar al siguiente nodo.
            i++; // Incrementar la posición.
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return -1; // Devolver -1 si no se encontró el elemento.
}

/**
 * @brief Elimina todos los elementos de la lista y libera la memoria. La lista quedará vacía y su tamaño
 * será igual a cero.
 * @complexity O(n)
 */
template <class T>
void DoublyLinkedList<T>::clear()
{
    DNode<T>* temp;

    for (int i = 0; i < size; i++)
    {
        temp = head; // Almacena el nodo actual.
        head = head->next; // Avanza al siguiente nodo.
        delete temp; // Libera la memoria del nodo anterior.
    }

    size = 0; // Establece el tamaño de la lista como cero después de eliminar todos los elementos.
}

/**
 * @brief Ordena la lista en orden ascendente utilizando el algoritmo Quick Sort.
 * @complexity O(nlogn)
 */
template <class T>
void DoublyLinkedList<T>::sort()
{
    quickSort(head, tail); // Llama a la función quickSort para ordenar la lista.
}

/**
 * @brief Duplica cada elemento de la lista en su posición actual.
 * @complexity O(n)
 */
template <class T>
void DoublyLinkedList<T>::duplicate()
{
    DNode<T>* aux = head; // Iniciar desde el primer nodo.

    for (int i = 0; i < size; i += 2)
    {
        T data = aux->data; // Obtener el valor del elemento actual.
        insert(i, data); // Insertar una copia del elemento en la misma posición.
        aux = aux->next; // Avanzar al siguiente nodo.
    }
}

/**
* @brief Elimina los elementos duplicados de la lista.
* @complexity O(n^2)
*/
template <class T>
void DoublyLinkedList<T>::removeDuplicate()
{
    if (size <= 1)
    {
        return; // No se eliminan duplicados si la lista tiene 0 o 1 elemento.
    }

    DNode<T>* aux = head;
    DNode<T>* aux2;

    for (int i = 1; i < size; i++)
    {
        aux2 = aux->next; // Avanzar al siguiente nodo.
        for (int j = i; j < size; j++)
        {
            if (aux->data == aux2->data) // En caso de encontrar un nodo duplicado
            {
                DNode<T>* curr = aux2->next; // Mantener una referencia al siguiente nodo.
                deleteAt(j - 1); // Eliminar el nodo duplicado.
                aux->next = curr; // Actualizar el puntero next.
                aux2 = aux->next; // Avanzar al siguiente nodo.
            }
            else
            {
                aux2 = aux2->next; // Avanzar al siguiente nodo.
            }
        }
        aux = aux->next; // Avanzar al siguiente nodo.
    }
}


/**
 * @brief Elimina el primer elemento de la lista.
 * @complexity O(1)
 */
template <class T>
void DoublyLinkedList<T>::removeFront()
{
    DNode<T>* aux = head; // Almacena el nodo actual.
    head->next->prev = aux->next; // Actualiza el puntero prev del siguiente nodo.
    head = aux->next; // Actualiza la cabeza de la lista para apuntar al siguiente elemento.
    head->prev = nullptr; // Establece el puntero prev de la nueva cabeza como nullptr.
    size--; // Reduce el tamaño de la lista en uno.
    delete aux; // Libera la memoria del elemento eliminado.
}

/**
 * @brief Elimina el último elemento de la lista.
 * Complejidad: O(1) 
 */
template <class T>
void DoublyLinkedList<T>::removeBack()
{
    DNode<T>* aux = tail; // Almacena el nodo actual (el último).
    
    tail->prev->next = aux->prev; // Actualiza el puntero next del nodo anterior para saltar el elemento eliminado.
    tail = tail->prev; // Actualiza la cola de la lista para apuntar al elemento anterior.
    tail->next = nullptr; // Establece el puntero next del nuevo último elemento como nullptr.
    
    size--; // Reduce el tamaño de la lista en uno.
    
    delete aux; // Libera la memoria del elemento eliminado.
}


template <class T>
void DoublyLinkedList<T>::print(){
    printForward();
}

template <class T>
void DoublyLinkedList<T>::print(bool forward){
    if(forward){
        printForward();
    }
    else{
        printReverse();
    }
}

/**
 * @brief Imprime los elementos de la lista doblemente enlazada en orden descendente.
 * Complejidad: O(n) 
 */
template <class T>
void DoublyLinkedList<T>::printReverse()
{
    DNode<T>* aux = tail; // Inicializa un puntero auxiliar al final de la lista.

    while (aux != nullptr)
    {
        cout << aux->data; // Imprime el valor del nodo actual.
        if (aux->prev != nullptr)
        {
            cout << " <- "; // Imprime una flecha "<-" si hay más elementos en la lista en sentido inverso.
        }
        aux = aux->prev; // Retrocede al nodo anterior.
    }
    cout << endl; // Imprime una nueva línea al final para mejorar la legibilidad.
}


/**
 * @brief Imprime los elementos de la lista doblemente enlazada en orden ascendente.
 * Complejidad: O(n) 
 */
template <class T>
void DoublyLinkedList<T>::printForward()
{
    DNode<T>* aux = head; // Inicializa un puntero auxiliar al principio de la lista.

    while (aux != nullptr)
    {
        cout << aux->data; // Imprime el valor del nodo actual.
        if (aux->next != nullptr)
        {
            cout << " -> "; // Imprime una flecha "->" si hay más elementos en la lista en sentido ascendente.
        }
        aux = aux->next; // Avanza al siguiente nodo.
    }
    cout << endl; // Imprime una nueva línea al final para mejorar la legibilidad.
}


template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
    return size == 0; // Devuelve true si el tamaño de la lista es igual a cero, indicando que está vacía.
}


template <class T>
int DoublyLinkedList<T>::getSize(){
    return size;
}   

/**
 * @brief Obtiene el valor del elemento en la posición especificada.
 * @param index (int): La posición del elemento que se desea obtener.
 * @return El valor del elemento en la posición indicada.
 * Complejidad: O(n) - Tiempo lineal en peor caso, donde "n" es el número de elementos en la lista.
 */
template <class T>
T DoublyLinkedList<T>::getData(int index)
{
    try {if (index >= 0 && index < size)
    {
        DNode<T>* aux;

        // Verifica si el índice está en la primera mitad de la lista para acelerar la búsqueda.
        if (index <= (size - 1) / 2)
        {
            int auxIndex = 0;
            aux = head;

            // Recorre la lista desde el principio hasta la posición deseada.
            while (auxIndex != index)
            {
                aux = aux->next;
                auxIndex++;
            }
        }
        else
        {
            int auxIndex = size - 1;
            aux = tail;

            // Recorre la lista desde el final hasta la posición deseada (en sentido inverso).
            while (auxIndex != index)
            {
                aux = aux->prev;
                auxIndex--;
            }
        }
        
        return aux->data; // Devuelve el valor del elemento en la posición indicada.
    }
    else
    {
        throw out_of_range("El índice no se encuentra en la lista"); 
        // Lanza una excepción si el índice está fuera de rango.
    }
    }
    
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


template <class T>
T& DoublyLinkedList<T>::operator[](int index) {
    try{
        if (index >= 0 && index < size) {
            DNode<T>* aux;
            if (index <= (size - 1) / 2) {
                int auxIndex = 0;
                aux = head;
                while (auxIndex != index) {
                    aux = aux->next;
                    auxIndex++;
                } 
            } else {
                int auxIndex = size - 1;
                aux = tail;
                while (auxIndex != index) {
                    aux = aux->prev;
                    auxIndex--;
                } 
            }
            return aux->data;
        } else {
            throw out_of_range("Índice fuera de rango");
        } 
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

/**
 * @brief Sobrecarga del operador de asignación (=) para copiar el contenido de otra lista.
 * @param list (DoublyLinkedList<T>): La lista desde la cual se copiarán los elementos.
 * Complejidad: O(n)
 */
template <class T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> list)
{
    clear(); // Borra todos los elementos de la lista actual.

    DNode<T>* b = list.head;

    // Copia los elementos de la lista "list" a la lista actual.
    while (b != nullptr)
    {
        addLast(b->data);
        b = b->next;
    }
}



//  QUICK SORT
/**
 * @brief Intercambia los valores de dos nodos en una lista doblemente enlazada.
 * @param a (DNode<T>*): Puntero al primer nodo cuyo valor se va a intercambiar.
 * @param b (DNode<T>*): Puntero al segundo nodo cuyo valor se va a intercambiar.
 * Complejidad: O(1) - Tiempo constante, ya que simplemente se intercambian los valores de los nodos.
 */
template <class T>
void swap(DNode<T>* a, DNode<T>* b)
{
    if (a->data != b->data) // Comprueba si los valores de los nodos son diferentes antes de intercambiar.
    {
        T auxData = a->data; // Almacena temporalmente el valor del primer nodo en una variable auxiliar.
        a->data = b->data;   // Asigna el valor del segundo nodo al primer nodo.
        b->data = auxData;   // Asigna el valor almacenado temporalmente al segundo nodo.
    }
}

/**
 * @brief Encuentra el pivote para el algoritmo de ordenamiento quicksort.
 *
 * @param left (DNode<T>*): Puntero al nodo izquierdo (inicio del subarreglo).
 * @param right (DNode<T>*): Puntero al nodo derecho (fin del subarreglo).
 * @return Puntero al nodo pivote.
 *
 * Complejidad: O(n) 
 */
template <class T>
DNode<T>* getPivot(DNode<T>* left, DNode<T>* right)
{
    T pivot = right->data; // Selecciona el valor del nodo "right" como pivote.
    DNode<T>* i = left->prev; // Inicializa un puntero "i" al nodo anterior a "left".

    for (DNode<T>* j = left; j != right; j = j->next)
    {
        if (j->data <= pivot)
        {
            i = (i == nullptr) ? left : i->next; // Avanza el puntero "i" si no es nulo.
            swap(i, j); // Intercambia los valores de los nodos "i" y "j" si se cumple la condición.
        }
    }

    i = (i == nullptr) ? left : i->next; // Avanza el puntero "i" si no es nulo.
    swap(i, right); // Intercambia el valor del nodo "i" con el del nodo "right" (pivote).

    return i; // Devuelve el puntero al nodo pivote.
}

/**
 * @brief Ordena un subarreglo de una lista doblemente enlazada utilizando el algoritmo de ordenamiento quicksort.
 * @param left (DNode<T>*): Puntero al primer nodo del subarreglo a ordenar.
 * @param right (DNode<T>*): Puntero al último nodo del subarreglo a ordenar.
 * Complejidad: O(n log n) 
 */
template <class T>
void quickSort(DNode<T>* left, DNode<T>* right)
{
    if (right != nullptr && left != right && left != right->next)
    {
        DNode<T>* pivot = getPivot(left, right); // Obtiene el nodo pivote para el subarreglo.
        quickSort(left, pivot->prev); // Ordena la parte izquierda del subarreglo.
        quickSort(pivot->next, right); // Ordena la parte derecha del subarreglo.
    }
}

#endif