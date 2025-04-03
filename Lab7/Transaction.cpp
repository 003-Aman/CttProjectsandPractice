#include "Transaction.h"

Transaction::Transaction() {
    bookISBN = "";
    memberID = "";
    dueDate = "";
    returned = false;
}

Transaction::Transaction(string bookISBN, string memberID, string dueDate) {
    this->bookISBN = bookISBN;
    this->memberID = memberID;
    this->dueDate = dueDate;
    this->returned = false;
}

string Transaction::getBookISBN() const {
    return bookISBN;
}

string Transaction::getMemberID() const {
    return memberID;
}

string Transaction::getDueDate() const {
    return dueDate;
}

bool Transaction::isReturned() const {
    return returned;
}

void Transaction::markReturned() {
    returned = true;
}

void Transaction::displayTransaction() const {
    cout << "Book ISBN: " << bookISBN << ", Member ID: " << memberID
         << ", Due Date: " << dueDate << ", Returned: " << (returned ? "Yes" : "No") << endl;
}
