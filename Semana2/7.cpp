#include<iostream>
using namespace std;

void incrementar(int* p) {
    (*p)++;
}

int main() {
    int x = 7;
    incrementar(&x);
    cout << x << endl; // 8
}