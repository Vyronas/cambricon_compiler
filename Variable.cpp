#include "Variable.h"

Variable::Variable(string n, string t, string r, vector<int> v) {
    name = n;
    varType = t;
    dVec = v;
    reg = r;
}

Variable::Variable(string n, string r) {
    name = n;
    reg = r;
}

vector<int> Variable::getDimension() {
    return dVec;
}

string Variable::getRegister() {
    return reg;
}

string Variable::getName() {
    return name;
}

string Variable::getType() {
    return varType;
}



