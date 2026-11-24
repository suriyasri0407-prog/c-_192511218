#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

class InvalidCharge : public runtime_error {
public:
    using runtime_error::runtime_error;
};

class Bill {
protected:
    string patient;

public:
    Bill(string p) : patient(p) {}
    virtual double total() const = 0;
    virtual string type() const = 0;
    virtual ~Bill() = default;

    void print() const {
        cout << type() << " Bill for " << patient
             << ": " << total() << endl;
    }
};

class MaternityBill : public Bill {
    double package, extraTests;

public:
    MaternityBill(string p, double pkg, double tests)
        : Bill(p), package(pkg), extraTests(tests) {
        if (pkg < 0 || tests < 0)
            throw InvalidCharge("Negative maternity charge");
    }

    double total() const override {
        return package + extraTests;
    }

    string type() const override {
        return "Maternity";
    }
};

class Payer {
public:
    virtual double amountCovered(const Bill& b) const = 0;
    virtual ~Payer() = default;
};

class CorporateTieUp : public Payer {
    double discountPercent;

public:
    explicit CorporateTieUp(double d) : discountPercent(d) {
        if (d < 0 || d > 100)
            throw invalid_argument("Invalid discount");
    }

    double amountCovered(const Bill& b) const override {
        return b.total() * (1.0 - discountPercent / 100.0);
    }
};

int main() {
    try {
        vector<unique_ptr<Bill>> bills;
        bills.push_back(make_unique<MaternityBill>("Anu", 30000, 5000));

        CorporateTieUp corporate(10);

        for (const auto& b : bills) {
            b->print();
            cout << "Corporate Covered Amount: "
                 << corporate.amountCovered(*b) << endl;
        }
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
