#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countBits(int n)
    {
        int count = 0;
        while (n != 0)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    int hammingDistance(int x, int y)
    {
        int hm = x ^ y;
        return countBits(hm);
    }
};