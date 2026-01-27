#include <iostream>
using namespace std;

int main() {
    const char* paises[] = {"Peru","Chile","Brasil"}; //Es un arreglo que tiene como elementos a punteros char constantes
    int n=sizeof(paises)/sizeof(paises[0]); //Esto funciona porque cada puntero tiene un tamaño especifico de bytes
    for (int i = 0; i < n; i++) {
        const char* p = *(paises + i);/* (paises) es la referencia del elemento de pos 0
                                        *(paises+i) es la desreferenciacion del elemento de pos i
                                        y en este caso la referencia de alguna letra en las palabras*/
        while (*p != '\0') {
            cout << *p; //Imprime  "Peru"
            p++;    //p corre una pos y pasa de referencia de "Peru" a referencia de "Chile" y asi ...
        }
        cout << endl;
    }
}
// Este bucle se puede usar en un funcion de forma void Imprimir(const char *p[],n);