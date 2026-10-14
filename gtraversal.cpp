#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void DFS(int v, vector<vector<int>>& a, vector<bool>& vis)
{
    vis[v] = true;
    cout << v << " ";
    for(int x : a[v])
        if(!vis[x])
            DFS(x, a, vis);
}
void BFS(int s, vector<vector<int>>& a, vector<bool>& vis)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int x : a[v])
            if(!vis[x])
            {
                vis[x] = true;
                q.push(x);
            }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<bool> vis(n, false);
    cout << "DFS: ";
    for(int i = 0; i < n; i++)
        if(!vis[i])
            DFS(i, a, vis);
    vis.assign(n, false);
    cout << "\nBFS: ";
    for(int i = 0; i < n; i++)
        if(!vis[i])
            BFS(i, a, vis);
}