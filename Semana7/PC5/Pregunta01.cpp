/*
#include<iostream>
#include<fstream>
using namespace std;


int main(){
    long n1;
    ofstream Escribir("Escrito.txt");
    ifstream Leer("Leido.txt");
    Escribir.write(reinterpret_cast<char*>(&n1),sizeof(long)); // Write == Escribir
    Leer.read(reinterpret_cast<char*>(&n1),sizeof(long)); // Read == Escribir
}
*/
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
    int codigo;
    int contador = 0;
    int EstudianteMAX, EstudianteMIN, Maxi, Mini;
    double promedio, promedio_general = 0, a, b, c;
    Escribir << "Codigo" << "\tNombre" << "\tPromedio" << "\tCondicion" << endl;

    while(Leer >> codigo, Leer >> nombre, Leer >> a >> b >> c){

        promedio = (a + b + c) / 3;
        promedio_general += promedio;

        if(contador == 0){
            EstudianteMAX = promedio;
            EstudianteMIN = promedio;
        }

        if( a < 5 || b < 5 || c < 5){
            condicion = "DESAPROBADO POR REGLA ACADEMICA";
            if(promedio < EstudianteMIN){
                EstudianteMIN = promedio;
                Min = nombre;
                Mini = codigo;
            }
        }
        else{
            if(promedio >= 10){
                condicion = "APROBADO";
                if(promedio > EstudianteMAX){
                    EstudianteMAX = promedio;
                    Max = nombre;
                    Maxi = codigo;
                }
            }
            else{
                condicion = "DESAPROBADO";
                if(promedio < EstudianteMIN){
                    EstudianteMIN = promedio;
                    Min = nombre;
                    Mini = codigo;
                }
            }
        }
        Escribir << codigo << "\t" << nombre << "\t" << promedio << "\t" << condicion << endl;

        contador++;
    }

    promedio_general /= contador;

    Escribir << "Total de estudiantes: " << contador << endl << "Promedio general del curso: " << 
    promedio_general << endl << "Estudiante con mayor promedio: " << Maxi << " " << Max << " " << EstudianteMAX << endl << "Estudiante con menor promedio: " << 
    Mini << " " << Min << " "<< EstudianteMIN << endl;

    Leer.close();
    Escribir.close();
    return 0;
}