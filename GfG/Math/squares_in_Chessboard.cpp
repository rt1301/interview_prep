/****
 * Find total number of Squares in a N*N cheesboard.
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long squaresInChessBoard(long long N)
    {
        // code here
        long long ans = 0;
        ans = N * (N + 1) * (2 * N + 1);
        return ans / 6;
    }
};