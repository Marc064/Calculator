#include <iostream>
#include "Syntax.h"

using namespace std;
int main() {

    cout<<"Calculadora"<<endl;
    while (true){
        cout<<"Escriba una operacion o escriba exit para salir"<<endl;
        string op;
        cin>>op;
        if(op != "exit"){
            Syntax *sin = new Syntax();
            if (sin->isCorrect(op)){

            }else{
                cout<<"SYNTAX ERROR"<<endl;
            }
        }else{
            cout<<"Apagando";
            break;
        }
    }

    return EXIT_SUCCESS;
}
