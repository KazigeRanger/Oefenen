#include <stdio.h>

int square(int* const i) {
    *i *= *i;
    return *i;
}

int main() {
    int number = 11;
    int* numPtr = &number;

    printf("%p\n", (void *)numPtr);
    printf("%d\n", number);

    square(numPtr);

    printf("%d\n", number);
    return 0;
}