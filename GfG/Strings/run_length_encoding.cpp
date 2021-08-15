/****
 * Given a string, Your task is to  complete the function encode that returns the run
 * length encoded string for the given string.
 * eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
 ****/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;

        cout << encode(str) << endl;
    }
    return 0;
} // } Driver Code Ends

/*You are required to complete this function */

string encode(string src)
{
    //Your code here
    char c = src[0];
    int count = 1;
    string ans;
    int n = src.length();
    for (int i = 1; i < n; i++)
    {
        if (src[i] == c)
        {
            count++;
        }
        else
        {
            ans.push_back(c);
            ans += (to_string(count));
            count = 1;
            c = src[i];
        }
    }
    ans.push_back(c);
    ans += (to_string(count));
    return ans;
}
