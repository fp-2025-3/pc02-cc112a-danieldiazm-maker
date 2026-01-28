#include <iostream>
using namespace std;

int suma(int a, int b) { return a + b; }
int resta(int a, int b) { return a - b; }

//int (*op)(int, int);  puntero op que apunta a una funcion

int main() {
    int (*op)(int,int) = suma; //el nombre de una función actúa como su dirección de memoria 

    cout << op(3,4) << endl;/*se puede invocar como si fuera una función normal
                            El programa irá a la dirección de memoria donde reside el código de suma*/

    op = resta;
    cout << op(10,5) << endl;
}

/*
int cuadrado(int x) { return x*x; }

int (*f)(int,int) = cuadrado; // ERROR EN LA FIRMA (parametros int, int no los tiene solo int)
*/