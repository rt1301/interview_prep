#include <bits/stdc++.h>
using namespace std;
int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size();
    int red = A[0][0];
    int blue = A[0][1];
    int green = A[0][2];

    for (int i = 1; i < n; ++i)
    {
        int newred = min(blue, green) + A[i][0];
        int newblue = min(red, green) + A[i][1];
        int newgreen = min(blue, red) + A[i][2];

        red = newred;
        blue = newblue;
        green = newgreen;
    }

    return min(min(red, blue), green);
}
