#include <iostream>
using namespace std;

void imprimir(const char* p){ /*Se recorre hasta encontrar el terminador. 
                            De esta manera se recorren cadenas las funciones estándar.*/
    while (*p != '\0') {
        cout << *p;
        p++;
    }
    cout<<endl;
}

int main(){
    char p[] = "Daniel";
    imprimir(p);
    cout<< p <<endl;
}