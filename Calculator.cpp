#include "Calculator.h"
#include <iostream>
#include <math.h>



Calculator::Calculator() {}

bool Calculator::isNumber(const string& str){
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

vector<string> Calculator::breakDown(string operation, bool type) {
    vector<string> breakOperation;
    string aux ="";
    for(char c : operation){
        if(isdigit(c)!=0){
            if(!isNumber(aux)){
                aux = "";
            }
            aux += c;
        }else{
            if(isNumber(aux)){
                breakOperation.push_back(aux);
            }
            aux = c;
            if(breakOperation.back().compare("*")==0 && aux.compare("*")==0){
                breakOperation.back() = "**";
            }else{
                breakOperation.push_back(aux);
            }
        }
    }
    if(type == true){
        Pile<string> *operationInverse = new Pile<string>();
        for(string s : breakOperation){
            operationInverse->Stack(s);
        }
        breakOperation.clear();
        while(!operationInverse->isEmpty()){
            breakOperation.push_back(operationInverse->getTop());
            operationInverse->depile();
        }
    }
    return breakOperation;
}

Pile<string>* Calculator::operationPosFix(string operation) {
    vector<string> breakOperation = breakDown(operation, false);
    Pile<string>* out = new Pile<string>();
    Pile<string>* symbols = new Pile<string>();
    for(string s : breakOperation){
        if(isNumber(s)){
            out->Stack(s);
            if(!symbols->isEmpty()){
                if(symbols->getTop().compare("*")==0){
                    out->Stack(symbols->getTop());
                    symbols->depile();
                }
            }
        }else{
            symbols->Stack(s);
            if(symbols->getTop().compare(")")==0){
                while(symbols->getTop().compare("(")!=0){
                    if(symbols->getTop().compare("(")!=0 && symbols->getTop().compare(")")!=0){
                        out->Stack(symbols->getTop());
                    }
                    symbols->depile();
                }
                symbols->depile();
            }
        }
    }
    if(!symbols->isEmpty()){
        while(!symbols->isEmpty()){
            out->Stack(symbols->getTop());
            symbols->depile();
        }
    }
    return out;
}

/*Pile<string>* Calculator::operationPreFix(string operation) {
    vector<string> operationreverse = breakDown(operation, true);
    Pile<string>* operationPreFix = new Pile<string>();
    Pile<string>* symbols = new Pile<string>();
    for(string s : operationreverse){
        if(isNumber(s)){
            operationPreFix->Stack(s);
        }else{
            symbols->Stack(s);
            if(s.compare("(")==0){
                if(symbols->findNode(")") != NULL){
                    while(!symbols->isEmpty()||symbols->getTop().compare(")")!=0){
                        if(symbols->getTop().compare(")")!=0&&symbols->getTop().compare("(")!=0){
                            operationPreFix->Stack(symbols->getTop());
                        }
                        symbols->depile();
                    }
                    symbols->depile();
                }else{
                    return NULL;
                }
            }else if(operationPreFix->findNode(")")== NULL && operationPreFix->findNode(")")== NULL){

            }
        }
    }
    if(!symbols->isEmpty()){
        while(!symbols->isEmpty()){
            operationPreFix->Stack(symbols->getTop());
            symbols->depile();
        }
    }
    return operationPreFix;
}*/

double Calculator::calculate(string operation, bool type) {
    double result;
    if (type == true) {
        /*string aux;
        vector<string> calculatePreFix;
        Pile<string>* PreFix = operationPreFix(operation);
        while(!PreFix->isEmpty()){
            calculatePreFix.push_back(PreFix->getTop());
            PreFix->depile();
        }
        for(string s: calculatePreFix){
            PreFix->Stack(s);
        }*/
    } else {
        Pile<string> *PosFix = operationPosFix(operation);
        Pile<string> *aux = new Pile<string>();
        while (!PosFix->isEmpty()) {
            aux->Stack(PosFix->getTop());
            PosFix->depile();
        }
        for (string s: aux->getPile()) {
            PosFix->Stack(s);
            if (!isNumber(PosFix->getTop())) {
                string opertion = PosFix->depile();
                std::cout << opertion << std::endl;
                double a = stod(PosFix->depile());
                std::cout << a << std::endl;
                double b = stod(PosFix->depile());
                std::cout << b << std::endl;
                if (opertion.compare("+") == 0 || opertion.compare("-") == 0) {
                    result = opertion.compare("+") == 0 ? b + a : b - a;
                    std::cout << "1: " << result << std::endl;
                    PosFix->Stack(to_string(result));
                } else if (opertion.compare("/") == 0 || opertion.compare("*") == 0) {
                    result = opertion.compare("/") == 0 ? b / a : b * a;
                    std::cout << "2: " << result << std::endl;
                    PosFix->Stack(to_string(result));

                } else {
                    result = pow(b, a);
                    std::cout << "3: " << result << std::endl;
                    PosFix->Stack(to_string(result));
                }
            }
        }
        result = stod(PosFix->getTop());
        return result;
    }
}

Calculator::~Calculator() {

}
