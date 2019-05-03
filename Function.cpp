#include "Function.h"

Function::Function(string n, string r, string ty, Variable *out, vector<Variable *> in)
        : Variable(n, r) {
    funcType = ty;
    outVar = out;
    inVar = in;
}

string Function::process() {
    if (funcType == "convolution") {
        // TODO: Implement this part to generate real ISA code
        string FuncLines;
        int address = 100;
        // Initialize inputs iteratively
        for (int i = 0; i < size(inVar); i++) {
            string singleLine;
            string regIn = inVar[i]->getRegister();
            // Get a new register to save the size
            string assignRegLoadi = regDeque[0];
            regDeque.pop_front();

            // The assignment of size
            int varSize = getSize(inVar[i]);
            string loadi = "LOADI " + assignRegLoadi + " #" + to_hex(varSize) + "\n";

            // The assignment of matrix address
            string mload = "MLOAD " + regIn + " " + assignRegLoadi + " #" + to_hex(address) + "\n";
            address += varSize;

            FuncLines += loadi;
            FuncLines += mload;
        }
        return FuncLines;
    }
    string str = "NOP\n";
    return str;
}

int Function::getSize(Variable *var) {
    int matrixSize = 1;
    vector<int> sizeVec = var->getDimension();
    for (int i = 0; i < 5; i++) {
        if (sizeVec[i] != 0) {
            matrixSize *= sizeVec[i];
        }
    }

    // Get the size based on variable type
    string varType = var->getType();
    if (varType == "float") {
        matrixSize *= 4;
    } else if (varType == "index64") {
        matrixSize *= 8;
    } else if (varType == "bool") {
        matrixSize *= 1;
    }

    return matrixSize;
}

string Function::to_hex(int input) {
    stringstream stream;
    stream << hex << input;
    string hexSize(stream.str());
    return hexSize;
}
