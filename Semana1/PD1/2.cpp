#include <iostream>
using namespace std;


int minDias(int n) {
    // Caso base: en forma compacta, similar a fibonacciRecursivo
    if (n <= 0)
        return 0;
    
    // Casos recursivos: Tenemos tres opciones segun el enunciado


    // Opcion 1: Comer 1 manzana
    int min_final = 1 + minDias(n-1);

    // Opcion 2: Si es divisible entre 2 comer la mitad
    if(n % 2 == 0) {
        int opcion2 = 1 + minDias(n/2);

        //actualizamos el minimo
        if (opcion2  < min_final){
            min_final = opcion2;
        }
    }

    // Opcion 3: Si es divisible entre 3 comer dos tercios
    if(n % 3 == 0) {
        int opcion3 = 1 + minDias(n/3);

        //actualizamos el minimo
        if (opcion3  < min_final){
            min_final = opcion3;
        }
    }


    return min_final;

}


void pruebas(int n) {
    cout << "Numero minimo de dias para comer " << n << " manzanas: ";
    cout << minDias(n) << "\n\n";
}

int main(){

    pruebas(6);

    pruebas(10);

    return 0;
}