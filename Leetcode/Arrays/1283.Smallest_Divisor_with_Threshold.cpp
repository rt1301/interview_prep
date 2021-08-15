#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getSum(vector<int> nums, int div)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += (ceil(double(nums[i]) / div));
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int mxEl = *max_element(nums.begin(), nums.end());
        int sum = 0;
        int l = 1;
        int r = mxEl;
        int m = 0;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            sum = getSum(nums, m);
            if (sum > threshold)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return l;
    }
};