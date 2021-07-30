#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, h = n / 2;
        sort(nums.begin(), nums.end());
        if (n % 2 == 1)
        {
            h++;
        }
        int i = h;
        l = i - 1;
        h = n - 1;
        vector<int> ans;
        while (true)
        {
            if (l < 0 && h < i)
                break;
            if (l >= 0)
                ans.push_back(nums[l--]);
            if (h >= i)
                ans.push_back(nums[h--]);
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = ans[i];
        }
    }
};