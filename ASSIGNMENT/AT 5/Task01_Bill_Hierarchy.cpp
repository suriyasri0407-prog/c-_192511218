#include <iostream>
#include <string>
using namespace std;

class Bill {
protected:
    string patient;
    int billNo;
    string date;

public:
    Bill(string p, int no, string d)
        : patient(p), billNo(no), date(d) {}

    virtual double total() const = 0;
    virtual string type() const = 0;

    virtual void print() const {
        cout << "Bill Type: " << type()
             << "\nPatient: " << patient
             << "\nBill Number: " << billNo
             << "\nDate: " << date
             << "\nTotal: " << total() << "\n\n";
    }

    virtual ~Bill() {}
};

class OutPatientBill : public Bill {
    double consultation, tests;

public:
    OutPatientBill(string p, int no, string d, double c, double t)
        : Bill(p, no, d), consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "Out Patient";
    }
};

class InPatientBill : public Bill {
    int days;
    double perDay, procedure, medicines;

public:
    InPatientBill(string p, int no, string d, int days,
                  double rate, double proc, double med)
        : Bill(p, no, d), days(days), perDay(rate),
          procedure(proc), medicines(med) {}

    double total() const override {
        return days * perDay + procedure + medicines;
    }

    string type() const override {
        return "In Patient";
    }
};

class DayCareBill : public Bill {
    double packagePrice;

public:
    DayCareBill(string p, int no, string d, double price)
        : Bill(p, no, d), packagePrice(price) {}

    double total() const override {
        return packagePrice;
    }

    string type() const override {
        return "Day Care";
    }
};

class EmergencyBill : public Bill {
    double baseCharge, hourlyCharge;
    int hours;

public:
    EmergencyBill(string p, int no, string d, double base,
                  double rate, int h)
        : Bill(p, no, d), baseCharge(base),
          hourlyCharge(rate), hours(h) {}

    double total() const override {
        return baseCharge + hourlyCharge * hours;
    }

    string type() const override {
        return "Emergency";
    }
};

int main() {
    OutPatientBill b1("Ravi", 101, "21-11-2026", 500, 1200);
    InPatientBill b2("Meena", 102, "21-11-2026", 3, 2500, 40000, 0);
    DayCareBill b3("Arun", 103, "21-11-2026", 18000);
    EmergencyBill b4("Divya", 104, "21-11-2026", 2000, 500, 3);

    Bill* bills[] = {&b1, &b2, &b3, &b4};
    double grandTotal = 0;

    for (int i = 0; i < 4; i++) {
        bills[i]->print();
        grandTotal += bills[i]->total();
    }

    cout << "Grand Total: " << grandTotal << endl;
    return 0;
}
