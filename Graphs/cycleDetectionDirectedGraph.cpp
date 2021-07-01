#include <bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &stack)
{
    stack[src] = true;
    if (!vis[src])
    {
        vis[src] = true;
        for (auto i : adj[src])
        {
            if (!vis[i] && isCycle(i, adj, vis, stack))
            {
                return true;
            }
            if (stack[i])
            {
                return true;
            }
        }
    }
    stack[src] = false;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    bool cycle = false;
    vector<bool> visited(n, 0);
    vector<bool> stack(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && isCycle(i, adj, visited, stack))
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "Cycle Exists";
    }
    else
    {
        cout << "Cycle doesn't exist";
    }
    return 0;
}