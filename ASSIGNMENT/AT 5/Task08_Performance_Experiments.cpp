#include <iostream>
#include <vector>
#include <chrono>
#include <stdexcept>
using namespace std;
using namespace chrono;

struct BillRecord {
    int type;
    double amount1;
    double amount2;
};

double virtualTotal(const BillRecord& b) {
    switch (b.type) {
        case 0: return b.amount1 + b.amount2;
        case 1: return b.amount1 * 3 + b.amount2;
        case 2: return b.amount1;
        default: return b.amount1 + b.amount2 * 2;
    }
}

double switchTotal(const BillRecord& b) {
    switch (b.type) {
        case 0: return b.amount1 + b.amount2;
        case 1: return b.amount1 * 3 + b.amount2;
        case 2: return b.amount1;
        default: return b.amount1 + b.amount2 * 2;
    }
}

int main() {
    vector<BillRecord> bills;

    for (int i = 0; i < 1000000; i++) {
        bills.push_back({i % 4, 100.0 + i % 100, 50.0});
    }

    double virtualSum = 0;
    auto start1 = steady_clock::now();

    for (const auto& b : bills)
        virtualSum += virtualTotal(b);

    auto end1 = steady_clock::now();

    double switchSum = 0;
    auto start2 = steady_clock::now();

    for (const auto& b : bills)
        switchSum += switchTotal(b);

    auto end2 = steady_clock::now();

    double virtualTime = duration<double>(end1 - start1).count();
    double switchTime = duration<double>(end2 - start2).count();

    cout << "Number of Bills: " << bills.size() << endl;
    cout << "Virtual-style calculation time: " << virtualTime << " seconds" << endl;
    cout << "Switch calculation time: " << switchTime << " seconds" << endl;
    cout << "Virtual Total: " << virtualSum << endl;
    cout << "Switch Total: " << switchSum << endl;
    cout << "Totals Equal: " << (virtualSum == switchSum ? "Yes" : "No") << endl;

    return 0;
}
