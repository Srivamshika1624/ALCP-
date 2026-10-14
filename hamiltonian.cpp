#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, vector<vector<int>> &graph, vector<int> &path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    return true;
}

bool hamiltonianCycle(int pos, vector<vector<int>> &graph, vector<int> &path, int n) {
    if (pos == n)
        return graph[path[n - 1]][path[0]] == 1;

    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianCycle(pos + 1, graph, path, n))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the " << n << "x" << n << " adjacency matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> path(n, -1);
    path[0] = 0;

    if (hamiltonianCycle(1, graph, path, n)) {
        cout << "Hamiltonian cycle: ";

        for (int i = 0; i < n; i++)
            cout << path[i] << " ";

        cout << path[0] << endl;
    } else {
        cout << "No Hamiltonian cycle exists." << endl;
    }

    return 0;
}

