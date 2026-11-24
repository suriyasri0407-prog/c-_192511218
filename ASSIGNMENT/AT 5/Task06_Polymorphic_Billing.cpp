#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <algorithm>
using namespace std;

class BillingError : public runtime_error {
public:
    using runtime_error::runtime_error;
};

class InvalidCharge : public BillingError {
public:
    using BillingError::BillingError;
};

class Bill {
protected:
    string patient;

public:
    explicit Bill(const string& p) : patient(p) {}
    virtual ~Bill() = default;
    virtual double total() const = 0;
    virtual string type() const = 0;

    void print() const {
        cout << type() << " " << patient << ": " << total() << endl;
    }
};

class OutPatientBill : public Bill {
    double consultation, tests;

public:
    OutPatientBill(const string& p, double c, double t)
        : Bill(p), consultation(c), tests(t) {
        if (c < 0 || t < 0)
            throw InvalidCharge("Negative charge");
    }

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OP";
    }
};

class InPatientBill : public Bill {
    int days;
    double perDay, procedure, medicines;

public:
    InPatientBill(const string& p, int d, double rate,
                  double proc, double med)
        : Bill(p), days(d), perDay(rate), procedure(proc), medicines(med) {
        if (d < 0 || rate < 0 || proc < 0 || med < 0)
            throw InvalidCharge("Negative inpatient charge");
    }

    double total() const override {
        return days * perDay + procedure + medicines;
    }

    string type() const override {
        return "IP";
    }
};

class DayCareBill : public Bill {
    double packagePrice;

public:
    DayCareBill(const string& p, double price)
        : Bill(p), packagePrice(price) {
        if (price < 0)
            throw InvalidCharge("Negative package price");
    }

    double total() const override {
        return packagePrice;
    }

    string type() const override {
        return "DayCare";
    }
};

class EmergencyBill : public Bill {
    double baseCharge, hourlyCharge;
    int hours;

public:
    EmergencyBill(const string& p, double base, double rate, int h)
        : Bill(p), baseCharge(base), hourlyCharge(rate), hours(h) {
        if (base < 0 || rate < 0 || h < 0)
            throw InvalidCharge("Negative emergency charge");
    }

    double total() const override {
        return baseCharge + hourlyCharge * hours;
    }

    string type() const override {
        return "Emergency";
    }
};

class Payer {
public:
    virtual ~Payer() = default;
    virtual double amountCovered(const Bill& b) const = 0;
};

class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        return b.total();
    }
};

class Insurance : public Payer {
    double limit, copay;

public:
    Insurance(double l, double c) : limit(l), copay(c) {
        if (l < 0 || c < 0 || c > 100)
            throw invalid_argument("Invalid insurance policy");
    }

    double amountCovered(const Bill& b) const override {
        return min(b.total(), limit) * (1.0 - copay / 100.0);
    }
};

class GovernmentScheme : public Payer {
    map<string, double> rates;

public:
    explicit GovernmentScheme(map<string, double> r) : rates(move(r)) {}

    double amountCovered(const Bill& b) const override {
        auto it = rates.find(b.type());
        if (it == rates.end())
            throw BillingError("Unknown package");
        return it->second;
    }
};

int main() {
    try {
        vector<unique_ptr<Bill>> bills;

        bills.push_back(make_unique<OutPatientBill>("Ravi", 500, 1200));
        bills.push_back(make_unique<InPatientBill>("Meena", 3, 2500, 40000, 0));
        bills.push_back(make_unique<DayCareBill>("Arun", 18000));
        bills.push_back(make_unique<EmergencyBill>("Divya", 2000, 500, 3));

        SelfPay self;
        Insurance insurance(50000, 10);
        GovernmentScheme govt({
            {"OP", 1500}, {"IP", 45000},
            {"DayCare", 16000}, {"Emergency", 3000}
        });

        double grandTotal = 0;

        for (const auto& b : bills) {
            b->print();
            grandTotal += b->total();

            cout << "Self: " << self.amountCovered(*b)
                 << ", Insurance: " << insurance.amountCovered(*b)
                 << ", Scheme: " << govt.amountCovered(*b) << endl;
        }

        cout << "Grand Total: " << grandTotal << endl;
    }
    catch (const exception& e) {
        cout << "Billing Error: " << e.what() << endl;
    }
    catch (...) {
        cout << "Unknown Error" << endl;
    }

    return 0;
}
