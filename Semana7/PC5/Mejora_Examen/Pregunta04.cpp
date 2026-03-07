#include <iostream>
#include <fstream>

using namespace std;

struct Venta{
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

long contarRegistros(const char* nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary | ios::ate);
    if(!archivo){
        return 0;
    }
    long tam = archivo.tellg();
    archivo.close();
    return tam / sizeof(Venta);
}

int main(){
    const char* fileBin = "input/ventas.dat";
    long n = contarRegistros(fileBin);

    if(n == 0){
        cout << "Error: Archivo no encontrado o vacio." << endl;
        return 1;
    }

    Venta* ventas = new Venta[n];
    ifstream archivo(fileBin, ios::binary);
    archivo.read(reinterpret_cast<char*>(ventas), n * sizeof(Venta));
    archivo.close();

    int maxVend = 0, maxProd = 0;
    for(int i = 0; i < n; i++){
        if((ventas + i)->idVendedor > maxVend){
            maxVend = (ventas + i)->idVendedor;
        }
        if((ventas + i)->idProducto > maxProd){
            maxProd = (ventas + i)->idProducto;
        }
    }

    double* recaudacionVendedor = new double[maxVend + 1]{0};
    int* cantidadProducto = new int[maxProd + 1]{0};
    double montoTotal = 0;

    for(int i = 0; i < n; i++){
        Venta* v = (ventas + i);
        double subtotal = v->cantidad * v->precioUnitario;
        montoTotal += subtotal;
        
        *(recaudacionVendedor + v->idVendedor) += subtotal;
        *(cantidadProducto + v->idProducto) += v->cantidad;
    }

    int mejorVendedor = 0;
    for(int i = 1; i <= maxVend; i++){
        if(*(recaudacionVendedor + i) > *(recaudacionVendedor + mejorVendedor)){
            mejorVendedor = i;
        }
    }

    int mejorProducto = 0;
    for(int i = 1; i <= maxProd; i++){
        if(*(cantidadProducto + i) > *(cantidadProducto + mejorProducto)){
            mejorProducto = i;
        }
    }

    ofstream reporte("output/reporte.txt");
    reporte.setf(ios::fixed);
    reporte.precision(2);

    reporte << "--- REPORTE GENERAL DE VENTAS ---" << endl;
    reporte << "Total de registros: " << n << endl;
    reporte << "MONTO TOTAL VENDIDO:" << endl;
    reporte << "S/. " << montoTotal << endl;
    
    reporte << "\n----------------------" << endl;
    reporte << "VENDEDOR CON MAYOR RECAUDACIÓN" << endl;
    reporte << "ID Vendedor: " << mejorVendedor << endl;
    reporte << "Total vendido: S/. " << *(recaudacionVendedor + mejorVendedor) << endl;
    
    reporte << "\n----------------------" << endl;
    reporte << "PRODUCTO MAS VENDIDO" << endl;
    reporte << "ID Producto: " << mejorProducto << endl;
    reporte << "Total unidades: " << *(cantidadProducto + mejorProducto) << endl;

    reporte << "\n----------------------" << endl;
    reporte << "VENTAS SOSPECHOSAS (cantidad> 100):" << endl << endl;
    for(int i = 0; i < n; i++){
        Venta* v = (ventas + i);
        if(v->cantidad > 100){
            reporte << "ID Venta: " << v->idVenta 
                    << " | Vendedor: " << v->idVendedor 
                    << " Producto: " << v->idProducto 
                    << " Cantidad: " << v->cantidad << endl;
        }
    }

    reporte.close();
    cout << "Reporte generado en output/reporte.txt" << endl;

    delete[] ventas;
    delete[] recaudacionVendedor;
    delete[] cantidadProducto;

    return 0;
}