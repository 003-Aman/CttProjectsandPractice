#ifndef THEATER_H
#define THEATER_H

const int ROWS = 8;
const int COLS = 5;

void initializeLayout(char layout[][COLS]);
void displayLayout(const char layout[][COLS]);
void getSeatSelection(int &row, char &seat, char &membership);
bool bookSeat(char layout[][COLS], int sales[][COLS], int row, char seat, char membership);
void generateSalesReport(int sales[][COLS]);

#endif
