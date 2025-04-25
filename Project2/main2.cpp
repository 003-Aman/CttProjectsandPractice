#include <iostream>
#include <iomanip>
#include "Pricing.h"

using namespace std;

int main() {
    // Constants for pricing
    const double SOD_PRICE = 0.47; // $0.47 per square foot
    const double FENCE_PRICE = 22.50; // $22.50 per foot

    // Display title
    cout << "Landscaping Cost Calculator\n";
    cout << "==========================\n\n";

    // Get user input
    int length, width;
    cout << "Enter length of the area (in feet): ";
    cin >> length;
    cout << "Enter width of the area (in feet): ";
    cin >> width;

    // Create Pricing object
    Pricing project(length, width);

    // Calculate and display costs
    cout << fixed << setprecision(2);
    cout << "\nSod Cost: $" << project.getSodCost(SOD_PRICE) << endl;
    cout << "Fence Cost: $" << project.getFenceCost(FENCE_PRICE) << endl;

    system("pause");
    return 0;
}