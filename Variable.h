//
// Created by 54443 on 4/23/2019.
//

#ifndef CAMBRICON_COMPILER_VARIABLE_H
#define CAMBRICON_COMPILER_VARIABLE_H

#include <string>
#include <vector>

using namespace std;

class Variable {
private:
    string varType;
    vector<int> dVec;
public:
    Variable(string t, int x1, int x2, int x3, int x4);
    vector<int> getDimension();
};



#endif //CAMBRICON_COMPILER_VARIABLE_H
