#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <chrono>
#include "largeInt.hpp"
using namespace std;

// auto start = chrono::high_resolution_clock::now();

largeInt addLarge(largeInt firstLarge, largeInt secondLarge) {
    // Store the lengths of the values of the integers to add
    int firstLength = firstLarge.value.length();
    int secondLength = secondLarge.value.length();

    // Add the necessary amount of zeroes to the .value strings of the 
    // largeInts to add.
    largeInt& biggestInt = (max(firstLength, secondLength) == firstLength) ? firstLarge : secondLarge;
    largeInt& smallestInt = (min(firstLength, secondLength) == secondLength) ? secondLarge : firstLarge;

    biggestInt.value.insert(0, 1, '0');
    smallestInt.value.insert(0, biggestInt.value.length()-smallestInt.value.length(), '0');

    reverse(biggestInt.value.begin(), biggestInt.value.end());
    reverse(smallestInt.value.begin(), smallestInt.value.end());

    // Define a stack to store the result of each individual addition
    stack<char> resultStack;

    // Define the amount of iterations needed to do the addition
    int iterationCount = firstLarge.value.length();

    // Loop over the integer values to do the addition
    int carriedTerm = 0;
    for (int i = 0; i < iterationCount; i++) {
        int term = (firstLarge.value[i]-'0') + (secondLarge.value[i]-'0') + carriedTerm;
        if (term >= 10) {
            term -= 10;
            carriedTerm = 1;
            resultStack.push(term+'0');
        } else if (term < 10) {
            resultStack.push(term+'0');
            carriedTerm = 0;
        }
    }

    // Define a largeInt to store the result value of the addition
    largeInt result;

    // Loop over the resultStack to construct the value of the result
    int resultIterationCount = resultStack.size();
    for (int i = 0; i < resultIterationCount; i++) {
        result.value += resultStack.top();
        resultStack.pop();
    }

    if (result.value[0] == '0') {
        result.value = result.value.substr(1, result.value.length()-1);
        return result;
    } else {
        return result;
    }
}

// int main() {
//     // Keep track of the runtime of the program
//     auto start1 = chrono::high_resolution_clock::now();

//     // Code to run
//     largeInt firstInteger;
//     largeInt secondInteger;

//     firstInteger.value = "398746029837692803790823746098723480967230498729384760";
//     secondInteger.value = "293084758092734680927340986709238467028947092834760987";

//     largeInt additionResult = addLarge(firstInteger, secondInteger);
//     cout << "Addition result: " << additionResult.value << endl;

//     // Keep track of the runtime of the program
//     auto end1 = chrono::high_resolution_clock::now();
//     chrono::duration<double> duration1 = end1 - start1;
//     cout << "Runtime: " << duration1.count() << " seconds" << endl;

//     return 0;
// }