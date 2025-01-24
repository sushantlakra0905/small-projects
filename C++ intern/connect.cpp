#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLUMNS = 7;
const char EMPTY = '.';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; ++i) {
        board.push_back(vector<char>(COLUMNS, EMPTY));
    }
}

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < COLUMNS; ++i) {
        cout << i << ' ';
    }
    cout << endl;
}

bool isColumnFull(const vector<vector<char>>& board, int col) {
    return board[0][col] != EMPTY;
}

bool dropPiece(vector<vector<char>>& board, int col, char piece) {
    for (int i = ROWS - 1; i >= 0; --i) {
        if (board[i][col] == EMPTY) {
            board[i][col] = piece;
            return true;
        }
    }
    return false;
}

bool isWinningMove(const vector<vector<char>>& board, char piece) {
    // Check horizontal
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLUMNS - 3; ++col) {
            if (board[row][col] == piece && board[row][col + 1] == piece &&
                board[row][col + 2] == piece && board[row][col + 3] == piece) {
                return true;
            }
        }
    }

    // Check vertical
    for (int col = 0; col < COLUMNS; ++col) {
        for (int row = 0; row < ROWS - 3; ++row) {
            if (board[row][col] == piece && board[row + 1][col] == piece &&
                board[row + 2][col] == piece && board[row + 3][col] == piece) {
                return true;
            }
        }
    }

    // Check diagonal (bottom left to top right)
    for (int row = 3; row < ROWS; ++row) {
        for (int col = 0; col < COLUMNS - 3; ++col) {
            if (board[row][col] == piece && board[row - 1][col + 1] == piece &&
                board[row - 2][col + 2] == piece && board[row - 3][col + 3] == piece) {
                return true;
            }
        }
    }

    // Check diagonal (top left to bottom right)
    for (int row = 0; row < ROWS - 3; ++row) {
        for (int col = 0; col < COLUMNS - 3; ++col) {
            if (board[row][col] == piece && board[row + 1][col + 1] == piece &&
                board[row + 2][col + 2] == piece && board[row + 3][col + 3] == piece) {
                return true;
            }
        }
    }

    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (int col = 0; col < COLUMNS; ++col) {
        if (board[0][col] == EMPTY) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board;
    initializeBoard(board);

    char currentPlayer = PLAYER1;
    bool gameWon = false;

    while (!gameWon && !isBoardFull(board)) {
        printBoard(board);
        int col;
        cout << "Player " << currentPlayer << ", choose a column (0-6): ";
        cin >> col;

        while (col < 0 || col >= COLUMNS || isColumnFull(board, col)) {
            cout << "Invalid column. Choose a column (0-6): ";
            cin >> col;
        }

        dropPiece(board, col, currentPlayer);

        if (isWinningMove(board, currentPlayer)) {
            gameWon = true;
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else {
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
        }
    }

    if (!gameWon) {
        printBoard(board);
        cout << "It's a draw!" << endl;
    }

    return 0;
}
