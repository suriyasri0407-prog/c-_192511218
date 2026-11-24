#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    int copies;
    string author;

public:
    Book() : Book("Unknown", 0, "Unknown") {}

    Book(string t) : Book(t, 1, "Unknown") {}

    Book(string t, int c) : Book(t, c, "Unknown") {}

    Book(string t, int c, string a)
        : title(t), copies(c), author(a) {
        if (copies < 0)
            throw invalid_argument("Copies cannot be negative");
    }

    void display() const {
        cout << "Title: " << title
             << "\nCopies: " << copies
             << "\nAuthor: " << author << "\n\n";
    }
};

int main() {
    try {
        Book b1;
        Book b2("C++ Programming");
        Book b3("Python", 5, "James");

        b1.display();
        b2.display();
        b3.display();

        // Book b4("Java", -2, "John"); // Invalid copies
    }
    catch (const exception& e) {
        cout << e.what() << '\n';
    }

    return 0;
}