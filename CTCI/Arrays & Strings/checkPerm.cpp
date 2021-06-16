/****
 * Given two strings
 * Check if one is a permuation of the other
 ****/
#include<bits/stdc++.h>
using namespace std;

bool checkPermuation(string s1, string s2){
    unordered_map<char,int>mp;
    if(s1.length() != s2.length()) return false;
    for(int i=0;i<s1.length();i++){
        if(mp[s1[i]]){
            mp[s1[i]]++;
        }else mp[s1[i]] = 1;
    }
    for(int i=0;i<s2.length();i++){
        if(mp.find(s2[i]) == mp.end()){
            return false;
        }else{
            mp[s2[i]]--;
        }
        if(mp[s2[i]]<0) return false;
    }
    return true;
}

int main(){
    string str1,str2;
    str1 = "testest";
    str2 = "estxest";
    if (checkPermuation(str1, str2))
        cout << str1 << " and " << str2 << " are permutation of each other" << endl;
    else
        cout << str1 << " and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
    if (checkPermuation(str1, str2))
        cout << str1 << " and " << str2 << " are permutation of each other" << endl;
    else
        cout << str1 << " and " << str2 << " are not permutation of each other" << endl;
    return 0;
}