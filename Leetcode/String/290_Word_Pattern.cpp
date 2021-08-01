#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        vector<string> v;
        for (int i = 0; i < s.length(); i++)
        {
            string temp;
            while (i < s.length() && s[i] != ' ')
            {
                temp.push_back(s[i]);
                i++;
            }
            v.push_back(temp);
        }
        if (pattern.size() != v.size())
            return false;
        for (int i = 0; i < v.size(); i++)
        {
            if (mp2[v[i]] == 0 && mp1[pattern[i]] == "")
            {
                mp2[v[i]] = pattern[i];
                mp1[pattern[i]] = v[i];
            }
            else if (v[i] != mp1[pattern[i]] || pattern[i] != mp2[v[i]])
                return false;
        }
        return true;
    }
};