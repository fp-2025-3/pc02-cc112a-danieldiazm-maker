#include<iostream>
using namespace std;
int* maximo(int* a, int* b) {
    if (*a > *b)
        return a;
    return b;
}

int main() {
    int x = 5, y = 10;
    int* pMax = maximo(&x, &y);
    cout << *pMax << endl; // 10
}

// No se crea memoria nueva, solo se devuelve una referencia existente