#include <iostream>
using namespace std;

// & con eso se pasaba con referencia pero ahora con ---* = &---- podremos pasar punteros (apuntan)

int main() {
    int a = 50; //valor de a es 50
    int* p1 = &a; // p1 me representa la direccion de a
    int** p2 = &p1; //p2 es la direccion de p1 se pone ** porque es una puntero de puntero

    cout << "Valor de a: " << a << endl;
    cout << "Valor de a vía p1: " << *p1 << endl;
    cout << "Valor de a vía p2: " << **p2 << endl;
    cout << "Direccion de p1: " << p2 <<endl;
    cout << "Direccion de p1: " << &p1 <<endl;

    cout << "\n";

    char mensaje[] = "Hola Mundo";//Guarda "valor"
    char* pm = mensaje;//Digamos que pm guarda la "direccion de pm //con un char ya no es necesario &-----

    while (*pm != '\0') { //*pm guarda un valor  
        cout << *pm; //me inrprime el valor de la direccion de pm
        pm++; //sube un byte a la direccion con lo cual el bucle falla
    }
    cout<<endl;
    return 0;
}