#include <iostream>

using namespace std;

int main() {
    // Define a constant for the pay increase percentage
    const double PAY_INCREASE = 6.2 / 100; // 6.2% increase

    // Declare variables to store salary details
    double formerSalary, payIncrease, newAnnualSalary, newMonthlySalary;

    // Prompt the user to enter the employee's former annual salary
    cout << "Enter the employee's former annual salary: $";
    cin >> formerSalary;

    // Calculate the pay increase amount
    payIncrease = formerSalary * PAY_INCREASE;

    // Calculate the new annual salary after the pay increase
    newAnnualSalary = formerSalary + payIncrease;

    // Calculate the new monthly salary
    newMonthlySalary = newAnnualSalary / 12;

    // Display the results
    cout << "\n--- Salary Update ---\n";
    cout << "Pay Increase Amount: $" << payIncrease << endl;
    cout << "New Annual Salary: $" << newAnnualSalary << endl;
    cout << "New Monthly Salary: $" << newMonthlySalary << endl;

    // End of the program
    return 0;
}
