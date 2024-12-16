#include "XOR.h"
#include "AND.h"
#include "NOR.h"

int XOR(int inputBit1, int inputBit2) {
    return NOR(NOR(inputBit1, inputBit2), AND(inputBit1, inputBit2));
}