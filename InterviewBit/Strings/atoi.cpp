#include<bits/stdc++.h>
using namespace std;
int Solution::atoi(const string A)
{
    long long int sum = 0;
    bool flag = 0;
    int i = 0;
    if (A[0] == '-')
        flag = 1, i++;
    else if (A[0] == '+')
        i++;
    for (; i < A.size(); i++)
    {

        if (A[i] >= '0' && A[i] <= '9')
            sum = sum * 10 + A[i] - '0';
        else
            break;

        if (sum > INT_MAX)
            return flag == 1 ? INT_MIN : INT_MAX;
    }
    if (flag)
        return -1 * (int)sum;
    else
        return (int)sum;
}
