#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    set<long long> s;
    int nthUglyNumber(int n)
    {
        if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5)
            return n;
        s.insert(1);
        n--;
        while (n--)
        {
            auto it = s.begin();
            long long x = *it;
            s.erase(it);
            s.insert(x * 2);
            s.insert(x * 3);
            s.insert(x * 5);
        }
        return *s.begin();
    }
};