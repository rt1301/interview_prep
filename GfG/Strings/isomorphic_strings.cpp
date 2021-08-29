
/***************************
 * #INCLUDE<BITS/STDC++.H> *
 * Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
 * Two strings str1 and str2 are called isomorphic if there is a one to one
 * mapping possible for every character of str1 to every character of str2 
 * while preserving the order.
 ***************************/
using namespace std;
class Solution
{
public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {

        // Your code here
        int n = str1.length();
        int m = str2.length();
        if (n != m)
        {
            return 0;
        }
        int v1[256] = {0};
        int v2[256] = {0};
        for (int i = 0; i < n; i++)
        {
            v1[str1[i]]++;
            v2[str2[i]]++;

            if (v1[str1[i]] != v2[str2[i]])
            {
                return false;
            }
        }
        return true;
    }
};