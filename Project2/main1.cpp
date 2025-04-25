#include <iostream>
#include "Geometry.h"

using namespace std;

int main() {
    // Test variables
    int len = 5, wid = 3, side = 4;

    // Test mutator functions
    Geometry geo1;
    cout << "Testing mutator functions...\n";
    geo1.setLength(len);
    geo1.setWidth(wid);
    cout << "Length set to: " << geo1.getLength() << endl;
    cout << "Width set to: " << geo1.getWidth() << endl;

    // Test rectangle constructor
    Geometry rect(len, wid);
    cout << "\nTesting rectangle constructor...\n";
    cout << "Length: " << rect.getLength() << endl;
    cout << "Width: " << rect.getWidth() << endl;
    cout << "Area: " << rect.getArea() << endl;
    cout << "Perimeter: " << rect.getPerimeter() << endl;

    // Test cube constructor
    Geometry cube(side);
    cout << "\nTesting cube constructor...\n";
    cout << "Side: " << cube.getSide() << endl;
    cout << "Surface Area: " << cube.getSurfaceArea() << endl;

    // Test default constructor
    Geometry defaultGeo;
    cout << "\nTesting default constructor...\n";
    cout << "Default length: " << defaultGeo.getLength() << endl;
    cout << "Default width: " << defaultGeo.getWidth() << endl;
    cout << "Default side: " << defaultGeo.getSide() << endl;

    // Test error handling (uncomment to test)
    // Geometry errorTest(-5, 10); // Should exit with error

    system("pause");
    return 0;
}