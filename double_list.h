#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// ------------------------------------------------------
// Clase Clima
// ------------------------------------------------------
class Clima {
public:
    string fecha;
    double tmax;
    double tmin;
    double humedad;
    string tipo;

    Clima();
    Clima(const string &f, double ma, double mi, double h, const string &t);

    string toString() const;
};

Clima::Clima() : fecha(""), tmax(0), tmin(0), humedad(0), tipo("") {}

Clima::Clima(const string &f, double ma, double mi, double h, const string &t)
    : fecha(f), tmax(ma), tmin(mi), humedad(h), tipo(t) {}

string Clima::toString() const {
    stringstream ss;
    ss << fecha << " | " << tmax << " | " << tmin
       << " | " << humedad << " | " << tipo;
    return ss.str();
}


class Node {
public:
    Clima data;
    Node *next;
    Node *prev;

    Node(const Clima &c);
};

Node::Node(const Clima &c)
    : data(c), next(nullptr), prev(nullptr) {}

// Lista doblemente enlazada
class Double_list {
private:
    Node *head;
    Node *tail;
    int cnt;

    void printRec(Node *n) const;
    void toVectorRec(Node *n, vector<Clima> &v) const;
    Node *buscarFechaRec(Node *n, const string &fecha) const;
    int countRec(Node *n) const;

public:
    Double_list();
    ~Double_list();

    bool empty() const;
    int size() const;

    void push_back(const Clima &c);
    Node *nodeAt(int index) const;
    bool removeAt(int index);

    void clear();
    Node *removeNode(Node *n);
    void insertBefore(Node *ref, Node *n);

    vector<Clima> toVector() const;
    void print() const;

    Node *buscarPorFecha(const string &fecha) const;
    int countRecursive() const;

    // Insertion sort
    template <typename Comparator>
    void insertionSort(Comparator comp);
};

// Constructores
Double_list::Double_list() : head(nullptr), tail(nullptr), cnt(0) {}

Double_list::~Double_list() {
    clear();
}

bool Double_list::empty() const { return cnt == 0; }
int Double_list::size() const { return cnt; }


void Double_list::push_back(const Clima &c) {
    Node *n = new Node(c);
    if (!head) head = tail = n;
    else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    cnt++;
}

Node *Double_list::nodeAt(int index) const {
    if (index < 0 || index >= cnt) return nullptr;

    Node *cur;
    if (index < cnt / 2) {
        cur = head;
        for (int i = 0; i < index; i++) cur = cur->next;
    } else {
        cur = tail;
        for (int i = cnt - 1; i > index; i--) cur = cur->prev;
    }
    return cur;
}

bool Double_list::removeAt(int index) {
    Node *n = nodeAt(index);
    if (!n) return false;
    removeNode(n);
    return true;
}

void Double_list::clear() {
    Node *cur = head;
    while (cur) {
        Node *next = cur->next;
        delete cur;
        cur = next;
    }
    head = tail = nullptr;
    cnt = 0;
}

Node *Double_list::removeNode(Node *n) {
    if (!n) return nullptr;

    if (n->prev) n->prev->next = n->next;
    else head = n->next;

    if (n->next) n->next->prev = n->prev;
    else tail = n->prev;

    n->next = n->prev = nullptr;
    cnt--;
    return n;
}

// ------------------------------------------------------
// insertBefore
// ------------------------------------------------------
void Double_list::insertBefore(Node *ref, Node *nuevo) {
    if (!ref) return;

    nuevo->next = ref;
    nuevo->prev = ref->prev;

    if (ref->prev) ref->prev->next = nuevo;
    else head = nuevo;

    ref->prev = nuevo;

    cnt++;
}

// ------------------------------------------------------
// insertionSort
// ------------------------------------------------------
template <typename Comparator>
void Double_list::insertionSort(Comparator comp) {
    if (!head || !head->next) return;

    Node *actual = head->next;

    while (actual) {
        Node *siguiente = actual->next;
        Node *mover = actual;

        Node *pre = actual->prev;
        while (pre && comp(mover->data, pre->data)) {
            pre = pre->prev;
        }

        if (pre == actual->prev) {
            actual = siguiente;
            continue;
        }

        mover = removeNode(mover);

        if (!pre) insertBefore(head, mover);
        else insertBefore(pre->next, mover);

        actual = siguiente;
    }
}

// ------------------------------------------------------
// Recursivas
// ------------------------------------------------------
void Double_list::printRec(Node *n) const {
    if (!n) return;
    cout << n->data.toString() << "\n";
    printRec(n->next);
}

void Double_list::toVectorRec(Node *n, vector<Clima> &v) const {
    if (!n) return;
    v.push_back(n->data);
    toVectorRec(n->next, v);
}

Node *Double_list::buscarFechaRec(Node *n, const string &fecha) const {
    if (!n) return nullptr;
    if (n->data.fecha == fecha) return n;
    return buscarFechaRec(n->next, fecha);
}

int Double_list::countRec(Node *n) const {
    if (!n) return 0;
    return 1 + countRec(n->next);
}

// ------------------------------------------------------
// Públicas que llaman recursivas
// ------------------------------------------------------
vector<Clima> Double_list::toVector() const {
    vector<Clima> v;
    toVectorRec(head, v);
    return v;
}

void Double_list::print() const {
    cout << "Fecha | TempMax | TempMin | Humedad | TipoClima\n";
    printRec(head);
}

Node *Double_list::buscarPorFecha(const string &fecha) const {
    return buscarFechaRec(head, fecha);
}

int Double_list::countRecursive() const {
    return countRec(head);
}

#endif // DOUBLE_LIST_H
