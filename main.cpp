#include <iostream>
#include "clima.h"
#include "insertion_sort.h"

using namespace std;

int main() {
    Registro_clima clima;
    int opcion = 0;
    string fecha, descripcion;
    double tempMax, tempMin, humedad;

    cout << "=== Bienvenido al Sistema de Registro del Clima ===\n";

    // Cargar datos al inicio
    clima.leerCSV("registro_clima.csv");
    cout << "\nDatos cargados correctamente desde 'registro_clima.csv'.\n";

    while (true) {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Mostrar datos\n";
        cout << "2. Agregar nuevo registro\n";
        cout << "3. Eliminar registro por indice\n";
        cout << "4. Deshacer última acción\n";
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
            cout << "\nIngrese la fecha (YYYY-MM-DD): ";
            cin >> fecha;
            cout << "Ingrese temperatura maxima: ";
            cin >> tempMax;
            cout << "Ingrese temperatura minima: ";
            cin >> tempMin;
            cout << "Ingrese humedad: ";
            cin >> humedad;
            cout << "Ingrese descripcion del clima: ";
            cin.ignore();
            getline(cin, descripcion);

            clima.agregarRegistro(fecha, tempMax, tempMin, humedad, descripcion);
            cout << "\nRegistro agregado correctamente.\n";
        } 
        else if (opcion == 3) {
            int pos;
            cout << "\nIngrese el indice del registro a eliminar: ";
            cin >> pos;
            clima.eliminarRegistro(pos);
            cout << "Registro eliminado (si existia).\n";
        } 
        else if (opcion == 4) {
            cout << "\n=== Deshaciendo ultima acción ===\n";
            clima.deshacerUltimaAccion();
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


    return 0;
}

