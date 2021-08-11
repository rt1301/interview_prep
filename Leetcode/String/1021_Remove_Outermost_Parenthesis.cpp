#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int count = 0;
        string ans = "";
        for (char ch : s)
        {
            if (count == 0 && ch == '(')
            {
                count++;
            }
            else if (count != 0 && ch == '(')
            {
                count++;
                ans += ch;
            }
            else if (count == 1 && ch == ')')
            {
                count--;
            }
            else if (count > 1 && ch == ')')
            {
                count--;
                ans += ch;
            }
        }
        return ans;
    }
};