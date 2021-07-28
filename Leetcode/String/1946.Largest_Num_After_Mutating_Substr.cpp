#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string maximumNumber(string num, vector<int> &change)
    {
        bool isChange = false;
        for (char &c : num)
        {
            int before = c - '0';
            int after = change[before];
            if (after < before)
            {
                if (isChange)
                    break;
                continue;
            }
            else if (after == before)
                continue;
            else
            {
                isChange = true;
                c = '0' + after;
            }
        }
        return num;
    }
};