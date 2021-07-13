#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        int h = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (citations[i] >= i + 1)
            {
                h = i + 1;
                break;
            }
        }
        return h;
    }
};