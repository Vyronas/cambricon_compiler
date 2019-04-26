#ifndef CAMBRICON_COMPILER_FUNCTION_H
#define CAMBRICON_COMPILER_FUNCTION_H


#include "Variable.h"

class Function : public Variable{
private:
    string funcType;
    string outVar;
    vector<string> inVar;
public:
    Function(string n, string r, string ty, string out, vector<string> in);
};


#endif //CAMBRICON_COMPILER_FUNCTION_H
