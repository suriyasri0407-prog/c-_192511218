#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual double vrate() const {
        return 3.5;
    }

    virtual ~Account() {
        cout << "Account destroyed" << endl;
    }
};

class SeniorAccount : public Account {
    vector<double> history;

public:
    SeniorAccount() : history(100) {}

    double rate() const override {
        return 4.0;
    }

    double vrate() const override {
        return 4.0;
    }

    ~SeniorAccount() override {
        cout << "SeniorAccount destroyed" << endl;
    }
};

int main() {
    vector<unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Account>());
    accounts.push_back(make_unique<SeniorAccount>());

    for (const auto& account : accounts) {
        cout << "Rate: " << account->rate() << endl;
    }

    SeniorAccount senior;
    Account* p = &senior;

    cout << "Virtual Rate: " << p->vrate() << endl;

    Account copy = senior;
    cout << "Copied Account Rate: " << copy.rate() << endl;

    return 0;
}
