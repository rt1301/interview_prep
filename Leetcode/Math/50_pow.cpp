#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return (double)1;
        double temp = myPow(x, abs(n) / 2);
        if (n > 0)
        {
            if (n % 2 == 0)
                return temp * temp;
            else
                return temp * temp * x;
        }
        else
        {
            if (abs(n) % 2 == 0)
                return 1 / (temp * temp);
            else
                return 1 / (temp * temp * x);
        }
    }
};