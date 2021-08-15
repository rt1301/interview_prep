/****
 * A number n can be broken into three parts n/2, n/3 and n/4 
 * (consider only integer part). Each number obtained in this process can be 
 * divided further recursively. Find the maximum sum that can be obtained by 
 * summing up the divided parts together.
 * Note: The maximum sum may be obtained without dividing n also.
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int dp[], int sz, int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = max(n, solve(dp, sz, n / 2) + solve(dp, sz, n / 3) + solve(dp, sz, n / 4));
    }
    int maxSum(int n)
    {
        //code here.
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        // dp[0] = 0;
        return solve(dp, n, n);
    }
};