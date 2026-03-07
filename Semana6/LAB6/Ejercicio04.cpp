#include <iostream>
#include <fstream>

using namespace std;

struct Punto {
    double x, y;
};

struct Triangulo {
    int v1, v2, v3;
};

struct Datos_Area {
    int nt; // Numero de triangulos
    int nv; // NUmero de vertices
    Punto* coordenadas;
    Triangulo* triangulos;
};

double calcularArea(Punto p1, Punto p2, Punto p3) {
    double resultado = p1.x * (p3.y - p2.y) + p2.x * (p1.y - p3.y) + p3.x * (p2.y - p1.y);
    
    if (resultado < 0) {
        resultado = -resultado;
    }
    
    return resultado / 2.0;
}

int main() {
    Datos_Area A1;
    
    ifstream Entrada("input/laguna.txt");
    ofstream Salida("output/area.txt");

    if (!Entrada) { 
        cout << "Error, no se pudo abrir laguna.txt";
        return 1;
    }

    if (!Salida) {
        cout << "Error, no se pudo abrir area.txt";
        return 1;
    }
    

    if (!(Entrada >> A1.nt >> A1.nv)) { // Leemos, en caso no se pueda retornamos y fin
        return 1;
    }

    A1.coordenadas = new Punto[A1.nv];
    A1.triangulos = new Triangulo[A1.nt];

    for (int i = 0; i < A1.nv; i++) {
        Entrada >> A1.coordenadas[i].x >> A1.coordenadas[i].y;
    }

    for (int i = 0; i < A1.nt; i++) {
        Entrada >> A1.triangulos[i].v1 >> A1.triangulos[i].v2 >> A1.triangulos[i].v3;
    }

    double areaTotal = 0;
    for (int i = 0; i < A1.nt; i++) {
        Punto p1 = A1.coordenadas[A1.triangulos[i].v1 - 1];
        Punto p2 = A1.coordenadas[A1.triangulos[i].v2 - 1];
        Punto p3 = A1.coordenadas[A1.triangulos[i].v3 - 1];
        
        areaTotal += calcularArea(p1, p2, p3);
    }

    Salida << "Area total de la laguna: " << areaTotal << endl;
    cout << "Calculo finalizado. Area: " << areaTotal << endl;

    delete[] A1.coordenadas;
    delete[] A1.triangulos;
    Entrada.close();
    Salida.close();

    return 0;
}