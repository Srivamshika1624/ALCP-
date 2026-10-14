#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<vector<int>> maze;
vector<vector<bool>> visited;
vector<string> allPaths;

void findPaths(int r, int c, string &path) {
    if (r == n - 1 && c == n - 1) {
        allPaths.push_back(path);
        return;
    }

    visited[r][c] = true;

    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, -1, 1, 0};
    char move[] = {'D', 'L', 'R', 'U'};

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
            maze[nr][nc] == 1 && !visited[nr][nc]) {
            path.push_back(move[k]);
            findPaths(nr, nc, path);
            path.pop_back();
        }
    }

    visited[r][c] = false;
}

int main() {
    cin >> n;

    if (n <= 0) {
        cout << "Invalid maze size." << endl;
        return 0;
    }

    maze.assign(n, vector<int>(n));
    visited.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    string path = "";

    if (maze[0][0] == 1 && maze[n - 1][n - 1] == 1) {
        findPaths(0, 0, path);
    }

    if (allPaths.empty()) {
        cout << "No path exists." << endl;
    } else {
        cout << "Number of paths: " << allPaths.size() << endl;

        for (const string &p : allPaths) {
            cout << p << endl;
        }
    }

    return 0;
}

