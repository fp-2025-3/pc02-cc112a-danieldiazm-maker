#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Proyecto{
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMeses;
};

bool CompararID(Proyecto *P1, int n, int idNuevo){ // Agregando el apartado de idNuevo para una mejora comparacion
    for (int i = 0; i < n; ++i){
        if(P1[i].id == idNuevo){
            return true;
        }
    }
    return false;
}
void Ordenar(Proyecto *P1, int n){
    for (int i = 0; i < n - 1; ++i){ // Ordenamiento burbuja
        for (int j = 0; j < n - 1 - i; ++j){
            if(P1[i].presupuesto < P1[i + 1].presupuesto){ // Forma decreciente
                swap(P1[i],P1[i+1]);
            }
        }
    }
}
Proyecto* Duplicartamano(Proyecto* arreglo, int &capacidad){ // Creamos esta funcion para poder lograr duplicar la capacidad de un arreglo dinamica si se llena
    int nuevacapacidad = capacidad * 2;
    Proyecto* arreglo_nuevo = new Proyecto[nuevacapacidad];

    for (int i = 0; i < capacidad; ++i){
        arreglo_nuevo[i] = arreglo[i];
    }
    delete [] arreglo;

    capacidad = nuevacapacidad;
    return arreglo_nuevo;
}

int main(){
    int opcion; // cambio el nombre para mejor entendimiento
    int n = 1; // Se empieza con capacidad 1
    int contador = 0;
    Proyecto *P1 = new Proyecto[n];

    ifstream ArchLeer("proyectos.dat",ios::binary);
    if(ArchLeer){
        Proyecto temp;

        while(ArchLeer.read(reinterpret_cast<char*>(&temp),sizeof(Proyecto))){
            if(contador == n){ // Aqui es si se llena, lo duplicamos
                P1 = Duplicartamano(P1,n);
            }
            P1[contador] = temp; // Guardamos en memoria
            contador++;
        }
        ArchLeer.close();
    }
    do{
        cout << "\n2. Agregar |1. Mostrar |0. Salir: ";
        cin >> opcion;

        if (opcion == 2){
            Proyecto nuevo = {};
            cout << "Digite el id: ";
            cin >> nuevo.id;

            if(CompararID(P1, contador, nuevo.id)){
                cout << "ERROR: Ya existe otro proyecto con igual id.\n";
            }
            else{
                cout << "Digite el Titulo del Proyecto: ";
                cin.ignore(); // Para borrar la basura del cin de nuevo.id
                cin.getline(nuevo.titulo, 40);
                cout << "Digite el Presupuesto del Proyecto: ";
                cin >> nuevo.presupuesto;
                cout << "Digite la duracion del Proyecto en meses: ";
                cin >> nuevo.duracionMeses;

                if(contador == n){
                    P1 = Duplicartamano(P1, n);
                }

                P1[contador] = nuevo;
                contador++;

                Ordenar(P1, contador);

                ofstream ArchEscribir("proyectos.dat",ios::binary);
                for(int i = 0; i < contador; i++){
                    ArchEscribir.write(reinterpret_cast<char*>(&P1[i]), sizeof(Proyecto));
                }
                ArchEscribir.close();
            }
        }
        if(opcion == 1){
            cout << "LISTA DE PROYECTOS: "<<endl;
            for (int i = 0; i < contador; ++i){
                cout << "ID: " <<P1[i].id << " | Titulo: " <<P1[i].titulo<< " | Presupuesto: S/" <<P1[i].presupuesto << " | Duracion: " <<P1[i].duracionMeses << " meses\n";
            }
        }
    }while(opcion != 0);

    delete [] P1;
    
    return 0;
}