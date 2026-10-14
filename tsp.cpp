#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int firstMin(vector<vector<int>> &adj, int i, int n) {
    int minValue = INT_MAX;

    for (int k = 0; k < n; k++) {
        if (i != k && adj[i][k] < minValue)
            minValue = adj[i][k];
    }

    return minValue;
}

int secondMin(vector<vector<int>> &adj, int i, int n) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (int j = 0; j < n; j++) {
        if (i == j)
            continue;

        if (adj[i][j] < first) {
            second = first;
            first = adj[i][j];
        } else if (adj[i][j] < second) {
            second = adj[i][j];
        }
    }

    return second;
}

void TSPRec(vector<vector<int>> &adj, int curr_bound,
            int curr_weight, int level, int *curr_path,
            vector<bool> &visited, int &final_res, int n,
            vector<int> &best_path) {
    if (level == n) {
        if (adj[curr_path[level - 1]][curr_path[0]] != 0) {
            int curr_res = curr_weight +
                           adj[curr_path[level - 1]][curr_path[0]];

            if (curr_res < final_res) {
                final_res = curr_res;
                best_path.assign(curr_path, curr_path + n);
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (adj[curr_path[level - 1]][i] != 0 && !visited[i]) {
            int temp = curr_bound;
            curr_weight += adj[curr_path[level - 1]][i];

            if (level == 1) {
                curr_bound -=
                    (firstMin(adj, curr_path[level - 1], n) +
                     firstMin(adj, i, n)) / 2;
            } else {
                curr_bound -=
                    (secondMin(adj, curr_path[level - 1], n) +
                     firstMin(adj, i, n)) / 2;
            }

            if (curr_bound + curr_weight < final_res) {
                curr_path[level] = i;
                visited[i] = true;

                TSPRec(adj, curr_bound, curr_weight, level + 1,
                       curr_path, visited, final_res, n, best_path);
            }

            curr_weight -= adj[curr_path[level - 1]][i];
            curr_bound = temp;

            fill(visited.begin(), visited.end(), false);

            for (int j = 0; j < level; j++)
                visited[curr_path[j]] = true;
        }
    }
}

void TSP(vector<vector<int>> &adj, int n) {
    int curr_bound = 0;
    int *curr_path = new int[n];
    vector<bool> visited(n, false);
    vector<int> best_path;
    int final_res = INT_MAX;

    for (int i = 0; i < n; i++) {
        curr_bound += firstMin(adj, i, n) +
                      secondMin(adj, i, n);
    }

    curr_bound = (curr_bound + 1) / 2;

    fill(curr_path, curr_path + n, -1);

    curr_path[0] = 0;
    visited[0] = true;

    TSPRec(adj, curr_bound, 0, 1, curr_path, visited,
           final_res, n, best_path);

    if (final_res == INT_MAX) {
        cout << "No Hamiltonian cycle exists." << endl;
    } else {
        cout << "Minimum cost: " << final_res << endl;
        cout << "Path: ";

        for (int i = 0; i < n; i++)
            cout << best_path[i] << " ";

        cout << best_path[0] << endl;
    }

    delete[] curr_path;
}

int main() {
    int n;
    cin >> n;

    if (n < 2) {
        cout << "Enter at least 2 vertices." << endl;
        return 0;
    }

    vector<vector<int>> adj(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    TSP(adj, n);

    return 0;
}