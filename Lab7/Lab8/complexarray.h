#ifndef COMPLEXARRAY_H
#define COMPLEXARRAY_H

#include "complexnumber.h"
#include <vector>
#include <string>

/**
 * @class ComplexArray
 * @brief Manages a collection of ComplexNumber objects
 * 
 * Provides operations for storing, retrieving, and performing calculations on complex numbers
 */
class ComplexArray {
private:
    std::vector<ComplexNumber> numbers;  ///< Dynamic storage for complex numbers
    std::vector<std::string> history;    ///< Operation history log

public:
    // Core functionality
    bool addComplexNumber(const ComplexNumber& cn);
    void displayAll() const;
    void displayHistory() const;
    
    // Arithmetic operations
    ComplexNumber performOperation(int index1, int index2, char op);
    
    // Utility functions
    int getCount() const;
    void clear();
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    
    // Accessors
    ComplexNumber getNumber(int index) const;
};

#endif // COMPLEXARRAY_H