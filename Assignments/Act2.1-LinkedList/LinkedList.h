#ifndef LinkedList_h
#define LinkedList_h
#include "Node.h"

template <class T>

class LinkedList
{
private:
    Node<T>* head;
    int size;
public:
    //Constructores
    LinkedList();

    //Getters 
    int getSize();

    //Agregar datos
    void addFirst(T data);
    void addLast(T data);
    void insert(int, T);

    //Borrar datos
    bool deleteData(T);
    bool deleteAt(int);

    T getData(int); //Obtener datos

    //Actualizar datos
    void updateData(T,T);
    void updateAt(int, T);

    //Busqueda
    int findData(T);

    //Operadores
    T& operator[](int);
    void  operator = (LinkedList<T>);


    void print(); //Imprimir 
    bool isEmpty(); //Lista vacía
    void clear(); //Borrar datos de la lista
};


// Constructor default, inicia en null 
template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    size = 0;

}

// Regresa el número de elementos en la lista
template <class T>
int LinkedList<T>::getSize()
{
    return size;
}

// Agrega un nuevo elemento al inicio de la lista
/// @param data (T): valor nuevo que se quiere ingresar

template <class T>
void LinkedList<T>::addFirst(T data){
    //Asignar un nuevo nodo a head este va a contener el valor de data y va a apaturar a head;
    head = new Node(data, head);
    size++; //Aumentar el tamaño
}

/// @brief Agrega un nuevo elemento al final de la lista
/// @param data (T): valor nuevo que se quiere ingresar

template <class T>
void LinkedList<T>::addLast(T data){

    Node<T> *aux = head; // Nodo auxiliar para recorrer la lista
    if (isEmpty()){
        addFirst(data);  // En caso de lista vacía agregar al inicio 
    }else{
        while (aux->next != nullptr){ //Recorrer la lista hasta el final
            aux = aux->next;
        }
        // Al alcanzar al final se agrega un nuevo nodo en la propiedad next
        aux->next = new Node<T>(data);  
        size++; // Aumentar el tamaño
    }
    
}

/// @brief Agrega un nuevo nodo en la posición brindada
/// @tparam T 
/// @param index (int): posición en la que va el dato
/// @param data (T): valor del dato

template <class T>
void LinkedList<T>::insert(int index, T data){

    if (size > index && index >= 0){ // Validar que el índice este en el rango
        Node<T> *aux = head; //aux para recorrer la fila
        if(index == 0){
            addFirst(data); // Agregar al principio si indice ==? 0;
        }
        else{
            for(int i = 0; i < index-1 ; i++){ //Recorrer hasta un punto antes del índice
            aux = aux->next;
            }
            //En next del nodo agregar nuevo cuyo next es igual al anterior next; 
            aux->next = new Node(data, aux->next); 
        }
        size++; // Aumentar tamaño
        
    }
    else{
        throw std::out_of_range("Índice fuera de rango"); 
    }
    
}
/**
 * @brief Elimina la primera aparición del dato especificado de la lista.
 * @param data (T): El valor del dato que se desea eliminar.
 * @return true si se encontró y eliminó el dato, false si no se encontró.
 *
 **/
template <class T>
bool LinkedList<T>::deleteData(T data){
    // Busca la posición del dato en la lista.
    int index = findData(data);
    if (index >= 0 && index < size){

        // Inicializa punteros auxiliares.
        Node<T> *aux = head;
        Node<T> *aux2 = aux->next;

        // Recorre la lista hasta la posición anterior al dato que se va a eliminar.
        for (int i = 0; i <index-1 ; i ++){
            aux = aux->next;
            aux2 = aux2->next;
        }
        // Conecta el nodo anterior al nodo siguiente, eliminando así el nodo con el dato.
        if (aux2->next!= nullptr){
            aux->next = aux2->next;
        }else{
            // Conecta el nodo anterior al nodo siguiente, eliminando así el nodo con el dato.
            aux->next = nullptr;  
        }

        // Libera la memoria del nodo eliminado.
        delete aux2;
        size--; // Reduce el tamaño de la lista.
        return true; // Indica que se encontró y eliminó el dato.
    }
    else{
        // Si el índice está fuera de rango, lanza una excepción.
        throw std::out_of_range("Índice fuera de rango");
    }
    return false; // Si el índice está fuera de rango, lanza una excepción.
    
}

