
#include <iostream>
using namespace std;

int& highestMark(int marks[], int size) {
    int index = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[index])
            index = i;
    }

    return marks[index];
}

// Demonstrates a dangerous dangling reference.
// Do not call this function.
int& dangerousFunction() {
    int x = 50;
    return x;
}

int main() {
    int marks[] = {78, 91, 85, 96, 88};
    int size = 5;

    cout << "Original marks: ";
    for (int i = 0; i < size; i++)
        cout << marks[i] << " ";

    highestMark(marks, size) += 2;

    cout << "\nUpdated marks: ";
    for (int i = 0; i < size; i++)
        cout << marks[i] << " ";

    cout << "\nHighest mark: "
         << highestMark(marks, size) << '\n';

    return 0;
}
