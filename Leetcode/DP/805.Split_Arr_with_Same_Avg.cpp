#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(int m, int sum, int n)
    {
        bool possible = false;
        for (int i = 1; i <= m; i++)
        {
            if ((i * sum) % n == 0)
            {
                possible = true;
                break;
            }
        }
        return possible;
    }
    bool splitArraySameAverage(vector<int> &nums)
    {
        int n = nums.size();
        int m = n / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (!isPossible(m, sum, n))
            return false;
        vector<unordered_set<int>> dp(m + 1);
        dp[0].insert(0);
        for (int num : nums)
        {
            for (int t = m; t >= 1; t--)
            {
                for (auto it : dp[t - 1])
                {
                    dp[t].insert(it + num);
                }
            }
        }

        for (int i = 1; i <= m; i++)
        {
            if ((sum * i) % n == 0 && dp[i].count((i * sum) / n))
            {
                return true;
            }
        }
        return false;
    }
};