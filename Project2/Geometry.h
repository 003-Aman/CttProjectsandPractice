#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cstdlib> // for exit()

class Geometry {
public:
    // Constructors
    Geometry(); // Default constructor
    Geometry(int l, int w); // Rectangle constructor
    Geometry(int s); // Cube constructor

    // Mutator functions
    void setLength(int l);
    void setWidth(int w);
    void setSide(int s);

    // Accessor functions
    int getLength() const;
    int getWidth() const;
    int getSide() const;

    // Calculation functions
    int getArea() const;
    int getPerimeter() const;
    int getSurfaceArea() const;

private:
    // Private member variables
    int length;
    int width;
    int side;

    // Private helper function
    void checkNum(int num) const;
};

#endif // GEOMETRY_H