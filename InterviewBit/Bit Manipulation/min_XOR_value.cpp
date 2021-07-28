#include <bits/stdc++.h>
using namespace std;
int Solution::findMinXor(vector<int> &A)
{
    int mn = INT_MAX;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size() - 1; i++)
    {
        int temp = A[i] ^ A[i + 1];
        mn = min(mn, temp);
    }
    return mn;
}
