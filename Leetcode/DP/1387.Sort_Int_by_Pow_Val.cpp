#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int inf = 1e6 + 5;
    vector<int> dp;
    int getPower(int x)
    {
        if (dp[x] != -1)
        {
            return dp[x];
        }
        if (x == 1)
        {
            return 0;
        }
        int p = 0;
        if (x % 2 == 0)
        {
            if (dp[x / 2] != -1)
            {
                p = 1 + dp[x / 2];
            }
            else
            {
                p = 1 + getPower(x / 2);
            }
        }
        else
        {
            if (dp[3 * x + 1] != -1)
            {
                p = 1 + dp[3 * x + 1];
            }
            else
            {
                p = 1 + getPower(3 * x + 1);
            }
        }
        return dp[x] = p;
    }
    bool compare(int a, int b)
    {
        int p1 = getPower(a);
        int p2 = getPower(b);
        if (p1 == p2)
        {
            return a < b;
        }
        else
        {
            return p1 < p2;
        }
    }
    int getKth(int lo, int hi, int k)
    {
        dp = vector<int>(inf, -1);
        vector<int> arr;
        for (int i = lo; i <= hi; i++)
        {
            arr.push_back(i);
        }
        sort(arr.begin(), arr.end(), [this](int a, int b)
             { return compare(a, b); });
        return arr[k - 1];
    }
};