/**
 * @brief Elimina el elemento en la posición especificada de la lista.
 * @param index (int): La posición del elemento que se desea eliminar.
 * @return true si se encontró y eliminó el elemento, false si no se encontró.
 */
template <class T>
bool LinkedList<T>::deleteAt(int index){
    // Verifica si el índice está dentro del rango válido.
    if (index >= 0 && index < size){
        // Inicializa punteros auxiliares.
        Node<T> *aux = head;
        Node<T> *aux2 = aux->next;

        // Recorre la lista hasta la posición anterior a la del elemento que se va a eliminar.
        for (int i = 0; i < index - 1; i++){
            aux = aux->next;
            aux2 = aux2->next;
        }

        // Conecta el nodo anterior al nodo siguiente, eliminando así el nodo en la posición index.
        if (aux2->next != nullptr){
            aux->next = aux2->next;
        } else {
            // Si el nodo a eliminar es el último de la lista, ajusta el puntero next del nodo anterior a nullptr.
            aux->next = nullptr;
        }

        // Libera la memoria del nodo eliminado.
        delete aux2;
        size--; // Reduce el tamaño de la lista.
        return true; // Indica que se encontró y eliminó el elemento.
    } else {
        // Si el índice está fuera de rango, lanza una excepción.
        throw std::out_of_range("Índice fuera de rango");
    }
    return false; // Devuelve false si no se encontró el elemento en la lista.
}

/**
 * @brief Busca la primera aparición del dato especificado en la lista.
 * @param data (T): El valor del dato que se desea buscar.
 * @return El índice de la primera aparición del dato o -1 si no se encuentra.
 */
template <class T>
int LinkedList<T>::findData(T data){
    // Inicializa un puntero auxiliar para recorrer la lista.
    Node<T> *aux = head;
    int i = 0; // Variable para almacenar el índice actual.

    // Recorre la lista mientras se busca el dato.
    while (i < size){
        if(aux->data == data){
            return i; // Devuelve el índice si se encuentra el dato.
        }
        aux = aux->next; // Avanza al siguiente nodo.
        i++; // Incrementa el índice.
    }
    return -1; // Devuelve -1 si no se encuentra el dato en la lista.
}


/**
 * @brief Actualiza el valor de la primera aparición del dato especificado en la lista.
 * @param find (T): El valor del dato que se desea buscar y actualizar.
 * @param data (T): El nuevo valor que se desea asignar al dato encontrado.
 *
 * Esta función busca la primera aparición del dato especificado en la lista y actualiza su valor
 * con el nuevo valor proporcionado. Si no se encuentra el dato, no se realiza ninguna acción.
 */
template <class T>
void LinkedList<T>::updateData(T find, T data){
    // Busca la posición del dato en la lista.
    int index = findData(find);

    // Verifica si se encontró el dato en la lista.
    if (index >= 0 && index < size){
        Node<T> *aux = head;

        // Avanza al nodo correspondiente.
        for (int i = 0; i < index; i++){
            aux = aux->next;
        }

        // Actualiza el valor del dato con el nuevo valor proporcionado.
        aux->data = data;
    }
    // No se realiza ninguna acción si el dato no se encuentra en la lista.
}

/**
 * @brief Actualiza el valor del elemento en la posición especificada de la lista.
 *
 * @param index (int): La posición del elemento que se desea actualizar.
 * @param data (T): El nuevo valor que se desea asignar al elemento en la posición especificada.
 *
 * Esta función actualiza el valor del elemento en la posición especificada de la lista
 * con el nuevo valor proporcionado. Si el índice está fuera de rango, se lanza una excepción.
 */
template <class T>
void LinkedList<T>::updateAt(int index, T data){
    // Verifica si el índice está dentro del rango válido.
    if (index >= 0 && index < size){
        Node<T> *aux = head;

        // Avanza al nodo correspondiente.
        for (int i = 0; i < index; i++){
            aux = aux->next;
        }

        // Actualiza el valor del elemento en la posición especificada con el nuevo valor proporcionado.
        aux->data = data;
    } else {
        // Si el índice está fuera de rango, lanza una excepción.
        throw std::out_of_range("Índice fuera de rango");
    }
}


