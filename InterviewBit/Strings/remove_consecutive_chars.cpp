#include<bits/stdc++.h>
using namespace std;
string Solution::solve(string A, int B)
{
    int st = 0;
    int i = 0;
    string res = "";
    while (i < A.size())
    {
        st = i;
        while (st < (A.size() - 1) && A[st] == A[st + 1])
        {
            st++;
        }
        if (st - i + 1 != B)
        {
            res += A.substr(st, st - i + 1);
        }
        i = st + 1;
    }
    return res;
}