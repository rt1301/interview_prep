#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix[0].size();
        vector<vector<int>> sum(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            sum[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                {
                    sum[i][j] = matrix[i][j] + min(sum[i - 1][j], sum[i - 1][j + 1]);
                }
                else if (j == n - 1)
                {
                    sum[i][j] = matrix[i][j] + min(sum[i - 1][j], sum[i - 1][j - 1]);
                }
                else
                {
                    sum[i][j] = matrix[i][j] + min({sum[i - 1][j], sum[i - 1][j - 1], sum[i - 1][j + 1]});
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, sum[n - 1][i]);
        }
        return ans;
    }
};