/**
 * @brief Obtiene el valor del elemento en la posición especificada de la lista.
 *
 * @param index (int): La posición del elemento del cual se desea obtener el valor.
 *
 * @return El valor del elemento en la posición especificada.
 *
 * Esta función retorna el valor del elemento en la posición especificada de la lista.
 * Si el índice está fuera de rango, se lanza una excepción.
 */
template <class T>
T LinkedList<T>::getData(int index){
    // Inicializa un puntero auxiliar para recorrer la lista.
    Node<T> *aux = head;

    // Verifica si el índice está dentro del rango válido.
    if (index >= 0 && index < size){
        // Avanza al nodo correspondiente.
        for (int i = 0; i < index; i++){
            aux = aux->next;
        }

        // Retorna el valor del elemento en la posición especificada.
        return aux->data;
    } else {
        // Si el índice está fuera de rango, lanza una excepción.
        throw std::out_of_range("Índice fuera de rango");
    }
}


/**
 * @brief Acceso a elementos de la lista mediante el operador [].
 *
 * @param index (int): La posición del elemento al que se desea acceder.
 *
 * @return Una referencia al valor del elemento en la posición especificada.
 *
 * Esta función permite acceder a elementos de la lista utilizando el operador de corchetes ([]) 
 * como si fuera un arreglo. Retorna una referencia al valor del elemento en la posición especificada.
 * Si el índice está fuera de rango, se lanza una excepción.
 */
template <class T>
T& LinkedList<T>::operator[](int index){
    // Inicializa un puntero auxiliar para recorrer la lista.
    Node<T> *aux = head;

    // Verifica si el índice está dentro del rango válido.
    if (index >= 0 && index < size){
        // Avanza al nodo correspondiente.
        for (int i = 0; i < index; i++){
            aux = aux->next;
        }

        // Retorna una referencia al valor del elemento en la posición especificada.
        return aux->data;
    } else {
        // Si el índice está fuera de rango, lanza una excepción.
        throw std::out_of_range("Índice fuera de rango");
    }
}

/**
 * @brief Sobrecarga del operador de asignación (=) para copiar el contenido de otra lista.
 * @param list (LinkedList<T>): La lista desde la cual se copiarán los elementos.
 *
 */
template <class T>
void LinkedList<T>::operator=(LinkedList<T> list){
    // Limpia la lista actual liberando su memoria.
    clear();

    // Asigna el puntero head de la lista actual al puntero head de la lista proporcionada,
    // lo que hace que ambas listas compartan los mismos nodos.
    head = list.head;
    size = list.getSize();
}

/**
 * @brief Imprime los elementos de la lista en la consola.
 *
 * Esta función recorre la lista e imprime sus elementos en la consola, separados por flechas "->".
 * Si la lista está vacía, no se imprime nada.
 */
template <class T>
void LinkedList<T>::print(){
    // Inicializa un puntero auxiliar para recorrer la lista desde el principio.
    Node<T> *aux = head;

    // Recorre la lista e imprime los elementos.
    while (aux != nullptr){
        // Imprime el valor del nodo actual.
        cout << aux->data;

        // Si no es el último nodo, imprime una flecha "->".
        if (aux->next != nullptr){
            cout << " -> ";
        }

        // Avanza al siguiente nodo.
        aux = aux->next;
    }

    // Imprime un salto de línea al final para formatear la salida.
    cout << endl;
}

/**
 * @brief Verifica si la lista está vacía.
 * @return true si la lista está vacía, false si contiene elementos.
 */
template <class T>
bool LinkedList<T>::isEmpty(){
    // Comprueba si el tamaño de la lista es igual a cero para determinar si está vacía.
    return size == 0;
}

/// @brief Borra todos los elementos de la lista y libera la memoria. La lista quedará vacía.
template <class T>
void LinkedList<T>::clear(){
    Node<T>* temp; // Declaración de un puntero auxiliar para mantener una referencia temporal al nodo a eliminar.

    // Itera a través de la lista mientras haya nodos para eliminar.
    while(head != nullptr) {
        temp = head;     // Almacena una referencia al nodo actual.
        head = head->next; // Avanza al siguiente nodo.
        delete temp;      // Libera la memoria del nodo actual.
    }
}

#endif