#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[1001][3];
    int solve(int f, int e)
    {
        if (f <= 1)
            return f;
        if (e == 1)
            return f;
        if (dp[f][e] != -1)
        {
            return dp[f][e];
        }
        int ans = INT_MAX;
        for (int k = 1; k <= f; k++)
        {
            int l = 0, h = 0;
            if (dp[f - k][e] != -1)
            {
                l = dp[f - k][e];
            }
            else
            {
                l = solve(f - k, e);
            }
            if (dp[k - 1][e - 1] != -1)
            {
                h = dp[k - 1][e - 1];
            }
            else
            {
                h = solve(k - 1, e - 1);
            }
            int temp = 1 + max(l, h);
            ans = min(ans, temp);
        }
        return dp[f][e] = ans;
    }
    int twoEggDrop(int n)
    {
        int e = 2;
        memset(dp, -1, sizeof(dp));
        int ans = solve(n, e);
        return ans;
    }
};