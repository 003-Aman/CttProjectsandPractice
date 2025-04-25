#include "Geometry.h"

// Default constructor - sets all variables to zero
Geometry::Geometry() : length(0), width(0), side(0) {}

// Rectangle constructor - takes length and width
Geometry::Geometry(int l, int w) {
    checkNum(l);
    checkNum(w);
    length = l;
    width = w;
    side = 0; // Not used for rectangle
}

// Cube constructor - takes side length
Geometry::Geometry(int s) {
    checkNum(s);
    side = s;
    length = 0; // Not used for cube
    width = 0;  // Not used for cube
}

// Private helper function to validate numbers
void Geometry::checkNum(int num) const {
    if (num <= 0) {
        std::cerr << "Error: Value must be greater than zero.\n";
        exit(1);
    }
}

// Mutator functions
void Geometry::setLength(int l) {
    checkNum(l);
    length = l;
}

void Geometry::setWidth(int w) {
    checkNum(w);
    width = w;
}

void Geometry::setSide(int s) {
    checkNum(s);
    side = s;
}

// Accessor functions
int Geometry::getLength() const {
    return length;
}

int Geometry::getWidth() const {
    return width;
}

int Geometry::getSide() const {
    return side;
}

// Calculation functions
int Geometry::getArea() const {
    return length * width;
}

int Geometry::getPerimeter() const {
    return 2 * (length + width);
}

int Geometry::getSurfaceArea() const {
    return 6 * side * side;
}