#ifndef STACK_H_
#define STACK_H_

#include <string>
#include<iostream>
#include <sstream>
#include <list>

using namespace std;
template <class T>
class Stack {
public:
	virtual void push(T) = 0;
	virtual T top() const  = 0;
	virtual void pop()  = 0;
	virtual bool empty() const = 0;
	virtual void clear() = 0;
};



template <class T>
class StackList : public Stack<T> {
private:
    list<T> data;

public:
    void push(T val);
    T top() const;
    void pop();
    bool empty() const;
    void clear();
};

template <class T>
void StackList<T>::push(T val)  {
    data.push_front(val);
}

template <class T>
T StackList<T>::top() const  {
    if (data.empty()) {
        cout << "Error: la pila está vacía.\n";
        return T(); // Retorna valor por defecto del tipo T (0, "", etc.)
    }
    return data.front();
}

template <class T>
void StackList<T>::pop()  {
    if (data.empty()) {
        cout << "Error: no se puede hacer pop, pila vacía.\n";
        return;
    }
    data.pop_front();
}

template <class T>
bool StackList<T>::empty() const  {
    return data.empty();
}

template <class T>
void StackList<T>::clear()  {
    data.clear();
}


#endif //Stack_H_