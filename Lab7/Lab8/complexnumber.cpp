#include "complexnumber.h"

/**
 * @brief Default constructor initializes to 0 + 0i
 */
ComplexNumber::ComplexNumber() : real(0.0), imaginary(0.0) {}

/**
 * @brief Parameterized constructor
 * @param r Real part
 * @param i Imaginary part
 */
ComplexNumber::ComplexNumber(double r, double i) : real(r), imaginary(i) {}

// Getters
double ComplexNumber::getReal() const { return real; }
double ComplexNumber::getImaginary() const { return imaginary; }

// Setters
void ComplexNumber::setReal(double r) { real = r; }
void ComplexNumber::setImaginary(double i) { imaginary = i; }

/**
 * @brief Calculates magnitude of the complex number
 * @return Magnitude (absolute value)
 */
double ComplexNumber::magnitude() const {
    return sqrt(real * real + imaginary * imaginary);
}

/**
 * @brief Calculates phase angle in radians
 * @return Phase angle (-π to π)
 */
double ComplexNumber::phase() const {
    return atan2(imaginary, real);
}

/**
 * @brief Displays complex number in rectangular form
 */
void ComplexNumber::display() const {
    std::cout << *this;
}

/**
 * @brief Displays complex number in polar form
 */
void ComplexNumber::displayPolar() const {
    std::cout << magnitude() << "(cos(" << phase() << ") + i*sin(" << phase() << "))";
}

// Arithmetic operators
ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    return ComplexNumber(real + other.real, imaginary + other.imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    return ComplexNumber(real - other.real, imaginary - other.imaginary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    return ComplexNumber(
        real * other.real - imaginary * other.imaginary,
        real * other.imaginary + imaginary * other.real
    );
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
    double denom = other.real * other.real + other.imaginary * other.imaginary;
    if (denom == 0) throw std::runtime_error("Division by zero in complex number operation");
    
    return ComplexNumber(
        (real * other.real + imaginary * other.imaginary) / denom,
        (imaginary * other.real - real * other.imaginary) / denom
    );
}

// Assignment operator
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other) {
    if (this != &other) {
        real = other.real;
        imaginary = other.imaginary;
    }
    return *this;
}

// Equality comparison
bool ComplexNumber::operator==(const ComplexNumber& other) const {
    return (real == other.real) && (imaginary == other.imaginary);
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn) {
    os << cn.real;
    if (cn.imaginary >= 0) {
        os << " + " << cn.imaginary << "i";
    } else {
        os << " - " << -cn.imaginary << "i";
    }
    return os;
}

// Stream extraction operator
std::istream& operator>>(std::istream& is, ComplexNumber& cn) {
    char sign, i;
    is >> cn.real >> sign >> cn.imaginary >> i;
    if (sign == '-') cn.imaginary = -cn.imaginary;
    if (i != 'i') is.setstate(std::ios::failbit);
    return is;
}