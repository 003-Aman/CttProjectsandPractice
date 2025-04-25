#include "Pricing.h"

// Calculate sod cost (area * price)
double Pricing::getSodCost(double price) const {
    return getArea() * price;
}

// Calculate fence cost (perimeter * price)
double Pricing::getFenceCost(double price) const {
    return getPerimeter() * price;
}