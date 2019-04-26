#ifndef CAMBRICON_COMPILER_VARIABLE_H
#define CAMBRICON_COMPILER_VARIABLE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Variable {
protected:
    string name;
    string varType;
    string reg;
    vector<int> dVec;
public:
    Variable(string n, string t, string r, vector<int> v);

    Variable(string n, string r);

    vector<int> getDimension();

    string getName();

    string getRegister();
};


#endif //CAMBRICON_COMPILER_VARIABLE_H
