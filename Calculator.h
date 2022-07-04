#include <string>
#include "Pile.cpp"

using namespace std;

class Calculator {
public:

    Calculator();

    bool isNumber(const string &str);

    vector<string> breakDown(string operation, bool type);

    //Pile<string>* operationPreFix(string operation);

    double calculate (string operation, bool type);

    Pile<string>* operationPosFix(string operation);

    //vector<string>record();

    virtual ~Calculator();


};
