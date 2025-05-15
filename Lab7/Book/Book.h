#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string author;
    string title;

public:
    Book(string a, string t);
    Book(string t);
    virtual void printBook() const = 0;
    string getInfo() const;
    virtual ~Book();
};

#endif
