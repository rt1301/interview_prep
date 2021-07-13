#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<string> &v, string op, int open, int close)
    {
        if (open == 0 && close == 0)
        {
            v.push_back(op);
            return;
        }
        if (open != 0)
        {
            string op1 = op;
            op1.push_back('(');
            solve(v, op1, open - 1, close);
        }
        if (close > open)
        {
            string op2 = op;
            op2.push_back(')');
            solve(v, op2, open, close - 1);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        string op = "";
        int open = n;
        int close = n;
        solve(v, op, open, close);
        return v;
    }
};