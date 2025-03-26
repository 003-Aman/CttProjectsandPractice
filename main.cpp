#include <iostream>
#include <iomanip>
#include <cctype>
#include "theater.h" // User-defined header file

using namespace std;

int main() {
    char layout[ROWS][COLS]; // Seat layout array
    int sales[ROWS][COLS] = {0}; // Sales tracking array

    cout << "====================================\n";
    cout << " 🎭 WELCOME TO CINEMA SEAT BOOKING 🎭 \n";
    cout << "====================================\n\n";

    initializeLayout(layout);
    displayLayout(layout);

    int row;
    char seat;
    char membership;
    
    while (true) {
        getSeatSelection(row, seat, membership); // Get user input

        if (row == -1) {
            break; // End program when -1 is entered
        }

        if (bookSeat(layout, sales, row, seat, membership)) {
            cout << "\n✅ Success! Seat " << row << seat << " has been booked.\n\n";
        } else {
            cout << "\n❌ Seat is already taken. Please choose another seat.\n\n";
        }

        displayLayout(layout);
    }

    generateSalesReport(sales);

    return 0;
}
