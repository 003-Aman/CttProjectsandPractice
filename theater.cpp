#include <iostream>
#include <iomanip>
#include "theater.h"

using namespace std;

// Function to initialize the theater layout with open seats
void initializeLayout(char layout[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            layout[i][j] = 'O'; // 'O' represents an open seat
        }
    }
}

// Function to display the formatted theater layout
void displayLayout(const char layout[][COLS]) {
    cout << "\n     A   B   C   D   E\n";
    cout << "  ╔═════════════════════╗\n";
    for (int i = 0; i < ROWS; i++) {
        cout << i + 1 << " ║ ";
        for (int j = 0; j < COLS; j++) {
            if (layout[i][j] == 'O') {
                cout << "🟩  "; // Open seat
            } else {
                cout << "❌  "; // Booked seat
            }
        }
        cout << "║\n";
    }
    cout << "  ╚═════════════════════╝\n";
    cout << "    🎥 SCREEN THIS WAY 🎥  \n\n";
}

// Function to get user input for seat selection
void getSeatSelection(int &row, char &seat, char &membership) {
    cout << "\nEnter row number (1-8) or -1 to exit: ";
    cin >> row;

    if (row == -1) return; // Exit condition

    cout << "Enter seat letter (A-E): ";
    cin >> seat;
    seat = toupper(seat); // Convert to uppercase

    cout << "Enter membership type (G - Gold, S - Silver, N - No membership): ";
    cin >> membership;
    membership = toupper(membership);
}

// Function to book a seat and update sales
bool bookSeat(char layout[][COLS], int sales[][COLS], int row, char seat, char membership) {
    int rowIndex = row - 1;
    int colIndex = seat - 'A';

    if (layout[rowIndex][colIndex] == 'X') {
        return false; // Seat is already booked
    }

    layout[rowIndex][colIndex] = 'X'; // Mark seat as booked

    // Assign price based on membership type
    int price = (membership == 'G') ? 22 : (membership == 'S') ? 20 : 18;
    sales[rowIndex][colIndex] = price;

    return true;
}

// Function to generate sales report
void generateSalesReport(int sales[][COLS]) {
    int totalSeatsSold = 0;
    double totalRevenue = 0.0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (sales[i][j] > 0) {
                totalSeatsSold++;
                totalRevenue += sales[i][j];
            }
        }
    }

    double occupancyRate = (totalSeatsSold / 40.0) * 100;

    cout << "--------------------------------\n";
    cout << "📊 SALES REPORT: \n";
    cout << "--------------------------------\n";
    cout << "🎟️ Total seats sold: " << totalSeatsSold << "/40\n";
    cout << "📈 Percentage occupied: " << fixed << setprecision(2) << occupancyRate << "%\n";
    cout << "💰 Total revenue: $" << totalRevenue << "\n";
    cout << "--------------------------------\n";
}
