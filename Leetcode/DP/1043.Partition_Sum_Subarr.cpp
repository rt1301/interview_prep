#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[501];
    int solve(vector<int> &arr, int i, int k)
    {
        if (i >= arr.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int mx = INT_MIN;

        for (int j = i; j < min((int)arr.size(), i + k); j++)
        {
            mx = max(mx, arr[j]);
            dp[i] = max(dp[i], mx * (j - i + 1) + solve(arr, j + 1, k));
        }
        return dp[i];
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        memset(dp, -1, sizeof(dp));
        int ans = solve(arr, 0, k);
        return ans;
    }
};