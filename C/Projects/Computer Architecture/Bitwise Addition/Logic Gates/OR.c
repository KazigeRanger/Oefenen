#include "OR.h"
#include "AND.h"
#include "NOT.h"
#include "NAND.h"

int OR(int inputBit1, int inputBit2) {
    return NAND(NOT(inputBit1), NOT(inputBit2));
}