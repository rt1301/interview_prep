// Kadane's Algorithm
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkAllNeg(vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] > 0)
                return false;
        }
        return true;
    }
    int maxSubArray(vector<int> &nums)
    {
        if (checkAllNeg(nums))
        {
            return *max_element(nums.begin(), nums.end());
        }
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int curr = 0;
        int mx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            curr += nums[i];
            if (curr < 0)
                curr = 0;
            mx = max(mx, curr);
        }
        return mx;
    }
};