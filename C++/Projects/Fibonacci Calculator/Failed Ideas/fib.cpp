#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <chrono>
using namespace std;

auto start = chrono::high_resolution_clock::now();
typedef struct largeInt {
    string value;
} largeInt;

// string largeIntAdd(largeInt int1, largeInt int2) {
//     stack<int> int1Stack;
//     stack<int> int2Stack;
//     for (char charDigit : int1.value) {
//         int intDigit = charDigit - '0';
//         int1Stack.push(intDigit);
//     }
//     for (char charDigit : int2.value) {
//         int intDigit = charDigit - '0';
//         int2Stack.push(intDigit);
//     }

//     int carriedTerm = 0;
//     int iterationCount = min(int1Stack.size(), int2Stack.size());
//     stack<int> resultStack;
//     for (int i = 0; i < iterationCount; i++) {
//         // if (i == iterationCount-1) {
//         //     resultStack.push(((max(int1Stack.size(), int2Stack.size()) == int1Stack.size() ? int1 : int2).value[max(int1Stack.size(), int2Stack.size())-min(int1Stack.size(), int2Stack.size())]-'0')+carriedTerm);
//         // } else {
//             int term = int1Stack.top() + int2Stack.top();
//             int totalTerm = term + carriedTerm;
//             if (totalTerm >= 10) {
//                 totalTerm = totalTerm - 10;
//                 carriedTerm = 1;
//                 resultStack.push(totalTerm);
//                 int1Stack.pop();
//                 int2Stack.pop();
//             } else {
//                 carriedTerm = 0;
//                 resultStack.push(totalTerm);
//                 int1Stack.pop();
//                 int2Stack.pop();
//             }
//         // }
//     }
//     largeInt result;

//     // result.value += (max(int1Stack.size(), int2Stack.size())==int1Stack.size()) ? int1.value.substr(0, int1Stack.size()-int2Stack.size()) : int2.value.substr(0, int2Stack.size()-int1Stack.size());

//     // if ((int1.value[0]-'0')+(int2.value[0]-'0') >= 10) {
//     //     result.value += 1+'0';
//     // }
//     int resultIterationCount = resultStack.size();
//     for (int i = 0; i < resultIterationCount; i++) {
//         result.value += resultStack.top()+'0';
//         resultStack.pop();
//     }

//     return result.value;
// }

string largeIntAdd(largeInt int1, largeInt int2) {
    stack<int> int1Stack;
    stack<int> int2Stack;
    for (char charDigit : int1.value) {
        int intDigit = charDigit - '0';
        int1Stack.push(intDigit);
    }
    for (char charDigit : int2.value) {
        int intDigit = charDigit - '0';
        int2Stack.push(intDigit);
    }
    cout << "int1Stack.size(): " << int1Stack.size() << endl;
    cout << "int2Stack.size(): " << int2Stack.size() << endl;
    int carriedTerm = 0;
    int iterationCount = max(int1Stack.size(), int2Stack.size());
    stack<int> resultStack;
    for (int i = 0; i < iterationCount; i++) {
        // cout << "carriedTerm[" << i << "]: " << carriedTerm << endl;
        int term = int1Stack.top() + int2Stack.top();
        // cout << "term[" << i << "]: " << term << endl;
        int totalTerm = term + carriedTerm;
        if (totalTerm >= 10) {
            totalTerm = totalTerm - 10;
            // cout << "totalTerm[" << i << "]: " << totalTerm << endl;
            carriedTerm = 1;
            // cout << "carriedTerm[" << i << "]: " << carriedTerm << endl;
            resultStack.push(totalTerm);
            int1Stack.pop();
            int2Stack.pop();
            // cout << totalTerm;
        } else {
            carriedTerm = 0;
            // cout << "totalTerm[" << i << "]: " << totalTerm << endl;
            // cout << "carriedTerm[" << i << "]: " << carriedTerm << endl;
            resultStack.push(totalTerm);
            int1Stack.pop();
            int2Stack.pop();
            // cout << totalTerm;
        }
    }
    largeInt result;
    // cout << "int1.value[0] = " << int1.value[0] << endl;
    // cout << "int2.value[0] = " << int2.value[0] << endl;
    // cout << "int1.value[0]+int2.value[0] = " << (int1.value[0]-'0')+(int2.value[0]-'0') << endl;
    if ((int1.value[0]-'0')+(int2.value[0]-'0') >= 10) {
        result.value += 1+'0';
    }
    cout << "resultStack.size(): " << resultStack.size() << endl;
    int resultIterationCount = resultStack.size();
    for (int i = 0; i < resultIterationCount; i++) {
        result.value += resultStack.top()+'0';
        // cout << "resultStack.top(): " << resultStack.top() << "\t" << i << endl;
        resultStack.pop();
    }
    return result.value;
}

string calculateLargeNthFib(int n) {
    largeInt firstFib;
    largeInt secondFib;
    firstFib.value = "0";
    secondFib.value = "1";
    vector<largeInt> fibSequence;
    fibSequence.push_back(firstFib);
    fibSequence.push_back(secondFib);
    largeInt currentFib;
    for (int i = 2; i < n; i++) {
        currentFib.value = largeIntAdd(fibSequence[i-2], fibSequence[i-1]);
        fibSequence.push_back(currentFib);
        cout << currentFib.value << endl;
    }

    return fibSequence[n-1].value;
}

int main(int argc, char* argv[]) {
    // cout << "argc: " << argc << endl;
    // for (int i = 0; i < argc; i++) {
    //     cout << "argv[" << i << "]: " << argv[i] << endl;
    // }

    largeInt large1;
    largeInt large2;
    large1.value = "659276794615768104738620023097697737986690963290734028799098669829349870476879236977549509173951200069903945853";
    large2.value = "409834678092347896089271098722364798087329683749823890743498502594807628097408920789746468096548739746389476937";

    largeInt addedResult;
    addedResult.value = largeIntAdd(large1, large2);
    cout << "Result: " << addedResult.value << endl;
    cout << "number of digits: " << large1.value.length() << endl;

    string test = "1069111472708116000827891121820062536074020647040557919542597172424157498574288157767295977270499939816293422790";
    if (test == addedResult.value) {
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }

    // largeInt nthFib;
    // int n = 10;
    // nthFib.value = calculateLargeNthFib(n);
    // cout << n << "th fib: " << nthFib.value << endl;

    // auto end = chrono::high_resolution_clock::now();

    // chrono::duration<double> duration = end - start;
    // cout << "Runtime: " << duration.count() << " seconds" << endl;

    return 0;
}