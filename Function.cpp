#include "Function.h"

Function::Function(string n, string r, string ty, Variable *out, vector<Variable *> in)
        : Variable(n, r) {
    funcType = ty;
    outVar = out;
    inVar = in;
}

string Function::process() {
    if (funcType == "convolution") {
        string FuncLines;
        int address = 100;
        string inputReg;
        string kernelReg = regDeque[0];
        regDeque.pop_front();
        string strideReg = regDeque[0];
        regDeque.pop_front();

        // Initialize inputs iteratively
        for (int i = 0; i < size(inVar); i++) {
            string singleLine;
            string regIn = inVar[i]->getRegister();

            if (i == 1) {
                int midSize = getMidSize(inVar[i]);
                string assignReg = regDeque[0];
                regDeque.pop_front();
                int midAddress = address + 4 * inVar[i]->getDimension()[0];
                string loadi = "LOADI " + assignReg + " #" + to_hex(midSize) + "\n";

                string mload = "MLOAD " + kernelReg + " " + assignReg + " #" + to_hex(midAddress) + "\n";

                FuncLines += loadi;
                FuncLines += mload;
            }

            // Get a new register to save the size
            string assignRegLoadi = regDeque[0];
            regDeque.pop_front();

            // The assignment of size
            int varSize = getSize(inVar[i]);
            string loadi = "LOADI " + assignRegLoadi + " #" + to_hex(varSize) + "\n";

            // The assignment of matrix address
            string mload = "MLOAD " + regIn + " " + assignRegLoadi + " #" + to_hex(address) + "\n";
            if (i == 0)
                inputReg = regIn;
            address += varSize;

            FuncLines += loadi;
            FuncLines += mload;
        }

        string outSizeReg = regDeque[0];
        regDeque.pop_front();
        string xReg = regDeque[0];
        regDeque.pop_front();
        string yReg = regDeque[0];
        regDeque.pop_front();

        string outSizeLoad = "LOADI " + outSizeReg + " #" + to_hex(getSize(outVar)) + "\n";

        string yloadi = "LOADI " + yReg + " #" + to_hex(inVar[0]->getDimension()[2]) + "\n";

        string xloadi = "L0: LOADI " + xReg + " #" + to_hex(inVar[0]->getDimension()[1]) + "\n";

        string vgtm = "L1: VGTM " + outVar->getRegister() + " " + outSizeReg + " " + inputReg + "\n";

        string sadd1 = "SADD " + inputReg + " " + inputReg + " " + outSizeReg + "\n";

        string sadd2 = "SADD " + xReg + " " + xReg + " #-1" + "\n";

        string cb1 = "CB #L1 " + xReg + "\n";

        string sadd3 = "SADD " + inputReg + " " + inputReg + " " + yReg + "\n";

        string sadd4 = "SADD " + yReg + " " + yReg + " #-1" + "\n";

        string cb2 = "CB #L0 " + yReg + "\n";

        string vstore = "VSTORE " + outVar->getRegister() + " " + outSizeReg + " #" + to_hex(address) + "\n";

        FuncLines += outSizeLoad;
        FuncLines += yloadi;
        FuncLines += xloadi;
        FuncLines += vgtm;
        FuncLines += sadd1;
        FuncLines += sadd2;
        FuncLines += cb1;
        FuncLines += sadd3;
        FuncLines += sadd4;
        FuncLines += cb2;
        FuncLines += vstore;

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

int Function::getMidSize(Variable * var) {
    int size = 4;
    for (int i = 1; i < 3; i++) {
        size *= var->getDimension()[i];
    }
    return size;
}
