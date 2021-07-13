#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[38];
    int tribonacci(int n)
    {
        memset(dp, -1, sizeof(dp));
        return tribHelper(n);
    }
    int loopSoln(int n)
    {
        int t0 = 0, t1 = 1, t2 = 1;
        if (n == 0)
            return t0;
        if (n == 1)
            return t1;
        if (n == 2)
            return t2;
        int t = 0;
        for (int i = 3; i <= n; i++)
        {
            t = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t;
        }
        return t;
    }
    //     DP Based Soln
    int tribHelper(int n)
    {
        if (dp[n] != -1)
            return dp[n];
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        dp[n] = tribHelper(n - 1) + tribHelper(n - 2) + tribHelper(n - 3);
        return dp[n];
    }
};