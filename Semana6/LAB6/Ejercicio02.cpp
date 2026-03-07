#include <iostream>
#include <fstream>
using namespace std;

int main(){

    double nota;
    int contarNotas = 0;
    double suma = 0.0;
    double mayorNota = 0, menorNota = 0;
    int aprobados = 0, desaprobados = 0;

    ifstream archivoEntrada("input/notas.txt"); // Leemos es archivos notas.txt que esta en la carpeta input

    ofstream archivoSalida("output/reporte.txt"); // Creamos o escribimos el archico reporte.txt y escrbimos en el, el cual esta en la carpeta output

    if (!archivoEntrada) { 
        cout << "Error, no se pudo abrir notas.txt"; // Si no se abre, imprimimos este mensaje y despues retornamos
        return 1;
    }

    if (!archivoSalida) {
        cout << "Error, no se pudo abrir reporte.txt"; // Si no se abre, imprimimos este mensaje y despues retornamos
        return 1;
    }


   

    while (archivoEntrada >> nota) { // Leemos nota del archivo entrada
        contarNotas++; // Contamos la cantidad de notas
        suma += nota; // Suma total de notas

        if (contarNotas == 1){ // Al inicio inicializamos mayorNote y menorNota como nota al ver solo una nota
            mayorNota = nota;
            menorNota = nota;
        } else {
            if (nota > mayorNota){ // Al haber dos o mas notas damos los valos para mayor y menor nota
                mayorNota = nota;
            }

            if (nota < menorNota){
                menorNota = nota;
            }
        }

        if (nota >= 10) { // Si la nota es mayor o igual a 10, ingresamos al if y sumamos a la cantidad de aprobados
            aprobados++;
        }
        else {
            desaprobados++; // Caso contrario sumamos a la cantidad de desaprobados
        }

    }

    double promedio = suma/contarNotas;


    archivoSalida << "REPORTE GENERAL" <<endl;
    archivoSalida <<"------------------------"<<endl;
    archivoSalida << "Total de estudiantes: " << contarNotas <<endl;
    archivoSalida << "Promedio: " << promedio <<endl;
    archivoSalida << "Mayor nota: " << mayorNota <<endl;
    archivoSalida << "Menor nota: " << menorNota <<endl;
    archivoSalida << "Aprobados: " << aprobados <<endl;
    archivoSalida <<"Desaprobados: " << desaprobados <<endl;


    archivoEntrada.close(); // Cerramos
    archivoSalida.close(); // Cerramos 

    cout << "Reporte generado correctamente" <<endl;


    return 0;
}