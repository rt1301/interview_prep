#include<bits/stdc++.h>
using namespace std;
// Solution 1 - using Hash maps O(n) complexity
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (m[nums[i]])
            {
                m[nums[i]]++;
            }
            else
            {
                m[nums[i]] = 1;
            }
        }
        for (auto i = m.begin(); i != m.end(); i++)
        {
            if (i->second > n / 2)
            {
                return i->first;
            }
        }
        return -1;
    }
};

// Solution 2 - Sorting the array O(nlogn) complexity
// sort(nums.begin(),nums.end());
// return nums[nums.size()/2];