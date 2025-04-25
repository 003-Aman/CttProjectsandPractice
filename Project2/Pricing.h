#ifndef PRICING_H
#define PRICING_H

#include "Geometry.h"

class Pricing : public Geometry {
public:
    // Constructor - invokes Geometry constructor
    Pricing(int l, int w) : Geometry(l, w) {}

    // Cost calculation functions
    double getSodCost(double price) const;
    double getFenceCost(double price) const;
};

#endif // PRICING_H