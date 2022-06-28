//
// Created by Marco Vargas and Miguel Alfonso on 27/06/2022.
//

#ifndef CALCULATOR_STACK_H
#define CALCULATOR_STACK_H

#include "Node.h"
#include <string>
#include <vector>

template <class T>
class Stack {

public:
    Stack();

    bool isEmpty();
    void stack(T info);
    void unstack();

    std::vector<T> getStack();

    virtual ~Stack();

private:

    Node<T>* head;

};



#endif //CALCULATOR_STACK_H
