
#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    double balance;
    double transactions[10];
    int count;
    int nextIndex;

    void addTransaction(double amount) {
        transactions[nextIndex] = amount;
        nextIndex = (nextIndex + 1) % 10;

        if (count < 10)
            count++;
    }

public:
    SavingsAccount(string number, double openingBalance) {
        accountNumber = number;
        balance = openingBalance;
        count = 0;
        nextIndex = 0;

        addTransaction(openingBalance);
    }

    void deposit(double amount);
    void withdraw(double amount);

    void miniStatement() {
        cout << "\nAccount: " << accountNumber << '\n';
        cout << "Balance: " << balance << '\n';

        cout << "Last transactions:\n";

        int start = (count == 10) ? nextIndex : 0;

        for (int i = 0; i < count; i++) {
            int index = (start + i) % 10;
            cout << transactions[index] << '\n';
        }
    }
};

void SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        addTransaction(amount);
    }
}

void SavingsAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        addTransaction(-amount);
    }
}

int main() {
    SavingsAccount account("SA1001", 1000);

    account.deposit(500);
    account.withdraw(200);
    account.deposit(300);
    account.withdraw(100);
    account.deposit(750);
    account.withdraw(50);
    account.deposit(250);
    account.withdraw(150);
    account.deposit(400);
    account.withdraw(100);
    account.deposit(600);

    account.miniStatement();

    return 0;
}
