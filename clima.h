#ifndef CLIMA_H_
#define CLIMA_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "insertion_sort.h"
#include "stack.h"
using namespace std;

class Registro_clima {
private:
    // Atributos privados
    vector<string> fechas;
    vector<double> tempMax;
    vector<double> tempMin;
    vector<double> humedad;
    vector<string> tipoClima;

    // Pilas para control de acciones
    StackList<vector<string>> pilaAgregados;
    StackList<vector<string>> pilaEliminados;

public:
    // Métodos principales
    void leerCSV(const string &filename);
    void mostrarDatos() const;

    // Métodos POO extra
    string toString(int i) const;

    // Ordenamientos usando Insertion Sort
    void ordenporTempmax();
    void ordenporTempMin();
    void ordenporhumedad();
    void ordenporFecha();

    // Control de filas
    void swapfila(int i, int j);

    // Operaciones con stack
    void agregarRegistro(const string& fecha, double tmax, double tmin, double hum, const string& tipo);
    void eliminarRegistro(int index);
    void deshacerUltimaAccion();
};

// ======================================================
// Implementaciones
// ======================================================

void Registro_clima::leerCSV(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo: " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // Saltar encabezado

    while (getline(file, line)) {
        stringstream ss(line);
        string tempMaxStr, tempMinStr, humStr;
        string fecha, tipo;

        getline(ss, fecha, ',');
        getline(ss, tempMaxStr, ',');
        getline(ss, tempMinStr, ',');
        getline(ss, humStr, ',');
        getline(ss, tipo, ',');

        fechas.push_back(fecha);
        tempMax.push_back(stod(tempMaxStr));
        tempMin.push_back(stod(tempMinStr));
        humedad.push_back(stod(humStr));
        tipoClima.push_back(tipo);
    }

    file.close();
}

void Registro_clima::mostrarDatos() const {
    cout << "Fecha | TempMax | TempMin | Humedad | TipoClima\n";
    for (size_t i = 0; i < fechas.size(); ++i) {
        cout << toString(i) << endl;
    }
}

// Muestra un registro como string (POO)
string Registro_clima::toString(int i) const {
    stringstream ss;
    ss << fechas[i] << " | "
       << tempMax[i] << " | "
       << tempMin[i] << " | "
       << humedad[i] << " | "
       << tipoClima[i];
    return ss.str();
}

// ==========================================
// Ordenamientos
// ==========================================
void Registro_clima::swapfila(int i, int j) {
    swap(fechas[i], fechas[j]);
    swap(tempMax[i], tempMax[j]);
    swap(tempMin[i], tempMin[j]);
    swap(humedad[i], humedad[j]);
    swap(tipoClima[i], tipoClima[j]);
}

void Registro_clima::ordenporTempmax() {
    Insertion_sorts<double> sorter;
    sorter.insertionSort(tempMax, this);
}

void Registro_clima::ordenporTempMin() {
    Insertion_sorts<double> sorter;
    sorter.insertionSort(tempMin, this);
}

void Registro_clima::ordenporhumedad() {
    Insertion_sorts<double> sorter;
    sorter.insertionSort(humedad, this);
}

void Registro_clima::ordenporFecha() {
    Insertion_sorts<string> sorter;
    sorter.insertionSort(fechas, this);
}

// ==========================================
// Funcionalidad con Stack (agregar, eliminar, deshacer)
// ==========================================
void Registro_clima::agregarRegistro(const string& fecha, double tmax, double tmin, double hum, const string& tipo) {
    vector<string> nuevo = {fecha, to_string(tmax), to_string(tmin), to_string(hum), tipo};
    pilaAgregados.push(nuevo);

    fechas.push_back(fecha);
    tempMax.push_back(tmax);
    tempMin.push_back(tmin);
    humedad.push_back(hum);
    tipoClima.push_back(tipo);

    cout << "Registro agregado y guardado en pila de acciones.\n";
}

void Registro_clima::eliminarRegistro(int index) {
    if (index < 0 || index >= (int)fechas.size()) {
        cout << "Índice inválido.\n";
        return;
    }

    vector<string> eliminado = {
        fechas[index],
        to_string(tempMax[index]),
        to_string(tempMin[index]),
        to_string(humedad[index]),
        tipoClima[index]
    };
    pilaEliminados.push(eliminado);

    fechas.erase(fechas.begin() + index);
    tempMax.erase(tempMax.begin() + index);
    tempMin.erase(tempMin.begin() + index);
    humedad.erase(humedad.begin() + index);
    tipoClima.erase(tipoClima.begin() + index);

    cout << "Registro eliminado y guardado en pila de eliminados.\n";
}

void Registro_clima::deshacerUltimaAccion() {
    if (!pilaAgregados.empty()) {
        cout << "Deshaciendo última inserción...\n";
        pilaAgregados.pop();
        fechas.pop_back();
        tempMax.pop_back();
        tempMin.pop_back();
        humedad.pop_back();
        tipoClima.pop_back();
    } else if (!pilaEliminados.empty()) {
        cout << "Deshaciendo última eliminación...\n";
        vector<string> ult = pilaEliminados.top();
        pilaEliminados.pop();

        fechas.push_back(ult[0]);
        tempMax.push_back(stod(ult[1]));
        tempMin.push_back(stod(ult[2]));
        humedad.push_back(stod(ult[3]));
        tipoClima.push_back(ult[4]);
    } else {
        cout << "No hay acciones para deshacer.\n";
    }
}

#endif // CLIMA_H_
