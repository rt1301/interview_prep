/****
 * Given an array A[] of size N and a positive integer K, find the 
 * first negative integer for each and every window(contiguous subarray) of size K.
 ****/
#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    vector<long long> ans;
    int i = 0, j = 0;
    queue<long long> q;
    while (j < N)
    {
        if (A[j] < 0)
        {
            q.push(A[j]);
        }
        if ((j - i + 1) < K)
        {
            j++;
        }
        else if ((j - i + 1) == K)
        {
            if (!q.empty())
            {
                ans.push_back(q.front());
                if (A[i] == q.front())
                {
                    q.pop();
                }
            }
            else
            {
                ans.push_back(0);
            }
            i++;
            j++;
        }
    }
    return ans;
}