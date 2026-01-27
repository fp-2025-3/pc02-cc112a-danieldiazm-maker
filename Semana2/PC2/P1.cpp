#include <iostream>

using namespace std;

void burbujaPunteros(int *A, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Usamos *(A + j) en lugar de A[j]
            if (*(A + j) > *(A + j + 1)) {
                int temp = *(A + j);
                *(A + j) = *(A + j + 1);
                *(A + j + 1) = temp;
            }
        }
    }
}

int main() {
    int A[] = {5, 2, 9, 4, 1, 8, 5, 6, 3, 0, 7};
    int n = 11;

    burbujaPunteros(A, n);

    cout << "Vector despues de ser ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << *(A + i); // Acceso con punteros
    }
    cout << endl;

    return 0;
}