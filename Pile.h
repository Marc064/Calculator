//
// Created by Marco Vargas and Miguel Alfonso on 27/06/2022.
//

#ifndef CALCULATOR_STACK_H
#define CALCULATOR_STACK_H

#include "Node.h"
#include <string>
#include <vector>

template <class T>
class Pile {
public:
    Pile();

    bool isEmpty();

    void Stack(T info);

    T depile();

    int getSize();

    T getTop();

    T* findInfo(char x);

    Node<T> * findNode(char x);

    std::vector<T> getPile();

    virtual ~Pile();

private:
    Node<T>* top;
};

#endif //CALCULATOR_STACK_H
