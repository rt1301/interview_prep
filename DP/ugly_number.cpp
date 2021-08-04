/****
 * Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
 * The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. 
 * By convention, 1 is included. Write a program to find Nth Ugly Number.
 ****/
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
class Solution
{
public:
    // #define ull unsigned long long
    /* Function to get the nth ugly number*/
    ull getNthUglyNo(int n)
    {
        // code here
        ull dp[n];
        ull i2 = 0, i3 = 0, i5 = 0;
        ull mul2 = 2, mul3 = 3, mul5 = 5;
        ull next_ugly = 1;
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            next_ugly = min(mul2, min(mul3, mul5));
            dp[i] = next_ugly;
            if (next_ugly == mul2)
            {
                i2++;
                mul2 = dp[i2] * 2;
            }
            if (next_ugly == mul3)
            {
                i3++;
                mul3 = dp[i3] * 3;
            }
            if (next_ugly == mul5)
            {
                i5++;
                mul5 = dp[i5] * 5;
            }
        }

        return next_ugly;
    }
};