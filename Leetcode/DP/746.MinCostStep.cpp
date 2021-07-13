#include <bits/stdc++.h>
using namespace std;
// Memoization based soln
int dp[1001];
int helper(vector<int> cost, int n)
{
    if (n == 1 || n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = min(cost[n - 1] + helper(cost, n - 1), cost[n - 2] + helper(cost, n - 2));
    return dp[n];
}

// Tabulation based soln
class Solution
{
public:
    //     Tabulation soln
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int t[n + 1];
        t[0] = t[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            t[i] = min(cost[i - 1] + t[i - 1], cost[i - 2] + t[i - 2]);
        }
        return t[n];
    }
};