
#ifndef CLIMA_H_
#define CLIMA_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "insertion_sort.h"
using namespace std;



class Registro_clima {
public:
    void leerCSV(const string &filename);
    void mostrarDatos() const;

    //Ordenamientos usando Insertion sort

    void ordenporTempmax();
    void ordenporTempMin();
    void ordenporhumedad();
    void ordenporFecha();


    void swapfila(int i, int j);



    // Vectores públicos para poder ordenarlos después
    vector<string> fechas;
    vector<double> tempMax;
    vector<double> tempMin;
    vector<double> humedad;
    vector<string> tipoClima;
};

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
        cout << fechas[i] << " | " 
             << tempMax[i] << " | " 
             << tempMin[i] << " | " 
             << humedad[i] << " | " 
             << tipoClima[i] << endl;
    }
}


void Registro_clima::swapfila(int i, int j){
    swap(fechas[i],fechas[j]);
    swap(tempMax[i],tempMax[j]);
    swap(tempMin[i],tempMin[j]);
    swap(humedad[i],humedad[j]);
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



















#endif //Clima_H_//