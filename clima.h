#ifndef CLIMA_H_
#define CLIMA_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "double_list.h"
using namespace std;

class Registro_clima {
private:
    Double_list lista;

public:
    // Métodos principales
    void leerCSV(const string &filename);
    void mostrarDatos() const;

    void agregarRegistro(const string& f,double max, double min, double hum, const string& t);
    void eliminarRegistro(int index);

    void guardarCSV(const string&filename);

    string toString(int i) const;

    // Ordenamientos usando Insertion Sort
    void ordenporTempmax();
    void ordenporTempMin();
    void ordenporhumedad();
    void ordenporFecha();
};


void Registro_clima::leerCSV(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo: " << filename << endl;
        return;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        string tempMaxStr, tempMinStr, humStr;
        string fecha, tipo;

        getline(ss, fecha, ',');
        getline(ss, tempMaxStr, ',');
        getline(ss, tempMinStr, ',');
        getline(ss, humStr, ',');
        getline(ss, tipo, ',');

        lista.push_back(Clima(fecha,stod(tempMaxStr),stod(tempMinStr),stod(humStr),tipo));
    }

    file.close();
}


void Registro_clima::mostrarDatos() const {
    lista.print(); 
}

void Registro_clima::agregarRegistro(const string& fecha, double tmax,
                                     double tmin, double hum,
                                     const string& tipo) {
    lista.push_back(Clima(fecha, tmax, tmin, hum, tipo));
}

void Registro_clima::eliminarRegistro(int index) {
    if (!lista.removeAt(index)) {
        cout << "Índice inválido.\n";
    }
}



void Registro_clima::guardarCSV(const string &filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error al escribir: " << filename << endl;
        return;
    }

    file << "fecha,tempMax,tempMin,humedad,tipo\n";

    for (auto &c : lista.toVector()) {
        file << c.fecha << ","
             << c.tmax << ","
             << c.tmin << ","
             << c.humedad << ","
             << c.tipo << "\n";
    }

    file.close();
    cout << "Archivo guardado.\n";
}

void Registro_clima::ordenporTempmax() {
    lista.insertionSort([](const Clima &a, const Clima &b) {
        return a.tmax < b.tmax;
    });
}

void Registro_clima::ordenporTempMin() {
    lista.insertionSort([](const Clima &a, const Clima &b) {
        return a.tmin < b.tmin;
    });
}

void Registro_clima::ordenporhumedad() {
    lista.insertionSort([](const Clima &a, const Clima &b) {
        return a.humedad < b.humedad;
    });
}

void Registro_clima::ordenporFecha() {
    lista.insertionSort([](const Clima &a, const Clima &b) {
        return a.fecha < b.fecha;
    });
}

#endif // CLIMA_H_
