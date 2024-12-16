#include "NAND.h"
#include "AND.h"
#include "NOT.h"

int NAND(int inputBit1, int inputBit2) {
    return NOT(AND(inputBit1, inputBit2));
}