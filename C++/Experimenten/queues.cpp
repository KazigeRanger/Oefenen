#include <queue>
#include <string>
#include <iostream>
using namespace std;

int main() {
    queue<string> line;

    line.push("Renger");
    line.push("Nog iemand");
    line.push("Barack Obama");

    cout << line.front();
    line.pop();
    cout << " " << line.front();
    cout << " " << line.back();

    cout << endl << line.front() << " " << line.back();
    line.pop();
    cout << endl << line.front();
}