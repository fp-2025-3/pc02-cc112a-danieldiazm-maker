#include <iostream>

using namespace std;

int main() {
    int n, k;
    cout << "Ingrese grado del polinomio: "; cin >> n;

    double A[100] = {0}; // Coeficientes inicializados en 0 
    for (int i = 0; i <= n; i++) {
        cout << "A[" << i << "]="; cin >> *(A + i);
    }

    cout << "Ingrese k: "; cin >> k;

    // Aplicamos la derivada k veces
    for (int d = 0; d < k; d++) {
        for (int i = 0; i < n; i++) {
            // El coeficiente a_i se convierte en a_{i+1} * (i+1)
            *(A + i) = *(A + i + 1) * (i + 1);
        }
        *(A + n) = 0; // El término de mayor grado desaparece
        n--; // El grado efectivo baja en cada derivada
    }

    cout << "La derivada k-esima es:" << endl;
    for (int i = 0; i <= n; i++) {
        if (*(A + i) != 0)
            cout << *(A + i) << "x^" << i << " ";
    }

    return 0;
}