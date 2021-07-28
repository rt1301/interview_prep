#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        map<pair<int, int>, int> mp;
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0], y = points[i][1];
            mp[{x, y}] = (x * x + y * y);
        }
        priority_queue<pair<int, pair<int, int>>> mh;
        vector<vector<int>> ans;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            mh.push({it->second, it->first});
            if (mh.size() > k)
            {
                mh.pop();
            }
        }
        while (!mh.empty())
        {
            vector<int> temp(2);
            temp[0] = mh.top().second.first;
            temp[1] = mh.top().second.second;
            ans.push_back(temp);
            mh.pop();
        }
        return ans;
    }
};