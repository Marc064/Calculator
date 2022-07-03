//
// Created by Marco on 2/07/2022.
//

#include "Operation.h"
#include <cmath>

Operation::Operation() {}

long double Operation::addition(double a, double b) {
    long double result = a+b;
    return result;
}

long double Operation::sustraction(double a, double b) {
    long double result = a-b;
    return result;
}

long double Operation::multiplication(double a, double b) {
    long double result = a*b;
    return result;
}

long double Operation::division(double a, double b) {
    long double result = a/b;
    return result;
}

long double Operation::potency(double a, double b) {
    long double result = std::pow(a,b);
    return result;
}
