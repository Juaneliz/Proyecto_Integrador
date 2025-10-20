#ifndef INSERTION_SORTS_H_
#define INSERTION_SORTS_H_

#include <vector>
using namespace std;

template <class T>
class Insertion_sorts {
public:
    // v = la columna a usar como criterio
    // tabla = objeto que tiene swapfila
    template <class Clima>
    void insertionSort(vector<T> &v, Clima *tabla);
};


template <class T>
template <class Clima>
void Insertion_sorts<T>:: insertionSort(vector<T> &v, Clima *tabla) {
    for (size_t i = 1; i < v.size(); i++) {
        int j = i;
        while (j > 0 && v[j] < v[j - 1]) {
            tabla->swapfila(j, j - 1); // aquí usamos el swapfila del objeto
            j--;
        }
    }
}
#endif


