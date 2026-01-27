#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int x = atoi("123");     // 123
    double y = atof("3.14"); // 3.14
    cout<<x<<endl;
    cout<<y<<endl;
}
/*
10. Funciones para convertir cadenas de caracteres
Ejercicio 10.1 Convertir cadena a número

No detectan errores correctamente
atoi confía demasiado en el usuario
*/