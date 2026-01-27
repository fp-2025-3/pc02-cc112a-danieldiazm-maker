#include <iostream>
using namespace std;

int main() {
    int arr[4]={1,2,3,4};

    int* p1 = arr;      // puntero a elemento
    int (*p2)[4] = &arr; // puntero a arreglo
    cout<< *p1 <<endl;
    cout<< *p1 + 1 <<endl;
    cout<< (p2)[1] <<endl;
    cout<< (p2)[2] <<endl;
}