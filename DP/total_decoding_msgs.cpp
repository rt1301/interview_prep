/****
 * A top secret message containing letters from A-Z is being encoded 
 * to numbers using the following mapping:
 * A -> 1
 * B-> 2
 * .... Z ->26
 * You are an FBI agent. You have to determine the total number of 
 * ways that message can be decoded.
 ****/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Recursive Approach
    int mod = 1e9 + 7;
    int solve(string s, int n)
    {
        int dp[n + 5];
        dp[0] = 1;
        dp[1] = 1;
        if (s[0] == '0')
            return 0;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = 0;
            if (s[i - 1] > '0')
            {
                dp[i] = dp[i - 1] % mod;
            }
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
            {
                dp[i] = (dp[i] + dp[i - 2]) % mod;
            }
        }

        return dp[n] % mod;
    }
    int CountWays(string str)
    {
        // Code here
        int n = str.length();
        return solve(str, n);
    }
};