#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    int hour;

    cout << "Enter journey hour (0-23): ";

    while (!(cin >> hour) || hour < 0 || hour > 23) {
        cout << "Invalid input. Enter again: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long balance = 10000;
    long long fare = 2000;

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak) {
        fare += fare * 20 / 100;
    }

    if (balance - fare >= 5000) {
        balance -= fare;

        cout << fixed << setprecision(2);

        cout << "Fare: Rs " << fare / 100.0 << endl;
        cout << "Remaining Balance: Rs "
             << balance / 100.0 << endl;
    } else {
        cout << "Journey Denied\n";
    }

    return 0;
}