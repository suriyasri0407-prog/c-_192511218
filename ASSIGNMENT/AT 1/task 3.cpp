#include <iostream>
#include <climits>
using namespace std;

int main() {
    bool peak = true;
    char zone = 'O';
    int fare = 3000;
    long long balance = 1000000;
    float value = 25.5f;
    double rupees = 30.50;
    unsigned int hour = 9;
    long long journeys = 3000000;

    cout << "Size of bool: " << sizeof(peak) << endl;
    cout << "Size of char: " << sizeof(zone) << endl;
    cout << "Size of int: " << sizeof(fare) << endl;
    cout << "Size of long long: " << sizeof(balance) << endl;
    cout << "Size of float: " << sizeof(value) << endl;
    cout << "Size of double: " << sizeof(rupees) << endl;
    cout << "Size of unsigned int: " << sizeof(hour) << endl;

    cout << "INT MAX: " << INT_MAX << endl;

    cout << "Total Fare: "
         << journeys * fare << " paise" << endl;

    return 0;
}