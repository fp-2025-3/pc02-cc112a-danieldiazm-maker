#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char a[] = "Hola";
    char b[] = "Hola";

    if(strcmp(a,b)==0) { 
        cout << "Iguales" << endl;
    }
}
/*
Compara carácter por carácter. Devuelve:
    0 --> iguales

   < 0 --> a < b // Menor que 0

   > 0 --> a > b // Mayor que 0
*/