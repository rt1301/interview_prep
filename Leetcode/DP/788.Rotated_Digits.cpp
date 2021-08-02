#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rotatedDigits(int n)
    {
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        int count = 0;
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int a = i % 10;
            int b = i / 10;

            if (a == 2 || a == 5 || a == 6 || a == 9)
                dp[a] = 1;

            if (a == 1 || a == 0 || a == 8)
                dp[a] = 0;

            if (a == 3 || a == 4 || a == 7)
            {
                dp[a] = -1;
                continue;
            }

            if (dp[b] == -1)
                continue;

            if (dp[a] == 1 || dp[b] == 1)
            {
                count++;
                dp[i] = 1;
            }
            else
                dp[i] = 0;
        }
        return count;
    }
};

// Non-DP Solution
class Solution
{
public:
    unordered_map<int, int> order;
    bool isGood(int x)
    {
        int ans = 0;
        int temp = x;
        int i = 0;
        while (x != 0)
        {
            int rem = x % 10;
            if (order[rem] == -1)
                return false;
            ans += (pow(10, i) * order[rem]);
            i++;
            x /= 10;
        }
        if (ans != temp)
            return true;
        else
            return false;
    }
    int rotatedDigits(int n)
    {
        order[0] = 0;
        order[1] = 1;
        order[2] = 5;
        order[5] = 2;
        order[6] = 9;
        order[9] = 6;
        order[8] = 8;
        order[3] = -1;
        order[4] = -1;
        order[7] = -1;
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (isGood(i))
            {
                count++;
            }
        }
        return count;
    }
};