#include "NOR.h"
#include "OR.h"
#include "NOT.h"

int NOR(int inputBit1, int inputBit2) {
    return NOT(OR(inputBit1, inputBit2));
}