#include "Logic Gates/AND.h"
#include "Logic Gates/NOT.h"
#include "Logic Gates/NAND.h"
#include "Logic Gates/OR.h"
#include "Logic Gates/NOR.h"
#include "Logic Gates/XOR.h"

#include "../Binary Types/fourBitBinary.h"
#include "../Binary Types/eightBitBinary.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
    FBBINARY binNum1 = {"1111"};  // 4-bit binary: 1111 (Decimal = 15)
    FBBINARY binNum2 = {"0001"};  // 4-bit binary: 0001 (Decimal = 1)

    EBBINARY addedNum = fourBitAdd(binNum1, binNum2);
    addedNum.binary[8] = '\0';
    printf("Added result: %s\n", addedNum.binary);  // Print the 8-bit result

    return 0;
}
