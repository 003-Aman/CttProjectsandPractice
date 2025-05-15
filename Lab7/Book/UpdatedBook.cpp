#include "UpdatedBook.h"

UpdatedBook::UpdatedBook(string a, string t, int e) : Book(a, t), edition(e) {}

int UpdatedBook::getEdition() const {
    return edition;
}

void UpdatedBook::printBook() const {
    cout << "Updated Book - Author: " << author << ", Title: " << title << ", Edition: " << edition << endl;
}
