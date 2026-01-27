#include <iostream>
using namespace std;

void ejecutar(int a, int b, int (*op)(int,int)) {
    cout << op(a,b) << endl; //llama la funcion guardada en la direccion op
}

int suma(int x, int y) { return x + y; }
int resta(int x,int y) { return x * y ; }

int main() {
    ejecutar(3,4,resta);
}