#include <bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long long int i = 0; i <= sqrt(c); i++)
        {
            double b = sqrt(c - (i * i));
            if (b == (int)b)
            {
                return true;
            }
        }
        return false;
    }
};