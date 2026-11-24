#include <iostream>
using namespace std;

enum class Zone {
    Inner,
    Middle,
    Outer
};

class FareTable {
public:
    long long getFare(Zone zone) {
        switch (zone) {
            case Zone::Inner:
                return 1000;

            case Zone::Middle:
                return 2000;

            case Zone::Outer:
                return 3000;
        }

        return 0;
    }
};

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) {
        balance = b;
    }

    bool deduct(long long fare) {
        if (fare < 0 || balance - fare < 5000) {
            return false;
        }

        balance -= fare;
        return true;
    }

    long long getBalance() {
        return balance;
    }
};

int main() {
    FareTable table;

    SmartCard card(10000);

    long long fare = table.getFare(Zone::Middle);

    cout << "Base Fare: " << fare << " paise\n";

    if (card.deduct(fare)) {
        cout << "Journey Approved\n";
    } else {
        cout << "Journey Denied\n";
    }

    cout << "Remaining Balance: "
         << card.getBalance() << " paise\n";

    return 0;
}