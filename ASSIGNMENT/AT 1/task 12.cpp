#include <iostream>
using namespace std;

enum class Zone {
    Inner,
    Middle,
    Outer,
    Airport
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

            case Zone::Airport:
                return 6000;
        }

        return 0;
    }
};

class MonthlyPass {
private:
    Zone zone1, zone2;
    bool active;

public:
    MonthlyPass(Zone z1, Zone z2) {
        zone1 = z1;
        zone2 = z2;
        active = true;
    }

    bool covers(Zone zone) {
        return active &&
               (zone == zone1 || zone == zone2);
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

long long calculateFare(
    Zone zone,
    bool peak,
    bool weekend,
    FareTable &table,
    MonthlyPass &pass
) {
    if (pass.covers(zone)) {
        return 0;
    }

    long long fare = table.getFare(zone);

    if (weekend) {
        fare = fare * 90 / 100;
    }
    else if (peak) {
        fare = fare * 120 / 100;
    }

    return fare;
}

int main() {
    FareTable table;

    MonthlyPass pass(
        Zone::Inner,
        Zone::Middle
    );

    SmartCard card(20000);

    Zone journeys[] = {
        Zone::Inner,
        Zone::Outer,
        Zone::Airport
    };

    bool peak[] = {false, true, false};
    bool weekend[] = {false, false, true};

    for (int i = 0; i < 3; i++) {

        long long fare = calculateFare(
            journeys[i],
            peak[i],
            weekend[i],
            table,
            pass
        );

        cout << "Journey " << i + 1 << endl;

        cout << "Fare: Rs "
             << fare / 100.0 << endl;

        if (fare == 0) {
            cout << "Monthly Pass Applied\n";
        }
        else if (card.deduct(fare)) {
            cout << "Journey Approved\n";
        }
        else {
            cout << "Journey Denied\n";
        }

        cout << "Balance: Rs "
             << card.getBalance() / 100.0 << endl;

        cout << "------------------\n";
    }

    return 0;
}