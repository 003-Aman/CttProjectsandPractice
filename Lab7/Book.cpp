#include "Book.h"

Book::Book() {
    title = "";
    author = "";
    ISBN = "";
    isAvailable = true;
}

Book::Book(string title, string author, string ISBN) {
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
    this->isAvailable = true;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return ISBN;
}

bool Book::getAvailability() const {
    return isAvailable;
}

void Book::setTitle(string title) {
    this->title = title;
}

void Book::setAuthor(string author) {
    this->author = author;
}

void Book::setISBN(string ISBN) {
    this->ISBN = ISBN;
}

void Book::setAvailability(bool availability) {
    this->isAvailable = availability;
}

void Book::displayBook() const {
    cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
}
