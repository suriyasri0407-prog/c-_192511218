#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Single parameter constructor
    Complex(double r) : real(r), imag(0) {}

    // Two parameter constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Addition
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication
    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // Division
    Complex operator/(const Complex& c) const {
        double denominator =
            c.real * c.real + c.imag * c.imag;

        if (denominator == 0)
            throw runtime_error("Division by zero impedance");

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    // Equality
    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }

    // Magnitude
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // Output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + j" << c.imag;
        else
            out << " - j" << -c.imag;

        return out;
    }
};

int main() {
    try {
        Complex resistor(10, 0);
        Complex inductor(0, 5);
        Complex capacitor(0, -2);

        // Series impedance
        Complex series = resistor + inductor + capacitor;

        cout << "Series Impedance: " << series << '\n';
        cout << "Magnitude: " << series.magnitude() << '\n';

        // Parallel impedance
        Complex z1(10, 5);
        Complex z2(5, -2);

        Complex parallel = (z1 * z2) / (z1 + z2);

        cout << "\nParallel Impedance: " << parallel << '\n';
        cout << "Magnitude: " << parallel.magnitude() << '\n';

        // Division by zero test
        Complex zero(0, 0);
        Complex result = z1 / zero;

        cout << result << '\n';
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}