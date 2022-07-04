//
// Created by Marco Vargas and Miguel Alfonso on 2/07/2022.
//

#ifndef CALCULATOR_OPERATION_H
#define CALCULATOR_OPERATION_H


class Operation {
public:
    Operation();
    long double addition (double, double);
    long double subtraction (double, double);
    long double multiplication (double, double);
    long double division (double, double);
    long double power (double, double);

    virtual ~Operation();
};


#endif //CALCULATOR_OPERATION_H