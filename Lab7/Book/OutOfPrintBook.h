#ifndef OUTOFPRINTBOOK_H
#define OUTOFPRINTBOOK_H
#include "Book.h"

struct Date {
    int day;
    int month;
    int year;
};

class OutOfPrintBook : public Book {
private:
    Date lastPrinted;

public:
    OutOfPrintBook(string a, string t, Date d);
    void printBook() const override;
};

#endif
