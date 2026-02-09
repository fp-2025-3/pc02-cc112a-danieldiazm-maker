#include<iostream>
using namespace std;

void agregar(int* &c, double* &p, int &n, int &cap, int cod, double prom){ // Usamos paso por referencia para que los cambios en direcciones (c y p) y valores (n y cap) se reflejen
    if (n == cap){
        cap *= 2; // Si el arreglo ya está lleno, duplicamos la capacidad del arreglo
        int* nc = new int[cap]; // Nuevo arreglo codigo
        double* np = new double[cap]; // Nuevo arreglo promedio
        for (int i = 0; i < n; i++){ // Rellenamos los nuevos arreglos con los anteriores
            *(nc + i) = *(c + i); 
            *(np + i) = *(p + i);
        }
        delete[] c; // Liberamos la memoria en el heap
        delete[] p;
        c = nc; // Cambiamos las referencias del arreglo y asi mismo duplicando su tamaño
        p = np;
    }
    *(c + n) = cod; // Se van guardando los codigos en las posiciones del arreglo
    *(p + n) = prom; // Se van guardando los promedios en las posiciones del arreglo
    n++; // Vamos contando la cantidad de alumnos agregados
}

void filtrar(int* &c, double* &p, int &n){
    int cont = 0;
    for(int i = 0; i < n; i++){
        if(*(p + i) >= 10){
            cont++; 
        }
    }

    int* nc = new int[cont]; // Nuevo arreglo codigo aprobado
    double* np = new double[cont]; // Nuevo arreglo promedio aprobado

    int j = 0;

    for(int i = 0; i < n; i++){
        if(*(p + i) >= 10){ // Guardando en cada arreglo solo a los estudiantes aprobados
            *(nc + j) = *(c + i);
            *(np + j) = *(p + i);
            j++;
        }
    }

    delete[] c; 
    delete[] p;
    c = nc; // Cambiamos las referencias del arreglo, y asi mismo solo dejando a los aprobados
    p = np; 
    n = cont; // Nueva capacidad del arreglo con aprobados
}

void mostrar(int* c, double* p, int n, const char* msg){
    cout << msg << endl;
    for (int i = 0; i < n; i++)
        cout << "Codigo: " << *(c + i) << " Promedio: " << *(p + i) << endl;
}

int main() {
    int cap = 2, n = 0;
    int cod;
    double prom;
    int* codigos = new int[cap];
    double* promedios = new double[cap];

    for (int i = 0; i < 5; i++){ // En este caso deseamos hasta 5 estudiantes pero podemos aumentar la cantidad de alumnos sin problema gracias a la funcion duplicar
        cout << "Estudiante " << i + 1 << " codigo: ";
        cin >> cod;
        do{
        cout << "Estudiante " << i + 1 << " promedio: ";
        cin >> prom;
        if(prom > 20){
            cout<<"ERROR: ELPROMEDIO NO PUEDE SER MAYOR A 20\n";
        }
        }while(prom > 20.0);
        agregar(codigos, promedios, n, cap, cod, prom);
    }

    mostrar(codigos, promedios, n, "\nEstudiantes registrados:");
    filtrar(codigos, promedios, n);
    mostrar(codigos, promedios, n, "\nEstudiantes aprobados:");

    delete[] codigos; 
    delete[] promedios;
    return 0;
}