#include <bits/stdc++.h>
using namespace std;
int inf = 1e9;
void djikstra(vector<vector<pair<int, int>>> adj, vector<int> &d, int src)
{
    d[src] = 0;
    set<pair<int, int>> s;
    s.insert({0, src});
    while (!s.empty())
    {
        auto x = *s.begin();
        s.erase(x);
        for (auto it : adj[x.second])
        {
            if (d[it.first] > d[x.second] + it.second)
            {
                s.erase({d[it.first], it.first});
                d[it.first] = d[x.second] + it.second;
                s.insert({d[it.first], it.first});
            }
        }
    }
}
int Solution::solve(int A, vector<vector<int>> &B, int C, int D, vector<vector<int>> &E)
{
    int n = B.size();
    int extra = E.size();
    vector<vector<pair<int, int>>> adj(A + 1);
    for (int i = 0; i < B.size(); i++)
    {
        adj[B[i][0]].push_back({B[i][1], B[i][2]});
        adj[B[i][1]].push_back({B[i][0], B[i][2]});
    }
    vector<int> ds(A + 1, inf);
    vector<int> de(A + 1, inf);
    ds[C] = 0;
    de[D] = 0;
    djikstra(adj, ds, C);
    djikstra(adj, de, D);
    int ans = ds[D];
    for (int i = 0; i < extra; i++)
    {
        int dist = ds[E[i][0]] + de[E[i][1]] + E[i][2];
        int dist1 = ds[E[i][1]] + de[E[i][0]] + E[i][2];
        ans = min(ans, min(dist, dist1));
    }
    if (ans == inf)
        return -1;
    else
        return ans;
}
