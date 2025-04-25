#include <iostream>
#include <limits>
#include "complexnumber.h"
#include "complexarray.h"

/**
 * @brief Displays the main menu and handles user interaction
 * 
 * Provides a complete interface for the Complex Number Calculator with all operations
 */
void displayMenu() {
    std::cout << "\n===== Complex Number Calculator =====\n";
    std::cout << "1. Add a new complex number\n";
    std::cout << "2. Perform arithmetic operation\n";
    std::cout << "3. Display all complex numbers\n";
    std::cout << "4. Display operation history\n";
    std::cout << "5. Save numbers to file\n";
    std::cout << "6. Load numbers from file\n";
    std::cout << "7. Clear all numbers\n";
    std::cout << "8. Display number in polar form\n";
    std::cout << "9. Exit\n";
    std::cout << "====================================\n";
    std::cout << "Enter your choice: ";
}

/**
 * @brief Gets a complex number from user input
 * @return The created ComplexNumber object
 */
ComplexNumber getComplexNumberFromUser() {
    double real, imag;
    std::cout << "Enter real part: ";
    while (!(std::cin >> real)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter real part: ";
    }
    
    std::cout << "Enter imaginary part: ";
    while (!(std::cin >> imag)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter imaginary part: ";
    }
    
    return ComplexNumber(real, imag);
}

int main() {
    ComplexArray calculator;
    int choice;
    
    std::cout << "Welcome to the Complex Number Calculator!\n";
    
    do {
        displayMenu();
        while (!(std::cin >> choice) || choice < 1 || choice > 9) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please enter 1-9: ";
        }
        
        try {
            switch (choice) {
                case 1: {
                    ComplexNumber cn = getComplexNumberFromUser();
                    calculator.addComplexNumber(cn);
                    std::cout << "Added: " << cn << "\n";
                    break;
                }
                
                case 2: {
                    if (calculator.getCount() < 2) {
                        std::cout << "Need at least 2 complex numbers to perform operations\n";
                        break;
                    }
                    
                    calculator.displayAll();
                    int index1, index2;
                    char op;
                    
                    std::cout << "Enter index of first number: ";
                    while (!(std::cin >> index1) || index1 < 0 || index1 >= calculator.getCount()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid index. Enter index (0-" << calculator.getCount()-1 << "): ";
                    }
                    
                    std::cout << "Enter index of second number: ";
                    while (!(std::cin >> index2) || index2 < 0 || index2 >= calculator.getCount()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid index. Enter index (0-" << calculator.getCount()-1 << "): ";
                    }
                    
                    std::cout << "Enter operation (+, -, *, /): ";
                    while (!(std::cin >> op) || (op != '+' && op != '-' && op != '*' && op != '/')) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid operation. Enter +, -, *, or /: ";
                    }
                    
                    ComplexNumber result = calculator.performOperation(index1, index2, op);
                    std::cout << "Result: " << result << "\n";
                    break;
                }
                
                case 3:
                    calculator.displayAll();
                    break;
                    
                case 4:
                    calculator.displayHistory();
                    break;
                    
                case 5: {
                    std::string filename;
                    std::cout << "Enter filename to save: ";
                    std::cin >> filename;
                    calculator.saveToFile(filename);
                    std::cout << "Data saved successfully.\n";
                    break;
                }
                
                case 6: {
                    std::string filename;
                    std::cout << "Enter filename to load: ";
                    std::cin >> filename;
                    calculator.loadFromFile(filename);
                    std::cout << "Data loaded successfully.\n";
                    break;
                }
                
                case 7:
                    calculator.clear();
                    std::cout << "All complex numbers cleared.\n";
                    break;
                    
                case 8: {
                    if (calculator.getCount() == 0) {
                        std::cout << "No complex numbers stored.\n";
                        break;
                    }
                    
                    calculator.displayAll();
                    int index;
                    std::cout << "Enter index of number to display in polar form: ";
                    while (!(std::cin >> index) || index < 0 || index >= calculator.getCount()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid index. Enter index (0-" << calculator.getCount()-1 << "): ";
                    }
                    
                    ComplexNumber cn = calculator.getNumber(index);
                    cn.displayPolar();
                    std::cout << "\n";
                    break;
                }
                
                case 9:
                    std::cout << "Exiting program. Goodbye!\n";
                    break;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
        
    } while (choice != 9);
    
    return 0;
}