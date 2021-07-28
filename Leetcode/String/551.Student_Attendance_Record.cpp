#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkRecord(string s)
    {
        int count = 0;
        int flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                count++;
            }
            if (count >= 2)
                return false;
            if (s[i] == 'L')
            {
                flag++;
            }
            else
            {
                flag = 0;
            }
            if (flag >= 3)
            {
                return false;
            }
        }
        return true;
    }
};