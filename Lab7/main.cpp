#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Member.h"
#include "Transaction.h"

using namespace std;

vector<Book> books;
vector<Member> members;
vector<Transaction> transactions;

Book* findBookByISBN(string isbn) {
    for (auto &book : books) {
        if (book.getISBN() == isbn) return &book;
    }
    return nullptr;
}

Member* findMemberByID(string id) {
    for (auto &member : members) {
        if (member.getMemberID() == id) return &member;
    }
    return nullptr;
}

void addBook() {
    string title, author, isbn;
    cout << "Enter book title: "; cin.ignore(); getline(cin, title);
    cout << "Enter author: "; getline(cin, author);
    cout << "Enter ISBN: "; getline(cin, isbn);
    books.push_back(Book(title, author, isbn));
    cout << "Book added successfully.\n";
}

void registerMember() {
    string name, contact, id;
    cout << "Enter member name: "; cin.ignore(); getline(cin, name);
    cout << "Enter contact: "; getline(cin, contact);
    cout << "Enter ID: "; getline(cin, id);
    members.push_back(Member(name, contact, id));
    cout << "Member registered successfully.\n";
}

void borrowBook() {
    string isbn, memberId, due;
    cout << "Enter book ISBN: "; cin.ignore(); getline(cin, isbn);
    cout << "Enter member ID: "; getline(cin, memberId);
    cout << "Enter due date: "; getline(cin, due);

    Book* book = findBookByISBN(isbn);
    Member* member = findMemberByID(memberId);
    if (book && member && book->getAvailability()) {
        book->setAvailability(false);
        transactions.push_back(Transaction(isbn, memberId, due));
        cout << "Book borrowed successfully.\n";
    } else {
        cout << "Borrowing failed.\n";
    }
}

void returnBook() {
    string isbn;
    cout << "Enter ISBN of book to return: "; cin.ignore(); getline(cin, isbn);
    for (auto &t : transactions) {
        if (t.getBookISBN() == isbn && !t.isReturned()) {
            t.markReturned();
            Book* book = findBookByISBN(isbn);
            if (book) book->setAvailability(true);
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Return failed.\n";
}

void listBooks() {
    for (auto &book : books) book.displayBook();
}

void listMembers() {
    for (auto &member : members) member.displayMember();
}

void listTransactions() {
    for (auto &trans : transactions) trans.displayTransaction();
}

int main() {
    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Register Member\n3. Borrow Book\n4. Return Book\n";
        cout << "5. List Books\n6. List Members\n7. List Transactions\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: registerMember(); break;
            case 3: borrowBook(); break;
            case 4: returnBook(); break;
            case 5: listBooks(); break;
            case 6: listMembers(); break;
            case 7: listTransactions(); break;
        }
    } while (choice != 8);

    return 0;
}
