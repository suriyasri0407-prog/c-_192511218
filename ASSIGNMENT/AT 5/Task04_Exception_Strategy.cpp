#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class BillingError : public runtime_error {
public:
    BillingError(string message) : runtime_error(message) {}
};

class InvalidCharge : public BillingError {
public:
    InvalidCharge(string message) : BillingError(message) {}
};

class ClaimError : public BillingError {
public:
    ClaimError(string message) : BillingError(message) {}
};

class UnknownPackage : public BillingError {
public:
    UnknownPackage(string message) : BillingError(message) {}
};

class MissingPatientRecord : public BillingError {
public:
    MissingPatientRecord(string message) : BillingError(message) {}
};

double calculateBill(double charge) {
    if (charge < 0) {
        throw InvalidCharge("Negative charge");
    }
    return charge;
}

double approveClaim(double bill, double cover) {
    if (bill < 0 || cover < 0) {
        throw InvalidCharge("Invalid amount");
    }

    if (bill > cover) {
        throw ClaimError("Claim exceeds cover");
    }

    return bill;
}

int main() {
    try {
        cout << "Bill Amount: " << calculateBill(1500) << endl;
        cout << "Approved Amount: " << approveClaim(40000, 50000) << endl;

        calculateBill(-500);
    }
    catch (const InvalidCharge& e) {
        cout << "Invalid Charge: " << e.what() << endl;
    }
    catch (const ClaimError& e) {
        cout << "Claim Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
