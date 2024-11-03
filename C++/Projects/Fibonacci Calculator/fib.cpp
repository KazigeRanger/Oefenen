#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>
using namespace std;

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

// largeInt largeIntAdd(largeInt int1, largeInt int2) {
    
// }

int main(int argc, char* argv[]) {
    // cout << "argc: " << argc << endl;
    // for (int i = 0; i < argc; i++) {
    //     cout << "argv[" << i << "]: " << argv[i] << endl;
    // }

    largeInt large;
    large.value = "65927679461576810473862977549509173951200069903945853";
    cout << "number of digits: " << large.value.length() << endl;

    vector<string> choppedLarge = chop(large.value);
    large.chops = choppedLarge;

    for (string chop : large.chops) {
        cout << "chop: " << chop << endl;
    }

    return 0;
}