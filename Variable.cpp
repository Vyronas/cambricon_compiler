#include "Variable.h"

Variable::Variable(string n, string t, string r, vector<int> v) {
    name = n;
    varType = t;
    dVec = v;
    reg = r;
}

vector<int> Variable::getDimension() {
    for (auto &it : dVec)
        cout << it << ",";
    cout << endl;
    return dVec;
}

string Variable::getRegister() {
    return reg;
}

string Variable::getName() {
    return name;
}

