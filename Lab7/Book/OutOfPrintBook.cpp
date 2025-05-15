#include "OutOfPrintBook.h"

OutOfPrintBook::OutOfPrintBook(string a, string t, Date d) : Book(a, t), lastPrinted(d) {}

void OutOfPrintBook::printBook() const {
    cout << "Out Of Print Book - Author: " << author << ", Title: " << title
         << ", Last Printed: " << lastPrinted.day << "/" << lastPrinted.month << "/" << lastPrinted.year << endl;
}
