#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int c, vector<int>& col) {
    for (int r = 0; r < row; r++) {
        if (col[r] == c)
            return false;

        int x = col[r] - c;
        int y = r - row;

        if (x < 0)
            x = -x;

        if (y < 0)
            y = -y;

        if (x == y)
            return false;
    }

    return true;
}

bool solveNQueens(int row, vector<int>& col, int N) {
    if (row == N)
        return true;

    for (int c = 0; c < N; c++) {
        if (isSafe(row, c, col)) {
            col[row] = c;

            if (solveNQueens(row + 1, col, N))
                return true;

            col[row] = -1;
        }
    }

    return false;
}

int main() {
    int N;

    cout << "Enter N: ";
    cin >> N;

    vector<int> col(N, -1);

    if (solveNQueens(0, col, N)) {
        cout << "Solution found:" << endl;

        for (int row = 0; row < N; row++) {
            for (int c = 0; c < N; c++) {
                cout << (col[row] == c ? "Q " : ". ");
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists for N = " << N << endl;
    }

    return 0;
}
