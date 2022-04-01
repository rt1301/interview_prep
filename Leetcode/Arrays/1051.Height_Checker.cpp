#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int ans = 0;
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        if (heights == expected)
        {
            return 0;
        }
        for (int i = 0; i < (int)heights.size(); i++)
        {
            if (heights[i] != expected[i])
            {
                ans++;
            }
        }
        return ans;
    }
};