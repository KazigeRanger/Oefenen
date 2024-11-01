#include <iostream>
#include <string>
using namespace std;

int main() {
    string naam;
    cout << "Wat is je naam?\n";
    cin >> naam;
    cin.ignore();
    cout << "Je naam is: " << naam << endl;

    cout << naam << ", wat denk je dat het allemaal betekent? Het leven?\n";
    string betekenis_antwoord;
    getline(cin, betekenis_antwoord);
    cout << "Betekenis antwoord: " << betekenis_antwoord;

    return 0;
}