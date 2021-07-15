#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSquares(vector<vector<int>> &mt)
    {
        int n = mt.size();
        int m = mt[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        int squareCount = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = mt[i][0];
        }
        for (int j = 0; j < m; j++)
        {
            dp[0][j] = mt[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (mt[i][j])
                {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                squareCount += dp[i][j];
            }
        }
        return squareCount;
    }
};