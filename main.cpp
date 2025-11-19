#include <iostream>
#include "clima.h"
#include "double_list.h"

using namespace std;

int main() {
    Registro_clima clima;
    int opcion = 0;


    cout << "=== Bienvenido al Sistema de Registro del Clima ===\n";

    // Cargar datos al inicio
    clima.leerCSV("registro_clima.csv");
    cout << "\nDatos cargados correctamente desde 'registro_clima.csv'.\n";

    while (true) {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Mostrar datos\n";
        cout << "2. Agregar nuevo registro\n";
        cout << "3. Eliminar registro por indice\n";
        cout << "4. Guardar CSV\n";
        cout << "5. Ordenar por temperatura maxima\n";
        cout << "6. Ordenar por temperatura minima\n";
        cout << "7. Ordenar por humedad\n";
        cout << "8. Ordenar por fecha\n";
        cout << "9. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "\n=== Mostrando datos ===\n";
            clima.mostrarDatos();
        } 
        else if (opcion == 2) {
            string f,tipo;
            double tmax,tmin,hum;
            cout << "\nIngrese la fecha (YYYY-MM-DD): ";
            cin >> f;
            cout << "Ingrese temperatura maxima: ";
            cin >> tmax;
            cout << "Ingrese temperatura minima: ";
            cin >> tmin;
            cout << "Ingrese humedad: ";
            cin >> hum;
            cout << "Ingrese descripcion del clima: ";
            cin.ignore();
            cout <<"Tipo";

            getline(cin, tipo);

            clima.agregarRegistro(f, tmax, tmin, hum, tipo);
            cout << "\nRegistro agregado correctamente.\n";
        } 
        else if (opcion == 3) {
            int idx;
            cout << "\nIngrese el indice del registro a eliminar: ";
            cin >> idx;
            clima.eliminarRegistro(idx);
            cout << "Registro eliminado (si existia).\n";
        } 
        else if (opcion == 4) {
            cout << "\n=== Guardar CSV ===\n";
            clima.guardarCSV("registro_clima.csv");
        } 
        else if (opcion == 5) {
            cout << "\n=== Ordenando por Temperatura Maxima ===\n";
            clima.ordenporTempmax();
            clima.mostrarDatos();
        } 
        else if (opcion == 6) {
            cout << "\n=== Ordenando por Temperatura Minima ===\n";
            clima.ordenporTempMin();
            clima.mostrarDatos();
        } 
        else if (opcion == 7) {
            cout << "\n=== Ordenando por Humedad ===\n";
            clima.ordenporhumedad();
            clima.mostrarDatos();
        } 
        else if (opcion == 8) {
            cout << "\n=== Ordenando por Fecha ===\n";
            clima.ordenporFecha();
            clima.mostrarDatos();
        } 
        else if (opcion == 9) {
            cout << "\nSaliendo del programa...\n";
            break;
        } 
        else {
            cout << "\nOpcion no valida. Intente de nuevo.\n";
        }
    }

    return 0;
}

