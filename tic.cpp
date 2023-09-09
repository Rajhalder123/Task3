#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const vector<char>& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }

    // Check diagonals for a win
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const vector<char>& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false; // There's an empty cell, so it's not a draw
        }
    }
    return true; // All cells are filled, it's a draw
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameOver) {
        // Print the current board
        cout << "Current board:" << endl;
        printBoard(board);

        // Get the current player's move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
        } else {
            board[row][col] = currentPlayer;

            // Check for a win or draw
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (checkDraw(board)) {
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
    }

    // Ask if players want to play again
    char playAgain;
    cout << "Play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        // Reset the board and game state
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        gameOver = false;
    } else {
        cout << "Thanks for playing! Goodbye." << endl;
    }

    return 0;
}
