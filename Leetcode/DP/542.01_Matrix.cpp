#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(int i, int j, int n, int m)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        vector<int> col = {-1, 0, 1, 0};
        vector<int> row = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for (int i = 0; i < 4; i++)
            {
                int adjx = x + row[i];
                int adjy = y + col[i];
                if (isPossible(adjx, adjy, n, m))
                {
                    if (ans[adjx][adjy] > (ans[x][y] + 1))
                    {
                        ans[adjx][adjy] = ans[x][y] + 1;
                        q.push({adjx, adjy});
                    }
                }
            }
        }
        return ans;
    }
};