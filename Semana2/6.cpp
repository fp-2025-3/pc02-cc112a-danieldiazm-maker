#include<iostream>
using namespace std;

int main() {
    int a = 5;
    int& ref = a; // referencia
    int* p = &a; // puntero

    ref = 10;
    cout << a << " " << *p << endl; // ambos muestran 10
}