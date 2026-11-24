#include <iostream>
using namespace std;

class Auditorium {
private:
    int rows;
    int seats;
    char** seatMap;
    int booked;

public:
    Auditorium(int r, int s)
        : rows(r), seats(s), seatMap(nullptr), booked(0) {

        if (rows > 0 && seats > 0) {
            seatMap = new char*[rows];

            for (int i = 0; i < rows; i++) {
                seatMap[i] = new char[seats];

                for (int j = 0; j < seats; j++)
                    seatMap[i][j] = 'O';
            }
        }

        cout << "Auditorium created\n";
    }

    void bookSeat(int r, int s) {
        if (!seatMap || r < 0 || r >= rows ||
            s < 0 || s >= seats) {
            cout << "Invalid seat\n";
            return;
        }

        if (seatMap[r][s] == 'O') {
            seatMap[r][s] = 'X';
            booked++;
            cout << "Seat booked\n";
        } else {
            cout << "Seat already booked\n";
        }
    }

    void cancelSeat(int r, int s) {
        if (!seatMap || r < 0 || r >= rows ||
            s < 0 || s >= seats) {
            cout << "Invalid seat\n";
            return;
        }

        if (seatMap[r][s] == 'X') {
            seatMap[r][s] = 'O';
            booked--;
            cout << "Booking cancelled\n";
        }
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++)
                cout << seatMap[i][j] << " ";

            cout << '\n';
        }
    }

    ~Auditorium() {
        if (seatMap != nullptr) {
            for (int i = 0; i < rows; i++)
                delete[] seatMap[i];

            delete[] seatMap;
        }

        cout << "Auditorium closed. Booked seats: "
             << booked << '\n';
    }
};

int main() {
    Auditorium a1(3, 4);

    a1.bookSeat(0, 1);
    a1.bookSeat(1, 2);
    a1.display();

    a1.cancelSeat(0, 1);

    Auditorium* a2 = new Auditorium(2, 3);
    a2->bookSeat(0, 0);
    delete a2;

    {
        Auditorium a3(2, 2);
        a3.bookSeat(1, 1);
    }

    return 0;
}