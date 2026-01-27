#include<iostream>
using namespace std;
int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}
int aplicar(int a, int b, int (*op)(int, int)) {
    return op(a, b);
}

int main() {
    cout << aplicar(4, 2, suma) << endl;   // 6
    cout << aplicar(4, 2, resta) << endl;  // 2
}