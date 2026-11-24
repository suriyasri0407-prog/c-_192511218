#include <iostream>
using namespace std;

// Procedural approach
bool canTravel(long long balance, long long fare) {
    return balance - fare >= 5000;
}

void deductFare(long long &balance, long long fare) {
    if (canTravel(balance, fare)) {
        balance -= fare;
        cout << "Procedural: Journey Approved\n";
    } else {
        cout << "Procedural: Journey Denied\n";
    }
}

// Object-Oriented approach
class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) {
        balance = b;
    }

    bool canTravel(long long fare) {
        return balance - fare >= 5000;
    }

    void deduct(long long fare) {
        if (canTravel(fare)) {
            balance -= fare;
            cout << "OOP: Journey Approved\n";
        } else {
            cout << "OOP: Journey Denied\n";
        }
    }

    long long getBalance() {
        return balance;
    }
};

int main() {
    long long balance = 10000;

    deductFare(balance, 3000);
    cout << "Procedural Balance: " << balance << endl;

    SmartCard card(10000);

    card.deduct(3000);
    cout << "OOP Balance: " << card.getBalance() << endl;

    return 0;
}