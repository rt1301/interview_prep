#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> dist;
    int ans = 0;
    int inf = 1e9;
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int m = times.size();
        adj = vector<vector<pair<int, int>>>(n + 1);
        dist = vector<int>(n + 1, inf);
        for (int i = 0; i < m; i++)
        {
            int u = times[i][0], v = times[i][1], w = times[i][2];
            adj[v].push_back({u, w});
        }
        dist[k] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (auto e : times)
            {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == inf)
                return -1;
            ans = max(dist[i], ans);
        }
        return ans;
    }
};