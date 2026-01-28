#include<iostream>
using namespace std;
int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int (*operacion)(int, int);

int main() {
    operacion = suma;
    cout << operacion(3, 2) << endl;  // 5

    operacion = resta;
    cout << operacion(3, 2) << endl;  // 1
    
}