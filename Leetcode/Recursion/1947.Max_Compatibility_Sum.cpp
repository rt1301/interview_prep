#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        vector<int> pos;
        for (int i = 0; i < students.size(); i++)
            pos.push_back(i);
        int finalAns = 0;
        do
        {
            int ans = 0;
            for (int i = 0; i < students.size(); i++)
            {
                for (int j = 0; j < students[pos[i]].size(); j++)
                {
                    if (students[pos[i]][j] == mentors[i][j])
                        ans++;
                }
            }
            finalAns = max(ans, finalAns);
        } while (next_permutation(pos.begin(), pos.end()));

        return finalAns;
    }
};