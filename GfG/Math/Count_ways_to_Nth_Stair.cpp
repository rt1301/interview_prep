/****
 * There are N stairs, and a person standing at the bottom wants to reach 
 * the top. The person can climb either 1 stair or 2 stairs at a time. 
 * Count the number of ways, the person can reach the top (order does not matter).
 ****/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nthStair(int n)
    {
        return 1 + n / 2;
    }
};