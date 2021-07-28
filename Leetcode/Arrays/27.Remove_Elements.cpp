#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0;
        int index = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == val)
                count++;
        }
        int k = n - count;
        while (count != 0 && !nums.empty())
        {
            if (nums[index] == val)
            {
                count--;
                nums.erase(nums.begin() + index);
            }
            else
            {
                index++;
            }
        }
        return k;
    }
};