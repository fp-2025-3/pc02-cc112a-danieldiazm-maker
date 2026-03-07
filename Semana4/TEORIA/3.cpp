#include<iostream>
using namespace std;
int main(){
    // Asignación simple
    int* p = new int(0);
    *p = 42;
    
    cout<<*p<<endl;

    /*
    Error frecuente 1: usar sin inicializar
    int* p = new int; 
    cout << *p;  // valor basura
    */
    return 0;
}