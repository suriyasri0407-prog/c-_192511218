#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n;
    double discount;

public:
    Cart() : n(0), discount(0) {}

    Cart& add(const string& item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            ++n;
        }
        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double sum = 0;

        for (int i = 0; i < n; i++) {
            sum += prices[i];
        }

        return sum * (1.0 - discount / 100.0);
    }
};

int main() {
    Cart cart;

    cart.add("Book", 60)
        .add("Bag", 120)
        .add("Pen", 180)
        .setDiscount(10);

    cout << fixed << setprecision(2);
    cout << "Cart Total: " << cart.total() << endl;

    Cart cart1, cart2, cart3;
    cart1.add("Item1", 100);
    cart2.add("Item2", 250);
    cart3.add("Item3", 180);

    Cart* carts[3] = {&cart1, &cart2, &cart3};
    Cart* best = carts[0];

    for (int i = 1; i < 3; i++) {
        if (carts[i]->total() > best->total()) {
            best = carts[i];
        }
    }

    cout << "Highest Cart Total: " << best->total() << endl;

    return 0;
}
