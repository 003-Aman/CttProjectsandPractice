#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Piece {
public:
    virtual string getName() = 0;
    virtual bool isValidMove(int startX, int startY, int endX, int endY) = 0;
};

class Pawn : public Piece {
public:
    string getName() override {
        return "P";
    }

    bool isValidMove(int startX, int startY, int endX, int endY) override {
        return (startX == endX && endY == startY + 1);
    }
};

class Board {
private:
    vector<vector<Piece*>> board;
public:
    Board() {
        board.resize(8, vector<Piece*>(8, nullptr));
        for (int i = 0; i < 8; ++i) {
            board[1][i] = new Pawn();
            board[6][i] = new Pawn();
        }
    }

    ~Board() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                delete board[i][j];
            }
        }
    }

    void printBoard() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == nullptr) {
                    cout << ".";
                } else {
                    cout << board[i][j]->getName();
                }
                cout << " ";
            }
            cout << endl;
        }
    }

    bool movePiece(int startX, int startY, int endX, int endY) {
        if (board[startX][startY] == nullptr) {
            cout << "No piece at starting position!" << endl;
            return false;
        }
        if (board[startX][startY]->isValidMove(startX, startY, endX, endY)) {
            board[endX][endY] = board[startX][startY];
            board[startX][startY] = nullptr;
            return true;
        } else {
            cout << "Invalid move!" << endl;
            return false;
        }
    }
};

int main() {
    Board board;
    board.printBoard();

    int startX, startY, endX, endY;
    while (true) {
        cout << "Enter move (startX startY endX endY): ";
        cin >> startX >> startY >> endX >> endY;
        if (board.movePiece(startX, startY, endX, endY)) {
            board.printBoard();
        }
    }

    return 0;
}