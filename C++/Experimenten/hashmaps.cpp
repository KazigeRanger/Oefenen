#include <unordered_map>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    unordered_map<string, int> unordered_leeftijden({{"Renger", 16}, {"Marijn", 14}});
    map<int, string> leeftijden({{16, "Renger"}, {14, "Marijn"}});

    cout << "unordered leeftijden" << endl;
    for (pair it : unordered_leeftijden) {
        cout << it.first << " " << it.second << endl;
    }

    cout << endl << "ordered leeftijden" << endl;
    for (pair it : leeftijden) {
        cout << it.second << " " << it.first << endl;
    }

    unordered_leeftijden.insert({"Sjakie", 18});
    leeftijden.insert({18, "Sjakie"});

    cout << endl << "unordered leeftijden" << endl;
    for (pair it : unordered_leeftijden) {
        cout << it.first << " " << it.second << endl;
    }

    cout << endl << "ordered leeftijden" << endl;
    for (pair it : leeftijden) {
        cout << it.second << " " << it.first << endl;
    }
}