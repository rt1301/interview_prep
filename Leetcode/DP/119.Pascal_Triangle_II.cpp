#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> pascal(rowIndex + 1);
        pascal[0] = {1};
        for (int i = 1; i <= rowIndex; i++)
        {
            pascal[i] = vector<int>(i + 1);
            pascal[i][0] = 1;
            pascal[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
        return pascal[rowIndex];
    }
};