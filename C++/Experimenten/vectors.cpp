#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> intVector = {1, 2, 3};
    int intArray[] = {1, 2, 3};

    // This can only be done with vectors and not arrays.
    cout << intVector.front() << " " << intVector[1] << " " << intVector.back() << endl;
    intVector.push_back(4);
    cout << intVector.front() << " " << intVector[1] << " " << intVector[2] << " " << intVector.back() << endl;
    intVector.pop_back();
    cout << intVector.front() << " " << intVector[1] << " " << intVector.back() << endl;
    intVector.push_back(5);
    cout << intVector.front() << " " << intVector[1] << " " << intVector[2] << " " << intVector.back() << endl;
    cout << intVector.empty() << endl; // false
    cout << intVector.size() << endl;
}