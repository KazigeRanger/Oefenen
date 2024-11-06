#include <iostream>
#include <vector>
#include <chrono>
#include "largeIntAddition.hpp"
using namespace std;

largeInt calculateNthFib(int n) {
    // Define the first and second Fibonacci numbers to initiate the sequence
    largeInt firstFib;
    largeInt secondFib;

    firstFib.value = "0";
    secondFib.value = "1";

    vector<largeInt> fibSequence;
    fibSequence.push_back(firstFib);
    fibSequence.push_back(secondFib);
    for (int i = 2; i < n; i++) {
        largeInt fibTerm;
        fibTerm = addLarge(fibSequence[i-2], fibSequence[i-1]);
        fibSequence.push_back(fibTerm);
    }

    largeInt additionResult = fibSequence[n-1];

    return additionResult;
}

int main(int argc, char* argv[]) {
    auto start1 = chrono::high_resolution_clock::now();

    int n;
    if (argc != 2) {
        cout << "Error: one int argument should be passed.";
        return 1;
    } 
    try {
        // Convert the argument (string) to an integer
        n = std::stoi(argv[1]);
        // cout << "You entered the number: " << n << endl;
    } catch (const std::invalid_argument&) {
        cout << "Error: Invalid input. Please enter a valid integer." << endl;
        return 1;
    } catch (const std::out_of_range&) {
        cout << "Error: The number is out of range." << endl;
        return 1;
    }

    largeInt nthFib = calculateNthFib(n);

    cout << n << "th fib: " << nthFib.value << endl;

    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration1 = end1 - start1;
    cout << "Runtime: " << duration1.count() << " seconds" << endl;

    return 0;
}