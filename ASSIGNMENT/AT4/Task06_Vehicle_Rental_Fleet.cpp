#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string reg;
    double dailyRate;
    bool rented;

public:
    Vehicle(string r, double rate)
        : reg(r), dailyRate(rate), rented(false) {}

    virtual double charge(int days) const = 0;
    virtual string type() const = 0;

    bool rent() {
        if (rented)
            return false;

        rented = true;
        return true;
    }

    double returnVehicle(int lateDays, double fee) {
        rented = false;
        return lateDays > 0 ? lateDays * fee : 0.0;
    }

    virtual ~Vehicle() {}
};

class Bicycle : public Vehicle {
public:
    Bicycle(string r, double rate) : Vehicle(r, rate) {}

    double charge(int days) const override {
        return dailyRate * days;
    }

    string type() const override {
        return "Bicycle";
    }
};

class TwoWheeler : public Vehicle {
    double fuel;

public:
    TwoWheeler(string r, double rate, double f)
        : Vehicle(r, rate), fuel(f) {}

    double charge(int days) const override {
        return dailyRate * days + fuel;
    }

    string type() const override {
        return "TwoWheeler";
    }
};

class Car : public Vehicle {
    int seats;

public:
    Car(string r, double rate, int s)
        : Vehicle(r, rate), seats(s) {}

    double charge(int days) const override {
        return dailyRate * days;
    }

    string type() const override {
        return "Car";
    }
};

class ElectricCar : public Vehicle {
    double kwh, price;

public:
    ElectricCar(string r, double rate, double k, double p)
        : Vehicle(r, rate), kwh(k), price(p) {}

    double charge(int days) const override {
        return dailyRate * days + kwh * price;
    }

    string type() const override {
        return "ElectricCar";
    }
};

class ElectricBus : public Vehicle {
    double kwh, price;

public:
    ElectricBus(string r, double rate, double k, double p)
        : Vehicle(r, rate), kwh(k), price(p) {}

    double charge(int days) const override {
        return dailyRate * days + kwh * price;
    }

    string type() const override {
        return "ElectricBus";
    }
};

int main() {
    vector<unique_ptr<Vehicle>> fleet;

    fleet.push_back(make_unique<Bicycle>("B101", 100));
    fleet.push_back(make_unique<TwoWheeler>("T202", 300, 80));
    fleet.push_back(make_unique<Car>("C303", 1500, 5));
    fleet.push_back(make_unique<ElectricCar>("E404", 1800, 20, 8));
    fleet.push_back(make_unique<ElectricBus>("EB505", 5000, 80, 8));

    for (const auto& v : fleet) {
        cout << v->type() << " " << v->charge(2) << endl;
        cout << (v->rent() ? "Rented" : "Unavailable") << endl;
        cout << "Late Fee: " << v->returnVehicle(1, 100) << endl;
        cout << endl;
    }

    return 0;
}
