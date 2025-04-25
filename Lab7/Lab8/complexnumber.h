#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>
#include <cmath>
#include <stdexcept>

/**
 * @class ComplexNumber
 * @brief Represents complex numbers with real and imaginary parts
 * 
 * Provides arithmetic operations through overloaded operators and various utility functions
 */
class ComplexNumber {
private:
    double real;        ///< Real part of the complex number
    double imaginary;   ///< Imaginary part of the complex number

public:
    // Constructors
    ComplexNumber();
    ComplexNumber(double r, double i);

    // Getters and setters
    double getReal() const;
    double getImaginary() const;
    void setReal(double r);
    void setImaginary(double i);

    // Utility functions
    double magnitude() const;
    double phase() const;
    void display() const;
    void displayPolar() const;

    // Overloaded arithmetic operators
    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const;
    
    // Overloaded assignment and comparison operators
    ComplexNumber& operator=(const ComplexNumber& other);
    bool operator==(const ComplexNumber& other) const;
    
    // Friend functions for stream operations
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn);
    friend std::istream& operator>>(std::istream& is, ComplexNumber& cn);
};

#endif // COMPLEXNUMBER_H