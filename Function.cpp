#include "Function.h"

Function::Function(string n, string r, string ty, string out, vector<string> in)
                    : Variable(n, r) {
    funcType = ty;
    outVar = out;
    inVar = in;
}
