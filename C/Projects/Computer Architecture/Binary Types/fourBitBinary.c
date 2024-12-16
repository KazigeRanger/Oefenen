#include "fourBitBinary.h"
#include "eightBitBinary.h"

#include "../Bitwise Addition/Logic Gates/XOR.h"
#include "../Bitwise Addition/Logic Gates/AND.h"
#include "../Bitwise Addition/Logic Gates/OR.h"

#include <stdio.h>
#include <stdlib.h>

EBBINARY fourBitAdd(FBBINARY num1, FBBINARY num2) {
    printf("num1: %s\n", num1.binary);
    printf("num2: %s\n", num2.binary);

    int carryBit = 0;
    int sumBit;

    static EBBINARY result;

    for (int i = 0; i < 4; i++) {
        int bit = 3 - i;
        // printf("num1 bit: %c\n", num1.binary[bit]);
        // printf("num2 bit: %c\n", num2.binary[bit]);

        sumBit = XOR(XOR((int) num1.binary[bit] - '0', (int) num2.binary[bit] - '0'), carryBit);
        // printf("XOR((int) num1.binary[bit], (int) num2.binary[bit]) = %d\n", XOR((int) num1.binary[bit], (int) num2.binary[bit]));
        carryBit = OR(AND(carryBit,(int) num1.binary[bit] - '0'), OR(AND((int) num1.binary[bit] - '0', (int) num2.binary[bit] - '0'), AND((int) num2.binary[bit] - '0', carryBit)));

        // printf("Bit %d: sumBit = %d & carryBit = %d\n", bit, sumBit, carryBit);

        result.binary[bit+4] = sumBit + '0';
    }

    result.binary[0] = 0 + '0';
    result.binary[1] = 0 + '0';
    result.binary[2] = 0 + '0';
    result.binary[3] = carryBit + '0';

    printf("result: %s\n", result.binary);

    return result;
}

/**
 * LET OP!
 * De onderstaande code is geschreven door ChatGPT en werkt niet goed.
 */
// EBBINARY fourBitAdd(FBBINARY num1, FBBINARY num2) {
//     printf("num1: %s\n", num1.binary);
//     printf("num2: %s\n", num2.binary);

//     int carryBit = 0;
//     int sumBit;
//     static EBBINARY result;

//     // Start from the least significant bit (index 3) to the most significant bit (index 0)
//     for (int i = 0; i < 4; i++) {
//         int bit = 3 - i;  // Start from the last bit of the 4-bit number

//         // Compute the sum bit: XOR of the two bits and the carry bit
//         sumBit = XOR(XOR((int) num1.binary[bit] - '0', (int) num2.binary[bit] - '0'), carryBit);
        
//         // Compute the carry bit for the next bit
//         carryBit = AND((int) num1.binary[bit] - '0', (int) num2.binary[bit] - '0') 
//                     + AND(carryBit, XOR((int) num1.binary[bit] - '0', (int) num2.binary[bit] - '0'));

//         result.binary[bit] = sumBit + '0';  // Store the sum bit in result
//     }

//     // Store the carry in the higher bit
//     result.binary[4] = carryBit + '0';
//     result.binary[5] = result.binary[6] = result.binary[7] = '0';  // Clear the upper bits for the result

//     printf("result: %s\n", result.binary);
//     return result;
// }
