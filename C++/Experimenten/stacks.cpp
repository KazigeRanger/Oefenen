#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main() {
    stack<string> message;

    message.push("Hello");
    message.push("World");
    message.push("!");

    cout << message.top();
    message.pop();
    cout << message.top();
    message.pop();
    cout << message.top();

    return 0;
}