#include<iostream>
using namespace std;
int main(){
    /* int a[100] 
    Arreglo estatico
    
    Características:

        Tamaño fijo en tiempo de compilación
        Se almacenan en el stack
        Se destruyen automáticamente al salir del bloque

    Problemas reales:

        Desperdicio de memoria
        Riesgo de stack overflow
        No escalables
    */
    int* a = new int[100]; // se reserva memoria con el new 

    // liberamos memoria

    delete []a; //Como es un arreglo se pone [] antes del nombre del arreglo

    cout<<*a<<endl;

    /*
    Arreglos dinámico

    Características:

        Tamaño decidido en tiempo de ejecución
        Memoria en el heap
        Vida controlada explícitamente por el programador

        "con memoria dinámica, el poder viene con responsabilidad"
    */


    return 0;
}