#include <iostream>
#include <string>
#include <vector>
#include "insertion_sort.h"
#include "clima.h"

int main() {

    Registro_clima clima;
    clima.leerCSV("registro_clima.csv");

        // 2. Mostrar los datos originales
    cout << "=== Datos originales ===" << endl;
    clima.mostrarDatos();

    // 3. Ordenar por temperatura máxima
    clima.ordenporTempmax();
    cout << "\n=== Ordenados por TempMax ===" << endl;
    clima.mostrarDatos();

    // 4. Ordenar por temperatura mínima
    clima.ordenporTempMin();
    cout << "\n=== Ordenados por TempMin ===" << endl;
    clima.mostrarDatos();

    // 5. Ordenar por humedad
    clima.ordenporhumedad();
    cout << "\n=== Ordenados por Humedad ===" << endl;
    clima.mostrarDatos();

    // 6. Ordenar por fecha
    clima.ordenporFecha();
    cout << "\n=== Ordenados por Fecha ===" << endl;
    clima.mostrarDatos();


    return 0;
}
