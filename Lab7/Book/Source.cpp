#include "UpdatedBook.h"
#include "OutOfPrintBook.h"

int main() {
    int numBooks;
    cout << "Enter number of out-of-print books: ";
    cin >> numBooks;
    cin.ignore();

    Book** books = new Book*[numBooks];

    for (int i = 0; i < numBooks; ++i) {
        string author, title;
        Date date;
        cout << "\nBook " << i + 1 << endl;
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter last printed date (day month year): ";
        cin >> date.day >> date.month >> date.year;
        cin.ignore();

        books[i] = new OutOfPrintBook(author, title, date);
    }

    cout << "\n--- Book Details ---\n";
    for (int i = 0; i < numBooks; ++i) {
        books[i]->printBook();
    }

    for (int i = 0; i < numBooks; ++i) {
        delete books[i];
    }
    delete[] books;

    return 0;
}
