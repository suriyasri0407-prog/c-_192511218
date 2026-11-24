#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual string type() const = 0;
    virtual ~Bill() {}
};

class OutPatientBill : public Bill {
    double amount;

public:
    OutPatientBill(double a) : amount(a) {}

    double total() const override {
        return amount;
    }

    string type() const override {
        return "OP";
    }
};

class Payer {
public:
    virtual double amountCovered(const Bill& bill) const = 0;
    virtual ~Payer() {}
};

class SelfPay : public Payer {
public:
    double amountCovered(const Bill& bill) const override {
        return bill.total();
    }
};

class Insurance : public Payer {
    double coverLimit;
    double coPayPercent;

public:
    Insurance(double limit, double percent)
        : coverLimit(limit), coPayPercent(percent) {}

    double amountCovered(const Bill& bill) const override {
        double eligible = min(bill.total(), coverLimit);
        return eligible * (1.0 - coPayPercent / 100.0);
    }
};

class GovernmentScheme : public Payer {
    double packageRate;

public:
    GovernmentScheme(double rate) : packageRate(rate) {}

    double amountCovered(const Bill& bill) const override {
        return min(bill.total(), packageRate);
    }
};

class CorporateTieUp : public Payer {
    double discountPercent;

public:
    CorporateTieUp(double discount) : discountPercent(discount) {}

    double amountCovered(const Bill& bill) const override {
        return bill.total() * (1.0 - discountPercent / 100.0);
    }
};

int main() {
    OutPatientBill bill(1700);

    SelfPay self;
    Insurance insurance(50000, 10);
    GovernmentScheme government(1500);
    CorporateTieUp corporate(5);

    cout << "Bill Amount: " << bill.total() << endl;
    cout << "Self Pay: " << self.amountCovered(bill) << endl;
    cout << "Insurance: " << insurance.amountCovered(bill) << endl;
    cout << "Government Scheme: " << government.amountCovered(bill) << endl;
    cout << "Corporate Tie-Up: " << corporate.amountCovered(bill) << endl;

    return 0;
}
