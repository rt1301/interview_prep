/****
 * Given two strings, the task is to find if a string can 
 * be obtained by rotating another string two places. 
 ****/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    void leftRotate(string &s, int d)
    {
        int n = s.length();
        d = d % n;
        int factor = __gcd(n, d);
        for (int i = 0; i < factor; i++)
        {
            int j = i;
            int temp = s[i];
            while (true)
            {
                int k = j + d;
                if (k >= n)
                {
                    k = k - n;
                }
                if (k == i)
                {
                    break;
                }
                s[j] = s[k];
                j = k;
            }
            s[j] = temp;
        }
    }
    void rightRotate(string &s, int d)
    {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + d);
        reverse(s.begin() + d, s.end());
    }
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if (str1.length() != str2.length())
        {
            return false;
        }
        string a = str1, b = str1;
        leftRotate(a, 2);
        rightRotate(b, 2);
        if (a == str2 || b == str2)
        {
            return true;
        }
        else
        {
            return false;
        }
        return false;
    }
};