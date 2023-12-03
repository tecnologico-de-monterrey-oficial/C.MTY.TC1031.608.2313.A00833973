
//Helper
//Orden O(1)
//Intercambia 2 valores de una lista dado sus índices
//a y b
template <class T>
void swap(vector<T>& list, int a, int b){
    if (list[a] != list[b]){
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}


//Helper for quick
//Intercambia los valores del valor auxiliar y el actual
//si el valor actual es menor al del pivote
//Regresa el pivote para el ocuparlo en el quick
//Orden O(n)
template <class T>
int getPivot(vector<T>& list, int left, int right){
    int pivot = right;
    int aux = left - 1 ;
    for (int i = left; i < right; i++){
        if(list[i] < list[pivot]){
            aux++;
            swap(list,i,aux);
        }
    }
    aux++;
    swap(list, pivot,aux);

    return aux;
}

//Quick
// Orden pivot +  O(logn) = O(nlogn)
// Algoritmo basado en divide y conquistarás

template <class T>
void quick(vector<T>& list, int left, int right){
    if(left < right){
        int pivot = getPivot(list, left, right);
        quick(list, left, pivot-1);
        quick(list, pivot+1, right);
    }
    
}

//quickSort
//Pasa los parametros iniciales para ejecutar el quick
//Orden O(nlogn)
template <class T>
void quickSort(vector<T>& list){
    int left = 0;
    int right = list.size() - 1;
    quick(list, left, right);
}
