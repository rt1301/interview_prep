#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        string st = strs[0];
        string ans = "";
        for (int i = 0; i < st.length(); i++)
        {
            bool flag = false;
            for (int j = 0; j < strs.size(); j++)
            {
                if (st[i] == strs[j][i])
                {
                    flag = true;
                }
                else
                {
                    return ans;
                }
            }
            if (flag)
            {
                ans.push_back(st[i]);
            }
        }
        return ans;
    }
};