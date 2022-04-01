#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        unordered_map<int, pair<char, int>> mp1, mp2;
        int n = name.length();
        int m = typed.length();
        if (m < n)
        {
            return false;
        }
        if (n == 1 && m == 1)
        {
            if (name[0] != typed[0])
                return false;
            else
                return true;
        }
        char c = name[0];
        int count = 1;
        int index = 0;
        for (int i = 1; i < (int)name.length(); i++)
        {
            while (i < (int)name.length() && name[i] == c)
            {
                count++;
                i++;
            }
            mp1[index] = {c, count};
            count = 1;
            c = name[i];
            index++;
        }
        char last = name.back();
        if (n > 1)
        {
            if (mp1[index - 1].first == last)
            {
                mp1[index - 1].second++;
            }
            else
            {
                mp1[index] = {last, count};
            }
        }
        if (mp1.empty())
        {
            mp1[index] = {c, count};
        }
        c = typed[0];
        count = 1;
        index = 0;
        for (int i = 1; i < (int)typed.length(); i++)
        {
            while (i < (int)typed.length() && typed[i] == c)
            {
                count++;
                i++;
            }
            mp2[index] = {c, count};
            count = 1;
            c = typed[i];
            index++;
        }
        last = typed.back();
        if (m > 1)
        {
            if (mp2[index - 1].first == last)
            {
                mp2[index - 1].second++;
            }
            else
            {
                mp2[index] = {last, count};
            }
        }
        if (mp2.empty())
        {
            mp2[index] = {c, count};
        }
        if (mp1.size() != mp2.size())
        {
            return false;
        }
        for (auto it : mp1)
        {
            int i = it.first;
            char ch = it.second.first;
            int ct = it.second.second;
            if (mp2.find(i) == mp2.end())
            {
                return false;
            }
            if (mp2[i].first != ch || mp2[i].second < ct)
            {
                return false;
            }
        }
        return true;
    }
};