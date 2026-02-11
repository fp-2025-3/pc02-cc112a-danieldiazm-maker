/*
Ejercicio 2 (Punteros)

Se tiene una matriz estática cuadrada de enteros M de tamaño fijo N × N, con N ≥ 3.
La matriz se declara en la función main de la siguiente forma:

const int N = 5;
int M[N][N];
La matriz representa una estructura de relaciones entre filas y columnas.

Utilice aritmética de punteros e implemente las siguientes funciones:

bool esFilaDominante(int (*M)[N], int fila);

Una fila se considera dominante si cada uno de sus elementos es estrictamente mayor que el elemento correspondiente de todas las demás filas en la misma columna.

int contarColumnasCriticas(int (*M)[N]);

Una columna se considera crítica si la suma de sus elementos es mayor que la suma de cualquier fila de la matriz.

La función debe retornar la cantidad total de columnas críticas.

bool esMatrizEscalonada(int (*M)[N]);

Una matriz es escalonada si, para cada fila, la posición del primer elemento no nulo aparece en una columna estrictamente mayor que la del primer elemento no nulo de la fila anterior.

int valorNucleo(int (*M)[N]);

El núcleo de la matriz es un elemento que cumple simultáneamente:

Es el máximo de su fila

Es el mínimo de su columna

La función debe retornar el valor del núcleo. Si no existe ningún elemento que cumpla ambas condiciones, retornar -1.
*/
#include<iostream>
using namespace std;

int main(){
    /*const int N = 5;
    int M[N][N]={{0,0,7,8,9},
                 {0,0,0,5,6},
                 {0,0,0,0,4},
                 {1,2,3,4,5},
                 {9,8,7,6,5}};

    */
    return 0;
}