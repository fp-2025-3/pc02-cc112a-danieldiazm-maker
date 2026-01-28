#include <iostream>
#include <cstdlib> // Necesario para rand() (números aleatorios)
#include <ctime>   // Opcional: Para que los números cambien en cada ejecución

using namespace std;

// --- FUNCIÓN INTERCAMBIAR ---
// Ayuda a mover los valores de lugar en el arreglo
void intercambiar(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

// --- PARTICIÓN (El corazón de QuickSort) ---
// Ordenaremos de MAYOR a MENOR (Descendente) para tener los mejores promedios primero
int particion(float arr[], int bajo, int alto) {
    float pivote = arr[alto]; // Elegimos el último elemento como pivote
    int i = (bajo - 1);       // Índice del elemento más grande encontrado

    for (int j = bajo; j < alto; j++) {
        // CAMBIO CLAVE: Usamos ">" porque queremos orden Descendente (Mayor a menor)
        // Si fuera ascendente, usaríamos "<"
        if (arr[j] > pivote) {
            i++;
            intercambiar(arr[i], arr[j]);
        }
    }
    // Colocamos el pivote en su posición correcta final
    intercambiar(arr[i + 1], arr[alto]);
    return (i + 1);
}

// --- QUICKSORT RECURSIVO ---
void quickSort(float arr[], int bajo, int alto) {
    if (bajo < alto) {
        // pi es el índice de partición
        int pi = particion(arr, bajo, alto);

        // Ordenamos recursivamente las dos mitades
        quickSort(arr, bajo, pi - 1);  // Mitad izquierda (mayores que el pivote)
        quickSort(arr, pi + 1, alto);  // Mitad derecha (menores que el pivote)
    }
}

int main() {
    // Semilla para aleatorios (si no te dejan usar ctime, borra esta línea)
    srand(time(0)); 

    const int NUM_ALUMNOS = 10;
    const int NUM_NOTAS = 5;
    float promedios[NUM_ALUMNOS]; // Arreglo para guardar los promedios

    cout << "--- GENERANDO NOTAS Y PROMEDIOS ---" << endl;

    // a) y b) Generar notas y calcular promedios
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        float suma = 0;
        // Generamos 5 notas para cada alumno
        for (int k = 0; k < NUM_NOTAS; k++) {
            int nota = rand() % 21; // Genera números entre 0 y 20
            suma = suma + nota;
        }
        
        // Calculamos promedio y lo guardamos
        promedios[i] = suma / NUM_NOTAS;
        
        cout << "Alumno " << i << " Promedio: " << promedios[i] << endl;
    }

    // c) Ordenar usando QuickSort
    quickSort(promedios, 0, NUM_ALUMNOS - 1);

    cout << "\n--- MEJORES RESULTADOS (TOP 3) ---" << endl;
    
    // Mostramos solo los 3 primeros (indices 0, 1 y 2)
    for (int i = 0; i < 3; i++) {
        cout << "Puesto " << (i + 1) << ": " << promedios[i] << endl;
    }

    return 0;
}