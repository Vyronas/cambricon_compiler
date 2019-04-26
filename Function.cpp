#include "Function.h"

Function::Function(string n, string r, string ty, Variable * out, vector<Variable *> in)
                    : Variable(n, r) {
    funcType = ty;
    outVar = out;
    inVar = in;
}

string Function::process() {
    if (funcType == "convolution") {

    }
    return std::__cxx11::string();
}
