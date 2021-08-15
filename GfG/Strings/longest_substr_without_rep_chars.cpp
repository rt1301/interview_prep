/****
 * Given a string str, find the length of the longest substring without repeating characters.
 * For “ABDEFGABEF”, the longest substring are “BDEFGA” and “DEFGAB”, with length 6.
 ****/
#include<bits/stdc++.h>
using namespace std;
int solve(string s){
    int n = s.length();
    unordered_map<char,int>mp;
    int i=0,j=0;
    int mxLen = 0;
    while (j<n)
    {
        if(mp.find(s[j]) == mp.end()){
            mp[s[j]]++;
            j++;
            int len = j-i+1;
            mxLen = max(mxLen,len);
        }else{
            mp[s[j]]++;
            while(mp[s[j]] != 1){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            mxLen = max(mxLen,j-i+1);
            j++;
        }
    }
    return mxLen-1;
}
int main(){
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}