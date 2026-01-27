#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char a[] = "Hola";
    char b[] = "Hola";

    if (a == b) { // ERROR TÍPICO //Estan comparando referencias o dirreciones en este caso
        cout << "Iguales" << endl;
    }
}
/*
Forma correcta if (strcmp(a, b) == 0) //C           //Compara y mira si no hay diferencias

a == b compara direcciones. strcmp compara contenido

Compara carácter por carácter. Devuelve:
    0 --> iguales

   < 0 --> a < b // Menor que 0

   > 0 --> a > b // Mayor que 0
*/