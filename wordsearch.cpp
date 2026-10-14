#include <iostream>
#include <vector>
#include <string>
using namespace std;

int rows, cols;

bool search(vector<vector<char>>& board, string& word, int r, int c, int index) {
    if (index == word.size())
        return true;

    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return false;

    if (board[r][c] != word[index])
        return false;

    char ch = board[r][c];
    board[r][c] = '#';

    bool found = search(board, word, r + 1, c, index + 1) ||
                 search(board, word, r - 1, c, index + 1) ||
                 search(board, word, r, c + 1, index + 1) ||
                 search(board, word, r, c - 1, index + 1);

    board[r][c] = ch;

    return found;
}

int main() {
    cin >> rows >> cols;

    vector<vector<char>> board(rows, vector<char>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (search(board, word, i, j, 0)) {
                cout << "true";
                return 0;
            }
        }
    }

    cout << "false";
    return 0;
}
