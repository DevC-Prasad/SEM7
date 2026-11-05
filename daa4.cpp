
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> board;

// Check whether queen can be placed
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Backtracking function
bool solve(int row) {
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;

            if (solve(row + 1))
                return true;

            board[row] = -1;
        }
    }

    return false;
}

// Print chessboard
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter N: ";
    cin >> N;

    board.resize(N, -1);

    // Place first queen at (0, 0)
    board[0] = 0;

    if (solve(1)) {
        cout << "\nSolution:\n";
        printBoard();
    }
    else {
        cout << "\nNo solution exists\n";
    }

    return 0;
}
