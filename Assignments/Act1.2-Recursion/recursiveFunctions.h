
int factorialIterative(int fac){
    int factorial = 1;

    for (int i= 2; i <= fac; i++){
        factorial *= i;
    }

    return factorial;
}

int factorial(int fac){
    if( fac > 0){
        return fac * factorial(fac -1);
    } else{
        return 1;
    }
}

// sumIterative
// Función que regresa la suma desde 1 hasta n de forma iterativa, donde n es el parámetro de entrada de la función.
int sumIterative(int n){
    int sum = 0;
    for (int i = 1; i <= n; i ++){
        sum += i;
    }
    return sum;
}

// sumRecursive
// Función que regresa la suma desde 1 hasta n de forma iterativa, donde n es el parámetro de entrada de la función.
int sumRecursive(int n){
    if(n > 1) {
        return n + sumRecursive(n-1);
    }
    else{
        return n;
    }
}

// sumFormula
// Función que regresa la suma desde 1 hasta n con el uso de la fórmula para obtener la suma.
int sumFormula(int n){
    return n * (n +1) /2;
}
// fibonacciIterative
// La función calcula el número fibonacci de una variable n que recibe de parámetro, en donde n es un entero.
// El fibonacci se calcula sumando los dos números fibonacci anteriores, por lo tanto, los primeros dos no son calculados.
// Realiza la función con el uso de for o while.

// F(1)=1
// F(2)=1
// F(3)=2
// F(4)=3
// F(5)=5
// F(6)=8

int fibonnacciIterative (int n){
    int fib = 1;
    int a = 0;
    int b = 0;

    for (int i = 1; i < n; i++){
        b = fib;
        fib += a;
        a = b;
    }
    return fib;
}

// fibonacciRecursive
// Igual que la función anterior, pero con el uso de recursividad.
int fibonnacciRecursive(int n){
    if (n > 2){
        return fibonnacciRecursive(n-2) + fibonnacciRecursive(n-1);
    }else{
        return 1;
    }

}
// bacteriasIterative
// Cierta bacteria de laboratorio tiene un índice de crecimiento diario del 378% y un índice de fallecimiento diario del 234%; haz una función que calcule el número de bacteria finales en n días, en donde n será un entero que recibirá de parámetros
// (asume que en el día 0 solo se tiene una bacteria).
// Asume que los cálculos de nacimientos y fallecimientos son truncados a enteros.
// Realiza la función con el uso de for o while.

int bacteriasIterative(int n ){
    float grow = 2.44;
    int bac = 1;
    for (int i = 0; i < n; i++){
        bac *= grow;
    }
    return bac ;
}

// bacteriasRecursive
// Igual que la función anterior, pero con el uso de recursividad 
//TODO: buscar truncado
int bacteriasRecursive(int n ){
    float grow = 2.44 ;
    if (n > 0){
        return bacteriasRecursive(n - 1) * grow; 
    }
    else{
        return 1;
    }
}
// investmentIterative
// Cierto banco está ofreciendo un interés mensual del 18.75%;
// La función deberá regresar el monto final en n meses dada una cantidad
// Los meses y la cantidad los recibirá de parámetros
// Realiza la función con el uso de for o while

float investmentIteractive(float amount, int months ){
    float interest = (18.75 / 100) + 1;
    for (int i = 0; i < months; i ++){
        amount *= interest;
    }
    return amount;

}
// investmentRecursive
// Igual que la función anterior, pero con el uso de recursividad 

float investmentRecursive(float amount, int months ){
    float interest = (18.75 / 100) + 1;
    if (months > 0){
        return interest * investmentIteractive(amount,months-1);
    }
    else{
        return 1;
    }

}
// powIterative
// La función deberá de regresar un número n elevado a la potencia y, que son valores que se recibirán de parámetro
// Realiza la función con el uso de for o while.

float powIteractive(float base, int n){
    float b = base;
    for (int i = 1; i < n; i++){
        base *= b;
    }
    return base;
}

// powRecursive
// Igual que la función anterior, pero con el uso de recursividad.

float powRecursive(float base, int n){
    if(n>0){
        return base * powRecursive(base, n-1);
    }
    else{
        return 1;
    }
}