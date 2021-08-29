#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string ReFormatString(string S, int K)
    {
        int n = S.length();
        string ans = "";
        int count = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (isalpha(S[i]) || isdigit(S[i]))
            {
                ans.push_back(toupper(S[i]));
                count++;
            }
            if (count == K)
            {
                ans.push_back('-');
                count = 0;
            }
        }
        if (ans.back() == '-')
        {
            ans.erase(ans.size() - 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};