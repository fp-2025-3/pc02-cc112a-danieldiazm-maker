#include <iostream>
using namespace std;

int main() {
    int x=10;
const int* pc = &x; // no podemos modificar x vía puntero
void* pv = &x;      // puntero genérico

cout<<pv<<endl;
cout<<pc<<endl;
// *(int*)pv = 20; // conversión necesaria para desreferenciar
}