
#include <iostream>
using namespace std;

struct Parcel {
    double weight;
    bool express;
    bool insured;
};

double charge(double weight, bool express = false,
              bool insured = false) {
    double amount = weight * 50;

    if (express)
        amount += 30;

    if (insured)
        amount += 20;

    return amount;
}

double charge(int grams) {
    return (grams / 1000.0) * 50;
}

double charge(const Parcel& p) {
    return charge(p.weight, p.express, p.insured);
}

int main() {
    cout << charge(2) << '\n';
    cout << charge(2.0f) << '\n';
    cout << charge(2.0) << '\n';
    cout << charge(2.0, true) << '\n';
    cout << charge(2.0, false, true) << '\n';

    Parcel p = {2.0, true, true};
    cout << charge(p) << '\n';

    return 0;
}
