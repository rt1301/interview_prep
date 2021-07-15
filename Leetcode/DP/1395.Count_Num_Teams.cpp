#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        int count = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int leftGreater = 0, leftLess = 0, rightGreater = 0, rightLess = 0;
            for (int j = 0; j < i; j++)
            {
                if (rating[j] > rating[i])
                {
                    leftGreater++;
                }
                else
                {
                    leftLess++;
                }
            }
            for (int j = i + 1; j < n; j++)
            {
                if (rating[j] > rating[i])
                {
                    rightGreater++;
                }
                else
                {
                    rightLess++;
                }
            }

            count += (leftLess * rightGreater + leftGreater * rightLess);
        }
        return count;
    }
};