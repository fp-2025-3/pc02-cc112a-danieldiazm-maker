#include <iostream>
#include <cmath>
using namespace std;

class Sensor{ // Clase Padre
protected:
    string id;
    double* posicion;
public:
    Sensor(string _id, double x, double y) : id(_id){
        posicion = new double[2]{x, y}; 
    }
    
    Sensor(const Sensor& o) : id(o.id){
        posicion = new double[2]{o.posicion[0], o.posicion[1]}; 
    }
    Sensor& operator=(const Sensor& o){
        if(this != &o){
            id = o.id; delete[] posicion; posicion = new double[2]{o.posicion[0], o.posicion[1]};
    }
        return *this;
    }
    virtual ~Sensor(){ 
        delete[] posicion; 
    }

    virtual double areaCobertura() const = 0;
    virtual bool detecta(double x, double y) const = 0;
    virtual void imprimir() const = 0;
    string getId() const { 
        return id; 
    }
};

class SensorCircular : public Sensor{ // Clase hijo circular
    double radio;
public:
    SensorCircular(string _id, double x, double y, double r) : Sensor(_id, x, y), radio(r) {}
    double areaCobertura() const override{
        return 3.14159 * radio * radio;
    }
    bool detecta(double x, double y) const override{
        return sqrt(pow(x - posicion[0], 2) + pow(y - posicion[1], 2)) <= radio;
    }
    void imprimir() const override{
        cout<<"[Circular] ID: "<<id<<" | Pos: ("<<posicion[0]<<","<<posicion[1]<<") | Radio: "<<radio<<" | Area: "<<areaCobertura()<<"\n";
    }
};

class SensorRectangular : public Sensor{ // Clase hijo rectangular
    double ancho, alto;
public:
    SensorRectangular(string _id, double x, double y, double an, double al) : Sensor(_id, x, y), ancho(an), alto(al) {}
    double areaCobertura() const override{ 
        return ancho * alto; 
    }
    bool detecta(double x, double y) const override{
        return abs(x - posicion[0]) <= ancho/2.0 && abs(y - posicion[1]) <= alto/2.0; // Rectángulo centrado
    }
    void imprimir() const override {
        cout<<"[Rectangular] ID: "<<id<<" | Pos: ("<<posicion[0]<<","<<posicion[1]<<") | Dim: "<<ancho<<"x"<<alto<<" | Area: "<<areaCobertura()<<"\n";
    }
};

class SistemaSensores{ // Clase que gestiona sensores
    Sensor** sensores;
    int cantidad, capacidad;
public:
    SistemaSensores(int cap=2) : cantidad(0), capacidad(cap){
        sensores = new Sensor*[capacidad]; 
    }
    ~SistemaSensores() {
        for(int i = 0; i < cantidad; i++) delete sensores[i];
        delete[] sensores;
    }
    
    void agregarSensor(Sensor* s){
        if (cantidad == capacidad){
            capacidad *= 2;
            Sensor** nuevo = new Sensor*[capacidad];
            for(int i = 0; i < cantidad; i++) nuevo[i] = sensores[i];
            delete[] sensores;
            sensores = nuevo;
        }
        sensores[cantidad++] = s;
    }
    
    void mostrarSensores() const{
        for(int i=0; i<cantidad; i++) sensores[i]->imprimir(); 
    }
    
    double areaTotalCobertura() const{
        double total = 0;
        for(int i=0; i<cantidad; i++) total += sensores[i]->areaCobertura();
        return total;
    }
    
    int sensoresQueDetectan(double x, double y) const{
        int c = 0;
        for(int i=0; i<cantidad; i++) if (sensores[i]->detecta(x, y)) c++;
        return c;
    }
    
    Sensor* sensorMayorCobertura() const{
        if (!cantidad) return nullptr;
        Sensor* mayor = sensores[0];
        for(int i=1; i<cantidad; i++)
            if(sensores[i]->areaCobertura() > mayor->areaCobertura()) mayor = sensores[i];
        return mayor;
    }
};

int main(){
    SistemaSensores sistema;
    int op; double x, y, r, an, al; string id;
    
    do {
        cout << "\n1.Agregar Circular 2.Agregar Rectangular 3.Mostrar Todos 4.Area Total 5.Detectar Punto 6.Mayor Cobertura 0.Salir\nOp: ";
        cin >> op;
        
        if(op == 1){
            cout<<"ID, X, Y, Radio: ";
            cin>>id>>x>>y>>r;
            sistema.agregarSensor(new SensorCircular(id,x,y,r));
        }
        else if(op == 2){
            cout<<"ID, X, Y, Ancho, Alto: "; 
            cin>>id>>x>>y>>an>>al; sistema.agregarSensor(new SensorRectangular(id,x,y,an,al));
        }
        else if(op == 3){
            sistema.mostrarSensores();
        }
        else if(op == 4){
            cout << "Area Total: " << sistema.areaTotalCobertura() << "\n";
        }
        else if(op == 5){ 
            cout<<"Punto X Y: "; cin>>x>>y; cout<<"Detectado por "<<sistema.sensoresQueDetectan(x,y)<<" sensor(es)\n"; 
        }
        else if(op == 6){
            Sensor* m = sistema.sensorMayorCobertura(); if(m){
                cout<<"Mayor:\n"; m->imprimir();
            } 
        }
        
    } while(op != 0);
    return 0;
}