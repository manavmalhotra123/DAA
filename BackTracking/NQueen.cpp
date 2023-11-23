#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check if there is a queen in the same row
    for (int j = 0; j < col; j++) {
        if (board[row][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the lower left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the lower right diagonal
    for (int i = row, j = col; i < N && j < N; i++, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUntil(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        // All queens have been placed successfully
        // Print the board configuration like how the queens are placed
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return true;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1; // Place the queen in the cell
            if (solveNQueensUntil(board, row + 1, N)) {
                return true;
            }
            board[row][col] = 0; // Remove the queen from the cell
        }
    }

    return false;
}

int main() {
    int N; // number of queens
    cout << "Enter the number of queens (N): ";
    cin >> N;

    // Making the chess Board -- N X N
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensUntil(board, 0, N)) {
        cout << "No solution exists!" << endl;
    }

    return 0;
}