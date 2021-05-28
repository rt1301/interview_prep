#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        //         Binary Search
        int l = 0;
        int r = nums.size() - 1;
        int m;
        int first = -1, last = -1;
        //         1st BS
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (nums[m] < target)
                l = m + 1;
            else if (nums[m] > target)
                r = m - 1;
            else
            {
                first = m;
                r = m - 1;
            }
        }
        //         2nd BS
        l = 0;
        r = nums.size() - 1;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else if (nums[m] > target)
            {
                r = m - 1;
            }
            else
            {
                last = m;
                l = m + 1;
            }
        }
        //         Linear Search
        // for(int i=0;i<(int)nums.size();i++){
        //     if(nums[i] == target){
        //         ans.push_back(i);
        //         break;
        //     }
        // }
        // for(int i=(int)nums.size()-1;i>=0;i--){
        //     if(nums[i] == target){
        //         ans.push_back(i);
        //         break;
        //     }
        // }
        ans.push_back(first);
        ans.push_back(last);
        if (ans.size() > 0)
        {
            return ans;
        }
        else
        {
            return {-1, -1};
        }
    }
};