//
// Created by 54443 on 4/23/2019.
//

#include "Variable.h"

Variable::Variable(string t, int x1, int x2, int x3, int x4) {
    varType = t;
    dVec.push_back(x1);
    dVec.push_back(x2);
    dVec.push_back(x3);
    dVec.push_back(x4);
}
vector<int> Variable::getDimension() {
    return dVec;
}

