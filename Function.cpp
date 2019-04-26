#include "Function.h"

Function::Function(string n, string r, string ty, Variable * out, vector<Variable *> in)
                    : Variable(n, r) {
    funcType = ty;
    outVar = out;
    inVar = in;
}

string Function::process() {
    if (funcType == "convolution") {
        // TODO: Implement this part to generate real ISA code
    }
    return std::__cxx11::string();
}
