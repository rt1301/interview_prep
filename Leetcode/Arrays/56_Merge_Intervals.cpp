#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        if (intervals.size() == 0)
        {
            return ans;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tempInt = intervals[0];
        for (auto it : intervals)
        {
            if (it[0] <= tempInt[1])
            {
                tempInt[1] = max(tempInt[1], it[1]);
            }
            else
            {
                ans.push_back(tempInt);
                tempInt = it;
            }
        }

        ans.push_back(tempInt);
        return ans;
    }
};