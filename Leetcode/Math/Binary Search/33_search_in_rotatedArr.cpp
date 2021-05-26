#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int m;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            if (nums[l] <= nums[m])
            {
                if (target >= nums[l] && target < nums[m])
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else
            {
                if (target <= nums[r] && target > nums[m])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};