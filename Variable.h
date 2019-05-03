#ifndef CAMBRICON_COMPILER_VARIABLE_H
#define CAMBRICON_COMPILER_VARIABLE_H

#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <deque>

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

    string getType();
};

/*     Marcos for not using magic numbers     */
#define MAX_REG_NUM 128

/*     Global Variables    */

// Vector to save all the variables in declare and code
extern map<string, Variable> mapVar;
// Create data structures for registers
extern deque<string> regDeque;


#endif //CAMBRICON_COMPILER_VARIABLE_H
