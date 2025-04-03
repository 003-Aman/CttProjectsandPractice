#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
using namespace std;

class Transaction {
private:
    string bookISBN;
    string memberID;
    string dueDate;
    bool returned;

public:
    Transaction();
    Transaction(string bookISBN, string memberID, string dueDate);

    string getBookISBN() const;
    string getMemberID() const;
    string getDueDate() const;
    bool isReturned() const;

    void markReturned();
    void displayTransaction() const;
};

#endif
