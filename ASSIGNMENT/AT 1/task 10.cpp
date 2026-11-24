#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main() {
    long long journeys[] = {
        20000,
        500000,
        3000000
    };

    long long fare = 3000;

    cout << "Metro Fare Calculation\n";

    for (int i = 0; i < 3; i++) {
        long long totalPaise = journeys[i] * fare;

        double totalRupees = journeys[i] * 30.0;

        cout << "\nJourneys: " << journeys[i] << endl;

        cout << "Integer Paise Total: "
             << totalPaise << endl;

        cout << fixed << setprecision(2);

        cout << "Double Rupees Total: Rs "
             << totalRupees << endl;
    }

    cout << "\nMaximum Integer Value: "
         << INT_MAX << endl;

    cout << "Network Total: "
         << 3000000LL * fare << " paise" << endl;

    cout << "Long long is suitable for large totals.\n";

    return 0;
}