#include <unordered_set>
#include <set>
#include <iostream>
using namespace std;

int main() {
    unordered_set<int> unordered({1, 6, 7, 3, 4, 9});
    set<int> ordered({1, 6, 7, 3, 4, 9});

    cout << "unordered set: ";
    for (int i : unordered) {
        cout << i << " ";
    }

    cout << endl << "ordered set: ";
    for (int i : ordered) {
        cout << i << " ";
    }

    unordered.insert(121);
    unordered.insert(2);
    ordered.insert(121);
    ordered.insert(2);

    cout << endl << endl << "unordered set: ";
    for (int i : unordered) {
        cout << i << " ";
    }

    cout << endl << "ordered set: ";
    for (int i : ordered) {
        cout << i << " ";
    }

    return 0;
}