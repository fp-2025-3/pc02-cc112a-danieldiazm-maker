#include<iostream>
using namespace std;

void LeerDatos(char *corredores[], int *Tiempo, int n) {
    for(int i = 0; i < n; i++) {
        corredores[i] = new char[21]; // Reservamos memoria para cada nombre 20 caracteres + '\0'
        cout << "Nombre del corredor " << i + 1 << ": ";
        cin >> *(corredores + i); 
        cout << "Tiempo (en segundos): ";
        cin >> *(Tiempo + i);
    }
}

void Burburja(char *corredores[], int *Tiempo, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(*(Tiempo + j) > *(Tiempo + j + 1)) {
                swap(*(Tiempo + j),*(Tiempo + j + 1)); // Intercambiamos el tiempo a forma ascendente
                swap(*(corredores + j),*(corredores + j + 1)); // Intercambiamos la direccion de cada nombre del corredor en forma ascendente
            }
        }
    }
}

void RANKING(char *corredores[], int *Tiempo, int n) {
    cout << "\nRANKING FINAL" << endl;
    for(int i = 0; i < n; i++) {
        cout << i + 1 << ". " << *(corredores + i) << " - " << *(Tiempo + i) << " segundos" << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese numero de corredores: ";
    cin >> n;
    char *corredores[30]; 
    int Tiempo[30];

    LeerDatos(corredores, Tiempo, n);
    Burburja(corredores, Tiempo, n);
    RANKING(corredores, Tiempo, n);

    // Liberamos la memoria de los nombres
    for(int i = 0; i < n; i++){
        delete[] corredores[i];
    }
    return 0;
}