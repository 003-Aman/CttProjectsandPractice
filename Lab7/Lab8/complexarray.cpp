#include "complexarray.h"
#include <fstream>
#include <sstream>

bool ComplexArray::addComplexNumber(const ComplexNumber& cn) {
    numbers.push_back(cn);
    history.push_back("Added: " + std::to_string(numbers.size()) + ". " + std::to_string(cn.getReal()) + " + " + std::to_string(cn.getImaginary()) + "i");
    return true;
}

void ComplexArray::displayAll() const {
    if (numbers.empty()) {
        std::cout << "No complex numbers stored.\n";
        return;
    }
    
    std::cout << "Stored Complex Numbers:\n";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << "[" << i << "] " << numbers[i] << "\n";
    }
}

void ComplexArray::displayHistory() const {
    if (history.empty()) {
        std::cout << "No history available.\n";
        return;
    }
    
    std::cout << "Operation History:\n";
    for (const auto& entry : history) {
        std::cout << entry << "\n";
    }
}

ComplexNumber ComplexArray::performOperation(int index1, int index2, char op) {
    if (index1 < 0 || index1 >= numbers.size() || index2 < 0 || index2 >= numbers.size()) {
        throw std::out_of_range("Invalid index for complex number");
    }

    ComplexNumber result;
    std::string opSymbol;
    
    switch (op) {
        case '+': 
            result = numbers[index1] + numbers[index2];
            opSymbol = " + ";
            break;
        case '-': 
            result = numbers[index1] - numbers[index2];
            opSymbol = " - ";
            break;
        case '*': 
            result = numbers[index1] * numbers[index2];
            opSymbol = " * ";
            break;
        case '/': 
            result = numbers[index1] / numbers[index2];
            opSymbol = " / ";
            break;
        default: 
            throw std::invalid_argument("Invalid operation");
    }
    
    std::ostringstream oss;
    oss << "Performed: [" << index1 << "]" << opSymbol << "[" << index2 << "] = " << result;
    history.push_back(oss.str());
    
    return result;
}

int ComplexArray::getCount() const {
    return numbers.size();
}

void ComplexArray::clear() {
    numbers.clear();
    history.push_back("Cleared all complex numbers");
}

ComplexNumber ComplexArray::getNumber(int index) const {
    if (index < 0 || index >= numbers.size()) {
        throw std::out_of_range("Invalid index for complex number");
    }
    return numbers[index];
}

void ComplexArray::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Could not open file for writing");
    }
    
    for (const auto& num : numbers) {
        outFile << num.getReal() << " " << num.getImaginary() << "\n";
    }
    
    history.push_back("Saved data to file: " + filename);
}

void ComplexArray::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        throw std::runtime_error("Could not open file for reading");
    }
    
    numbers.clear();
    double real, imag;
    while (inFile >> real >> imag) {
        numbers.emplace_back(real, imag);
    }
    
    history.push_back("Loaded data from file: " + filename);
}