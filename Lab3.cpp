#include <iostream>
#include <iomanip>

using namespace std;

// Function to calculate property tax
double calculatePropertyTax(double houseCost, double taxRate) {
    return houseCost * (taxRate / 100);
}

// Function to calculate after-tax cost
double calculateAfterTaxCost(double houseCost, double propertyTax, double insuranceCost) {
    return houseCost + propertyTax + insuranceCost;
}

int main() {
    double houseCost, taxRate, insuranceRate;
    char choice;
    int houseCount = 0;
    double totalCost = 0;
    
    do {
        // Input from user
        cout << "Enter the cost of the house: $";
        while (!(cin >> houseCost) || houseCost <= 0) {
            cout << "Invalid input. Enter a valid positive number: $";
            cin.clear();
            cin.ignore(100, '\n');
        }
        
        cout << "Enter the property tax rate (as a percentage): ";
        while (!(cin >> taxRate) || taxRate < 0) {
            cout << "Invalid input. Enter a valid non-negative number: ";
            cin.clear();
            cin.ignore(100, '\n');
        }
        
        cout << "Enter the insurance cost percentage: ";
        while (!(cin >> insuranceRate) || insuranceRate < 0) {
            cout << "Invalid input. Enter a valid non-negative number: ";
            cin.clear();
            cin.ignore(100, '\n');
        }
        
        // Calculate costs
        double propertyTax = calculatePropertyTax(houseCost, taxRate);
        double insuranceCost = houseCost * (insuranceRate / 100);
        double afterTaxCost = calculateAfterTaxCost(houseCost, propertyTax, insuranceCost);
        
        // Display results
        cout << fixed << setprecision(2);
        cout << "\nHouse Cost: $" << houseCost << endl;
        cout << "Property Tax: $" << propertyTax << endl;
        cout << "Insurance Cost: $" << insuranceCost << endl;
        cout << "Annual After-Tax Cost: $" << afterTaxCost << "\n\n";
        
        // Update summary
        houseCount++;
        totalCost += afterTaxCost;
        
        // Ask user if they want to continue
        cout << "Would you like to enter another house? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    // Display summary
    cout << "\nTotal number of houses calculated: " << houseCount << endl;
    cout << "Total cost of all houses: $" << totalCost << endl;
    
    return 0;
}
