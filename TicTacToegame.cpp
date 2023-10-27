#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentPlayer = 'X';

// Function to display the Tic-Tac-Toe board
void displayBoard() {
    cout << "  1   2   3\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "  ---------\n";
        }
    }
    cout << endl;
}

// Function to check if the game is over
bool isGameOver() {
    // Check for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }

    // Check for a draw
    bool draw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                draw = false;
                break;
            }
        }
    }
    if (draw) {
        cout << "It's a draw!" << endl;
        return true;
    }

    return false;
}

// Function to switch players
void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

int main() {
    int row, col;

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter row and column (1-3): ";
        cin >> row >> col;

        // Check for valid input
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (isGameOver()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        switchPlayer();
    }

    return 0;
}
