#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string mostCommonWord(string para, vector<string> &banned)
    {
        unordered_map<string, int> mp;
        int n = para.length();
        for (int i = 0; i < n; i++)
        {
            string temp;
            while (i < n && isalpha(para[i]) != 0)
            {
                temp.push_back(tolower(para[i]));
                i++;
            }
            if (!temp.empty())
            {
                mp[temp]++;
            }
        }
        for (int i = 0; i < banned.size(); i++)
        {
            if (mp.find(banned[i]) != mp.end())
            {
                mp.erase(banned[i]);
            }
        }
        string ans;
        int mx = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second > mx)
            {
                mx = it->second;
                ans = it->first;
            }
        }
        return ans;
    }
};