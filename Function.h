#ifndef CAMBRICON_COMPILER_FUNCTION_H
#define CAMBRICON_COMPILER_FUNCTION_H


#include "Variable.h"
#include <vector>

class Function : public Variable {
private:
    string funcType;
    Variable * outVar;
    vector<Variable *> inVar;
public:
    Function(string n, string r, string ty, Variable *out, vector<Variable *> in);

    string process();
};


#endif //CAMBRICON_COMPILER_FUNCTION_H
