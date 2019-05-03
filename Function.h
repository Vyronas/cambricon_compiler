#ifndef CAMBRICON_COMPILER_FUNCTION_H
#define CAMBRICON_COMPILER_FUNCTION_H


#include "Variable.h"
#include <vector>
#include <sstream>
#include <ios>

class Function : public Variable {
private:
    string funcType;
    Variable * outVar;
    vector<Variable *> inVar;
    int getSize(Variable * var);
    string to_hex(int input);
public:
    Function(string n, string r, string ty, Variable *out, vector<Variable *> in);

    string process();
};


#endif //CAMBRICON_COMPILER_FUNCTION_H
