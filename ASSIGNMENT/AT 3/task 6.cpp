#include <iostream>
#include <cstring>
using namespace std;

class Text {
private:
    char* data;

public:
    // Constructor
    Text(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor
    Text(const Text& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy assignment
    Text& operator=(const Text& other) {
        if (this != &other) {
            char* temp = new char[strlen(other.data) + 1];
            strcpy(temp, other.data);

            delete[] data;
            data = temp;
        }

        return *this;
    }

    // Concatenation
    Text operator+(const Text& other) const {
        int len = strlen(data) + strlen(other.data);

        char* temp = new char[len + 1];

        strcpy(temp, data);
        strcat(temp, other.data);

        Text result(temp);
        delete[] temp;

        return result;
    }

    // Equality
    bool operator==(const Text& other) const {
        return strcmp(data, other.data) == 0;
    }

    // Not equal
    bool operator!=(const Text& other) const {
        return !(*this == other);
    }

    // Output
    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }

    // Destructor
    ~Text() {
        delete[] data;
    }
};

int main() {
    Text a("Hello ");
    Text b("World");
    Text c("!");

    Text result = a + b + c;

    cout << "Message: " << result << '\n';

    Text d("Hello World!");

    cout << boolalpha;
    cout << "Equal: " << (result == d) << '\n';
    cout << "Not Equal: " << (result != d) << '\n';

    // Self-assignment
    result = result;

    cout << "After self assignment: " << result << '\n';

    Text empty("");

    cout << "Empty message: " << empty << '\n';

    return 0;
}