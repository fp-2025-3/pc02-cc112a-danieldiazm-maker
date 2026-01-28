#include<iostream>
using namespace std;
void aplicarAArreglo(int* arr, int n, void (*f)(int&)) {
    for (int i = 0; i < n; i++) {
        f(arr[i]);
    }
}

void duplicar(int& x) {
    x *= 2;
}

int main() {
    int v[] = {1,2,3,4};
    aplicarAArreglo(v, 4, duplicar);

    for (int i = 0; i < 4; i++)
        cout << v[i] << " ";
    cout<<endl;
}