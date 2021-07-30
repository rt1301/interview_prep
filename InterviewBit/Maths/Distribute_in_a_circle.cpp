#include <bits/stdc++.h>
using namespace std;
int Solution::solve(int A, int B, int C)
{
    int index = C;
    while (A != 0)
    {
        index = index % B;
        if (index == 0)
        {
            index = B;
        }
        A--;
        index++;
    }
    return index - 1;
}
