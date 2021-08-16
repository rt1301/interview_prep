#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &v, int d)
    {
        int n = v.size();
        d = d % n;
        int gcd = __gcd(d, n);
        for (int i = 0; i < gcd; i++)
        {
            int temp = v[i];
            int j = i;
            while (true)
            {
                int k = j - d;
                if (k < 0)
                {
                    k = n + k;
                }
                if (k == i)
                {
                    break;
                }
                v[j] = v[k];
                j = k;
            }
            v[j] = temp;
        }
    }
};