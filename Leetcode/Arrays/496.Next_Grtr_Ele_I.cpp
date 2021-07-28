#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        vector<int> v;
        stack<int> s;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; i--)
        {
            mp[nums2[i]] = i;
            if (s.empty())
            {
                v.push_back(-1);
            }
            else if (!s.empty() && s.top() > nums2[i])
            {
                v.push_back(s.top());
            }
            else if (!s.empty() && s.top() < nums2[i])
            {
                while (!s.empty() && s.top() < nums2[i])
                {
                    s.pop();
                }
                if (s.empty())
                    v.push_back(-1);
                else
                    v.push_back(s.top());
            }
            s.push(nums2[i]);
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(v[mp[nums1[i]]]);
        }
        return ans;
    }
};