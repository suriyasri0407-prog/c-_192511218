#include <iostream>
#include <iomanip>
using namespace std;

class Money {
private:
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    // Addition operator
    Money operator+(const Money& other) const {
        Money result;
        result.paise = paise + other.paise;
        return result;
    }

    // Subtraction operator
    Money operator-(const Money& other) const {
        Money result;
        result.paise = paise - other.paise;
        return result;
    }

    // Addition assignment
    Money& operator+=(const Money& other) {
        paise += other.paise;
        return *this;
    }

    // Equality operator
    bool operator==(const Money& other) const {
        return paise == other.paise;
    }

    // Less than operator
    bool operator<(const Money& other) const {
        return paise < other.paise;
    }

    // Output operator
    friend ostream& operator<<(ostream& out, const Money& m) {
        long long amount = m.paise;

        if (amount < 0) {
            out << "-Rs " << -amount / 100 << "."
                << setw(2) << setfill('0') << -amount % 100;
        } else {
            out << "Rs " << amount / 100 << "."
                << setw(2) << setfill('0') << amount % 100;
        }

        out << setfill(' ');
        return out;
    }

    // Input operator
    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;
        in >> rupees >> p;

        if (in)
            m.paise = rupees * 100 + p;

        return in;
    }
};

int main() {
    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << c << '\n';
    cout << boolalpha << (c == Money(200)) << '\n';

    Money x(0, 75);
    Money y(0, 50);

    cout << "Paise addition: " << x + y << '\n';

    cout << "Subtraction: " << x - y << '\n';

    a += b;
    cout << "After += : " << a << '\n';

    return 0;
}