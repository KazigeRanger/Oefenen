#include <stdio.h>
#include <math.h>

char intToChar(int number) {
    int bitSize = sizeof(number);
    
    if (bitSize != 4) {
        fprintf(stderr, "Error: an integer should be passed as the argument to the intToChar() function.");
        return 1;
    }

    
}

int main() {
    int a = pow(2, 31)-1;
    intToChar(a);

    return 0;
}