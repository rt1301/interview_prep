#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubsets(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= sum; i++)
        {
            dp[0][sum] = 0;
        }
        for (int j = 0; j <= n; j++)
        {
            dp[j][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] == 0)
                {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int totalSum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
            if (nums[i] == 0)
            {
                count++;
            }
        }
        if ((totalSum + target) % 2 != 0)
        {
            return 0;
        }
        int s = (totalSum + target) / 2;
        int ans = countSubsets(nums, s) * pow(2, count);
        return ans;
    }
};