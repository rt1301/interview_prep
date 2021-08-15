/****
 * Given two strings, string1 and string2, the task is to find the smallest 
 * substring in string1 containing all characters of string2 efficiently. 
 ****/
#include<bits/stdc++.h>
using namespace std;
string minWindowSubstr(string s, string t){
    unordered_map<char,int>mp;
    int ans = INT_MAX;
    int count = 0;
    int start = -1;
    int n = s.length();
    int m = t.length();
    for(int k=0;k<m;k++){
        if (mp[t[k]] == 0){
            count++;
        }
        mp[t[k]]++;
    }
    int j=0,i=0;
    while (j<n)
    {
        mp[s[j]]--;
        if(mp[s[j]] == 0){
            count--;
        }
        if(count == 0){
            while (count == 0)
            {
                if(ans>(j-i+1)){
                    ans = j-i+1;
                    start = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    count++;
                }
                i++;
            }
        }
        j++;
    }
    if(ans != INT_MAX){
        return s.substr(start,ans);
    }else{
        return "No such string found";
    }
}
int main(){
    string s;
    string t;
    getline(cin,s);
    cin>>t;
    cout<<minWindowSubstr(s,t);
    return 0;
}