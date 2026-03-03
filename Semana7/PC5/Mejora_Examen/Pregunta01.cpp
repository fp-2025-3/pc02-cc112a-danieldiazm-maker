#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream Leer("input/notas.txt");
    ofstream Escribir("output/Alumnos.txt");

    if(!Leer){
        cout << "Error: No se puedo abrir notas.txt" << endl;
    }
    if(!Escribir){
        cout << "Error: No se puedo abrir Alumnos.txt" << endl;
    }

    string nombre, Max, Min, condicion;
    int codigo, contador = 0;
    double EstudianteMAX, EstudianteMIN;
    int Max_i, Min_i;
    double promedio, promedio_general = 0.0, a, b, c;
    Escribir << "Codigo" << "\tNombre" << "\tPromedio" << "\tCondicion" << endl;

    Escribir.setf(ios::fixed); // Para dar la precision despues del punto
    Escribir.precision(2); // Dos numeros de precision

    while(Leer >> codigo, Leer >> nombre, Leer >> a >> b >> c){

        promedio = (a + b + c) / 3.0;
        promedio_general += promedio;

        if(contador == 0){ // Inicializando tambien nombre y codigo en la primera pasada
            EstudianteMAX = EstudianteMIN = promedio;
            Max = Min = nombre;
            Max_i = Min_i = codigo;
        }

        if( a < 5 || b < 5 || c < 5){ // Separando las condiciones de tal forma que reducimos la carga
            condicion = "DESAPROBADO POR REGLA ACADEMICA";
        }
        else if(promedio >= 10){
            condicion = "APROBADO";
        }
        else{
            condicion = "DESAPROBADO";
        }

        if(promedio >= EstudianteMAX){
            EstudianteMAX = promedio;
            Max = nombre;
            Max_i = codigo;
        }
        if(promedio <= EstudianteMIN){
            EstudianteMIN = promedio;
            Min = nombre;
            Min_i = codigo;
        }



        Escribir << codigo << "\t" << nombre << "\t" << promedio << "\t\t" << condicion << endl;

        contador++;
    }

    promedio_general /= contador;

    Escribir << "\nTotal de estudiantes: " << contador << endl << "Promedio general del curso: " << 
    promedio_general << endl << "Estudiante con mayor promedio: " << Max_i << " " << Max << " " << EstudianteMAX << endl << "Estudiante con menor promedio: " << 
    Min_i << " " << Min << " "<< EstudianteMIN << endl;

    Leer.close();
    Escribir.close();
    return 0;
}