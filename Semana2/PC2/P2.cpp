#include <iostream>
#include <string.h>

using namespace std;

void rev(char *p) {
    int n = strlen(p);
    for (int i = 0; i < n / 2; i++) {
        // Intercambio de extremos
        char temp = *(p + i);
        *(p + i) = *(p + n - 1 - i);
        *(p + n - 1 - i) = temp;
    }
}

int main() {
    char cadena[100];
    cout << "Ingrese cadena: ";
    cin.getline(cadena, 100);

    rev(cadena);

    cout << "Salida: " << cadena << endl;
    return 0;
}