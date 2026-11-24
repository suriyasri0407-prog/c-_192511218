#include <iostream>
using namespace std;

class Bill {
public:
    virtual double total() const {
        return 0;
    }

    void show() const {
        cout << "Bill Amount: " << total() << endl;
    }

    virtual ~Bill() {
        cout << "~Bill" << endl;
    }
};

class OPBill : public Bill {
public:
    double total() const override {
        return 500;
    }

    ~OPBill() {
        cout << "~OPBill" << endl;
    }
};

int main() {
    Bill* b = new OPBill();

    b->show();
    delete b;

    return 0;
}
