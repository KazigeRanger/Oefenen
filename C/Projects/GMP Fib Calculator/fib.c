#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>
#include <windows.h>

void calculateNthFib(int n) {
    mpz_t fib_prev, fib_curr;
    
    // Initialise fib_prev and fib_curr
    mpz_init(fib_prev);
    mpz_init(fib_curr);

    // Set fib_prev and fib_curr to the starting values
    mpz_set_str(fib_prev, "1", 10);
    mpz_set_str(fib_curr, "0", 10);

    // Do the Fibonacci calculation
    for (int i = 2; i < n; i++) {
        // gmp_printf("fib_prev: %Zd\n", fib_prev);
        // gmp_printf("fib_curr: %Zd\n", fib_curr);
        // printf("----------------------------\n");

        mpz_add(fib_curr, fib_prev, fib_curr);
        mpz_swap(fib_prev, fib_curr);
    }

    gmp_printf("The result is: %Zd\n", fib_prev);
    fflush(stdout);

    mpz_clear(fib_prev);
    mpz_clear(fib_curr);
}

int main(int argc, char *argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);  // Disable stdout buffering

    LARGE_INTEGER start, end;
    double time_taken;
    LARGE_INTEGER frequency;

    // Get the frequency of the high-resolution timer
    QueryPerformanceFrequency(&frequency);

    // Get the start time
    QueryPerformanceCounter(&start);

    // Print the number of arguments
    // printf("Number of arguments: %d\n", argc);

    // // Print each argument passed to the program
    // printf("Arguments passed to the program:\n");
    // for (int i = 0; i < argc; i++) {
    //     printf("argv[%d]: %s\n", i, argv[i]);
    // }

    int n = strtol(argv[1], NULL, 10);
    calculateNthFib(n);

    // Get the end time
    QueryPerformanceCounter(&end);

    // Calculate the time taken in seconds
    time_taken = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}