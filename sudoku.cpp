#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) return false;
        if (board[i][col] == num) return false;
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter the board: 9 rows of 9 characters, use '.' for empty:\n";
    for (int i = 0; i < 9; i++) {
        string rowStr;
        cin >> rowStr;
        for (int j = 0; j < 9; j++) board[i][j] = rowStr[j];
    }

    if (solveSudoku(board)) {
        cout << "\nSolved board:\n";
        for (int i = 0; i < 9; i++) {
            if (i > 0 && i % 3 == 0) {
                cout << "------+-------+------\n";
            }
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
                if (j == 2 || j == 5) {
                    cout << "| ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}