/****
 * Your task  is to implement the function atoi. 
 * The function takes a string(str) as argument and converts it to an integer and returns it.
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int index = 0;
        int ans = 0;
        bool flag = false;
        int n = str.length();
        for (int i = n - 1; i >= 0; i--)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                ans += (pow(10, index) * (str[i] - '0'));
                index++;
            }
            else if (str[i] == '-')
            {
                flag = true;
            }
            else
            {
                return -1;
            }
        }
        if (flag)
        {
            return -ans;
        }
        return ans;
    }
};