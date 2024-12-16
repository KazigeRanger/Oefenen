#ifndef FOURBITBINARY_H
#define FOURBITBINARY_H

#include "eightBitBinary.h"

typedef struct {
    char binary[5];
} FBBINARY;

EBBINARY fourBitAdd(FBBINARY num1, FBBINARY num2);

#endif