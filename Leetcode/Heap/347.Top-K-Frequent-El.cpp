#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        priority_queue<pp, vector<pp>, greater<pp>> minH;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            minH.push({it->second, it->first});
            if (minH.size() > k)
                minH.pop();
        }
        vector<int> ans;
        while (!minH.empty())
        {
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};