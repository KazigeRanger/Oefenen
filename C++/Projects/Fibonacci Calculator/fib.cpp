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
    vector<string> chops;
} largeInt;

vector<string> chop(string str) {
    int strLength = str.length();

    int chopSize = 16;
    int amountOfChopsNeeded = strLength/chopSize+1;
    cout << "amount of chops needed: " << amountOfChopsNeeded << endl;

    vector<string> chops;
    for (int i = 0; i < amountOfChopsNeeded; i++) {
        if (i < amountOfChopsNeeded-1) {
            chops.push_back(str.substr(chopSize*i, chopSize));
        } else if (i == amountOfChopsNeeded-1) {
            chops.push_back(str.substr(chopSize*i, strLength-(amountOfChopsNeeded-1)*chopSize));
        }
    }

    return chops;
}

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

int main(int argc, char* argv[]) {
    // cout << "argc: " << argc << endl;
    // for (int i = 0; i < argc; i++) {
    //     cout << "argv[" << i << "]: " << argv[i] << endl;
    // }

    largeInt large1;
    largeInt large2;
    large1.value = "65927679461576810473862977549509173951200069903945853";
    large2.value = "20983467809234789608927109872468097204689723984670937";

    largeInt addedResult;
    addedResult.value = largeIntAdd(large1, large2);
    cout << "Result: " << addedResult.value << endl;
    // cout << "number of digits: " << large1.value.length() << endl;

    // large1.chops = chop(large1.value);

    // for (string chop : large1.chops) {
    //     cout << "chop: " << chop << endl;
    // }

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout << "Runtime: " << duration.count() << " seconds" << endl;

    return 0;
}