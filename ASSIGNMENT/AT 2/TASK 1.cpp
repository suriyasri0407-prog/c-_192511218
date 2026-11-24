
#include <iostream>
using namespace std;

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}

void applyByReference(long long& fee, int percent) {
    fee -= fee * percent / 100;
}

void applyByPointer(long long* fee, int percent) {
    if (fee != nullptr)
        *fee -= (*fee) * percent / 100;
}

void change(int a, int& b, int* c) {
    a += 10;
    b += 10;
    *c += 10;
}

int& bigger(int& p, int& q) {
    return p > q ? p : q;
}

void show(int x, int y = 5, int z = 10) {
    cout << x + y + z << ' ';
}

int main() {
    long long a = 45000, b = 45000, c = 45000;

    applyByValue(a, 10);
    applyByReference(b, 10);
    applyByPointer(&c, 10);

    cout << "Value: " << a << '\n';
    cout << "Reference: " << b << '\n';
    cout << "Pointer: " << c << '\n';

    int x = 1, y = 2, z = 3;
    change(x, y, &z);
    cout << x << ' ' << y << ' ' << z << '\n';

    bigger(x, z) = 100;
    cout << x << ' ' << z << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);
    cout << '\n';

    return 0;
}
