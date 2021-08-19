/****
 * Given a binary string S. The task is to count the number of substrings 
 * that start and end with 1. For example, if the input string is “00100101”, 
 * then there are three substrings “1001”, “100101” and “101”.
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a)
    {

        // Your code here
        long count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                count++;
            }
        }
        return (count * (count - 1)) / 2;
    }
};