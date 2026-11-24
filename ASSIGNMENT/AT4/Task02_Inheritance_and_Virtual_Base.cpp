#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string phone;

public:
    Person(string n, int i, string p)
        : name(n), id(i), phone(p) {
        cout << "Person" << endl;
    }

    virtual ~Person() {}
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;

public:
    Student(string n, int i, string ph, string prog, double c)
        : Person(n, i, ph), programme(prog), cgpa(c) {
        cout << "Student" << endl;
    }
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;

public:
    Staff(string n, int i, string ph, string dept, double s)
        : Person(n, i, ph), department(dept), salary(s) {
        cout << "Staff" << endl;
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string ph, string prog,
                      double cg, string dept, double sal)
        : Person(n, i, ph),
          Student(n, i, ph, prog, cg),
          Staff(n, i, ph, dept, sal) {
        cout << "Teaching Assistant" << endl;
    }

    void display() const {
        cout << "Name: " << name
             << "\nID: " << id
             << "\nPhone: " << phone
             << "\nProgramme: " << programme
             << "\nDepartment: " << department << endl;
    }
};

class ResearchScholar : public Student {
    double fellowship;

public:
    ResearchScholar(string n, int i, string ph, string prog,
                    double cg, double f)
        : Person(n, i, ph),
          Student(n, i, ph, prog, cg), fellowship(f) {}

    void display() const {
        cout << "Research Scholar: " << name
             << "\nFellowship: " << fellowship << endl;
    }
};

int main() {
    TeachingAssistant ta("Arun", 101, "9876543210",
                         "CSE", 8.5, "Computer Science", 25000);
    ta.display();

    cout << endl;

    ResearchScholar rs("Meena", 102, "9876501234",
                       "AI", 9.0, 15000);
    rs.display();

    return 0;
}
