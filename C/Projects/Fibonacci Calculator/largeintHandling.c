#include <stdio.h>
#include <math.h>

char intToChar(int number) {
    int bitSize = sizeof(number);
    printf("%d\n", bitSize);
}

int main() {
    int a = pow(2, 31)-1;
    intToChar(a);

    return 0;
}