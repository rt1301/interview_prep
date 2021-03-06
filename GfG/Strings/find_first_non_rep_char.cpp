/****
 * Given a string, find the first non-repeating character in it. 
 * For example, if the input string is “GeeksforGeeks”, then the output 
 * should be ‘f’ and if the input string is “GeeksQuiz”, then the output should be ‘G’. 
 ****/
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map<char,int>mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }
    for(int i=0;i<s.length();i++){
        if(mp[s[i]] == 1){
            cout<<s[i];
            break;
        }
    }
    return 0;
}