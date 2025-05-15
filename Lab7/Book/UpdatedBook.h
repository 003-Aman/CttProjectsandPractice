#ifndef UPDATEDBOOK_H
#define UPDATEDBOOK_H
#include "Book.h"

class UpdatedBook : public Book {
private:
    int edition;

public:
    UpdatedBook(string a, string t, int e);
    int getEdition() const;
    void printBook() const override;
};

#endif
