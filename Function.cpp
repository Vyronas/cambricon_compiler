#include "Function.h"

Function::Function(string n, string r, string ty, string out, vector<string> in)
                    : Variable(n, r) {
    funcType = ty;
    outVar = out;
    inVar = in;
}

string Function::process() {

    return std::__cxx11::string();
}
