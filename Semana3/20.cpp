#include <iostream>
using namespace std;

int main(){
    int numero = 0;
    for (const char* p = "123"; *p != '\0'; p++)
        numero = numero * 10 + (*p - '0'); //*(p+0)='1'==49 y'0'==48
    cout<<numero<<endl;
}
/*
10. Funciones para convertir cadenas de caracteres
Ejercicio 10.2 Conversión carácter por carácter (manual)

Note cómo una cadena se convierte en número usando solo punteros y ASCII.
*/