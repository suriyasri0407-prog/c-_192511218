#include <iostream>
#include <string>
using namespace std;

class SmartCard {
private:
    int balance;

public:
    SmartCard(int b) {
        balance = b;
    }

    bool canTravel(int fare) {
        return balance - fare >= 5000;
    }

    void deduct(int fare) {
        if (canTravel(fare)) {
            balance -= fare;
            cout << "Journey Approved\n";
        } else {
            cout << "Journey Denied\n";
        }
    }

    int getBalance() {
        return balance;
    }
};

class Passenger {
public:
    string name;

    Passenger(string n) {
        name = n;
    }
};

class Journey {
public:
    int zone;
    bool peak;

    Journey(int z, bool p) {
        zone = z;
        peak = p;
    }
};

int main() {
    Passenger p("Arun");
    SmartCard card(10000);
    Journey j(2, false);

    int fare = j.zone * 1000;

    if (j.peak)
        fare += fare * 20 / 100;

    cout << "Passenger: " << p.name << endl;

    card.deduct(fare);

    cout << "Balance: Rs " << card.getBalance() / 100.0 << endl;

    return 0;
}