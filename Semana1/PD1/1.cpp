#include <iostream>
using namespace std;

int main(){

    double A[] = {8.8, 10.1, 14.4, 16.6, 18.8, 20.5}; // arreglo de pesos en gramos de una caja de n galletas
    // p_i == A[i]


    int n = sizeof(A)/sizeof(A[0]);


    double p;
    cout << "Ingrese el peso p (en gramos) de una caja: ";
    cin >> p;

    double pv;

    if (p <= A[0]) {
        pv = A[0];
    } else if (p >= A[n-1]) {
        pv = A[n-1];

    } else {

        // Intentamos adaptar la búsqueda binaria
        // para encontrar la coincidencia (clave p) o el intervalo

        int l = 0, r = n-1;
        
        int pos = -1; 

        while( l <= r) {
            int medio = (l + r)/2;
            if (A[medio] == p) {
                pv = A[medio];
                pos = -2;
                break;
            } else if (A[medio] < p) {
                l = medio + 1 ;
            } else {
                pos = medio;
                r = medio -1;
            }
        }

        if (pos != -2) {
            pv = (A[pos -1] + A[pos])/2;
        }

        //cout << "Peso de una galleta: " << pv << endl;
        cout << "Precio sugerido: S/ " <<  pv /20.0 <<endl; 


    }




    return 0;
}