#include "Book.h"

Book::Book(string a, string t) : author(a), title(t) {}
Book::Book(string t) : author("unknown"), title(t) {}
string Book::getInfo() const { return author + ", " + title; }
Book::~Book() {}
