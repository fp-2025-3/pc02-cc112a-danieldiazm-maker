#include <iostream>
using namespace std;

void porValor(int a) { a++; }
void porPuntero(int* a) { (*a)++; }
void porReferencia(int& a) { a++; }

int main() {
    int x = 5;
    porValor(x);      // x=5 por valor
    cout << x << endl;

    porPuntero(&x);   // x=6 por puntero
    cout << x << endl;

    porReferencia(x); // x=7 por refencia
    cout << x << endl;

}