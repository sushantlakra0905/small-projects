#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic Tac Toe board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}

// Function to check if the board is full
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; // If there's an empty cell, game is not a draw
        }
    }
    return true; // If all cells are filled and no one has won, it's a draw
}

// Function to play the Tic Tac Toe game
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize empty board
    char currentPlayer = 'X';
    bool gameEnded = false;

    while (!gameEnded) {
        // Print current board
        printBoard(board);

        // Get player input
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row [1-3], column [1-3]): ";
        cin >> row >> col;

        // Convert to 0-based indexing
        row--;
        col--;

        // Check if the cell is empty and within bounds
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            // Make the move
            board[row][col] = currentPlayer;

            // Check if the player has won
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameEnded = true;
            }
            // Check for a draw
            else if (checkDraw(board)) {
                cout << "It's a draw!" << endl;
                gameEnded = true;
            }
            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }
}

int main() {
    cout << "Welcome to Tic Tac Toe!" << endl;
    playGame();
    return 0;
}
