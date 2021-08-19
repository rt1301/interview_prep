#include<bits/stdc++.h>
using namespace std;
string nextTerm(string s)
{
    string res = "";
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length() + 1; i++)
    {
        if (mp.find(s[i]) == mp.end() && i > 0)
        {
            auto prev = mp.find(s[i - 1]);
            res += to_string(prev->second);
            res.push_back(prev->first);
            mp.clear();
        }
        mp[s[i]]++;
    }
    return res;
}
string Solution::countAndSay(int A)
{
    string res = "1";
    for (int i = 1; i < A; i++)
    {
        res = nextTerm(res);
    }
    return res;
}