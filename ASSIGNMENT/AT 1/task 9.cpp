#include <iostream>
using namespace std;

enum class Zone {
    Inner = 1,
    Middle = 2,
    Outer = 3
};

long long calculateFare(Zone zone, int hour) {
    long long fare = 0;

    switch (zone) {
        case Zone::Inner:
            fare = 1000;
            break;

        case Zone::Middle:
            fare = 2000;
            break;

        case Zone::Outer:
            fare = 3000;
            break;

        default:
            return -1;
    }

    if ((hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20)) {
        fare += fare * 20 / 100;
    }

    return fare;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= 5000;
}

int main() {
    int zone, hour;
    long long balance = 10000;

    cout << "Enter Zone (1-Inner, 2-Middle, 3-Outer): ";
    cin >> zone;

    cout << "Enter Hour: ";
    cin >> hour;

    if (zone < 1 || zone > 3 || hour < 0 || hour > 23) {
        cout << "Invalid Input\n";
        return 0;
    }

    long long fare = calculateFare(
        static_cast<Zone>(zone), hour
    );

    cout << "Fare: " << fare << " paise\n";

    if (canTravel(balance, fare)) {
        balance -= fare;

        cout << "Journey Approved\n";
        cout << "Remaining Balance: "
             << balance << " paise\n";
    } else {
        cout << "Journey Denied\n";
    }

    return 0;
}