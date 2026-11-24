#include <iostream>
#include <string>
using namespace std;

class Address {
    string city;
    int pin;

public:
    Address(string c, int p) : city(c), pin(p) {}

    void display() const {
        cout << city << "-" << pin;
    }
};

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
};

class Student : public Person {
    long long regNo;
    Address home;

public:
    Student(const string& n, int a, long long r,
            const string& city, int pin)
        : Person(n, a), regNo(r), home(city, pin) {}

    void display() const {
        cout << regNo << " " << name
             << " (" << age << ") ";
        home.display();
        cout << endl;
    }
};

class Vehicle {
public:
    Vehicle() {
        cout << "Vehicle ";
    }

    virtual ~Vehicle() {
        cout << "~Vehicle ";
    }
};

class Engine {
public:
    Engine() {
        cout << "Engine ";
    }

    ~Engine() {
        cout << "~Engine ";
    }
};

class Car : public Vehicle {
    Engine engine;

public:
    Car() {
        cout << "Car ";
    }

    ~Car() {
        cout << "~Car ";
    }
};

int main() {
    Student s("Kavya", 19, 192311001, "Salem", 636001);
    s.display();

    cout << "\nConstruction and Destruction Order:" << endl;
    {
        Car c;
    }
    cout << endl;

    return 0;
}
