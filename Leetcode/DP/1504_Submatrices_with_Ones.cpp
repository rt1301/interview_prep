#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> arr(r, vector<int>(c));
        int sum = 0;
        for (int i = 0; i < r; i++)
        {
            int count = 0;
            for (int j = c - 1; j >= 0; j--)
            {
                if (mat[i][j] == 0)
                {
                    count = 0;
                }
                else
                {
                    count++;
                }
                arr[i][j] = count;
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                // cout<<arr[i][j]<<" ";
                int mn = INT_MAX;

                for (int k = i; k < r; k++)
                {
                    mn = min(mn, arr[k][j]);
                    sum += mn;
                }
            }
            // cout<<endl;
        }
        return sum;
    }
};