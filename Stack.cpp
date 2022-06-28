//
// Created by Marco Vargas and Miguel Alfonso on 27/06/2022.
//

#include "Stack.h"


template<class T>
Stack<T>::Stack() {

}

template<class T>
bool Stack<T>::isEmpty() {
    return head == NULL;
}

template<class T>
void Stack<T>::stack(T info) {

    Node<T>* newNode =new Node<T>(info);

    if ( isEmpty() ){
        head = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }

}

template<class T>
void Stack<T>::unstack() {
    if ( isEmpty() ){

    }

}

template<class T>
std::vector<T> Stack<T>::getStack() {
    return std::vector<T>();
}

template<class T>
Stack<T>::~Stack() {

}
