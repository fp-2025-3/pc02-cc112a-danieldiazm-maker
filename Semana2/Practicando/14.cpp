#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20, c = 30;

    int* ptrs[3] = {&a, &b, &c}; //Puntero a cada elemento

    for (int i = 0; i < 3; ++i) {
        cout << *ptrs[i] << " "; //Imprime cada elemento que apunta ptrs
    }
    cout<<endl;
}