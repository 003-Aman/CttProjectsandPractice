#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool isAvailable;

public:
    Book();
    Book(string title, string author, string ISBN);

    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    bool getAvailability() const;
    void setTitle(string title);
    void setAuthor(string author);
    void setISBN(string ISBN);
    void setAvailability(bool availability);
    void displayBook() const;
};

#endif
