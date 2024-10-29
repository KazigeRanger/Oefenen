#include <iostream>
#include <string>
using namespace std;

int main(float balance = 0) {
    cout << "Your current balance is: $" << balance << endl;
    cout << "To exit the piggybank session type 'exit'" << endl;
    if (balance == 0) {
        cout << "To make a deposit type 'deposit'" << endl;
    } else {
        cout << "To make a withdrawal type 'withdraw', to make a deposit type 'deposit'." << endl;
    }
    string action;
    cin >> action;
    if (action == "deposit") {
        cout << "What is the amount that you want to deposit?\n$";
        float deposit;
        cin >> deposit;
        balance += deposit;
        cout << "Thank you for your deposit. Your current balance is: $" << balance << endl;
        main(balance);
    } else if (action == "withdraw") {
        cout << "What is the amount that you want to withdraw?\n$";
        float withdrawal;
        cin >> withdrawal;
        if (withdrawal > balance) {
            cout << "Error: Invalid withdrawal.\nThe withdrawal amount should be less than your balance." << endl;
            main(balance);
        } else {
            balance -= withdrawal;
            cout << "Your withdrawal is succesful. Your current balance is: $" << balance << endl;
            main(balance);
        }
    } else if (action == "exit") {
        return 0;
    } else {
        cout << "Error: Invalid argument." << endl;
        main(balance);
    }
}