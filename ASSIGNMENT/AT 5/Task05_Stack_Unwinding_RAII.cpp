#include <iostream>
#include <stdexcept>
using namespace std;

class Guard {
    string name;

public:
    Guard(string n) : name(n) {
        cout << name << " created" << endl;
    }

    ~Guard() {
        cout << name << " destroyed" << endl;
    }
};

void process() {
    Guard g("Function Guard");
    cout << "Exception is raised" << endl;
    throw 42;
}

int main() {
    Guard m("Main Guard");

    try {
        process();
        cout << "This line is not printed" << endl;
    }
    catch (int value) {
        cout << "Caught: " << value << endl;
    }

    return 0;
}
