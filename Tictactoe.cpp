#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Set up the game board as an array
vector<string> board = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};

// Define a function to print the game board
void printBoard() {
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Define a function to handle a player's turn
void takeTurn(string player) {
    cout << player << "'s turn." << endl;
    cout << "Choose a position from 1-9: ";
    int position;
    cin >> position;
    position -= 1; //since we start to count from zer0

    while (position < 0 || position > 8 || board[position] != "-") {
        cout << "Invalid input or position already taken. Choose a different position: ";
        cin >> position;
        position -= 1;
    }

    board[position] = player;
    printBoard();
}

// Define a function to check if the game is over
string checkGameOver() {
    // Check for a win
    if ((board[0] == board[1] && board[1] == board[2] && board[0] != "-") ||
        (board[3] == board[4] && board[4] == board[5] && board[3] != "-") ||
        // ... (other win conditions)
        (board[2] == board[4] && board[4] == board[6] && board[2] != "-")) {
        return "win";
    }
    // Check for a tie
    else if (count(board.begin(), board.end(), "-") == 0) {
        return "tie";
    }
    // Game is not over
    else {
        return "play";
    }
}

// Define the main game loop
int main() {
    printBoard();
    string currentPlayer = "X";
    bool gameOver = false;

    while (!gameOver) {
        takeTurn(currentPlayer);
        string gameResult = checkGameOver();

        if (gameResult == "win") {
            cout << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (gameResult == "tie") {
            cout << "It's a tie!" << endl;
            gameOver = true;
        } else {
            // Switch to the other player
            currentPlayer = (currentPlayer == "X") ? "O" : "X";
        }
    }

    return 0;
}
