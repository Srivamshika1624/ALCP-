#include <iostream>
using namespace std;

int graph[20][20], visited[20], n;

bool DFS(int v, int parent) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1) {
            if (!visited[i]) {
                if (DFS(i, v))
                    return true;
            }
            else if (i != parent) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    if (DFS(0, -1))
        cout << "Cycle exists";
    else
        cout << "No cycle";

    return 0;
}
