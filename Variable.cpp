#include "Variable.h"

Variable::Variable(string n, string t, vector<int> v) {
    name = n;
    varType = t;
    dVec = v;
}
vector<int> Variable::getDimension() {
    for (auto &it : dVec)
        cout << it << ",";
    cout << endl;
    return dVec;
}

