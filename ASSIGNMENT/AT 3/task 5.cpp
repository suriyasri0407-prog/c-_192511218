#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Time {
private:
    int h, m, s;

public:
    Time(int hh = 0, int mm = 0, int ss = 0)
        : h(hh), m(mm), s(ss) {
        normalize();
    }

    void normalize() {
        int total = h * 3600 + m * 60 + s;

        if (total < 0)
            total = 0;

        h = total / 3600;
        m = (total % 3600) / 60;
        s = total % 60;
    }

    // Prefix increment
    Time& operator++() {
        s++;

        if (s == 60) {
            s = 0;
            m++;
        }

        if (m == 60) {
            m = 0;
            h++;
        }

        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time old = *this;
        ++(*this);
        return old;
    }

    bool operator==(const Time& other) const {
        return h == other.h &&
               m == other.m &&
               s == other.s;
    }

    bool operator<(const Time& other) const {
        if (h != other.h) return h < other.h;
        if (m != other.m) return m < other.m;
        return s < other.s;
    }

    void display() const {
        cout << h << ":" << m << ":" << s << '\n';
    }
};

class Playlist {
private:
    string tracks[5] = {
        "Song 1", "Song 2", "Song 3",
        "Song 4", "Song 5"
    };

public:
    string& operator[](int index) {
        if (index < 0 || index >= 5)
            throw out_of_range("Invalid playlist index");

        return tracks[index];
    }

    const string& operator[](int index) const {
        if (index < 0 || index >= 5)
            throw out_of_range("Invalid playlist index");

        return tracks[index];
    }
};

int main() {
    Time t(0, 59, 58);

    Time a = t++;
    Time b = ++t;

    cout << "a: ";
    a.display();

    cout << "b: ";
    b.display();

    cout << "Current time: ";
    t.display();

    Time x(1, 0, 0);
    Time y(1, 0, 0);

    cout << boolalpha << (x == y) << '\n';
    cout << (t < x) << '\n';

    Playlist p;

    try {
        for (int i = 0; i < 5; i++)
            cout << p[i] << '\n';

        cout << p[5] << '\n';
    }
    catch (const out_of_range& e) {
        cout << e.what() << '\n';
    }

    return 0;
}