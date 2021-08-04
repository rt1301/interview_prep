#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        int a, b, c;
        int N;
        N = n;
        while (n % 2 == 0)
        {
            n /= 2;
        }
        a = N / n;
        n = N;
        while (n % 3 == 0)
        {
            n /= 3;
        }
        b = N / n;
        n = N;
        while (n % 5 == 0)
        {
            n /= 5;
        }
        c = N / n;
        n = N;
        return (a * b * c) == N;
    }
};