//
// Created by Marco on 2/07/2022.
//

#include "Syntax.h"

Syntax::Syntax() {

}

bool Syntax::isCorrect(std::string operation) {
    if (!haveLetters(operation)){
        return true;
    }else{
        return false;
    }

}

bool Syntax::haveLetters(std::string operation) {
    if(!operation.empty()){
        for (int i = 0; i < operation.length(); ++i) {
        if(std::isalpha(operation[i])) {
            return true;
         }
        }
        return false;

    }
    return true;
}

Syntax::~Syntax() {

}


