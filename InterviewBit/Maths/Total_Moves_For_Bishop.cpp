#include <bits/stdc++.h>
using namespace std;
int Solution::solve(int A, int B)
{
    int i = A, j = B;
    int n = 8;
    int count = 0;
    while (i <= n && i >= 1 && j <= n && j >= 1)
    {
        i--;
        j++;
        count++;
    }
    i = A, j = B;
    while (i <= n && i >= 1 && j <= n && j >= 1)
    {
        i++;
        j++;
        count++;
    }
    i = A, j = B;
    while (i <= n && i >= 1 && j <= n && j >= 1)
    {
        i++;
        j--;
        count++;
    }
    i = A, j = B;
    while (i <= n && i >= 1 && j <= n && j >= 1)
    {
        i--;
        j--;
        count++;
    }
    return count - 4;
}
