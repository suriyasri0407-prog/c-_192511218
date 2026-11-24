#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr int INNER_FARE = 1000;
constexpr int MIDDLE_FARE = 2000;
constexpr int OUTER_FARE = 3000;

constexpr int PEAK_SURCHARGE = 20;
constexpr int MIN_BALANCE = 5000;

int main() {
    Zone zone = Zone::Outer;
    int fare = 0;

    switch (zone) {
        case Zone::Inner:
            fare = INNER_FARE;
            break;

        case Zone::Middle:
            fare = MIDDLE_FARE;
            break;

        case Zone::Outer:
            fare = OUTER_FARE;
            break;
    }

    cout << "Base Fare: " << fare << " paise" << endl;

    int peakFare = fare + (fare * PEAK_SURCHARGE / 100);

    cout << "Peak Fare: " << peakFare << " paise" << endl;
    cout << "Minimum Balance: " << MIN_BALANCE << " paise" << endl;

    return 0;
}