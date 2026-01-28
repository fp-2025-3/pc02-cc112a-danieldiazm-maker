#include <iostream>
using namespace std;

// & con eso se pasaba con referencia pero ahora con ---* = &---- podremos pasar punteros (apuntan)

int main() {
    int arr[3] = {10,20,30};
    int* p = arr;

    cout << *(p) << endl;     // 10
    cout << *(p+1) << endl;   // 20
    cout << *(p+2) << endl;   // 30

    *(p+1)*=2; //40 = 20*2

    cout << *(p+1) << endl; //50

    return 0;
}