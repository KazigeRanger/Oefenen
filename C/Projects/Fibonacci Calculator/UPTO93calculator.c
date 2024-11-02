#include <stdio.h>
#include <stdlib.h>

#define TYPEOF(x) _Generic((x), \
                    int: "int", \
                    float: "float", \
                    double: "double", \
                    char *: "string", \
                    default: "unknown type")

long long calculateNthFibonacci(int const N) {
    long long firstFibNum = 0;
    long long secondFibNum = 1;

    long long *fibNumbers = (long long *)malloc(N * sizeof(long long));

    if (fibNumbers == NULL) {
        fprintf(stderr, "Error: failed to allocate memory.");
        return 1;
    }

    fibNumbers[0] = firstFibNum;
    fibNumbers[1] = secondFibNum;

    for (int i = 2; i < N; i++) {
        fibNumbers[i] = fibNumbers[i-1]+fibNumbers[i-2];
    }

    // for (int i = 0; i < N; i++) {
    //     printf("%d\n", fibNumbers[i]);
    // }

    long long result = fibNumbers[N-1];
    free(fibNumbers);

    return result;
}

int main(int argc, char *argv[]) {
    // printf("argc: %d\n", argc);

    // for (int i = 0; i < argc; i++) {
    //     printf("arg %d: %s\n", i, argv[i]);
    // }

    if (argc != 2) {
        fprintf(stderr, "Error: after the .exe call one integer argument should be passed.\n");
        return 1;
    }

    char *nptr;
    long n = strtol(argv[1], &nptr, 10);
    long long nthFibNumber = calculateNthFibonacci(n);

    printf("%lld\n", nthFibNumber);

    return 0;
}