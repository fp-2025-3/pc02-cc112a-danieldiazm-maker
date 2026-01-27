#include <iostream>
using namespace std;

// & con eso se pasaba con referencia pero ahora con ---* = &---- podremos pasar punteros (apuntan)

int main() {
    int* ptr = nullptr;//nullptr puntero nulo

    if (ptr != nullptr) {
        cout << *ptr << endl;
    } else {
        cout << "Puntero nulo, no se puede desreferenciar." << endl;
    }

    cout<<"\n";

    int arr[] = {1,2,3,4,5};
    int* p = arr; // arr decae a puntero al primer elemento

    for (int i=0; i<5; i++) {
        cout << *(p+i) << " "; //*(p+0) es el primer valor de la direccion de (p+0)
    }
    cout << endl;

    return 0;
}