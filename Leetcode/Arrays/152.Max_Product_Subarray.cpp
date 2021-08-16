#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int mx = nums[0];
        int mn = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++)
        {
            int temp_max = max(mx * nums[i], max(nums[i], nums[i] * mn));
            mn = min(mx * nums[i], min(nums[i], nums[i] * mn));
            mx = temp_max;
            res = max(res, mx);
        }
        return res;
    }
};