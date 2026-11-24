
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

const int CAPACITY = 1000;
const int OPERATIONS = 200000;

// Original design: shifting array
class OriginalHistory {
private:
    int data[CAPACITY]{};
    int count = 0;

public:
    void add(int value) {
        if (count < CAPACITY) {
            data[count++] = value;
        } else {
            for (int i = 1; i < CAPACITY; i++) {
                data[i - 1] = data[i];
            }

            data[CAPACITY - 1] = value;
        }
    }
};

// Redesigned solution: circular array
class CircularHistory {
private:
    int data[CAPACITY]{};
    int count = 0;
    int nextIndex = 0;

public:
    void add(int value) {
        data[nextIndex] = value;

        nextIndex = (nextIndex + 1) % CAPACITY;

        if (count < CAPACITY)
            count++;
    }
};

int main() {
    OriginalHistory original;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < OPERATIONS; i++) {
        original.add(i);
    }

    auto end1 = high_resolution_clock::now();

    CircularHistory redesigned;

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < OPERATIONS; i++) {
        redesigned.add(i);
    }

    auto end2 = high_resolution_clock::now();

    auto time1 =
        duration_cast<microseconds>(end1 - start1).count();

    auto time2 =
        duration_cast<microseconds>(end2 - start2).count();

    cout << "Operations: " << OPERATIONS << '\n';

    cout << "Original shifting time: "
         << time1 << " microseconds\n";

    cout << "Circular buffer time: "
         << time2 << " microseconds\n";

    cout << "Original insertion complexity: O(k)\n";
    cout << "Circular insertion complexity: O(1)\n";

    cout << "Both use O(k) space.\n";

    return 0;
}
