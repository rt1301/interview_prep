/****
 * Given binary string str of 0’s and 1’s only. The task is to count the total 
 * numbers of substrings of string str such that each substring has an equal 
 * number of consecutive 0’s and 1’s in it.
 ****/
#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    int n = s.length();
    int i = 0,ans=0;
    while (i<n)
    {
        // If the substring is of the type "01"
        int cnt0=0,cnt1=0;
        if(s[i] == '0'){
            while (i<n && s[i] == '0')
            {
                cnt0++;
                i++;
            }

            int j = i;

            while (j<n && s[j] == '1')
            {
                cnt1++;
                j++;
            }
            
        }else{
            // If the substring is of the type "10"
            while (i<n && s[i] == '1')
            {
                cnt0++;
                i++;
            }
            int j = i;
            while (j<n && s[j] == '0')
            {
                cnt1++;
                j++;
            }
        }
        ans+=min(cnt0,cnt1);
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}