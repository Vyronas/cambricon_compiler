#ifndef CAMBRICON_COMPILER_VARIABLE_H
#define CAMBRICON_COMPILER_VARIABLE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Variable {
private:
    string name;
    string varType;
    vector<int> dVec;
public:
    Variable(string n, string t, vector<int> v);
    vector<int> getDimension();
};



#endif //CAMBRICON_COMPILER_VARIABLE_H
